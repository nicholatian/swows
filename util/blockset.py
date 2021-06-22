#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

from typing import List, Literal

import sdl2
import sdl2.sdlimage as sdl2i

BLOCK_KEYS = [
	'behav',
	'type',
	'l0tl_tile',
	'l0tl_pal',
	'l0tl_xf',
	'l0tl_yf',
	'l0tr_tile',
	'l0tr_pal',
	'l0tr_xf',
	'l0tr_yf',
	'l0bl_tile',
	'l0bl_pal',
	'l0bl_xf',
	'l0bl_yf',
	'l0br_tile',
	'l0br_pal',
	'l0br_xf',
	'l0br_yf',
	'l1tl_tile',
	'l1tl_pal',
	'l1tl_xf',
	'l1tl_yf',
	'l1tr_tile',
	'l1tr_pal',
	'l1tr_xf',
	'l1tr_yf',
	'l1bl_tile',
	'l1bl_pal',
	'l1bl_xf',
	'l1bl_yf',
	'l1br_tile',
	'l1br_pal',
	'l1br_xf',
	'l1br_yf'
]

BLOCK_KEYS_TLT = [
	'l2tl_tile',
	'l2tl_pal',
	'l2tl_xf',
	'l2tl_yf',
	'l2tr_tile',
	'l2tr_pal',
	'l2tr_xf',
	'l2tr_yf',
	'l2bl_tile',
	'l2bl_pal',
	'l2bl_xf',
	'l2bl_yf',
	'l2br_tile',
	'l2br_pal',
	'l2br_xf',
	'l2br_yf'
]

def chunks(l : List[List[3]], n : int):
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

class BlockTile:
	def __init__(self, tile : int, pal : int, xflip : bool, yflip : bool):
		if tile not in range(0, 0xFFFF):
			raise Exception('BlockTile tile number out of range')
		if pal not in range(0, 15):
			raise Exception('BlockTile palette number out of range')
		self.tile = tile
		self.pal = pal
		self.xflip = xflip
		self.yflip = yflip

class Block:
	def __init__(self, behav : int,
	type : Literal['normal', 'covered', 'split'],
	tiles : List[BlockTile]):
		if behav not in range(0, 255):
			raise Exception('Block behaviour byte out of range')
		tiles_sz = len(tiles)
		if tiles_sz != 8 and tiles_sz != 12:
			raise Exception('Wrong number of BlockTiles (must be 8 or 12)')
		if type != 'normal' and type != 'covered' and type != 'split':
			raise Exception('Bad Block display type "%s"' % type)
		self.behav = behav
		self.type = type
		self.tiles = tiles

