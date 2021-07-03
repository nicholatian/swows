#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

from typing import List

HELP_TEXT = '''
Pret Map Data to OW{B,M} conversion script
Copyright \u00A9 2021 Alexander Nicholi.
Released under BSD 0-Clause licence, a.k.a. the public domain.

Usage:-
\tmapbin2ow b [flags] <input> [output]
\tmapbin2ow m [flags] <input> [output]

The first parameter dictates which kind of output is being made.
\u2018b\u2019 outputs block data, and \u2018m\u2019 outputs movement
data.

If -s or --silent is provided, the program will not send anything to
stderr. Otherwise, it will print status info updates as it works to
stderr. stdout is still written to if [output] is not given.

The program will write to [output], or stdout if it is omitted. If
<input> is \u2018-\u2019, stdin is read for text input.
'''

def print2(x):
	from sys import stderr
	print(x, file=stderr)

def convert(data : bytes, blockmode : bool, silent : bool):
	r: str = ''
	data_sz = len(data)
	line_i = 0
	if data_sz & 1 != 0:
		if not silent:
			print2('WARNING: map binary has odd number of bytes. Truncating...')
		data_sz -= 1
	i = 0
	while i < data_sz:
		tile = data[i] | (data[i + 1] << 8)
		d = tile & 0x3FF if blockmode else (tile >> 10) & 0x3F
		l = 4 if blockmode else 2
		s = hex(d)[2:].upper()
		while len(s) < l:
			s = '0' + s
		if line_i > 0:
			s = ' ' + s
			line_i += l + 1
		else: line_i += l
		# add newline before 72 chars
		if line_i + 5 >= 72:
			s += '\n'
			line_i = 0
		r += s
		i += 2
	if r[-1] != '\n':
		r += '\n'
	return r

def main(args):
	argc = len(args)
	silent = False
	i = 1
	infile = ''
	outfile = ''
	nomoreflags = False
	blockmode: bool
	while i < argc:
		if not nomoreflags and args[i] == '-' and infile == '':
			infile = '-'
		elif not nomoreflags and args[i].startswith('-'):
			if args[i] == '--':
				nomoreflags = True
			elif args[i] == '-s' or args[i] == '--silent':
				silent = True
			elif args[i] == '-h' or args[i] == '--help':
				if not silent: print2(HELP_TEXT)
				return 0
			elif not silent:
				print2('WARNING: Unknown flag \u2018%s\u2019' % args[i])
		elif i == 1:
			if args[1] == 'b':
				blockmode = True
			elif args[1] == 'm':
				blockmode = False
			else:
				if not silent:
					print2('Invalid output mode \u2018%s\u2019 given. Exiting...'
					% args[1])
				return 127
		elif infile == '':
			infile = args[i]
		elif outfile == '':
			outfile = args[i]
		elif not silent:
			print2('WARNING: Unknown flag \u2018%s\u2019' % args[i])
		i += 1
	if infile == '':
		if not silent:
			print2('Insufficient parameters specified. Exiting...')
		return 127
	out: str = ''
	if infile == '-':
		from sys import stdin
		out = convert(stdin.buffer.read(), blockmode, silent)
	else:
		f = open(infile, 'rb')
		out = convert(f.read(), blockmode, silent)
		f.close()
	if outfile == '':
		from sys import stdout
		stdout.buffer.write(out.encode('utf-8'))
	else:
		f = open(outfile, 'wb')
		f.write(out.encode('utf-8'))
		f.close()
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
