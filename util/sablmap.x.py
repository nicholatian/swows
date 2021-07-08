#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

from typing import List, Tuple, Dict, Literal

from PIL import Image as PILImage

from ctypes import byref as Ref
import os as OS
import re as RegExp
import sdl2 as SDL2
import sdl2.ext as SDL2Ext

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
		Ini.marshal(self)
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
		if line_sz == 0:
			return
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
			Ini._marshal_init_line(lines[i])
			i += 1
	def marshal(self):
		#assert type(self._d) is 'dict[str, dict[str, str]]'
		for section in self._d:
			assert type(section) is str
			for key in self._d[section]:
				assert type(key) is str
				assert key != ''
				assert type(self._d[section][key]) is str
	def __getitem__(self, idx : 'tuple[str, str] | str'):
		#assert type(idx) is 'tuple[str, str]' or type(idx) is str
		if type(idx) is str:
			assert idx != ''
			return self._d[''][idx]
		else:
			assert idx[0] != ''
			assert idx[1] != ''
			return self._d[idx[0]][idx[1]]
	def __setitem__(self, idx : 'tuple[str, str] | str', val : 'str | bool'):
		assert type(val) is str or type(val) is bool
		#assert type(idx) is 'tuple[str, str]' or type(idx) is str
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
	@staticmethod
	def truthy(s : str):
		return True if s == 'true' or s == 'True' or s == 'TRUE' or \
		s == 'y' or s == 'Y' or s == 'yes' or s == 'Yes' or \
		s == 'YES' or s == 'on' or s == 'On' or s == 'ON' or \
		int(s, 0) == 1 else False
	@staticmethod
	def falsey(s : str):
		return True if s == 'false' or s == 'False' or s == 'FALSE' or \
		s == 'n' or s == 'N' or s == 'no' or s == 'No' or \
		s == 'NO' or s == 'off' or s == 'Off' or s == 'OFF' or \
		int(s, 0) == 0 else False

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
	def __init__(self, fpath : str):
		f = open(fpath, 'r')
		text = f.read()
		f.close()
		self._d = AgbPalette._parse(text)
		AgbPalette._marshal(self._d)
		if len(self._d) <= 16: self._8bpp = False
		else: self._8bpp = True
	@staticmethod
	def _marshal_init_line(line : str):
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
			AgbPalette._marshal_init_line(lines[i])
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
		#assert type(idx) is 'tuple[int, int]' or type(idx) is int
		if type(idx) is tuple:
			# Multi-dimensional access requires 8-bit palette store
			assert self._8bpp
			# << 4 is * 16
			idx = (idx[0] << 4) + idx[1]
		assert idx < len(self._d)
		r: Col = self._d[idx]
		return r
	def __setitem__(self, idx : 'tuple[int, int] | int', val : Col):
		#assert type(idx) is 'tuple[int, int]' or type(idx) is int
		assert type(val) is Col
		if type(idx) is tuple:
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
		self._len = len(self._d) >> 6
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
		y = offs // w
		x = offs % w
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
			big_offs = (i >> 6)
			# coordinate conversion must be denominated in tiles
			x, y = Tileset._offs2xy(big_offs, tiles_w, tiles_h)
			# multiply back to get pixel xy
			x <<= 3
			y <<= 3
			pixel = image.getpixel((x, y)) >> 4
			data[i] = pixel
			i += 1
		return data
	def __getitem__(self, idx : 'tuple[int, int] | int'):
		#assert type(idx) is 'tuple[int, int]' or type(idx) is int
		if type(idx) is tuple:
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
		#assert type(idx) is 'tuple[int, int]'
		assert idx[0] >= 0 and idx[0] < self._len
		assert idx[1] >= 0 and idx[1] < 64
		assert type(val) is int
		assert val >= 0 and val <= 15
		# << 6 is * 64
		i = (idx[0] << 6) + idx[1]
		self._d[i] = val
	def __len__(self):
		return self._len

class MapBlock:
	def __init__(self, data : int):
		assert type(data) is int
		assert data >= 0 and data < 65536
		self.block = data & 0x3FF
		self.move = (data >> 10) & 0x3F

