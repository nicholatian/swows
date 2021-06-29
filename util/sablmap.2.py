#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

from typing import List, Literal, Tuple

from PIL import Image as PILImage

from ctypes import byref as Ref
import os as OS
import re as RegExp
import sdl2 as SDL2
import ini as INI
import jascpal as JASC
import chkascii as CheckASCII

MAPVIEW_W = 640
MAPVIEW_H = 400

BLOCVIEW_W = 256
BLOCVIEW_H = 400

FRAME_W = 960
FRAME_H = 416

FBUF_RECT = SDL2.SDL_Rect(0, 0, FRAME_W, FRAME_H)

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

def chunks(l : List, n : int):
	n = max(1, n)
	ret: List[List[List[3]]] = [[]]
	l_sz = len(l)
	i = 0
	ret_i = 0
	long_i = 0
	while long_i < l_sz:
		ret[ret_i].append(l[long_i])
		i += 1
		long_i += 1
		if i >= 16:
			a: List[List[3]] = []
			ret.append(a)
			i = 0
			ret_i += 1
	return ret

class INIBool:
	def __init__(self, input : str):
		assert(type(input) is str)
		if input == 'true' or input == 'True' or input == 'TRUE' or \
		input == 'y' or input == 'Y' or input == 'yes' or input == 'Yes' or \
		input == 'YES' or input == 'on' or input == 'On' or input == 'ON':
			self.value = True
		elif input == 'false' or input == 'False' or input == 'FALSE' or \
		input == 'n' or input == 'N' or input == 'no' or input == 'No' or \
		input == 'NO' or input == 'off' or input == 'Off' or input == 'OFF':
			self.value = False
		else:
			n = int(input, 0)
			if n == 0:
				self.value = False
			elif n == 1:
				self.value = True
			else: raise Exception(
				'INI value \u2018%s\u2019 is not boolean' % input)

class PixelRGBA8:
	def __init__(self, r : int, g : int, b : int, a : int):
		assert(r >= 0 and r <= 255)
		assert(g >= 0 and g <= 255)
		assert(b >= 0 and b <= 255)
		assert(a >= 0 and a <= 255)
		self.data = (r << 24) | (g << 16) | (b << 8) | a

class PixelIdx4:
	def __init__(self, i : int):
		assert(i >= 0 and i <= 15)
		self.data = i

class PixelIdx8:
	def __init__(self, i : int):
		assert(i >= 0 and i <= 255)
		self.data = i

class Tile:
	def __init__(self, pixels : List[PixelIdx4]):
		# 32 bytes = 8 wide * 8 tall * 4 bits/pixel
		assert(len(pixels) == 64)
		assert(type(pixels[0]) is PixelIdx4)
		self.pixels = pixels

class Palette4:
	def __init__(self, cols : List[PixelRGBA8]):
		assert(type(cols) is list)
		cols_sz = len(cols)
		assert(cols_sz <= 16)
		self.data: List[PixelRGBA8] = cols
		while cols_sz < 16:
			self.data.append(PixelRGBA8(0, 0, 0, 255))
			cols_sz += 1
		assert(type(cols[0]) is PixelRGBA8)
		self.len = cols_sz

class Palette8:
	def __init__(self, cols : List[PixelRGBA8]):
		assert(type(cols) is list)
		cols_sz = len(cols)
		assert(cols_sz <= 256)
		self.data: List[PixelRGBA8] = cols
		while cols_sz < 256:
			self.data.append(PixelRGBA8(0, 0, 0, 255))
			cols_sz += 1
		assert(type(cols[0]) is PixelRGBA8)
		self.len = cols_sz

class BlockTile:
	def __init__(self, tile : int, pal : int, xflip : bool, yflip : bool):
		assert(tile <= 0x3FF)
		assert(pal <= 0xF)
		self.data = tile | (pal << 12) | ((1 << 10) if xflip else 0) | \
			((1 << 11) if yflip else 0)
	def get_tile(self):
		return self.data & 0x3FF
	def get_pal(self):
		return (self.data >> 12) & 0xF
	def get_xflip(self):
		return (self.data >> 10) & 1
	def get_yflip(self):
		return (self.data >> 11) & 1

