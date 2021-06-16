#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

HELP_TEXT = 'Pret text to snip text converter\n\nUsage:\n    \n    pret2snip.py <input> [output]\n    Takes the file <input> and converts it to its binary equivalent.\n    If <input> is - then standard input is read.\n'

from snip2bin import TABLE
import re

def hex2ascii(byte, inRegex=False):
	for key in TABLE:
		if TABLE[key] == byte:
			return key
	retval = hex(byte).upper()[2:]
	if len(retval) == 1:
		retval = '0' + retval
	return '\\h' + retval

def rhs2vals(rhs):
	bytes_ct = (len(rhs) + 1) / 3
	bytes = []
	i = 0
	while i < bytes_ct:
		bytes.append(int(rhs[(i * 3)] + rhs[(i * 3) + 1], 16))
		i += 1
	vals = []
	for byte in bytes:
		vals.append(hex2ascii(byte, True))
	return vals

def charmap2table(text):
	lines = text.replace('\r\n', '\n').replace('\r', '\n').split('\n')
	chars = {}
	aliases = {}
	for lnum, line in enumerate(lines):
		line = re.sub('@.*$', '', line)
		if len(line) == 0:
			continue
		if line[0] == "'":
			i = 1
			while i < len(line):
				if line[i] == "'" and line[i - 1] != '\\':
					break
				i += 1
			char = line[1:i]
			chars[char] = rhs2vals(line.split('=')[-1].lstrip().rstrip())
		else:
			spl = line.split('=', 1)
			if len(spl) < 2:
				continue
			lhs = spl[0].lstrip().rstrip()
			rhs = spl[1].lstrip().rstrip()
			aliases[lhs] = rhs2vals(rhs)
	return (chars, aliases)

def convert(text, charmapfile='charmap.txt'):
	out = text[:]
	chars, aliases = charmap2table(open(charmapfile, 'r').read())
	regexs = []
	for key in aliases:
		keyesc = re.escape(key)
		out = re.sub('\\{' + keyesc + '\\}',
			''.join(aliases[key]).replace('\\', '\\\\'), out)
	for key in chars:
		keyesc = re.escape(key)
		out = re.sub(keyesc, ''.join(chars[key]).replace('\\', '\\\\'), out)
	return out

def main(args):
	argc = len(args)
	if argc <= 1 or (argc == 2 and (args[1] == '--help' or args[1] == '-h')):
		print(HELP_TEXT)
		return 0
	input = None
	if args[1] == '-':
		# Use stdin
		from sys import stdin
		input = stdin.read()
	else:
		input = open(args[1], 'r').read()
	output = convert(input)
	if argc == 2:
		# Use stdout
		from sys import stdout
		stdout.write(output)
	else:
		open(args[2], 'w').write(output)
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
