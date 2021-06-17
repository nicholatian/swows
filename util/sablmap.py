#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

import sdl2.ext
import sdl2

WIN_DIMENSIONS = (960, 416)

HELP_TEXT = '''
SABLMAP map editor
Copyright \u00A9 2021 Alexander Nicholi.
Released under BSD 0-Clause licence, a.k.a. the public domain.

Usage:-
	sablmap [flags] <map.ini> <map.owb> <map.owm>
	sablmap [flags] -d|--dimensions <w>x<l> <map.owb> <map.owm>

If -s or --silent is provided, the program will not send anything to
stdout nor stderr. Otherwise, it will print status info updates as it
works to stderr. stdin and stdout are never used.

If the map.ini is provided, the dimensions will be read from it and used to
construct the map. If it is not, the -d or --dimensions flag must be given,
the value of which must be of the form "<w>x<l>" where w is horizontal width
and l is vertical length.
'''

def print2(x):
	from sys import stderr
	print(x, file=stderr)

class BlockSprite:
	def __init__(self, fac):
		self.data = fac.create_software_sprite((16, 16))
		self.view = sdl2.ext.PixelView(self.data)

class Renderer(sdl2.ext.SoftwareSpriteRenderSystem):
	def __init__(self, window):
		super(Renderer, self).__init__(window)

	def render(self, sprite, x, y):
		super(Renderer, self).render(sprite, x, y)

class State:
	def __init__(self, blocks, moves, width, length, silent):
		self.blocks = blocks
		self.moves = moves
		self.mapwidth = width
		self.maplength = length
		self.silent = silent
		self.mapview_chg = True
		self.blockset_chg = True
		self.win = sdl2.ext.Window('SABLMAP', WIN_DIMENSIONS)
		self.ren = Renderer(self.win)
		self.fac = sdl2.ext.SpriteFactory(sdl2.ext.SOFTWARE)
		self.fbuf = self.fac.create_software_sprite(WIN_DIMENSIONS)
		self.fview = sdl2.ext.PixelView(self.fbuf)
		self.mapblocks = []
		self.blockset = []

	def render(self):
		# update the frame buffer with the coherent data
		if self.mapview_chg:
			#self.render_mapview()
			self.mapview_chg = False
		if self.blockset_chg:
			#self.render_blockset()
			self.blockset_chg = False

	def render_mapview(self):
		for i in range(25):
			for j in range(40):
				self.ren.render(self.mapblocks[i][j].data, i, j)

	def render_blockset(self):
		for i in range(25):
			for j in range(16):
				self.ren.render(self.blockset[i][j].data, i, j)

def mainloop(state: State):
	state.win.show()
	events = sdl2.ext.get_events()
	for event in events:
		if event.type == sdl2.SDL_QUIT:
			return True
	state.render()
	sdl2.SDL_Delay(10)
	return False

def gfxmain(blocks, moves, d, silent):
	sdl2.ext.init()
	state: State = State(blocks, moves, d[0], d[1], silent)
	while mainloop(state) == False:
		pass
	sdl2.ext.quit()
	return 0

def main(args):
	argc = len(args)
	silent = '-s' in args or '--silent' in args
	if argc == 1 or '-h' in args or '--help' in args:
		if not silent:
			print2(HELP_TEXT)
		return 127
	return gfxmain(0, 0, (30, 30), silent)

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
