#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

HELP_TEXT = '''
Symbol map to CSV
Copyright \u00A9 2021 Alexander Nicholi.
Released under BSD 0-Clause licence, a.k.a. the public domain.

Usage:-
\tmap2csv [flags] <input> [output]

If -s or --silent is provided, the program will not send anything to
stdout nor stderr. Otherwise, it will print status info updates as it
works to stderr. stdout is never used.

If -S or --strict is provided, the first row of the CSV file will be
token headers labeling the columns. This is normally omitted for
further processing.

The program will write to [output], or stdout if it is omitted. If
<input> is \u2018-\u2019, stdin is read for text input.
'''

def print2(x):
	from sys import stderr
	print(x, file=stderr)

def parse_map(text):
	ret = []
	import re
	sym_expr = re.compile(r'[A-Za-z_][A-Za-z0-9_]*')
	offs_expr = re.compile(r'0x[A-Fa-f0-9]{16}')
	text = re.sub(r'[ \t\v\f\r]+', ' ', text)
	lines = text.splitlines()
	lines_sz = len(lines)
	i = 0
	while i < lines_sz:
		fields = lines[i].lstrip(' \t\v\f\r').rstrip(' \t\v\f\r').split(' ')
		i += 1
		if offs_expr.match(fields[0]) == None:
			continue
		if sym_expr.match(fields[1]) == None:
			continue
		ret.append((fields[1], int(fields[0], 16)))
	return ret

def list2csv(lis, write_heading):
	ret = 'symbol,value\n' if write_heading else ''
	lis_sz = len(lis)
	i = 0
	while i < lis_sz:
		ret += lis[i][0] + ',' + ('0x%X' % lis[i][1]) + '\n'
		i += 1
	return ret

def main(args):
	argc = len(args)
	silent = '-s' in args or '--silent' in args
	strict = '-S' in args or '--strict' in args
	if argc == 1 or '-h' in args or '--help' in args:
		if not silent:
			print2(HELP_TEXT)
		return 127
	i = 1
	infile = ''
	outfile = ''
	while i < argc:
		if args[i] == '-' and infile == '':
			infile = '-'
		elif args[i].startswith('-'):
			if args[i] == '-s' or args[i] == '--silent':
				pass # handled above
			elif args[i] == '-S' or args[i] == '--strict':
				pass # handled above
			elif not silent:
				print2('WARNING: Unknown flag \u2018%s\u2019' % args[i])
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
	text = ''
	if infile == '-':
		from sys import stdin
		block = stdin.buffer.read()
		blocksz = len(block)
		import chkascii
		r = chkascii.bad_ascii(block, blocksz, False)
		if r < blocksz:
			if not silent:
				print2('Invalid octet at offset $%X: 0x%02X is not valid ASCII' %
					(r, block[r]))
			return 127
		text = block.decode('utf-8')
	else:
		f = open(infile, 'rb')
		block = f.read()
		blocksz = len(block)
		import chkascii
		r = chkascii.bad_ascii(block, blocksz, False)
		if r < blocksz:
			if not silent:
				print2('Invalid octet at offset $%X: 0x%02X is not valid ASCII' %
					(r, block[r]))
			return 127
		text = block.decode('utf-8')
	output = bytes(list2csv(parse_map(text), strict), 'utf-8')
	output_sz = len(output)
	import chkascii
	r = chkascii.bad_ascii(output, output_sz, False)
	if r < output_sz:
		if not silent:
			print2('CSV output is invalid!')
			print2('This is probably an issue with map2csv. Exiting...')
		return 127
	if outfile == '':
		from sys import stdout
		r = stdout.buffer.write(output)
		if r < output_sz and not silent:
			print2('WARNING: Some of the output did not make it through')
	else:
		f = open(outfile, 'wb')
		r = f.write(output)
		if r < output_sz and not silent:
			print2('WARNING: Some of the output did not make it through')
		f.close()
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
