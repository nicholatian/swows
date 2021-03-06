#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

from typing import List, Tuple, Dict

from PIL import Image as PILImage

from ctypes import byref as Ref
import sdl2.ext as SDL2Ext
import os as OS
import re as RegExp
import sdl2 as SDL2
import jascpal as JASC
import chkascii as CheckASCII

MAPVIEW_W = 640
MAPVIEW_H = 400

BLOCVIEW_W = 256
BLOCVIEW_H = 400

FRAME_W = 960
FRAME_H = 416

FBUF_RECT = SDL2.SDL_Rect(0, 0, FRAME_W, FRAME_H)

WSPACE_EXPR = RegExp.compile('[ \t\v\f\r]+')

# Bitmasks for RGBA colour (needed for SDL2)
MASK_R = 0x000000FF
MASK_G = 0x0000FF00
MASK_B = 0x00FF0000
MASK_A = 0xFF000000

HELP_TEXT = '''
SABLMAP map editor
Copyright \u00A9 2021 Alexander Nicholi.
Released under BSD 0-Clause licence, a.k.a. the public domain.

Usage:-
	sablmap [flags] <map.ini> <map.owb> <map.owm>

If -s or --silent is provided, the program will not send anything to
stdout nor stderr. Otherwise, it will print status info updates as it
works to stderr. stdin and stdout are never used.
'''

class INI:
	def __init__(self, fpath : str):
		assert(type(fpath) is str)
		f = open(fpath, 'rb')
		t = f.read()
		f.close()
		t_sz = len(t)
		assert(CheckASCII.bad_ascii(t, t_sz, False) == t_sz)
		self.d = self._parse(t.decode('utf-8'))
	def _getbool(self, section : str, key : str):
		input: str = self.d[section][key]
		if input == 'true' or input == 'True' or input == 'TRUE' or \
		input == 'y' or input == 'Y' or input == 'yes' or input == 'Yes' or \
		input == 'YES' or input == 'on' or input == 'On' or input == 'ON':
			return 1
		elif input == 'false' or input == 'False' or input == 'FALSE' or \
		input == 'n' or input == 'N' or input == 'no' or input == 'No' or \
		input == 'NO' or input == 'off' or input == 'Off' or input == 'OFF':
			return 0
		else: return -1
	def readval(self, section : str, key : str):
		assert(type(section) is str)
		assert(section != '')
		assert(type(key) is str)
		assert(key != '')
		assert(section in self.d)
		assert(key in self.d[section])
		r = self._getbool(section, key)
		if r == -1: return self.d[section][key]
		else: return True if r == 1 else False
	def enumsections(self):
		r: List[str] = []
		for section in self.d:
			if section == '':
				continue
			r.append(section)
		return r
	def readgval(self, key : str):
		assert(type(key) is str)
		assert(key != '')
		assert(key in self.d[''])
		r = self._getbool('', key)
		if r == -1: return self.d[''][key]
		else: return True if r == 1 else False
	def writeval(self, section : str, key : str, val : str):
		assert(type(section) is str)
		assert(section != '')
		assert(type(key) is str)
		assert(key != '')
		assert(type(val) is str)
		if section not in self.d:
			self.d[section] = {}
		self.d[section][key] = val
	def writegval(self, key : str, val : str):
		assert(type(key) is str)
		assert(key != '')
		self.d[''][key] = val
	def _parse(self, t : str):
		assert(type(t) is str)
		ret: Dict[str, Dict[str, str]] = {'': {}}
		cur_s = '' # Empty string is the global section
		lines = t.splitlines()
		lines_sz = len(lines)
		i = 0
		while i < lines_sz:
			# Remove comments, anywhere they appear
			line = lines[i].split(';', 1)[0]
			if '[' in line and ']' in line:
				s = line.lstrip(' \t\v\f\r').rstrip(' \t\v\f\r')
				assert(s[0] == '[')
				assert(s[-1] == ']')
				cur_s = s[1:-1]
				ret[cur_s] = {}
				# done parsing now. don't look for a keypair that isn't here
				i += 1
				continue
			elif '=' not in line:
				# Not dealing with a keypair, check it
				line_sz = len(line)
				j = 0
				while j < line_sz:
					ch = line[j]
					# only whitespace is permitted outside of comments and keypairs
					assert(ch == ' ' or ch == '\t' or ch == '\v' or ch == '\f' or
						ch == '\r')
					j += 1
				# don't try to parse this, there's nothing here
				i += 1
				continue
			# NOTE: no whitespace stripping is done. this is deliberate
			p = line.split('=', 1)
			key = p[0]
			val = p[1]
			assert(key != '')
			ret[cur_s][key] = val
			i += 1
		return ret
	def serialise(self):
		r: str = '\n'
		for key in self.d['']:
			r += key + '=' + self.d[''][key] + '\n'
		r += '\n'
		for section in self.d:
			if section == '':
				continue
			r += '[' + section + ']\n'
			for key in self.d[section]:
				r += key + '=' + self.d[section][key] + '\n'
			r += '\n'
		return r

