#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

from typing import List, Dict

import chkascii as CheckASCII

HELP_TEXT = '''
Pret Metatile to Blockset conversion script
Copyright \u00A9 2021 Alexander Nicholi.
Released under BSD 0-Clause licence, a.k.a. the public domain.

Usage:-
\tmetatile2blockset [flags] <input> [output]

If -s or --silent is provided, the program will not send anything to
stderr. Otherwise, it will print status info updates as it works to
stderr. stdout is still written to if [output] is not given.

The program will write to [output], or stdout if it is omitted. If
<input> is \u2018-\u2019, stdin is read for text input.
'''

class INI:
	def __init__(self, fpath=None):
		if(fpath == None):
			self.d = {'': {}}
			return
		assert(type(fpath) is str)
		f = open(fpath, 'rb')
		t = f.read()
		f.close()
		t_sz = len(t)
		assert(CheckASCII.bad_ascii(t, t_sz, False) == t_sz)
		self.d = self._parse(t.decode('utf-8'))
	def _getbool(self, section : str, key : str):
		input: str = self.d[section][key]
		intval: int = int(input, 0)
		if input == 'true' or input == 'True' or input == 'TRUE' or \
		input == 'y' or input == 'Y' or input == 'yes' or input == 'Yes' or \
		input == 'YES' or input == 'on' or input == 'On' or input == 'ON' or \
			intval == 1:
			return 1
		elif input == 'false' or input == 'False' or input == 'FALSE' or \
		input == 'n' or input == 'N' or input == 'no' or input == 'No' or \
		input == 'NO' or input == 'off' or input == 'Off' or input == 'OFF' or \
			intval == 0:
			return 0
		else: return -1
	def readval(self, section : str, key : str):
		assert(type(section) is str)
		assert(section != '')
		assert(type(key) is str)
		assert(key != '')
		assert(section in self.d)
		assert(key in self.d[section])
		r = self._getbool(section, key)
		if r == -1: return self.d[section][key]
		else: return True if r == 1 else False
	def enumsections(self):
		r: List[str] = []
		for section in self.d:
			if section == '':
				continue
			r.append(section)
		return r
	def readgval(self, key : str):
		assert(type(key) is str)
		assert(key != '')
		assert(key in self.d[''])
		r = self._getbool('', key)
		if r == -1: return self.d[''][key]
		else: return True if r == 1 else False
	def writeval(self, section : str, key : str, val : str):
		assert(type(section) is str)
		assert(section != '')
		assert(type(key) is str)
		assert(key != '')
		assert(type(val) is str)
		if section not in self.d:
			self.d[section] = {}
		self.d[section][key] = val
	def writegval(self, key : str, val : str):
		assert(type(key) is str)
		assert(key != '')
		self.d[''][key] = val
	def _parse(self, t : str):
		assert(type(t) is str)
		ret: Dict[str, Dict[str, str]] = {'': {}}
		cur_s = '' # Empty string is the global section
		lines = t.splitlines()
		lines_sz = len(lines)
		i = 0
		while i < lines_sz:
			# Remove comments, anywhere they appear
			line = lines[i].split(';', 1)[0]
			if '[' in line and ']' in line:
				s = line.lstrip(' \t\v\f\r').rstrip(' \t\v\f\r')
				assert(s[0] == '[')
				assert(s[-1] == ']')
				cur_s = s[1:-1]
				ret[cur_s] = {}
				# done parsing now. don't look for a keypair that isn't here
				i += 1
				continue
			elif '=' not in line:
				# Not dealing with a keypair, check it
				line_sz = len(line)
				j = 0
				while j < line_sz:
					ch = line[j]
					# only whitespace is permitted outside of comments and keypairs
					assert(ch == ' ' or ch == '\t' or ch == '\v' or ch == '\f' or
						ch == '\r')
					j += 1
				# don't try to parse this, there's nothing here
				i += 1
				continue
			# NOTE: no whitespace stripping is done. this is deliberate
			p = line.split('=', 1)
			key = p[0]
			val = p[1]
			assert(key != '')
			ret[cur_s][key] = val
			i += 1
		return ret
	def serialise(self):
		r: str = '\n'
		for key in self.d['']:
			r += key + '=' + self.d[''][key] + '\n'
		r += '\n'
		for section in self.d:
			if section == '':
				continue
			r += '[' + section + ']\n'
			for key in self.d[section]:
				r += key + '=' + self.d[section][key] + '\n'
			r += '\n'
		return r

def print2(x):
	from sys import stderr
	print(x, file=stderr)

