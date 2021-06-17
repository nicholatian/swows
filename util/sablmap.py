#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

import sdl2.ext

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

class State:
	def __init__(self, blocks, moves, width, length, silent, window):
		self.blocks = blocks
		self.moves = moves
		self.mapwidth = width
		self.maplength = length
		self.silent = silent
		self.window = window

def mainloop(state: State):
	state.window.show()
	events = sdl2.ext.get_events()
	for event in events:
		if event.type == sdl2.SDL_QUIT:
			return True
	state.window.refresh()
	return False

def gfxmain(blocks, moves, d, silent):
	w = sdl2.ext.Window('SABLMAP', (960, 416))
	state: State = State(blocks, moves, d[0], d[1], silent, w)
	while mainloop(state) == False:
		pass
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