class Block:
	def __init__(self, behav : int, btype : str, tiles : List[BlockTile],
	tlt_tiles : List[BlockTile]):
		assert(type(behav) is int)
		assert(type(btype) is str)
		assert(type(tiles) is list)
		assert(type(tlt_tiles) is list)
		assert(behav >= 0 and behav <= 0xFF)
		assert(btype == 'normal' or btype == 'covered' or btype == 'split')
		self.behav = behav
		self.btype = btype
		assert(len(tiles) == 8)
		self.tiles: List[BlockTile] = tiles
		tlt_tiles_sz = len(tlt_tiles)
		if tlt_tiles_sz > 0:
			assert(tlt_tiles_sz == 4)
			self.tlt_tiles: List[BlockTile] = tlt_tiles
		else: self.tlt_tiles = None

class Blockset:
	def __init__(self, ini_fpath : str, tset_fpath : str, pal_fpath : str,
	silent : bool):
		assert(type(ini_fpath) is str)
		assert(type(tset_fpath) is str)
		assert(type(pal_fpath) is str)
		assert(type(silent) is bool)
		# parse the blockset.ini
		assert(not CheckASCII.is_invalid(ini_fpath, False, silent))
		f = open(ini_fpath, 'r')
		t = f.read()
		f.close()
		ini = INI.parse(t)
		count = int(ini['']['count'], 0)
		# pre-fill the block list to check bounds and duplicates
		blocks: List[Block] = [None] * count
		for s in ini:
			if s == '':
				# ignore the global section
				continue
			n = int(s, 0)
			# no out-of-bounds sections
			assert(n >= 0 and n < count)
			# no section collisions
			assert(blocks[n] == None)
			behav = int(ini[s]['behav'], 0)
			btype = ini[s]['type']
			btiles = []
			tlt_btiles = []
			btiles.append(BlockTile(
				int(ini[s]['l0tl_tile'], 0),
				int(ini[s]['l0tl_pal'], 0),
				INIBool(ini[s]['l0tl_xf']).value,
				INIBool(ini[s]['l0tl_yf']).value))
			btiles.append(BlockTile(
				int(ini[s]['l0tr_tile'], 0),
				int(ini[s]['l0tr_pal'], 0),
				INIBool(ini[s]['l0tr_xf']).value,
				INIBool(ini[s]['l0tr_yf']).value))
			btiles.append(BlockTile(
				int(ini[s]['l0bl_tile'], 0),
				int(ini[s]['l0bl_pal'], 0),
				INIBool(ini[s]['l0bl_xf']).value,
				INIBool(ini[s]['l0bl_yf']).value))
			btiles.append(BlockTile(
				int(ini[s]['l0br_tile'], 0),
				int(ini[s]['l0br_pal'], 0),
				INIBool(ini[s]['l0br_xf']).value,
				INIBool(ini[s]['l0br_yf']).value))
			btiles.append(BlockTile(
				int(ini[s]['l1tl_tile'], 0),
				int(ini[s]['l1tl_pal'], 0),
				INIBool(ini[s]['l1tl_xf']).value,
				INIBool(ini[s]['l1tl_yf']).value))
			btiles.append(BlockTile(
				int(ini[s]['l1tr_tile'], 0),
				int(ini[s]['l1tr_pal'], 0),
				INIBool(ini[s]['l1tr_xf']).value,
				INIBool(ini[s]['l1tr_yf']).value))
			btiles.append(BlockTile(
				int(ini[s]['l1bl_tile'], 0),
				int(ini[s]['l1bl_pal'], 0),
				INIBool(ini[s]['l1bl_xf']).value,
				INIBool(ini[s]['l1bl_yf']).value))
			btiles.append(BlockTile(
				int(ini[s]['l1br_tile'], 0),
				int(ini[s]['l1br_pal'], 0),
				INIBool(ini[s]['l1br_xf']).value,
				INIBool(ini[s]['l1br_yf']).value))
			if 'l2tl_tile' in ini[s]:
				tlt_btiles.append(BlockTile(
					int(ini[s]['l2tl_tile'], 0),
					int(ini[s]['l2tl_pal'], 0),
					INIBool(ini[s]['l2tl_xf']).value,
					INIBool(ini[s]['l2tl_yf']).value))
				tlt_btiles.append(BlockTile(
					int(ini[s]['l2tr_tile'], 0),
					int(ini[s]['l2tr_pal'], 0),
					INIBool(ini[s]['l2tr_xf']).value,
					INIBool(ini[s]['l2tr_yf']).value))
				tlt_btiles.append(BlockTile(
					int(ini[s]['l2bl_tile'], 0),
					int(ini[s]['l2bl_pal'], 0),
					INIBool(ini[s]['l2bl_xf']).value,
					INIBool(ini[s]['l2bl_yf']).value))
				tlt_btiles.append(BlockTile(
					int(ini[s]['l2br_tile'], 0),
					int(ini[s]['l2br_pal'], 0),
					INIBool(ini[s]['l2br_xf']).value,
					INIBool(ini[s]['l2br_yf']).value))
			blocks[n] = Block(behav, btype, btiles, tlt_btiles)
		i = 0
		while i < count:
			if blocks[i] == None:
				blocks[i] = Block(0, 'normal',
					[BlockTile(0, 0, False, False),
					BlockTile(0, 0, False, False),
					BlockTile(0, 0, False, False),
					BlockTile(0, 0, False, False),
					BlockTile(0, 0, False, False),
					BlockTile(0, 0, False, False),
					BlockTile(0, 0, False, False),
					BlockTile(0, 0, False, False)], [])
			i += 1
		self.blocks = blocks
		# load the tileset.png
		tmp = PILImage.open(tset_fpath)
		# convert to 8-bit grayscale
		tset = tmp.convert('L')
		#tset.show()
		tmp.close()
		tiles: List[Tile] = []
		tiles_w = tset.size[0] // 8
		tiles_h = tset.size[1] // 8
		i = 0
		while i < tiles_h:
			j = 0
			while j < tiles_w:
				img = tset.crop((j << 3, i << 3, (j << 3) + 8, (i << 3) + 8))
				pels: List[PixelIdx4] = []
				img_sz = 64
				k = 0
				while k < img_sz:
					pels.append(PixelIdx4(img.getpixel((k & 7, k >> 3)) >> 4))
					k += 1
				tiles.append(Tile(pels))
				j += 1
			i += 1
		self.tiles = tiles
		tset.close()
		# load the JASC palettes
		pals = chunks(JASC.from_file(pal_fpath, silent), 16)
		self.pals: List[Palette4] = [None] * 16
		i = 0
		while i < 16:
			cols: List[PixelRGBA8] = [None] * 16
			j = 0
			while j < 16:
				cols[j] = PixelRGBA8(pals[i][j][0], pals[i][j][1],
					pals[i][j][2], 255)
				j += 1
			self.pals[i] = Palette4(cols)
			i += 1
		self.count = count

