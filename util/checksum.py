#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

def print2(x):
	from sys import stderr
	print(x, file=stderr)

def sha2_256sum(filename):
	import hashlib
	f = open(filename, 'rb')
	data_hash = hashlib.sha256()
	# Read and update hash string value in blocks of 4K
	for block in iter(lambda: f.read(4096), b''): data_hash.update(block)
	digest = data_hash.hexdigest()
	f.close()
	return digest

HELP_TEXT = '''
ROM checksum verifier
Copyright \u00A9 2021 Alexander Nicholi.
Released under BSD 0-Clause licence, a.k.a. the public domain.

Usage:-
\tchecksum.py [flags] <input_file> <sha2_256sum>

If -s or --silent is provided, the program will not send anything to
stdout nor stderr. Otherwise, it will print status info updates as it
works to stderr. stdout is never used.

If -f or --file is provided, sha2_256sum is treated as a file path,
the contents of which contain the checksum in ASCII. Otherwise, it is
taken as the actual checksum. The placement and ordering of the flags
does not matter, but the parameter ordering does: the input file comes
first.

The program returns exit code 0 when verification passes, and 1 when
it fails. Printing help text returns 127.
'''

def main(args):
	argc = len(args)
	silent = '-s' in args or '--silent' in args
	if argc == 1 or '-h' in args or '--help' in args:
		if not silent: print2(HELP_TEXT)
		return 127
	i = 1
	sumbyfile = False
	romfpath = ''
	checksum = ''
	while i < argc:
		if args[i].startswith('-'):
			if args[i] == '-f' or args[i] == '--file': sumbyfile = True
			elif args[i] == '-s' or args[i] == '--silent': pass # handled above
			elif not silent:
				print2('WARNING: Unknown flag \u2018%s\u2019' % args[i])
		elif romfpath == '': romfpath = args[i]
		elif checksum == '': checksum = args[i]
		elif not silent:
			print2('WARNING: Excess parameter \u2018%s\u2019' % args[i])
		i += 1
	if sumbyfile:
		f = open(checksum, 'r')
		checksum = f.read()
		f.close()
		checksum = checksum.replace('\r', '').replace('\n', '')
		checksum = checksum.replace('\t', '').replace(' ', '')
	digest = sha2_256sum(romfpath)
	if checksum == '':
		if not silent: print2(digest + '  ' + romfpath)
		return 0
	if digest == checksum:
		if not silent: print2('Checksum verification passed!')
		return 0
	if not silent: print2('Checksum verification failed!')
	return 1

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
