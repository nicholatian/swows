#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                                  SwowS™                                  ##
##                                                                          ##
##                    Copyright © 2021 Alexander Nicholi                    ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

def print2(x):
	from sys import stderr
	print(x, file=stderr)

HELP_TEXT = '''
Check for ASCII validity in a file.
Copyright © 2021 Alexander Nicholi.
Released under BSD 0-Clause licence, a.k.a. the public domain.

Usage:-
\tchkascii.py [flags] <input file> [more inputs...]

Any octet outside the range of 1..127 causes failure. To consider NUL
octets as valid, pass the -0 or --zero flag.

If -s or --silent is provided, the program will not send anything to
stdout nor stderr. Otherwise, it will print status info updates as it
works to stderr. stdout is never used.

The program returns exit code 0 when verification passes, and 1 when
it fails. Printing help text returns 127.
'''

def bad_ascii(block, sz, allow_nul):
	i = 0
	sz = len(block)
	lower = 0 if allow_nul else 1
	while i < sz:
		octet = int(block[i])
		if octet < lower or octet > 127:
			return i
		i += 1
	return i

def is_invalid(filename, allow_nul, silent):
	f = open(filename, 'rb')
	fail = False
	# Read and check bytes in blocks of 4KiB
	blocksz = 4096
	super_i = 0
	for block in iter(lambda: f.read(blocksz), b''):
		r = bad_ascii(block, blocksz, allow_nul)
		super_i += blocksz
		if r < blocksz:
			if not silent:
				print2('Invalid octet at offset $%X: 0x%02X is not valid ASCII' %
				(super_i, block[r]))
			break
	return fail

def main(args):
	argc = len(args)
	silent = '-s' in args or '--silent' in args
	if argc == 1 or '-h' in args or '--help' in args:
		if not silent:
			print2(HELP_TEXT)
		return 127
	i = 1
	files = []
	allow_nul = False
	while i < argc:
		if args[i].startswith('-'):
			if args[i] == '-s' or args[i] == '--silent':
				pass # handled above
			elif args[i] == '-0' or args[i] == '--zero':
				allow_nul = True
			elif not silent:
				print2('WARNING: Unknown flag ‘%s’' % args[i])
		else:
			files.append(args[i])
		i += 1
	i = 0
	sz = len(files)
	while i < sz:
		r = is_invalid(files[i], allow_nul, silent)
		if r == True:
			if not silent:
				print2('Checksum failed on file ‘%s’!' % files[i])
			return 1
		i += 1
	if sz > 0:
		if not silent:
			print2('Checksum passed for all files!')
		return 0
	else:
		if not silent:
			print2('WARNING: No input files provided. Exiting...')
		return 127

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