class Col:
	def __init__(self, r : int = 0, g : int = 0, b : int = 0, a : int = 0):
		assert type(r) is int
		assert r >= 0 and r <= 255
		assert type(g) is int
		assert g >= 0 and g <= 255
		assert type(b) is int
		assert b >= 0 and b <= 255
		assert type(a) is int
		assert a >= 0 and a <= 255
		self.r = r
		self.g = g
		self.b = b
		self.a = a
	def rgb555(self):
		r = (self.r >> 3) & 0x1F
		g = (self.g >> 3) & 0x1F
		b = (self.b >> 3) & 0x1F
		return r | (g << 5) | (b << 10)

class MapPalette:
	def __init__(self, fpath : str):
		assert type(fpath) is str
		self.d = JASC.from_file(fpath, False)
		assert len(self.d) == 256
	def get16(self, idx : int):
		assert type(idx) is int
		assert idx >= 0 and idx <= 16
		r: list[Col] = []
		i = idx << 4 # * 16
		end = i + 16
		while i < end:
			a = self.d[i]
			r.append(Col(a[0], a[1], a[2], 255))
			i += 1
		return r
	def get256(self):
		r: list[Col] = []
		i = 0
		while i < 256:
			a = self.d[i]
			r.append(Col(a[0], a[1], a[2], 255))
		return r
	def get1of256(self, idx : int):
		assert type(idx) is int
		assert idx >= 0 and idx <= 255
		a = self.d[idx]
		return Col(a[0], a[1], a[2], 255)
	def get1of16(self, lnum : int, idx : int):
		assert type(lnum) is int
		assert type(idx) is int
		assert lnum >= 0 and lnum <= 15
		assert idx >= 0 and idx <= 15
		i = (lnum << 4) + idx
		a = self.d[i]
		return Col(a[0], a[1], a[2], 255)

class Tileset:
	def __init__(self, fpath : str):
		assert type(fpath) is str
		tmp = PILImage.open(fpath)
		tset = tmp.convert('L')
		tmp.close()
		tset_w = tset.size[0] >> 3 # // 8
		tset_h = tset.size[1] >> 3 # // 8
		tdata = bytearray(((tset_w << 3) * (tset_h << 3)) >> 1)
		tdata_i = 0
		i = 0
		while i < tset_h:
			j = 0
			while j < tset_w:
				tile = tset.crop((j << 3, i << 3, (j << 3) + 8, (i << 3) + 8))
				k = 0
				while k < 32:
					tile_k = k << 1
					tdata[tdata_i] = (tile.getpixel((tile_k & 7, (tile_k >> 3)))
						>> 4) | (tile.getpixel(((tile_k + 1) & 7, (tile_k + 1) >> 3)))
					tdata_i += 1
					k += 1
				j += 1
			i += 1
		self.d = bytes(tdata)
	def readtile(self, idx : int):
		assert type(idx) is int
		return self.d[idx << 5:(idx << 5) + 32] # * 32
	def readtile8(self, idx : int):
		rpack = self.readtile(idx)
		if len(rpack) == 0:
			rpack = bytes(64)
		r = bytearray(64)
		i = 0
		while i < 32:
			r[i << 1] = rpack[i] & 0xF
			r[(i << 1) + 1] = (rpack[i] >> 4)
			i += 1
		return bytes(r)
	def readtile8x(self, idx : int):
		d = self.readtile8(idx)
		r = bytearray(64)
		i = 0
		while i < 8:
			a = bytearray(d[i << 3:(i << 3) + 8])
			a.reverse()
			r[i << 3:(i << 3) + 8] = a
			i += 1
		return bytes(r)
	def readtile8y(self, idx : int):
		d = self.readtile8(idx)
		r = bytearray(64)
		i = 0
		j = 7
		while i < 8:
			r[i << 3:(i << 3) + 8] = bytearray(d[j << 3:(j << 3) + 8])
			i += 1
			j -= 1
		return bytes(r)
	def readtile8xy(self, idx : int):
		d = self.readtile8(idx)
		r = bytearray(64)
		i = 0
		j = 7
		while i < 8:
			a = bytearray(d[j << 3:(j << 3) + 8])
			a.reverse()
			r[i << 3:(i << 3) + 8] = a
			i += 1
			j -= 1
		return bytes(r)
	def readtile8r(self, idx : int, xflip : bool, yflip : bool):
		assert type(idx) is int
		assert type(xflip) is bool
		assert type(yflip) is bool
		if xflip:
			if yflip: return self.readtile8xy(idx)
			else: return self.readtile8x(idx)
		elif yflip: return self.readtile8y(idx)
		else: return self.readtile8(idx)
	def readtiles(self, idxs : List[int]):
		assert(type(idxs) is list)
		idxs_sz = len(idxs)
		if idxs_sz == 0:
			return bytes()
		assert(type(idxs[0]) is int)
		r = bytearray(idxs_sz << 5) # * 32
		i = 0
		while i < idxs_sz:
			r2 = self.readtile(idxs[i])
			r[i << 5:(i << 5) + 32] = r2 # * 32
		return bytes(r)

