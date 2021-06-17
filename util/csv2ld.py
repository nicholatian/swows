#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

HELP_TEXT = '''
Symbol CSV table to linker script
Copyright \u00A9 2021 Alexander Nicholi.
Released under BSD 0-Clause licence, a.k.a. the public domain.

Usage:-
\tcsv2ld [flags] <input> [output]

If -s or --silent is provided, the program will not send anything to
stdout nor stderr. Otherwise, it will print status info updates as it
works to stderr. stdout is never used.

The program will write to [output], or stdout if it is omitted. If
<input> is \u2018-\u2019, stdin is read for text input.
'''

def print2(x):
	from sys import stderr
	print(x, file=stderr)

def csv2lis(text, silent):
	ret = []
	lines = text.splitlines()
	lines_sz = len(lines)
	i = 0
	while i < lines_sz:
		fields = lines[i].split(',')
		if len(fields) != 2:
			if not silent:
				print2('Wrong number of columns on line %s of CSV!' % (i, 10))
			return []
		ret.append([fields[0], fields[1]])
		i += 1
	return ret

def lis2ld(lis):
	ret = ''
	lis_sz = len(lis)
	i = 0
	while i < lis_sz:
		ret += lis[i][0] + ' = ' + lis[i][1] + ';\n'
		i += 1
	return bytes(ret, 'utf-8')

def main(args):
	argc = len(args)
	silent = '-s' in args or '--silent' in args
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
	output = lis2ld(csv2lis(text, silent))
	output_sz = len(output)
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
