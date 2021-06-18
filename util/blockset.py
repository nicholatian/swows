#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

from typing import List

import sdl2.ext

def print2(x):
	from sys import stderr
	print(x, file=stderr)

def chunks(l, n):
	n = max(1, n)
	ret = [[]]
	l_sz = len(l)
	i = 0
	ret_i = 0
	long_i = 0
	while long_i < l_sz:
		ret[ret_i].append(l[long_i])
		i += 1
		long_i += 1
		if i >= 16:
			ret.append([])
			i = 0
			ret_i += 1
	return ret

def name2fpath(name : str):
	from os import path
	return path.join('data', 'map', 'tileset', name)

def load(fpath : str, silent : bool):
	import chkascii
	if chkascii.is_invalid(fpath, False, False):
		return None
	import ini
	f = open(fpath, 'rb')
	cfg = ini.parse(f.read().decode('utf-8'))
	f.close()
	ret = {}
	fac = sdl2.ext.SpriteFactory(sdl2.ext.SOFTWARE)
	ret['tiles'] = fac.from_image(name2fpath(cfg['']['tileset']) + \
		'.4tn.il.png')
	import jascpal
	fullpal = jascpal.from_file(name2fpath(cfg['']['tileset']) + '.jasc',
		silent)
	ret['palettes'] = chunks(fullpal, 16)
	ret['count'] = int(cfg['']['count'], 0)

def main(args : List[str]):
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