def convert(data : bytes):
	r: INI = INI()
	count = len(data) // 16
	r.writegval('count', str(count))
	i = 0
	while i < count:
		section = '0x' + hex(i)[2:].upper()
		r.writeval(section, 'behav', '0')
		r.writeval(section, 'type', 'normal')
		# parse tiles
		fields: List[str] = [''] * 32
		fields[0] = '0x' + hex(int(data[i * 16]) | \
			(int(data[(i * 16) + 1] & 0x3) << 8))[2:].upper()
		fields[1] = str(int(data[(i * 16) + 1]) >> 4)
		fields[2] = str((int(data[(i * 16) + 1]) >> 2) & 1)
		fields[3] = str((int(data[(i * 16) + 1]) >> 3) & 1)
		fields[4] = '0x' + hex(int(data[(i * 16) + 2]) | \
			(int(data[(i * 16) + 3] & 0x3) << 8))[2:].upper()
		fields[5] = str(int(data[(i * 16) + 3]) >> 4)
		fields[6] = str((int(data[(i * 16) + 3]) >> 2) & 1)
		fields[7] = str((int(data[(i * 16) + 3]) >> 3) & 1)
		fields[8] = '0x' + hex(int(data[(i * 16) + 4]) | \
			(int(data[(i * 16) + 5] & 0x3) << 8))[2:].upper()
		fields[9] = str(int(data[(i * 16) + 5]) >> 4)
		fields[10] = str((int(data[(i * 16) + 5]) >> 2) & 1)
		fields[11] = str((int(data[(i * 16) + 5]) >> 3) & 1)
		fields[12] = '0x' + hex(int(data[(i * 16) + 6]) | \
			(int(data[(i * 16) + 7] & 0x3) << 8))[2:].upper()
		fields[13] = str(int(data[(i * 16) + 7]) >> 4)
		fields[14] = str((int(data[(i * 16) + 7]) >> 2) & 1)
		fields[15] = str((int(data[(i * 16) + 7]) >> 3) & 1)
		fields[16] = '0x' + hex(int(data[(i * 16) + 8]) | \
			(int(data[(i * 16) + 9] & 0x3) << 8))[2:].upper()
		fields[17] = str(int(data[(i * 16) + 9]) >> 4)
		fields[18] = str((int(data[(i * 16) + 9]) >> 2) & 1)
		fields[19] = str((int(data[(i * 16) + 9]) >> 3) & 1)
		fields[20] = '0x' + hex(int(data[(i * 16) + 10]) | \
			(int(data[(i * 16) + 11] & 0x3) << 8))[2:].upper()
		fields[21] = str(int(data[(i * 16) + 11]) >> 4)
		fields[22] = str((int(data[(i * 16) + 11]) >> 2) & 1)
		fields[23] = str((int(data[(i * 16) + 11]) >> 3) & 1)
		fields[24] = '0x' + hex(int(data[(i * 16) + 12]) | \
			(int(data[(i * 16) + 13] & 0x3) << 8))[2:].upper()
		fields[25] = str(int(data[(i * 16) + 13]) >> 4)
		fields[26] = str((int(data[(i * 16) + 13]) >> 2) & 1)
		fields[27] = str((int(data[(i * 16) + 13]) >> 3) & 1)
		fields[28] = '0x' + hex(int(data[(i * 16) + 14]) | \
			(int(data[(i * 16) + 15] & 0x3) << 8))[2:].upper()
		fields[29] = str(int(data[(i * 16) + 15]) >> 4)
		fields[30] = str((int(data[(i * 16) + 15]) >> 2) & 1)
		fields[31] = str((int(data[(i * 16) + 15]) >> 3) & 1)
		r.writeval(section, 'l0tl_tile', fields[0])
		r.writeval(section, 'l0tl_pal', fields[1])
		r.writeval(section, 'l0tl_xf', fields[2])
		r.writeval(section, 'l0tl_yf', fields[3])
		r.writeval(section, 'l0tr_tile', fields[4])
		r.writeval(section, 'l0tr_pal', fields[5])
		r.writeval(section, 'l0tr_xf', fields[6])
		r.writeval(section, 'l0tr_yf', fields[7])
		r.writeval(section, 'l0bl_tile', fields[8])
		r.writeval(section, 'l0bl_pal', fields[9])
		r.writeval(section, 'l0bl_xf', fields[10])
		r.writeval(section, 'l0bl_yf', fields[11])
		r.writeval(section, 'l0br_tile', fields[12])
		r.writeval(section, 'l0br_pal', fields[13])
		r.writeval(section, 'l0br_xf', fields[14])
		r.writeval(section, 'l0br_yf', fields[15])
		r.writeval(section, 'l1tl_tile', fields[16])
		r.writeval(section, 'l1tl_pal', fields[17])
		r.writeval(section, 'l1tl_xf', fields[18])
		r.writeval(section, 'l1tl_yf', fields[19])
		r.writeval(section, 'l1tr_tile', fields[20])
		r.writeval(section, 'l1tr_pal', fields[21])
		r.writeval(section, 'l1tr_xf', fields[22])
		r.writeval(section, 'l1tr_yf', fields[23])
		r.writeval(section, 'l1bl_tile', fields[24])
		r.writeval(section, 'l1bl_pal', fields[25])
		r.writeval(section, 'l1bl_xf', fields[26])
		r.writeval(section, 'l1bl_yf', fields[27])
		r.writeval(section, 'l1br_tile', fields[28])
		r.writeval(section, 'l1br_pal', fields[29])
		r.writeval(section, 'l1br_xf', fields[30])
		r.writeval(section, 'l1br_yf', fields[31])
		i += 1
	return r.serialise()

def main(args):
	argc = len(args)
	silent = False
	i = 1
	infile = ''
	outfile = ''
	nomoreflags = False
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
		out = convert(stdin.buffer.read())
	else:
		f = open(infile, 'rb')
		out = convert(f.read())
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