class MapData:
	def __init__(self, owbtext : str, owmtext : str, w : int, h : int):
		assert(type(owbtext) is str)
		assert(owbtext != '')
		owbtext_sz = len(owbtext)
		assert(CheckASCII.bad_ascii(owbtext.encode('utf-8'),
			owbtext_sz, False) == owbtext_sz)
		assert(type(owmtext) is str)
		assert(owmtext != '')
		owmtext_sz = len(owmtext)
		assert(CheckASCII.bad_ascii(owmtext.encode('utf-8'),
			owmtext_sz, False) == owmtext_sz)
		assert(type(w) is int)
		assert(w > 0)
		assert(type(h) is int)
		assert(h > 0)
		mdata = bytearray((w * h) << 1) # * 2
		owb = self._parse(owbtext)
		owm = self._parse(owmtext)
		i = 0
		while i < h:
			j = 0
			while j < w:
				idx = (i * w) + j
				cur_owb = owb[idx]
				lo = cur_owb & 0xFF
				hi = ((cur_owb >> 8) & 0x3) | ((owm[idx] & 0x3F) << 2)
				mdata[idx << 1] = lo
				mdata[(idx << 1) + 1] = hi
				j += 1
			i += 1
		assert(len(mdata) >> 1 == w * h)
		self.d = mdata
		self.w = w
		self.h = h
	def writeblock(self, block : int, x : int, y : int):
		assert(type(block) is int)
		assert(block >= 0 and block <= 0x3FF)
		assert(type(x) is int)
		assert(x >= 0)
		assert(type(y) is int)
		assert(y >= 0)
		idx = (x * self.w) + y
		# zero out the hi byte's block bits and then OR the new bits back in
		hi = (self.d[(idx << 1) + 1] & 0xFC) | (block >> 8)
		lo = block & 0xFF
		# multiply idx by 2 because we???re getting 16-bit data from a bytearray
		self.d[idx << 1] = lo
		self.d[(idx << 1) + 1] = hi
	def writemperm(self, mperm : int, x : int, y : int):
		assert(type(mperm) is int)
		assert(mperm >= 0 and mperm <= 0x3F)
		assert(type(x) is int)
		assert(x >= 0)
		assert(type(y) is int)
		assert(y >= 0)
		# go ahead and multiply idx by 2 and add 1, we only need hi byte
		idx = (((x * self.w) + y) << 1) + 1
		self.d[idx] = (self.d[idx] & 0x3) | (mperm << 2)
	def readblock(self, x : int, y : int):
		assert(type(x) is int)
		assert(x >= 0)
		assert(type(y) is int)
		assert(y >= 0)
		idx = (y * self.w) + x
		return (self.d[idx << 1]) | ((self.d[(idx << 1) + 1] & 0x3) << 8)
	def readblocks(self, blocks : List[Tuple[int, int]]):
		assert(type(blocks) is list)
		blocks_sz = len(blocks)
		r: List[int] = []
		i = 0
		while i < blocks_sz:
			block = blocks[i]
			assert(type(block) is tuple)
			assert(len(block) == 2)
			x: int = blocks[i][0]
			y: int = blocks[i][1]
			assert(type(x) is int)
			assert(type(y) is int)
			r.append(self.readblock(x, y))
			i += 1
		return r
	def readmperm(self, x : int, y : int):
		assert(type(x) is int)
		assert(x >= 0)
		assert(type(y) is int)
		assert(y >= 0)
		# go ahead and multiply idx by 2 and add 1, we only need hi byte
		idx = (((y * self.w) + x) << 1) + 1
		return self.d[idx] >> 2
	def readmperms(self, mperms : List[Tuple[int, int]]):
		assert(type(mperms) is list)
		mperms_sz = len(mperms)
		r: List[int] = []
		i = 0
		while i < mperms_sz:
			mperm = mperms[i]
			assert(type(mperm) is tuple)
			assert(len(mperm) == 2)
			x: int = mperm[0]
			y: int = mperm[1]
			assert(type(x) is int)
			assert(type(y) is int)
			r.append(self.readmperm(x, y))
			i += 1
		return r
	def _parse(self, text : str):
		r: List[int] = []
		lines = text.splitlines()
		lines_sz = len(lines)
		i = 0
		while i < lines_sz:
			line = lines[i].lstrip(' \t\v\f\r').rstrip(' \t\v\f\r')
			if line == '':
				i += 1
				continue
			items = WSPACE_EXPR.sub(line, ' ').split(' ')
			items_sz = len(items)
			j = 0
			while j < items_sz:
				r.append(int(items[j], 16))
				j += 1
			i += 1
		return r