wspace_expr = RegExp.compile('[ \t\v\f\r]+')

class MapData:
	def __init__(self, owbtext : str, owmtext : str, w : int, h : int):
		assert(type(w) is int)
		assert(type(h) is int)
		assert(w >= 0 and w <= 65535)
		assert(h >= 0 and h <= 65535)
		assert(type(owbtext) is str)
		assert(type(owmtext) is str)
		owbtext_sz = len(owbtext)
		owmtext_sz = len(owmtext)
		assert(CheckASCII.bad_ascii(owbtext.encode('utf-8'),
			owbtext_sz, False) == owbtext_sz)
		assert(CheckASCII.bad_ascii(owmtext.encode('utf-8'),
			owmtext_sz, False) == owmtext_sz)
		lines = owbtext.splitlines()
		lines_sz = len(lines)
		started = False
		rows: List[List[int]] = []
		blocks: List[int] = []
		row_i = 0
		i = 0
		while i < lines_sz:
			line = lines[i].lstrip(' \t\v\f\r').rstrip(' \t\v\f\r')
			if line == '':
				if started:
					assert(len(blocks) == w)
					rows.append(blocks)
					blocks = []
					row_i += 1
				i += 1
				continue
			line = wspace_expr.sub(line, ' ')
			nums = line.split(' ')
			nums_sz = len(nums)
			started = True
			j = 0
			while j < nums_sz:
				n = int(nums[j], 16)
				assert(n >= 0 and n <= 0x3FF)
				blocks.append(n)
				j += 1
			i += 1
		blocks_sz = len(blocks)
		if blocks_sz > 0:
			assert(blocks_sz == w)
			rows.append(blocks)
			blocks = []
		assert(len(rows) == h)
		block_tiles = rows
		lines = owmtext.splitlines()
		lines_sz = len(lines)
		started = False
		rows: List[List[int]] = []
		blocks: List[int] = []
		row_i = 0
		i = 0
		while i < lines_sz:
			line = lines[i].lstrip(' \t\v\f\r').rstrip(' \t\v\f\r')
			if line == '':
				if started:
					assert(len(blocks) == w)
					rows.append(blocks)
					blocks = []
					row_i += 1
				i += 1
				continue
			line = wspace_expr.sub(line, ' ')
			nums = line.split(' ')
			nums_sz = len(nums)
			started = True
			j = 0
			while j < nums_sz:
				if nums[j] == '':
					j += 1
					continue
				n = int(nums[j], 16)
				assert(n >= 0 and n < 0x3F)
				blocks.append(n)
				j += 1
			i += 1
		blocks_sz = len(blocks)
		if blocks_sz > 0:
			assert(blocks_sz == w)
			rows.append(blocks)
			blocks = []
		assert(len(rows) == h)
		i = 0
		while i < h:
			j = 0
			while j < w:
				block_tiles[i][j] |= (rows[i][j] << 10)
				j += 1
			i += 1
		self.blocks = block_tiles

