#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

from typing import List

def print2(x):
	from sys import stderr
	print(x, file=stderr)

import re

wspc_expr = re.compile(r'[ \t\v\f\r]+')

def from_text(text : str, silent : bool):
	lines = text.splitlines()
	lines_sz = len(lines)
	if lines_sz < 4:
		if not silent: print2('Insufficient data in JASC-PAL!')
		return []
	if lines[0] != 'JASC-PAL':
		if not silent: print2('Bad magic bytes header')
		return []
	if lines[1] != '0100':
		if not silent: print2('WARNING: Unsupported version ' + lines[1])
	count = int(lines[2], 10)
	if lines_sz - 3 < count:
		if not silent: print2('Too few lines for %s colours' % lines[2])
	i = 3
	ret = []
	while i < lines_sz:
		line = lines[i].lstrip(' \t\v\f\r').rstrip(' \t\v\f\r')
		if line == '':
			# Nothing here, carry on
			i += 1
			continue
		# Normalise whitespace in lines
		line = wspc_expr.sub(' ', line)
		fields = line.split(' ')
		fields_sz = len(fields)
		if fields_sz < 3:
			if not silent:
				print2('Too few colours on line %s (need 3)' % int(i + 1))
			return []
		if fields_sz > 3:
			if not silent:
				print2('Too many colours on line %s (need 3)' % int(i + 1))
			return []
		r = int(fields[0], 10)
		g = int(fields[1], 10)
		b = int(fields[2], 10)
		if r < 0 or r > 255:
			if not silent:
				print2('Red channel out of bounds (was %s)' % fields[0])
			return []
		if g < 0 or g > 255:
			if not silent:
				print2('Green channel out of bounds (was %s)' % fields[1])
			return []
		if b < 0 or b > 255:
			if not silent:
				print2('Blue channel out of bounds (was %s)' % fields[2])
			return []
		ret.append([r, g, b])
		i += 1
	return ret

def from_file(fpath : str, silent : bool):
	f = open(fpath, 'rb')
	raw = f.read()
	raw_sz = len(raw)
	import chkascii
	ascii_i = chkascii.bad_ascii(raw, raw_sz, False)
	if ascii_i < raw_sz:
		if not silent:
			print2('Invalid octet at offset $%X: 0x%02X is not valid ASCII' %
				(ascii_i, raw[ascii_i]))
		return []
	text = raw.decode('utf-8')
	f.close()
	return from_text(text, silent)

HELP_TEXT = '''
JASC-PAL viewer
Copyright \u00A9 2021 Alexander Nicholi.
Released under BSD 0-Clause licence, a.k.a. the public domain.

Usage:-
	jascpal [flags] <pal file> [pal files ...]

If -s or --silent is provided, the program will not send anything to
stdout nor stderr. Otherwise, it will print status info updates as it
works to stderr. stdin and stdout are never used.
'''

def main(args : List[str]):
	argc = len(args)
	silent = '-s' in args or '--silent' in args
	if argc == 1 or '-h' in args or '--help' in args:
		if not silent: print2(HELP_TEXT)
		return 0
	i = 1
	files: List[str] = []
	while i < argc:
		if args[i].startswith('-'):
			if args[i] == '-s' or args[i] == '--silent':
				pass # handled above
			elif not silent:
				print2('WARNING: Unknown flag \u2018%s\u2019' % args[i])
		else:
			files.append(args[i])
		i += 1
	files_sz = len(files)
	i = 0
	while i < files_sz:
		print(from_file(files[i], silent))
		i += 1
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