class Blockset:
	def __init__(self, ini : INI, tset : Tileset):
		assert(type(ini) is INI)
		assert(type(tset) is Tileset)
		count = int(ini.readgval('count'), 0)
		# this is appended to to track duplicate sections
		existing_nums: List[int] = []
		assert(count > 0)
		# each block takes 18 bytes, for 8 tile metadata pieces + 2 behav bytes
		# each tile metadata piece is 2 bytes, stored little endian
		blocks = bytearray(count * 18)
		sections = ini.enumsections()
		sections_sz = len(sections)
		i = 0
		while i < sections_sz:
			section = sections[i]
			num = int(section, 0)
			assert num not in existing_nums
			existing_nums.append(num)
			block = bytearray(18)
			n = int(ini.readval(section, 'l0tl_tile'), 0)
			assert(n >= 0 and n <= 0x3FF)
			block[0] = n & 0xFF
			block[1] = (n >> 8) & 3
			n = int(ini.readval(section, 'l0tl_pal'), 0)
			assert(n >= 0 and n <= 0xF)
			block[1] |= (n << 4)
			n = int(ini.readval(section, 'l0tl_xf'), 0)
			assert(n >= 0 and n <= 1)
			block[1] |= (n << 2)
			n = int(ini.readval(section, 'l0tl_yf'), 0)
			assert(n >= 0 and n <= 1)
			block[1] |= (n << 3)
			n = int(ini.readval(section, 'l0tr_tile'), 0)
			assert(n >= 0 and n <= 0x3FF)
			block[2] = n & 0xFF
			block[3] = (n >> 8) & 3
			n = int(ini.readval(section, 'l0tr_pal'), 0)
			assert(n >= 0 and n <= 0xF)
			block[3] |= (n << 4)
			n = int(ini.readval(section, 'l0tr_xf'), 0)
			assert(n >= 0 and n <= 1)
			block[3] |= (n << 2)
			n = int(ini.readval(section, 'l0tr_yf'), 0)
			assert(n >= 0 and n <= 1)
			block[3] |= (n << 3)
			n = int(ini.readval(section, 'l0bl_tile'), 0)
			assert(n >= 0 and n <= 0x3FF)
			block[4] = n & 0xFF
			block[5] = (n >> 8) & 3
			n = int(ini.readval(section, 'l0bl_pal'), 0)
			assert(n >= 0 and n <= 0xF)
			block[5] |= (n << 4)
			n = int(ini.readval(section, 'l0bl_xf'), 0)
			assert(n >= 0 and n <= 1)
			block[5] |= (n << 2)
			n = int(ini.readval(section, 'l0bl_yf'), 0)
			assert(n >= 0 and n <= 1)
			block[5] |= (n << 3)
			n = int(ini.readval(section, 'l0br_tile'), 0)
			assert(n >= 0 and n <= 0x3FF)
			block[6] = n & 0xFF
			block[7] = (n >> 8) & 3
			n = int(ini.readval(section, 'l0br_pal'), 0)
			assert(n >= 0 and n <= 0xF)
			block[7] |= (n << 4)
			n = int(ini.readval(section, 'l0br_xf'), 0)
			assert(n >= 0 and n <= 1)
			block[7] |= (n << 2)
			n = int(ini.readval(section, 'l0br_yf'), 0)
			assert(n >= 0 and n <= 1)
			block[7] |= (n << 3)
			n = int(ini.readval(section, 'l1tl_tile'), 0)
			assert(n >= 0 and n <= 0x3FF)
			block[8] = n & 0xFF
			block[9] = (n >> 8) & 3
			n = int(ini.readval(section, 'l1tl_pal'), 0)
			assert(n >= 0 and n <= 0xF)
			block[9] |= (n << 4)
			n = int(ini.readval(section, 'l1tl_xf'), 0)
			assert(n >= 0 and n <= 1)
			block[9] |= (n << 2)
			n = int(ini.readval(section, 'l1tl_yf'), 0)
			assert(n >= 0 and n <= 1)
			block[9] |= (n << 3)
			n = int(ini.readval(section, 'l1tr_tile'), 0)
			assert(n >= 0 and n <= 0x3FF)
			block[10] = n & 0xFF
			block[11] = (n >> 8) & 3
			n = int(ini.readval(section, 'l1tr_pal'), 0)
			assert(n >= 0 and n <= 0xF)
			block[11] |= (n << 4)
			n = int(ini.readval(section, 'l1tr_xf'), 0)
			assert(n >= 0 and n <= 1)
			block[11] |= (n << 2)
			n = int(ini.readval(section, 'l1tr_yf'), 0)
			assert(n >= 0 and n <= 1)
			block[11] |= (n << 3)
			n = int(ini.readval(section, 'l1bl_tile'), 0)
			assert(n >= 0 and n <= 0x3FF)
			block[12] = n & 0xFF
			block[13] = (n >> 8) & 3
			n = int(ini.readval(section, 'l1bl_pal'), 0)
			assert(n >= 0 and n <= 0xF)
			block[13] |= (n << 4)
			n = int(ini.readval(section, 'l1bl_xf'), 0)
			assert(n >= 0 and n <= 1)
			block[13] |= (n << 2)
			n = int(ini.readval(section, 'l1bl_yf'), 0)
			assert(n >= 0 and n <= 1)
			block[13] |= (n << 3)
			n = int(ini.readval(section, 'l1br_tile'), 0)
			assert(n >= 0 and n <= 0x3FF)
			block[14] = n & 0xFF
			block[15] = (n >> 8) & 3
			n = int(ini.readval(section, 'l1br_pal'), 0)
			assert(n >= 0 and n <= 0xF)
			block[15] |= (n << 4)
			n = int(ini.readval(section, 'l1br_xf'), 0)
			assert(n >= 0 and n <= 1)
			block[15] |= (n << 2)
			n = int(ini.readval(section, 'l1br_yf'), 0)
			assert(n >= 0 and n <= 1)
			block[15] |= (n << 3)
			behav = int(ini.readval(section, 'behav'), 0)
			assert(behav >= 0 and behav <= 0xFFF)
			block[16] = behav & 0xFF
			typ = ini.readval(section, 'type')
			assert(typ == 'normal' or typ == 'covered' or typ == 'split')
			typ_n = 0
			if typ == 'covered': typ_n = 1
			elif typ == 'split': typ_n = 2
			block[17] = (behav >> 16) | (typ_n << 6)
			blocks[i * 18:(i * 18) + 18] = block
			i += 1
		self.d = bytes(blocks)
	def readtile(self, num : int, layer : int, quadrant : int):
		assert(type(num) is int)
		assert(num >= 0 and num <= 0x3FF)
		assert(type(layer) is int)
		assert(layer >= 0 and layer <= 1)
		assert(type(quadrant) is int)
		assert(quadrant >= 0 and quadrant <= 3)
		idx = (num * 18) + (layer * 8) + (quadrant * 2)
		return self.d[idx] | ((self.d[idx + 1] & 0x3) << 8)
	def readtiles(self, tiles : List[Tuple[int, int, int]]):
		assert(type(tiles) is list)
		tiles_sz = len(tiles)
		r: List[int] = []
		i = 0
		while i < tiles_sz:
			tile = tiles[i]
			assert(type(tile) is tuple)
			assert(len(tile) == 3)
			num: int = tile[0]
			layer: int = tile[1]
			quadrant: int = tile[2]
			r.append(self.readtile(num, layer, quadrant))
			i += 1
		return r
	def readpal(self, num : int, layer : int, quadrant : int):
		assert(type(num) is int)
		assert(num >= 0 and num <= 0x3FF)
		assert(type(layer) is int)
		assert(layer >= 0 and layer <= 1)
		assert(type(quadrant) is int)
		assert(quadrant >= 0 and quadrant <= 3)
		idx = (num * 18) + (layer * 8) + (quadrant * 2) + 1
		return (self.d[idx] >> 4) & 0xF
	def readxflip(self, num : int, layer : int, quadrant : int):
		assert(type(num) is int)
		assert(num >= 0 and num <= 0x3FF)
		assert(type(layer) is int)
		assert(layer >= 0 and layer <= 1)
		assert(type(quadrant) is int)
		assert(quadrant >= 0 and quadrant <= 3)
		idx = (num * 18) + (layer * 8) + (quadrant * 2) + 1
		return True if (self.d[idx] >> 2) & 1 == 1 else False
	def readxflips(self, flips : List[Tuple[int, int, int]]):
		assert(type(flips) is list)
		flips_sz = len(flips)
		r: List[bool] = []
		i = 0
		while i < flips_sz:
			flip = flips[i]
			assert(type(flip) is tuple)
			assert(len(flip) == 3)
			num: int = flip[0]
			layer: int = flip[1]
			quadrant: int = flip[2]
			r.append(self.readxflip(num, layer, quadrant))
			i += 1
		return r
	def readyflip(self, num : int, layer : int, quadrant : int):
		assert(type(num) is int)
		assert(num >= 0 and num <= 0x3FF)
		assert(type(layer) is int)
		assert(layer >= 0 and layer <= 1)
		assert(type(quadrant) is int)
		assert(quadrant >= 0 and quadrant <= 3)
		idx = (num * 18) + (layer * 8) + (quadrant * 2) + 1
		return True if (self.d[idx] >> 3) & 1 == 1 else False
	def readyflips(self, flips : List[Tuple[int, int, int]]):
		assert(type(flips) is list)
		flips_sz = len(flips)
		r: List[bool] = []
		i = 0
		while i < flips_sz:
			flip = flips[i]
			assert(type(flip) is tuple)
			assert(len(flip) == 3)
			num: int = flip[0]
			layer: int = flip[1]
			quadrant: int = flip[2]
			r.append(self.readyflip(num, layer, quadrant))
			i += 1
		return r