class MapProperties:
	def __init__(self, bankid : int, mapid : int, bgm : int,
	flash : bool, biking : bool, running : bool, rope : bool, showname : bool,
	weather : int, scene : int, maptype : int):
		assert(type(bankid) is int)
		assert(type(mapid) is int)
		assert(type(bgm) is int)
		assert(type(flash) is bool)
		assert(type(biking) is bool)
		assert(type(running) is bool)
		assert(type(rope) is bool)
		assert(type(showname) is bool)
		assert(type(weather) is int)
		assert(type(scene) is int)
		assert(type(maptype) is int)
		assert(bankid <= 255)
		assert(mapid <= 255)
		assert(bgm <= 65535)
		assert(weather <= 15)
		assert(scene <= 15)
		assert(maptype <= 15)
		self.bankid = bankid
		self.mapid = mapid
		self.bgm = bgm
		self.flash = flash
		self.biking = biking
		self.running = running
		self.rope = rope
		self.showname = showname
		self.weather = weather
		self.scene = scene
		self.maptype = maptype

class MapConnection:
	def __init__(self, direc : Literal['up', 'down', 'left', 'right'],
	bankid : int, mapid : int, offset : int = 0):
		assert(type(direc) is str)
		assert(direc == 'up' or direc == 'down' or direc == 'left'
		or direc == 'right')
		assert(type(bankid) is int)
		assert(type(mapid) is int)
		assert(type(offset) is int)
		assert(bankid <= 255)
		assert(mapid <= 255)
		self.direc = direc
		self.bankid = bankid
		self.mapid = mapid
		self.offset = offset

class ObjPerson:
	def __init__(self, x : int, y : int, z : int, gfxid : int,
	flag : int, movtype : int, mov_xrange : int, mov_yrange : int,
	los : int, script : int):
		assert(type(x) is int)
		assert(type(y) is int)
		assert(type(z) is int)
		assert(type(gfxid) is int)
		assert(type(flag) is int)
		assert(type(movtype) is int)
		assert(type(mov_xrange) is int)
		assert(type(mov_yrange) is int)
		assert(type(los) is int)
		assert(type(script) is int)
		assert(x >= 0 and x <= 65535)
		assert(y >= 0 and y <= 65535)
		assert(z >= 0 and z <= 15)
		assert(gfxid >= 0 and gfxid <= 65535)
		assert(flag >= 0 and flag <= 65535)
		assert(movtype >= 0 and movtype <= 255)
		assert(los >= 0 and los <= 255)
		assert(script >= 0 and script <= 0x1FFFFFF)
		self.x = x
		self.y = y
		self.z = z
		self.gfxid = gfxid
		self.flag = flag
		self.movtype = movtype
		self.mov_xrange = mov_xrange
		self.mov_yrange = mov_yrange
		self.los = los
		self.script = script

