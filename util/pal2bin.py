#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

HELP_TEXT = 'Nich palette to binary converter\n\nUsage:\n    \n    pal2bin.py <input> [output]\n    Takes the NPAL file <input> and converts it to its binary equivalent.\n    If <input> is - then standard input is read.\n'

def convert(input):
	input     = input.replace('\r', '').split('\n')
	index_arr = []
	values    = []
	for lnum, line in enumerate(input):
		if line == '':
			continue
		newline = ''
		for char in line:
			if char == '#':
				break
			else: newline += char
		if '=' not in newline:
			# not dealing with a pair. check it
			for char in newline:
				# only whitespace is permitted outside comments and pairs
				if char != ' ' and char != '\t':
					raise Exception('Bad syntax on line ' + str(lnum + 1))
			# don’t try to parse this, there’s nothing here
			continue
		pair = newline.split('=', 1)
		# Remove surrounding whitespace
		pair[0] = pair[0].replace(' ', '')
		pair[1] = pair[1].replace(' ', '')
		if pair[0] == '' or pair[1] == '':
			# either the key or value (or both) are empty
			raise Exception('Bad key/value pair on line ' + str(lnum + 1))
		index_arr.append(get_indexes(pair[0]))
		strval = pair[1]
		if strval.startswith('rgb'):
			values.append(func2hword(strval, True))
		elif strval.startswith('gba'):
			values.append(func2hword(strval, False))
		elif strval.startswith('$'):
			values.append(hex2hword(strval))
		elif ',' in strval:
			values.append(bytes2hword(strval))
		else:
			values.append(int(strval, 0))
		if values[-1] > 0x7FFF:
			# not a valid 15-bit colour
			raise Exception('Value too high to be a 15-bit colour: ' +
				hex(values[-1]))
	maxnum = 0
	for indexes in index_arr:
		indexes.sort()
		highest = indexes[-1]
		if highest > maxnum:
			maxnum = highest
	out = bytearray(b'\x00\x00') * (maxnum + 1)
	for i, indexes in enumerate(index_arr):
		bytestrs = [values[i] >> i2 & 0xFF for i2 in (8, 0)]
		for index in indexes:
			out[i * 2]     = bytestrs[1] # lo byte
			out[i * 2 + 1] = bytestrs[0] # hi byte
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
		stdout.buffer.write(output)
	else:
		open(args[2], 'wb').write(output)
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv))