class MapData:
	def __init__(self, owbtext : str, owmtext : str, w : int, h : int):
		MapData._marshal(owbtext, owmtext, w, h)
		self._d = MapData._parse(owbtext, owmtext, w, h)
		self._w = w
		self._h = h
	@staticmethod
	def _marshal(owbtext : str, owmtext : str, w : int, h : int):
		assert type(owbtext) is str
		assert type(owmtext) is str
		assert type(w) is int
		assert w > 0 and w < 65536
		assert type(h) is int
		assert h > 0 and h < 65536
		MapData._marshal_ow(owbtext, w, h, True)
		MapData._marshal_ow(owmtext, w, h, False)
	@staticmethod
	def _marshal_ow(text : str, w : int, h : int, is_blocks : bool):
		assert type(text) is str
		assert type(is_blocks) is bool
		nums = WSPACE_EXPR.sub(text.replace('\n', ' '), ' ').split(' ')[:-1]
		count = w * h
		assert len(nums) == count
		i = 0
		while i < count:
			n = int(nums[i], 16)
			assert n >= 0
			if is_blocks: assert n <= 0x3FF
			else: assert n <= 0x3F
			i += 1
	@staticmethod
	def _parse(owbtext : str, owmtext : str, w : int, h : int):
		owbs = WSPACE_EXPR.sub(owbtext.replace('\n', ' '), ' ').split(' ')
		owms = WSPACE_EXPR.sub(owmtext.replace('\n', ' '), ' ').split(' ')
		count = w * h
		# << 1 is * 2
		ret = bytearray(count << 1)
		i = 0
		while i < count:
			# store this in little endian, so LSB first
			# << 1 is * 2
			owb = int(owbs[i], 16)
			ret[i << 1] = owb & 0xFF
			ret[(i << 1) + 1] = (owb >> 8) | (int(owms[i], 16) << 2)
			i += 1
		return ret
	def __getitem__(self, idx : 'tuple[int, int]'):
		#assert type(idx) is 'tuple[int, int]'
		assert idx[0] >= 0 and idx[0] < self._w
		assert idx[1] >= 0 and idx[1] < self._h
		i = (idx[1] * self._h) + idx[0]
		return MapBlock(self._d[i])
	def __setitem__(self, idx : 'tuple[int, int]', val : MapBlock):
		#assert type(idx) is 'tuple[int, int]'
		assert idx[0] >= 0 and idx[0] < self._w
		assert idx[1] >= 0 and idx[1] < self._h
		assert type(val) is MapBlock
		i = (idx[1] * self._h) + idx[0]
		n = (val.block & 0x3FF) | ((val.move & 0x3F) << 10)
		self._d[i] = MapBlock(n)

class BlocksetBlock:
	def __init__(self, tiles : List[int], pals : List[int],
	xflips : List[bool], yflips : List[bool], behav : int,
	btype : Literal['normal', 'covered', 'split']):
		#assert type(tiles) is 'list[int]'
		assert len(tiles) == 8
		#assert type(pals) is 'list[int]'
		assert len(pals) == 8
		#assert type(xflips) is 'list[bool]'
		assert len(xflips) == 8
		#assert type(yflips) is 'list[bool]'
		assert len(yflips) == 8
		assert type(btype) is str
		assert type(behav) is int
		assert behav >= 0 and behav <= 255
		assert btype == 'normal' or btype == 'covered' or btype == 'split'
		self.tiles = tiles
		self.pals = pals
		self.xflips = xflips
		self.yflips = yflips
		self.behav = behav
		self.btype = btype

BLOCK_FIELDS = ['tl', 'tr', 'bl', 'br']