class State:
	def __init__(self, win : SDL2.SDL_Window, fbuf : SDL2.SDL_Surface,
	mapdata : MapData, bprima : Blockset, bsecunda : Blockset,
	tprima : Tileset, tsecunda : Tileset, pprima : MapPalette,
	psecunda : MapPalette):
		assert type(mapdata) is MapData
		assert type(bprima) is Blockset
		assert type(bsecunda) is Blockset
		assert type(tprima) is Tileset
		assert type(tsecunda) is Tileset
		assert type(pprima) is MapPalette
		assert type(psecunda) is MapPalette
		self.win = win
		self.fbuf = fbuf
		self.mapdata = mapdata
		self.bprima = bprima
		self.bsecunda = bsecunda
		self.tprima = tprima
		self.tsecunda = tsecunda
		self.pprima = pprima
		self.psecunda = psecunda
		self._need_update = True
		self.onsplash = True
		self.loadmap = False
		self.x_offs = 0
		self.y_offs = 0
	def req_update(self):
		self._need_update = True
	def ack_update(self):
		self._need_update = False
	def need_update(self):
		return self._need_update

# render0: get all tiles, perform x flipping and y flipping
#  -> this deals in one-dimensional bytearrays
#  -> the pixel format is just two (2) flat 8bpp index bitmaps (no tiling)
# render1: colour tiles by palette, apply transparency
#  -> this takes a 1D bytearray and colours onto an SDL_Surface