class Blockset:
	def __init__(self, tsimg_fpath : str, tspal_fpath : str,
	blockset_fpath : str, silent : bool):
		import chkascii
		# Do our own encoding verification
		if chkascii.is_invalid(blockset_fpath, False, False):
			return None
		import ini
		# Read in binary to bypass locales
		f = open(blockset_fpath, 'rb')
		cfg = ini.parse(f.read().decode('utf-8'))
		f.close()
		# We need this to make images for use in SABLMAP and GEMEATER
		self.tileset = sdl2i.IMG_Load(tsimg_fpath)
		import jascpal
		fullpal = jascpal.from_file(tspal_fpath, silent)
		# Split the 256-colour super-palette into 16 distinct ones
		self.palettes: List[List[List[3]]] = chunks(fullpal, 16)
		count = int(cfg['']['count'], 0)
		self.blocks: List[Block] = [None] * count
		for s in cfg:
			# Ignore the global section, as it is not a block
			if s == '':
				continue
			blockid = int(s, 0)
			if blockid > count:
				raise Exception('Block number 0x%03X out of range' % blockid)
			if self.blocks[blockid] != None:
				raise Exception('Duplicate blocks with ID 0x%03X' % blockid)
			# Ensure all required keys exist in the block's section
			for k in BLOCK_KEYS:
				if k not in cfg[s]:
					raise Exception('Required key "%s" not found in block 0x%04X' %
						(k, int(s)))
			# If any triple-layer properties exist, ensure they are ALL there
			tlt = False
			for k in BLOCK_KEYS_TLT:
				if k in cfg[s]:
					tlt = True
					break
			if tlt:
				for k in BLOCK_KEYS_TLT:
					if k not in cfg[s]:
						raise Exception('Some triple-layer keypairs present but ' +
							'some missing')
			tiles: List[BlockTile] = [None] * (12 if tlt else 8)
			tiles[0] = BlockTile(
				int(cfg[s]['l0tl_tile'], 0),
				int(cfg[s]['l0tl_pal'], 0),
				(False if cfg[s]['l0tl_xf'] == '0' else True),
				(False if cfg[s]['l0tl_yf'] == '0' else True))
			tiles[1] = BlockTile(
				int(cfg[s]['l0tr_tile'], 0),
				int(cfg[s]['l0tr_pal'], 0),
				(False if cfg[s]['l0tr_xf'] == '0' else True),
				(False if cfg[s]['l0tr_yf'] == '0' else True))
			tiles[2] = BlockTile(
				int(cfg[s]['l0bl_tile'], 0),
				int(cfg[s]['l0bl_pal'], 0),
				(False if cfg[s]['l0tl_xf'] == '0' else True),
				(False if cfg[s]['l0tl_yf'] == '0' else True))
			tiles[3] = BlockTile(
				int(cfg[s]['l0br_tile'], 0),
				int(cfg[s]['l0br_pal'], 0),
				(False if cfg[s]['l0br_xf'] == '0' else True),
				(False if cfg[s]['l0br_yf'] == '0' else True))
			tiles[4] = BlockTile(
				int(cfg[s]['l1tl_tile'], 0),
				int(cfg[s]['l1tl_pal'], 0),
				(False if cfg[s]['l1tl_xf'] == '0' else True),
				(False if cfg[s]['l1tl_yf'] == '0' else True))
			tiles[5] = BlockTile(
				int(cfg[s]['l1tr_tile'], 0),
				int(cfg[s]['l1tr_pal'], 0),
				(False if cfg[s]['l1tr_xf'] == '0' else True),
				(False if cfg[s]['l1tr_yf'] == '0' else True))
			tiles[6] = BlockTile(
				int(cfg[s]['l1bl_tile'], 0),
				int(cfg[s]['l1bl_pal'], 0),
				(False if cfg[s]['l1tl_xf'] == '0' else True),
				(False if cfg[s]['l1tl_yf'] == '0' else True))
			tiles[7] = BlockTile(
				int(cfg[s]['l1br_tile'], 0),
				int(cfg[s]['l1br_pal'], 0),
				(False if cfg[s]['l1br_xf'] == '0' else True),
				(False if cfg[s]['l1br_yf'] == '0' else True))
			if tlt:
				tiles[8] = BlockTile(
					int(cfg[s]['l2tl_tile'], 0),
					int(cfg[s]['l2tl_pal'], 0),
					(False if cfg[s]['l2tl_xf'] == '0' else True),
					(False if cfg[s]['l2tl_yf'] == '0' else True))
				tiles[9] = BlockTile(
					int(cfg[s]['l2tr_tile'], 0),
					int(cfg[s]['l2tr_pal'], 0),
					(False if cfg[s]['l2tr_xf'] == '0' else True),
					(False if cfg[s]['l2tr_yf'] == '0' else True))
				tiles[10] = BlockTile(
					int(cfg[s]['l2bl_tile'], 0),
					int(cfg[s]['l2bl_pal'], 0),
					(False if cfg[s]['l2tl_xf'] == '0' else True),
					(False if cfg[s]['l2tl_yf'] == '0' else True))
				tiles[11] = BlockTile(
					int(cfg[s]['l2br_tile'], 0),
					int(cfg[s]['l2br_pal'], 0),
					(False if cfg[s]['l2br_xf'] == '0' else True),
					(False if cfg[s]['l2br_yf'] == '0' else True))
			block = Block(int(cfg[s]['behav']), cfg[s]['type'], tiles)
			self.blocks[blockid] = block
		i = 0
		# Fill in the empty blocks with a "zero" Block
		while i < count:
			if self.blocks[i] == None:
				self.blocks[i] = Block(0, 'normal',
					BlockTile(0, 0, False, False) * 8)
			i += 1
	def get_tile(self, num : int, pal : int, transp : bool):
		ret: sdl2.SDL_Surface = sdl2.SDL_CreateRGBSurface(0, 8, 8, 32,
			0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000)
		tileset_w: int = self.tileset.size[0] // 8
		row = num // tileset_w
		col = num - (row * tileset_w)
		srcrect = (col * 8, row * 8, 8, 8)
		dstrect = (0, 0, 8, 8)
		sdl2.SDL_BlitSurface(self.tileset, srcrect, ret, dstrect)
		return ret

def main(args : List[str]):
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
