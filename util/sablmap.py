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
import os as OS
import re as RegExp
import sdl2 as SDL2

MAPVIEW_W = 640
MAPVIEW_H = 400

BLOCKVIEW_W = 256
BLOCKVIEW_H = 400

FRAME_W = 960
FRAME_H = 416

FRAME_RECT = SDL2.SDL_Rect(0, 0, FRAME_W, FRAME_H)
MAPVIEW_RECT = SDL2.SDL_Rect(0, 0, MAPVIEW_W, MAPVIEW_H)
BLOCKVIEW_RECT = SDL2.SDL_Rect(0, 0, BLOCKVIEW_W, BLOCKVIEW_H)

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

def is_ascii(text : 'str | bytes | bytearray', allow_nul : bool = False):
	assert type(allow_nul) is bool
	assert type(text) is str or type(text) is bytes or type(text) is bytearray
	if type(text) is str:
		text = text.encode('utf-8')
	elif type(text) is bytearray:
		text = bytes(text)
	# now text is certainly bytes
	text_sz = len(text)
	i = 0
	while i < text_sz:
		if text[i] > 127: return False
		if not allow_nul and text[i] == 0: return False
		i += 1
	return True

class Ini:
	def __init__(self, text : str):
		Ini._marshal_init(text)
		self._d = Ini._parse(text)
		Ini.marshal()
	@staticmethod
	def _parse(text : str):
		r: Dict[str, Dict[str, str]] = {'': {}}
		cur_s = '' # Empty string is the global section
		lines = text.splitlines()
		lines_sz = len(lines)
		i = 0
		while i < lines_sz:
			# Remove comments, anywhere they appear
			line = lines[i].split(';', 1)[0]
			if '[' in line and ']' in line:
				cur_s = line[1:-1]
				r[cur_s] = {}
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
			r[cur_s][key] = val
			i += 1
		return r
	@staticmethod
	def _marshal_init_line(line : str):
		# strip out comments
		line = line.split(';', 1)[0]
		line_sz = len(line)
		if line[0] == '[':
			# must be on the end
			assert line[-1] == ']'
			i = 1
			while i < line_sz - 1:
				# don't allow perceptively nesting brackets
				assert line[i] != '['
				assert line[i] != ']'
				# necessary to avoid ambiguity
				assert line[i] != '='
				i += 1
		elif '=' in line:
			keypair = line.split('=', 1)
			assert keypair[0] != ''
	@staticmethod
	def _marshal_init(text : str):
		assert type(text) is str
		text_sz = len(text)
		# file must be ASCII
		assert is_ascii(text)
		# trailing newlines
		assert text[-1] == '\n'
		lines = text.splitlines()
		lines_sz = len(lines)
		i = 0
		while i < lines_sz:
			Ini._marshal_line(lines[i])
			i += 1
	def marshal(self):
		assert type(self._d) is 'dict[str, dict[str, str]]'
		for section in self._d:
			assert type(section) is str
			for key in self._d[section]:
				assert type(key) is str
				assert key != ''
				assert type(self._d[key]) is str
	def __getitem__(self, idx : 'tuple[str, str] | str'):
		assert type(idx) is 'tuple[str, str]' or type(idx) is str
		if type(idx) is str:
			assert idx != ''
			return self._d[''][idx]
		else:
			assert idx[0] != ''
			assert idx[1] != ''
			return self._d[idx[0]][idx[1]]
	def __setitem__(self, idx : 'tuple[str, str] | str', val : 'str | bool'):
		assert type(val) is str or type(val) is bool
		assert type(idx) is 'tuple[str, str]' or type(idx) is str
		if type(val) is bool:
			val = 'on' if val else 'off'
		if type(idx) is str:
			assert idx != ''
			self._d[''][idx] = val
		else:
			assert idx[0] != ''
			assert idx[1] != ''
			self._d[idx[0]][idx[1]] = val
	def sections(self):
		r: List[str] = []
		for section in self._d:
			if section == '': continue
			r.append(section)
		return r

class Col:
	def __init__(self, r : int = 0, g : int = 0, b : int = 0, a : int = 255):
		Col._marshal(r, g, b, a)
		self.r = r
		self.g = g
		self.b = b
		self.a = a
	@staticmethod
	def _marshal(r : int, g : int, b : int, a : int):
		assert type(r) is int
		assert r >= 0 and r <= 255
		assert type(g) is int
		assert g >= 0 and g <= 255
		assert type(b) is int
		assert b >= 0 and b <= 255
		assert type(a) is int
		assert a >= 0 and a <= 255
	def marshal(self):
		Col._marshal(self.r, self.g, self.b, self.a)
	def argb8888(self):
		self.marshal()
		return self.b | (self.g << 8) | (self.r << 16) | (self.a << 24)
	def rgb555(self):
		self.marshal()
		return (self.r >> 3) | ((self.g >> 3) << 5) | ((self.b >> 3) << 10)
	def jasc(self):
		self.marshal()
		return str(self.r) + ' ' + str(self.g) + ' ' + str(self.b)