def render0(mdata : MapData, tprima : Tileset, tsecunda : Tileset,
bprima : Blockset, bsecunda : Blockset, pprima : MapPalette,
psecunda: MapPalette, mapview : Tuple[int, int, int, int]):
	assert(type(mdata) is MapData)
	assert(type(tprima) is Tileset)
	assert(type(tsecunda) is Tileset)
	assert(type(bprima) is Blockset)
	assert(type(bsecunda) is Blockset)
	assert(type(pprima) is MapPalette)
	assert(type(psecunda) is MapPalette)
	r1 = SDL2.SDL_CreateRGBSurfaceWithFormat(0, mapview[2] * 16,
		mapview[3] * 16, 32, SDL2.SDL_PIXELFORMAT_RGBA8888)
	r2 = SDL2.SDL_CreateRGBSurfaceWithFormat(0, mapview[2] * 16,
		mapview[3] * 16, 32, SDL2.SDL_PIXELFORMAT_RGBA8888)
	SDL2.SDL_SetSurfaceBlendMode(r1, SDL2.SDL_BLENDMODE_BLEND)
	SDL2.SDL_SetSurfaceBlendMode(r2, SDL2.SDL_BLENDMODE_BLEND)
	view = SDL2Ext.PixelView(r1.contents)
	view2 = SDL2Ext.PixelView(r2.contents)
	tprima_sz = len(tprima.d) // 32
	y = mapview[1]
	while y < mdata.h and y < mapview[3]:
		x = mapview[0]
		while x < mdata.w and y < mapview[2]:
			blockid = mdata.readblock(x, y)
			bset = bprima
			bprima_sz = len(bprima.d) // 18
			if blockid >= bprima_sz:
				blockid -= bprima_sz
				bset = bsecunda
			# each tile is a 64-long array of pixels
			# each pixel is a 1-byte index of a palette 0-15
			tilepels: List[bytes] = []
			i = 0
			while i < 8:
				tnum = bset.readtile(blockid, i >> 2, i & 3)
				tile = None
				if tnum >= tprima_sz:
					tile = tsecunda.readtile8r(tnum - tprima_sz,
						bset.readxflip(blockid, i >> 2, i & 3),
						bset.readyflip(blockid, i >> 2, i & 3))
				else:
					tile = tprima.readtile8r(tnum,
						bset.readxflip(blockid, i >> 2, i & 3),
						bset.readyflip(blockid, i >> 2, i & 3))
				tilepels.append(tile)
				i += 1
			palidxs: List[int] = [
				# top left, layer 0
				bset.readpal(blockid, 0, 0),
				# top right, layer 0
				bset.readpal(blockid, 0, 1),
				# bottom left, layer 0
				bset.readpal(blockid, 0, 2),
				# bottom right, layer 0
				bset.readpal(blockid, 0, 3),
				# top left, layer 1
				bset.readpal(blockid, 1, 0),
				# top right, layer 1
				bset.readpal(blockid, 1, 1),
				# bottom left, layer 1
				bset.readpal(blockid, 1, 2),
				# bottom right, layer 1
				bset.readpal(blockid, 1, 3)
			]
			# LAYER 0
			# copy top left tile
			pel_x = x * 16
			pel_y = y * 16
			i = 0
			while i < 64:
				pal = pprima if palidxs[0] < 6 else psecunda
				col = pal.get1of16(palidxs[0], int(tilepels[0][i]))
				view[pel_y + (i // 8)][pel_x + (i % 8)] = \
					col.b | (col.g << 8) | (col.r << 16) | 0xFF000000
				i += 1
			# copy top right tile
			pel_x = (x * 16) + 8
			pel_y = y * 16
			i = 0
			while i < 64:
				pal = pprima if palidxs[1] < 6 else psecunda
				col = pal.get1of16(palidxs[1], int(tilepels[1][i]))
				view[pel_y + (i // 8)][pel_x + (i % 8)] = \
					col.b | (col.g << 8) | (col.r << 16) | 0xFF000000
				i += 1
			# copy bottom left tile
			pel_x = x * 16
			pel_y = (y * 16) + 8
			i = 0
			while i < 64:
				pal = pprima if palidxs[2] < 6 else psecunda
				col = pal.get1of16(palidxs[2], int(tilepels[2][i]))
				view[pel_y + (i // 8)][pel_x + (i % 8)] = \
					col.b | (col.g << 8) | (col.r << 16) | 0xFF000000
				i += 1
			# copy bottom right tile
			pel_x = (x * 16) + 8
			pel_y = (y * 16) + 8
			i = 0
			while i < 64:
				pal = pprima if palidxs[3] < 6 else psecunda
				col = pal.get1of16(palidxs[3], int(tilepels[3][i]))
				view[pel_y + (i // 8)][pel_x + (i % 8)] = \
					col.b | (col.g << 8) | (col.r << 16) | 0xFF000000
				i += 1
			# LAYER 1
			# copy top left tile
			pel_x = x * 16
			pel_y = y * 16
			i = 0
			while i < 64:
				subpalidx = int(tilepels[4][i])
				pal = pprima if palidxs[4] < 6 else psecunda
				col = pal.get1of16(palidxs[4], subpalidx)
				alpha = 0 if subpalidx == 0 else 255
				view2[pel_y + (i // 8)][pel_x + (i % 8)] = \
					col.b | (col.g << 8) | (col.r << 16) | (alpha << 24)
				i += 1
			# copy top right tile
			pel_x = (x * 16) + 8
			pel_y = y * 16
			i = 0
			while i < 64:
				subpalidx = int(tilepels[5][i])
				pal = pprima if palidxs[5] < 6 else psecunda
				col = pal.get1of16(palidxs[5], subpalidx)
				alpha = 0 if subpalidx == 0 else 255
				view2[pel_y + (i // 8)][pel_x + (i % 8)] = \
					col.b | (col.g << 8) | (col.r << 16) | (alpha << 24)
				i += 1
			# copy bottom left tile
			pel_x = x * 16
			pel_y = (y * 16) + 8
			i = 0
			while i < 64:
				subpalidx = int(tilepels[6][i])
				pal = pprima if palidxs[6] < 6 else psecunda
				col = pal.get1of16(palidxs[6], subpalidx)
				alpha = 0 if subpalidx == 0 else 255
				view2[pel_y + (i // 8)][pel_x + (i % 8)] = \
					col.b | (col.g << 8) | (col.r << 16) | (alpha << 24)
				i += 1
			# copy bottom right tile
			pel_x = (x * 16) + 8
			pel_y = (y * 16) + 8
			i = 0
			while i < 64:
				subpalidx = int(tilepels[7][i])
				pal = pprima if palidxs[7] < 6 else psecunda
				col = pal.get1of16(palidxs[7], subpalidx)
				alpha = 0 if subpalidx == 0 else 255
				view2[pel_y + (i // 8)][pel_x + (i % 8)] = \
					col.b | (col.g << 8) | (col.r << 16) | (alpha << 24)
				i += 1
			x += 1
		y += 1
	return (r1, r2)

def pil2sdl(lis : List[Tuple]):
	assert(type(lis) is list)
	i = 0
	ret_i = 0
	lis_sz = len(lis)
	ret = bytearray(lis_sz << 2) # * 4
	while i < lis_sz:
		ret[ret_i] = lis[i][0]
		ret[ret_i + 1] = lis[i][1]
		ret[ret_i + 2] = lis[i][2]
		ret[ret_i + 3] = 255
		ret_i += 4
		i += 1
	return bytes(ret)

def mainloop(state : State):
	e = SDL2.SDL_Event()
	while SDL2.SDL_PollEvent(Ref(e)) != 0:
		if e.type == SDL2.SDL_QUIT:
			return True
		elif e.type == SDL2.SDL_KEYDOWN and not state.onsplash:
			code = e.key.keysym.scancode
			print('keypress!', code, '::', state.y_offs, state.mapdata.h)
			if code == SDL2.SDL_SCANCODE_DOWN and \
			state.y_offs + state.mapdata.h < MAPVIEW_H:
				state.y_offs += 1
				state.req_update()
			elif code == SDL2.SDL_SCANCODE_RIGHT and \
			state.x_offs + state.mapdata.w < MAPVIEW_W:
				state.x_offs += 1
				state.req_update()
			elif code == SDL2.SDL_SCANCODE_UP and state.y_offs > 0:
				state.y_offs -= 1
				state.req_update()
			elif code == SDL2.SDL_SCANCODE_LEFT and state.x_offs > 0:
				state.x_offs -= 1
				state.req_update()
		elif e.type == SDL2.SDL_MOUSEBUTTONUP:
			if state.onsplash:
				imag = PILImage.open(OS.path.join('etc', 'working.png'))
				surf = SDL2.SDL_CreateRGBSurfaceFrom(
					pil2sdl(list(imag.getdata())), FRAME_W, FRAME_H, 32,
					4 * FRAME_W, MASK_R, MASK_G, MASK_B, MASK_A)
				imag.close()
				SDL2.SDL_BlitSurface(surf, FBUF_RECT,
					state.fbuf, FBUF_RECT)
				state.req_update()
				state.onsplash = False
				state.loadmap = True
		if state.loadmap:
			surfs = render0(state.mapdata, state.tprima, state.tsecunda,
				state.bprima, state.bsecunda, state.pprima, state.psecunda,
				(state.x_offs, state.y_offs, MAPVIEW_W // 16, MAPVIEW_H // 16))
			MAP_RECT = SDL2.SDL_Rect(0, 0, MAPVIEW_W, MAPVIEW_H)
			SDL2.SDL_BlitSurface(surfs[0], MAP_RECT, state.fbuf, FBUF_RECT)
			SDL2.SDL_BlitSurface(surfs[1], MAP_RECT, state.fbuf, FBUF_RECT)
			state.req_update()
			state.loadmap = False
	if state.need_update():
		if not state.onsplash:
			surfs = render0(state.mapdata, state.tprima, state.tsecunda,
				state.bprima, state.bsecunda, state.pprima, state.psecunda,
				(state.x_offs, state.y_offs, MAPVIEW_W // 16, MAPVIEW_H // 16))
			MAP_RECT = SDL2.SDL_Rect(0, 0, MAPVIEW_W, MAPVIEW_H)
			SDL2.SDL_BlitSurface(surfs[0], MAP_RECT, state.fbuf, FBUF_RECT)
			SDL2.SDL_BlitSurface(surfs[1], MAP_RECT, state.fbuf, FBUF_RECT)
		SDL2.SDL_BlitSurface(state.fbuf, None,
			SDL2.SDL_GetWindowSurface(state.win), None)
		SDL2.SDL_UpdateWindowSurface(state.win)
		state.ack_update()
	SDL2.SDL_ShowWindow(state.win)
	SDL2.SDL_Delay(16)
	return False

def main(args : List[str]):
	assert(type(args) is list)
	argc = len(args)
	assert(argc >= 1)
	assert(type(args[0]) is str)
	silent = '-s' in args or '--silent' in args
	if argc == 1 or '-h' in args or '--help' in args:
		print(HELP_TEXT)
		return 127
	i = 1
	ini_fpath = None
	owb_fpath = None
	owm_fpath = None
	while i < argc:
		if args[i].startswith('-'):
			if args[i] == '-s' or args[i] == '--silent':
				# Already handled above
				pass
			else: print('WARNING: Unknown flag \u2018%s\u2019' % args[i])
		elif ini_fpath == None:
			ini_fpath = args[i]
		elif owb_fpath == None:
			owb_fpath = args[i]
		elif owm_fpath == None:
			owm_fpath = args[i]
		else: print('WARNING: Excess parameter \u2018%s\u2019' % args[i])
		i += 1
	if ini_fpath == None or owb_fpath == None or owm_fpath == None:
		print('Insufficient parameters. Exiting...')
		return 127
	SDL2.SDL_Init(SDL2.SDL_INIT_VIDEO)
	win: SDL2.SDL_Window = SDL2.SDL_CreateWindow(
		'SABLMAP alpha'.encode('utf-8'), SDL2.SDL_WINDOWPOS_UNDEFINED,
		SDL2.SDL_WINDOWPOS_UNDEFINED, FRAME_W, FRAME_H, 0)
	fbuf: SDL2.SDL_Surface = SDL2.SDL_CreateRGBSurface(0, FRAME_W, FRAME_H,
		32, MASK_R, MASK_G, MASK_B, MASK_A)
	SDL2.SDL_SetSurfaceBlendMode(fbuf, SDL2.SDL_BLENDMODE_NONE)
	ini = INI(ini_fpath)
	f = open(owb_fpath, 'r')
	owbtext = f.read()
	f.close()
	f = open(owm_fpath, 'r')
	owmtext = f.read()
	f.close()
	mdata = MapData(owbtext, owmtext,
		int(ini.readgval('w'), 0), int(ini.readgval('h'), 0))
	basedir = OS.path.dirname(ini_fpath)
	tdir = OS.path.join(basedir, 'tileset')
	bdir = OS.path.join(basedir, 'blockset')
	nprima = ini.readgval('prima')
	tprima = Tileset(OS.path.join(tdir, nprima + '.4tn.il.png'))
	pprima = MapPalette(OS.path.join(tdir, nprima + '.jasc'))
	bprima = Blockset(INI(OS.path.join(bdir, nprima + '.ini')), tprima)
	nsecunda = ini.readgval('secunda')
	tsecunda = Tileset(OS.path.join(tdir, nsecunda + '.4tn.il.png'))
	psecunda = MapPalette(OS.path.join(tdir, nsecunda + '.jasc'))
	bsecunda = Blockset(INI(OS.path.join(bdir, nsecunda + '.ini')),
		tsecunda)
	state = State(win, fbuf, mdata, bprima, bsecunda, tprima, tsecunda,
		pprima, psecunda)
	imag = PILImage.open(OS.path.join('etc', 'startup.png'))
	surf = SDL2.SDL_CreateRGBSurfaceFrom(pil2sdl(list(imag.getdata())),
		FRAME_W, FRAME_H, 32, 4 * FRAME_W, MASK_R, MASK_G, MASK_B, MASK_A)
	imag.close()
	SDL2.SDL_BlitSurface(surf, FBUF_RECT, fbuf, FBUF_RECT)
	state.req_update()
	while mainloop(state) == False: continue
	SDL2.SDL_DestroyWindow(win)
	SDL2.SDL_Quit()
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