class Blockset:
	def __init__(self, fpath : str):
		assert type(fpath) is str
		f = open(fpath, 'rb')
		d = f.read()
		f.close()
		assert is_ascii(d, False)
		ini = Ini(d.decode('utf-8'))
		sections = ini.sections()
		sections_sz = len(sections)
		self._len = int(ini['count'], 10)
		self._d: List[BlocksetBlock] = []
		block_i = 0
		while block_i < sections_sz:
			section = sections[block_i]
			quad_i = 0
			tiles: List[int] = [None] * 8
			pals: List[int] = [None] * 8
			xflips: List[bool] = [None] * 8
			yflips: List[bool] = [None] * 8
			# first layer
			while quad_i < 4:
				prefix = 'l0' + BLOCK_FIELDS[quad_i] + '_'
				tiles[quad_i] = int(ini[section, prefix + 'tile'], 0)
				pals[quad_i] = int(ini[section, prefix + 'pal'], 0)
				xflip = ini[section, prefix + 'xf']
				yflip = ini[section, prefix + 'yf']
				xflips[quad_i] = True if Ini.truthy(xflip) else False
				# must be falsey, otherwise is is not boolean
				if not xflips[quad_i]: assert Ini.falsey(xflip)
				yflips[quad_i] = True if Ini.truthy(yflip) else False
				# must be falsey, otherwise is is not boolean
				if not yflips[quad_i]: assert Ini.falsey(yflip)
				quad_i += 1
			# second layer
			quad_i = 0
			while quad_i < 4:
				prefix = 'l1' + BLOCK_FIELDS[quad_i] + '_'
				tiles[4 + quad_i] = int(ini[section, prefix + 'tile'], 0)
				pals[4 + quad_i] = int(ini[section, prefix + 'pal'], 0)
				xflip = ini[section, prefix + 'xf']
				yflip = ini[section, prefix + 'yf']
				xflips[4 + quad_i] = True if Ini.truthy(xflip) else False
				# must be falsey, otherwise is is not boolean
				if not xflips[4 + quad_i]: assert Ini.falsey(xflip)
				yflips[4 + quad_i] = True if Ini.truthy(yflip) else False
				# must be falsey, otherwise is is not boolean
				if not yflips[4 + quad_i]: assert Ini.falsey(yflip)
				quad_i += 1
			block = BlocksetBlock(tiles, pals, xflips, yflips,
				int(ini[section, 'behav'], 0), ini[section, 'type'])
			self._d.append(block)
			block_i += 1
		zero_block = BlocksetBlock([0] * 8, [0] * 8, [False] * 8, [False] * 8,
			0, 'normal')
		while sections_sz < self._len:
			self._d.append(zero_block)
			sections_sz += 1
		if self._len > sections_sz:
			self._d = self._d[:sections_sz]
			self._len = sections_sz
	def __len__(self):
		return self._len
	def __getitem__(self, idx : int):
		assert type(idx) is int
		assert idx >= 0 and idx < self._len
		return self._d[idx]
	def __setitem__(self, idx : int, val : BlocksetBlock):
		assert type(idx) is int
		assert idx >= 0 and idx < self._len
		assert type(val) is BlocksetBlock
		block = BlocksetBlock(val.tiles, val.pals, val.xflips, val.yflips,
			val.behav, val.btype)
		self._d[idx] = block

class State:
	def __init__(self, win : SDL2.SDL_Window, fbuf : SDL2.SDL_Surface,
	mapdata : MapData, tileset1 : Tileset, tileset2 : Tileset,
	blockset1 : Blockset, blockset2 : Blockset,
	palette1 : AgbPalette, palette2 : AgbPalette):
		assert type(mapdata) is MapData
		assert type(tileset1) is Tileset
		assert type(tileset2) is Tileset
		assert type(blockset1) is Blockset
		assert type(blockset2) is Blockset
		assert type(palette1) is AgbPalette
		assert type(palette2) is AgbPalette
		self.win = win
		self.fbuf = fbuf
		self.mapdata = mapdata
		self.tilesets = [tileset1, tileset2]
		self.blocksets = [blockset1, blockset2]
		self.palettes = [palette1, palette2]
		self.map_xoffs = 0
		self.map_yoffs = 0
		self._need_update = True
		self.loadmap = False
		self.onsplash = True
	def refresh(self):
		self._need_update = True
	def ack(self):
		self._need_update = False
	def pending(self):
		return self._need_update