class AgbPalette:
	def __init__(self, text : str):
		AgbPalette._marshal(text)
		self._d = AgbPalette._parse(text)
		if len(self._d) <= 16: self._8bpp = False
		else: self._8bpp = True
	@staticmethod
	def _marshal_line(line : str):
		if line == '': return
		channels = line.split(' ')
		assert len(channels) == 3
		red = int(channels[0], 10)
		green = int(channels[1], 10)
		blue = int(channels[2], 10)
		assert red >= 0 and red <= 255
		assert green >= 0 and green <= 255
		assert blue >= 0 and blue <= 255
	def marshal(self):
		AgbPalette._marshal(self._d)
	@staticmethod
	def _marshal_init(text : str):
		assert type(text) is str
		assert is_ascii(text)
		lines = text.splitlines()
		lines_sz = len(lines)
		assert lines_sz > 3
		assert lines[0] == 'JASC-PAL'
		assert int(lines[1], 16) >= 0x100
		count = int(lines[2], 10)
		assert count > 0 and count <= 256
		i = 3
		while i < lines_sz:
			AgbPalette._marshal_line(lines[i])
			i += 1
	@staticmethod
	def _marshal(cols : List[Col]):
		cols_sz = len(cols)
		i = 0
		while i < cols_sz:
			assert type(cols[i]) is Col
			i += 1
	@staticmethod
	def _parse(text : str):
		ret: List[Col] = []
		# skip over JASC header with slice
		lines = text.splitlines()[3:]
		lines_sz = len(lines)
		i = 0
		while i < lines_sz:
			if lines[i] != '':
				c = lines[i].split(' ')
				ret.append(Col(int(c[0], 10), int(c[1], 10), int(c[2], 10)))
			i += 1
		return ret
	@staticmethod
	def _stringify(cols : List[Col]):
		ret = ['JASC-PAL', '0100']
		cols_sz = len(cols)
		ret.append(str(cols_sz))
		i = 0
		while i < cols_sz:
			ret.append(cols[i].jasc())
			i += 1
		return '\n'.join(ret)
	def __getitem__(self, idx : 'tuple[int, int] | int'):
		assert type(idx) is 'tuple[int, int]' or type(idx) is int
		if type(idx) is 'tuple[int, int]':
			# Multi-dimensional access requires 8-bit palette store
			assert self._8bpp
			# << 4 is * 16
			idx = (idx[0] << 4) + idx[1]
		assert idx < len(self._d)
		r: Col = self._d[idx]
		return r
	def __setitem__(self, idx : 'tuple[int, int] | int', val : Col):
		assert type(idx) is 'tuple[int, int]' or type(idx) is int
		assert type(val) is Col
		if type(idx) is 'tuple[int, int]':
			# Multi-dimensional access requires 8-bit palette store
			assert self._8bpp
			# << 4 is * 16
			idx = (idx[0] << 4) + idx[1]
		assert idx < len(self._d)
		self._d[idx] = val
	def __len__(self):
		return len(self._d)
	def setsize(self, count : int):
		assert type(count) is int
		assert count > 0 and count <= 256
		old_sz = len(self._d)
		if old_sz > count:
			self._d = self._d[:count]
		elif old_sz < count:
			i = old_sz
			while i < count:
				self._d.append(Col())
				i += 1
		if count <= 16: self._8bpp = False
		else: self._8bpp = True

class Tileset:
	def __init__(self, fpath : str):
		assert type(fpath) is str
		assert fpath != ''
		image = PILImage.open(fpath)
		# make tileset grayscale
		image2 = image.convert('L')
		self._d = Tileset._parse(image2)
		image.close()
		image2.close()
		# >> 6 is / 64
		self._len = len(self._d >> 6)
	@staticmethod
	def _xy2offs(x : int, y : int, w : int, h : int):
		# width and height must be divisible by 8
		assert w & 7 == 0
		assert h & 7 == 0
		assert y < h
		assert x < w
		return (y * w) + x
	@staticmethod
	def _offs2xy(offs : int, w : int, h : int):
		# width and height must be divisible by 8
		assert w & 7 == 0
		assert h & 7 == 0
		offsdw = offs // w
		x = offs - offsdw
		y = offsdw
		assert y < h
		assert x < w
		return (x, y)
	@staticmethod
	def _parse(image : PILImage.Image):
		# image_{w,h} is denominated in pixels
		image_w = image.size[0]
		image_h = image.size[1]
		# tiles_{w,h} is denominated in tiles
		tiles_w = image_w >> 3
		tiles_h = image_h >> 3
		# each byte stores a palette index between 0-15
		data_sz = image_w * image_h
		data = bytearray(data_sz)
		i = 0
		while i < data_sz:
			# >> 6 is / 64
			# 64 bytes per tile
			big_offs = i >> 6
			# coordinate conversion must be denominated in tiles
			x, y = Tileset._offs2xy(big_offs, tiles_w, tiles_h)
			# multiply back to get pixel xy
			x <<= 3
			y <<= 3
			pixel = image.getpixel((x, y)) >> 4
			data[i] = pixel
			i += 1
		return bytes(data)
	def __getitem__(self, idx : 'tuple[int, int] | int'):
		assert type(idx) is 'tuple[int, int]' or type(idx) is int
		if type(idx) is 'tuple[int, int]':
			assert idx[0] >= 0 and idx[0] < self._len
			assert idx[1] >= 0 and idx[1] < 64
			# << 6 is * 64
			idx = (idx[0] << 6) + idx[1]
		else:
			assert idx >= 0 and idx < self._len
			# << 6 is * 64
			idx <<= 6
		return self._d[idx:idx + 64]
	def __setitem__(self, idx : 'tuple[int, int]', val : int):
		assert type(idx) is 'tuple[int, int]'
		assert idx[0] >= 0 and idx[0] < self._len
		assert idx[1] >= 0 and idx[1] < 64
		assert type(val) is int
		assert val >= 0 and val <= 15
		# << 6 is * 64
		i = (idx[0] << 6) + idx[1]
		self._d[i] = val
	def __len__(self):
		return self._len