class ObjWarp:
	def __init__(self, x : int, y : int, z : int,
	bankid : int, mapid : int, warpid : int):
		assert(type(x) is int)
		assert(type(y) is int)
		assert(type(z) is int)
		assert(type(bankid) is int)
		assert(type(mapid) is int)
		assert(type(warpid) is int)
		assert(x >= 0 and x <= 65535)
		assert(y >= 0 and y <= 65535)
		assert(z >= 0 and z <= 15)
		assert(bankid >= 0 and bankid <= 255)
		assert(mapid >= 0 and mapid <= 255)
		assert(warpid >= 0 and warpid <= 255)
		self.x = x
		self.y = y
		self.z = z
		self.bankid = bankid
		self.mapid = mapid
		self.warpid = warpid

class ObjSign:
	def __init__(self, x : int, y : int, z : int, script : int):
		assert(type(x) is int)
		assert(type(y) is int)
		assert(type(z) is int)
		assert(type(script) is int)
		assert(x >= 0 and x <= 65535)
		assert(y >= 0 and y <= 65535)
		assert(z >= 0 and z <= 15)
		assert(script >= 0 and script <= 0x1FFFFFF)
		self.x = x
		self.y = y
		self.z = z
		self.script = script

class ObjHitem:
	def __init__(self, x : int, y : int, z : int, flag : int, item : int):
		assert(type(x) is int)
		assert(type(y) is int)
		assert(type(z) is int)
		assert(type(flag) is int)
		assert(type(item) is int)
		assert(x >= 0 and x <= 65535)
		assert(y >= 0 and y <= 65535)
		assert(z >= 0 and z <= 15)
		assert(flag >= 0 and flag <= 65535)
		assert(item >= 0 and item <= 65535)
		self.x = x
		self.y = y
		self.z = z
		self.flag = flag
		self.item = item

class Program:
	def __init__(self, win : SDL2.SDL_Window, fbuf : SDL2.SDL_Surface):
		self.win = win
		self.fbuf = fbuf

class State:
	def __init__(self, program : Program, props : MapProperties,
	mapdata : MapData, prima : Blockset, secunda : Blockset):
		assert(type(program) is Program)
		assert(type(props) is MapProperties)
		assert(type(mapdata) is MapData)
		assert(type(prima) is Blockset)
		assert(type(secunda) is Blockset)
		self.program = program
		self.props = props
		self.mapdata = mapdata
		self.prima = prima
		self.secunda = secunda
		self._need_update = True
		self.onsplash = True
		self.loadmap = False
	def req_update(self):
		self._need_update = True
	def ack_update(self):
		self._need_update = False
	def need_update(self):
		return self._need_update

def print2(x):
	from sys import stderr
	print(x, file=stderr)

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

def tile2surf(tile : Tile, alpha : bool, pal : List[PixelRGBA8]):
	raw = bytearray(256)
	i = 0
	while i < 64:
		idx = tile.pixels[i].data
		raw[(i << 2) + 0] = pal[idx].data & 0xFF
		raw[(i << 2) + 1] = (pal[idx].data >> 8) & 0xFF
		raw[(i << 2) + 2] = (pal[idx].data >> 16) & 0xFF
		if alpha and idx == 0:
			raw[(i << 2) + 3] = 0
		else:
			raw[(i << 2) + 3] = 255
		i += 1
	surf = SDL2.SDL_CreateRGBSurfaceFrom(bytes(raw), 8, 8,
		32, 4 * 8, MASK_R, MASK_G, MASK_B, MASK_A)
	SDL2.SDL_SetSurfaceBlendMode(surf, SDL2.SDL_BLENDMODE_BLEND)
	return surf