def render_mapview(state : State, move_overlay : bool = False):
	r: SDL2.SDL_Surface = SDL2.SDL_CreateRGBSurfaceWithFormat(0,
		MAPVIEW_W, MAPVIEW_H, 32, SDL2.SDL_PIXELFORMAT_RGBA8888)
	SDL2.SDL_SetSurfaceBlendMode(r, SDL2.SDL_BLENDMODE_BLEND)
	view = SDL2Ext.PixelView(r.contents)
	# all these denominated in blocks
	x_lim = state.map_xoffs + (MAPVIEW_W >> 4)
	y_lim = state.map_yoffs + (MAPVIEW_H >> 4)
	# map data y, in blocks
	y = state.map_yoffs
	# view y, in blocks
	r_y = 0
	while y < y_lim:
		if y >= state.mapdata._h:
			y += 1
			r_y += 1
			continue
		# map data x, in blocks
		x = state.map_xoffs
		# view x, in blocks
		r_x = 0
		while x < x_lim:
			if x >= state.mapdata._w:
				x += 1
				r_x += 1
				continue
			block = state.mapdata[x, y]
			bset_i = 0 if block.block < len(state.blocksets[0]) else 1
			if bset_i == 1:
				block.block -= len(state.blocksets[0])
			# copy over pixels of each tile while colouring them
			a = 0
			while a < 8:
				xpx_out = (r_x << 4) + (8 if (a & 1) else 0)
				ypx_out = (r_y << 4) + (8 if ((a >> 1) & 1) else 0)
				alpha = True if a >= 4 else False
				tilenum = state.blocksets[bset_i][block.block].tiles[a]
				tset_i = 0 if tilenum < len(state.tilesets[0]) else 1
				pels = state.tilesets[tset_i][tilenum]
				i = 0
				while i < 64:
					indexed = int(pels[i])
					col = 0
					if not alpha or indexed > 0:
						col = state.palettes[bset_i][indexed].argb8888()
					# << 4 is * 16
					view[ypx_out + (i // 8)][xpx_out + (i % 8)] = col
					i += 1
				a += 1
			x += 1
			r_x += 1
		y += 1
		r_y += 1
	return r

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
		elif e.type == SDL2.SDL_KEYUP and not state.onsplash:
			sym = e.key.keysym.sym
		elif e.type == SDL2.SDL_MOUSEBUTTONUP:
			if state.onsplash:
				imag = PILImage.open(OS.path.join('etc', 'working.png'))
				surf = SDL2.SDL_CreateRGBSurfaceFrom(
					pil2sdl(list(imag.getdata())), FRAME_W, FRAME_H, 32,
					4 * FRAME_W, MASK_R, MASK_G, MASK_B, MASK_A)
				imag.close()
				SDL2.SDL_BlitSurface(surf, FRAME_RECT,
					state.fbuf, FRAME_RECT)
				state.refresh()
				state.onsplash = False
				state.loadmap = True
		if state.loadmap:
			surf = render_mapview(state)
			SDL2.SDL_BlitSurface(surf, MAPVIEW_RECT, state.fbuf, FRAME_RECT)
			state.refresh()
			state.loadmap = False
	if state.pending():
		SDL2.SDL_BlitSurface(state.fbuf, None,
			SDL2.SDL_GetWindowSurface(state.win), None)
		SDL2.SDL_UpdateWindowSurface(state.win)
		state.ack()
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
	f = open(ini_fpath, 'r')
	ini = Ini(f.read())
	f.close()
	f = open(owb_fpath, 'r')
	owbtext = f.read()
	f.close()
	f = open(owm_fpath, 'r')
	owmtext = f.read()
	f.close()
	mdata = MapData(owbtext, owmtext,
		int(ini['w'], 0), int(ini['h'], 0))
	basedir = OS.path.dirname(ini_fpath)
	tdir = OS.path.join(basedir, 'tileset')
	bdir = OS.path.join(basedir, 'blockset')
	nprima = ini['prima']
	tprima = Tileset(OS.path.join(tdir, nprima + '.4tn.il.png'))
	pprima = AgbPalette(OS.path.join(tdir, nprima + '.jasc'))
	bprima = Blockset(OS.path.join(bdir, nprima + '.ini'))
	nsecunda = ini['secunda']
	tsecunda = Tileset(OS.path.join(tdir, nsecunda + '.4tn.il.png'))
	psecunda = AgbPalette(OS.path.join(tdir, nsecunda + '.jasc'))
	bsecunda = Blockset(OS.path.join(bdir, nsecunda + '.ini'))
	state = State(win, fbuf, mdata, tprima, tsecunda, bprima, bsecunda,
		pprima, psecunda)
	imag = PILImage.open(OS.path.join('etc', 'startup.png'))
	surf = SDL2.SDL_CreateRGBSurfaceFrom(pil2sdl(list(imag.getdata())),
		FRAME_W, FRAME_H, 32, 4 * FRAME_W, MASK_R, MASK_G, MASK_B, MASK_A)
	imag.close()
	SDL2.SDL_BlitSurface(surf, FRAME_RECT, fbuf, FRAME_RECT)
	state.refresh()
	while mainloop(state) == False: continue
	SDL2.SDL_DestroyWindow(win)
	SDL2.SDL_Quit()
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