def render_mapview(prima : Blockset, secunda : Blockset, mapdata : MapData,
xoffs : int, yoffs : int, mov_opacity: float, fbuf : SDL2.SDL_Surface):
	assert(type(prima) is Blockset)
	assert(type(secunda) is Blockset)
	assert(type(mapdata) is MapData)
	assert(type(xoffs) is int)
	assert(xoffs >= 0)
	assert(type(yoffs) is int)
	assert(yoffs >= 0)
	assert(type(mov_opacity) is float)
	assert(mov_opacity >= 0.0 and mov_opacity <= 1.0)
	mov_opacity = 0.0
	visiblocks: List[List[int]] = []
	for row in mapdata.blocks[yoffs:(MAPVIEW_H // 16) + yoffs]:
		visiblocks.append(row[xoffs:(MAPVIEW_W // 16) + xoffs])
	for y, row in enumerate(visiblocks):
		for x, block in enumerate(row):
			bblock = None
			tiles = None
			pals = None
			if block >= prima.count:
				# must be in secunda
				assert(block - prima.count < secunda.count)
				bblock = secunda.blocks[block - prima.count]
				tiles = secunda.tiles
				pals = secunda.pals
			else:
				bblock = prima.blocks[block]
				tiles = prima.tiles
				pals = prima.pals
			surfs: List = [None] * 8
			surfs[0] = tile2surf(tiles[bblock.tiles[0].get_tile()],
				False, pals[bblock.tiles[0].get_pal()].data)
			surfs[1] = tile2surf(tiles[bblock.tiles[1].get_tile()],
				False, pals[bblock.tiles[1].get_pal()].data)
			surfs[2] = tile2surf(tiles[bblock.tiles[2].get_tile()],
				False, pals[bblock.tiles[2].get_pal()].data)
			surfs[3] = tile2surf(tiles[bblock.tiles[3].get_tile()],
				False, pals[bblock.tiles[3].get_pal()].data)
			surfs[4] = tile2surf(tiles[bblock.tiles[4].get_tile()],
				True, pals[bblock.tiles[4].get_pal()].data)
			surfs[5] = tile2surf(tiles[bblock.tiles[5].get_tile()],
				True, pals[bblock.tiles[5].get_pal()].data)
			surfs[6] = tile2surf(tiles[bblock.tiles[6].get_tile()],
				True, pals[bblock.tiles[6].get_pal()].data)
			surfs[7] = tile2surf(tiles[bblock.tiles[7].get_tile()],
				True, pals[bblock.tiles[7].get_pal()].data)
			srcrect = SDL2.SDL_Rect(0, 0, 8, 8)
			dst0rect = SDL2.SDL_Rect(x << 4, y << 4, 8, 8)
			dst1rect = SDL2.SDL_Rect((x << 4) + 8, y << 4, 8, 8)
			dst2rect = SDL2.SDL_Rect(x << 4, (y << 4) + 8, 8, 8)
			dst3rect = SDL2.SDL_Rect((x << 4) + 8, (y << 4) + 8, 8, 8)
			SDL2.SDL_BlitSurface(surfs[0], srcrect, fbuf, dst0rect)
			SDL2.SDL_BlitSurface(surfs[1], srcrect, fbuf, dst1rect)
			SDL2.SDL_BlitSurface(surfs[2], srcrect, fbuf, dst2rect)
			SDL2.SDL_BlitSurface(surfs[3], srcrect, fbuf, dst3rect)
			SDL2.SDL_BlitSurface(surfs[4], srcrect, fbuf, dst0rect)
			SDL2.SDL_BlitSurface(surfs[5], srcrect, fbuf, dst1rect)
			SDL2.SDL_BlitSurface(surfs[6], srcrect, fbuf, dst2rect)
			SDL2.SDL_BlitSurface(surfs[7], srcrect, fbuf, dst3rect)

def mainloop(state : State):
	e = SDL2.SDL_Event()
	while SDL2.SDL_PollEvent(Ref(e)) != 0:
		if e.type == SDL2.SDL_QUIT:
			return True
		elif e.type == SDL2.SDL_MOUSEBUTTONUP:
			if state.onsplash:
				imag = PILImage.open(OS.path.join('etc', 'working.png'))
				surf = SDL2.SDL_CreateRGBSurfaceFrom(
					pil2sdl(list(imag.getdata())), FRAME_W, FRAME_H, 32,
					4 * FRAME_W, MASK_R, MASK_G, MASK_B, MASK_A)
				imag.close()
				SDL2.SDL_BlitSurface(surf, FBUF_RECT,
					state.program.fbuf, FBUF_RECT)
				state.req_update()
				state.onsplash = False
				state.loadmap = True
		if state.loadmap:
			render_mapview(state.prima, state.secunda, state.mapdata, 0, 0, 0.0,
				state.program.fbuf)
			state.req_update()
			state.loadmap = False
	if state.need_update():
		print('Updating...')
		SDL2.SDL_BlitSurface(state.program.fbuf, None,
			SDL2.SDL_GetWindowSurface(state.program.win), None)
		SDL2.SDL_UpdateWindowSurface(state.program.win)
		state.ack_update()
	SDL2.SDL_ShowWindow(state.program.win)
	SDL2.SDL_Delay(16)
	return False

def main(args : List[str]):
	assert(type(args) is list)
	argc = len(args)
	assert(argc >= 1)
	assert(type(args[0]) is str)
	silent = '-s' in args or '--silent' in args
	if argc == 1 or '-h' in args or '--help' in args:
		if not silent:
			print2(HELP_TEXT)
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
			elif not silent:
				print2('WARNING: Unknown flag \u2018%s\u2019' % args[i])
		elif ini_fpath == None:
			ini_fpath = args[i]
		elif owb_fpath == None:
			owb_fpath = args[i]
		elif owm_fpath == None:
			owm_fpath = args[i]
		elif not silent:
			print2('WARNING: Excess parameter \u2018%s\u2019' % args[i])
		i += 1
	if ini_fpath == None or owb_fpath == None or owm_fpath == None:
		if not silent: print2('Insufficient parameters. Exiting...')
		return 127
	SDL2.SDL_Init( SDL2.SDL_INIT_VIDEO )
	win: SDL2.SDL_Window = SDL2.SDL_CreateWindow(
		'SABLMAP alpha'.encode('utf-8'), SDL2.SDL_WINDOWPOS_UNDEFINED,
		SDL2.SDL_WINDOWPOS_UNDEFINED, FRAME_W, FRAME_H, 0)
	fbuf: SDL2.SDL_Surface = SDL2.SDL_CreateRGBSurface(0, FRAME_W, FRAME_H,
		32, MASK_R, MASK_G, MASK_B, MASK_A)
	SDL2.SDL_SetSurfaceBlendMode(fbuf, SDL2.SDL_BLENDMODE_NONE)
	program = Program(win, fbuf)
	if CheckASCII.is_invalid(ini_fpath, False, silent) or \
	CheckASCII.is_invalid(owb_fpath, False, silent) or \
	CheckASCII.is_invalid(owm_fpath, False, silent):
		return 127
	f = open(ini_fpath, 'r')
	ini = INI.parse(f.read())
	f.close()
	f = open(owb_fpath, 'r')
	owbtext = f.read()
	f.close()
	f = open(owm_fpath, 'r')
	owmtext = f.read()
	f.close()
	map_w = int(ini['']['w'], 0)
	map_h = int(ini['']['h'], 0)
	mapdata = MapData(owbtext, owmtext, map_w, map_h)
	props = MapProperties(
		int(ini['']['bankid'], 0),
		int(ini['']['mapid'], 0),
		int(ini['']['bgm'], 0),
		INIBool(ini['']['flash']).value,
		INIBool(ini['']['biking']).value,
		INIBool(ini['']['running']).value,
		INIBool(ini['']['rope']).value,
		INIBool(ini['']['showname']).value,
		int(ini['']['weather'], 0),
		int(ini['']['scene'], 0),
		int(ini['']['maptype'], 0))
	# get base directory of map INIs
	# we assume there are two subfolders named "tileset" and "blockset"
	# with the same parent folder as the map INI file
	# we then get by name a tileset with mangledeggs suffix and a
	# JASC palette file
	basedir = OS.path.dirname(ini_fpath)
	tdir = OS.path.join(basedir, 'tileset')
	bdir = OS.path.join(basedir, 'blockset')
	prima = Blockset(OS.path.join(bdir, ini['']['prima'] + '.ini'),
		OS.path.join(tdir, ini['']['prima'] + '.4tn.il.png'),
		OS.path.join(tdir, ini['']['prima'] + '.jasc'), silent)
	secunda = Blockset(OS.path.join(bdir, ini['']['secunda'] + '.ini'),
		OS.path.join(tdir, ini['']['secunda'] + '.4tn.il.png'),
		OS.path.join(tdir, ini['']['secunda'] + '.jasc'), silent)
	state = State(program, props, mapdata, prima, secunda)
	imag = PILImage.open(OS.path.join('etc', 'startup.png'))
	surf = SDL2.SDL_CreateRGBSurfaceFrom(pil2sdl(list(imag.getdata())),
		FRAME_W, FRAME_H, 32, 4 * FRAME_W, MASK_R, MASK_G, MASK_B, MASK_A)
	imag.close()
	SDL2.SDL_BlitSurface(surf, FBUF_RECT, program.fbuf, FBUF_RECT)
	state.req_update()
	while mainloop(state) == False: continue
	SDL2.SDL_DestroyWindow(program.win)
	SDL2.SDL_Quit()
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
