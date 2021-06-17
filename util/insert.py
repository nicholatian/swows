#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

from os import linesep
from sys import argv, exit, stderr
from struct import pack, unpack_from
from shutil import copyfile


origin = 0xE3CF70


class Hook:
	def __init__(self, offset, value, sizesym):
		self.offset  = offset
		self.value   = value
		self.bytes   = pack('<' + sizesym, value)
		self.sizesym = sizesym

def run(command):
	import subprocess
	try:
		return subprocess.check_output(command).decode()
	except subprocess.CalledProcessError as e:
		print(e.output.decode(), file=stderr)
		exit(1)

def getHooks(hooksfile, objfile):
	hooks	= []
	hookfile = open(hooksfile, 'r').read().split(linesep)
	# parse the hooks list file, properly
	offsets = []
	widths  = []
	names   = []
	opvals  = []
	ops	 = []
	for lnum, line in enumerate(hookfile):
		if line == '':
			continue
		# Remove comments, anywhere they appear
		newline = ''
		for char in line:
			if char == '#':
				break
			else:
				newline += char
		if '=' not in newline:
			# not dealing with a pair, check it
			for char in newline:
				# only whitespace is permitted outside comments and pairs
				if char != ' ' and char != '\t':
					raise Exception('Malformed syntax on line ' + str(lnum + 1))
			# don't try to parse this, there's nothing here
			continue
		pair = newline.split('=', 1)
		# Remove surrounding whitespace
		pair[0] = pair[0].replace(' ', '')
		pair[1] = pair[1].replace(' ', '')
		if pair[0] == '' or pair[1] == '':
			# either the key name or value (or both) are empty
			raise Exception('Bad key/value pair on line ' + str(lnum + 1))
		# detach the symbol lengths from their names
		subpair = pair[1].split(':', 1)
		# ensure the given type is a valid one
		if subpair[0] != 'word' and subpair[0] != 'hword' and subpair[0] != 'byte':
			raise Exception('Invalid type for value on line ' + str(lnum + 1))
		# perform one-time right-hand arithmetic if requested
		name = None
		if '^' in subpair[1]:
			mathpair = subpair[1].split('^')
			name	 = mathpair[0]
			opvals  += [int(mathpair[1], 0)]
			ops	 += ['^']
		elif '&' in subpair[1]:
			mathpair = subpair[1].split('&')
			name	 = mathpair[0]
			opvals  += [int(mathpair[1], 0)]
			ops	 += ['&']
		elif '|' in subpair[1]:
			mathpair = subpair[1].split('|')
			name	 = mathpair[0]
			opvals  += [int(mathpair[1], 0)]
			ops	 += ['|']
		elif '/' in subpair[1]:
			mathpair = subpair[1].split('/')
			name	 = mathpair[0]
			opvals  += [int(mathpair[1], 0)]
			ops	 += ['/']
		elif '*' in subpair[1]:
			mathpair = subpair[1].split('*')
			name	 = mathpair[0]
			opvals  += [int(mathpair[1], 0)]
			ops	 += ['*']
		elif '-' in subpair[1]:
			mathpair = subpair[1].split('-')
			name	 = mathpair[0]
			opvals  += [int(mathpair[1], 0)]
			ops	 += ['-']
		elif '+' in subpair[1]:
			mathpair = subpair[1].split('+')
			name	 = mathpair[0]
			opvals  += [int(mathpair[1], 0)]
			ops	 += ['+']
		else:
			name	 = subpair[1]
			opvals  += [0]
			ops	 += ['+']
		# add the properties to the arrays
		offsets += [int(pair[0], 16)]
		widths  += [subpair[0]]
		names   += [name]
	
	# get the values of the symbols and store them
	values = []
	nmout  = run(['arm-none-eabi-nm', '-nPS', objfile]).split(linesep)
	for index, name in enumerate(names):
		foundparts = []
		# run through the output of arm-none-eabi-nm
		for lnum, line in enumerate(nmout):
			# ignore empty lines and lines only containing whitespace
			if line == '':
				continue
			nonblank = True
			for char in line:
				if char != ' ' and char != '\t':
					blank = False
					break
			if blank:
				continue
			# split the line into parts
			parts = line.split(' ')
			# remove blank parts
			i = 0
			while i < len(parts):
				if parts[i] == '':
					parts = parts[:i] + parts[i + 1:]
				else:
					i += 1
			count = len(parts)
			# ensure it's within normal bounds
			if count < 2 or count > 3:
				raise Exception('Strange number of items on line ' +
					str(lnum + 1) + ' of arm-none-eabi-nm\u2019s output: \u201C' +
					str(parts) + '\u201D')
			# finally, check for a match
			if parts[0] == name:
				foundparts += [parts]
		if len(foundparts) == 0:
			# didn't find any matches
			raise Exception('Symbol \u201C' + name + '\u201D defined in hooks ' +
				'list, but not found in output object code')
		addrs = []
		# go through what we found
		# ignore addressless lists as they're probably undefined dups
		for parts in foundparts:
			if len(parts) == 2:
				continue
			addr = int(parts[2], 16)
			# perform the requested arithmetic first
			if ops[index] == '^':
				addr ^= opvals[index]
			elif ops[index] == '&':
				addr &= opvals[index]
			elif ops[index] == '|':
				addr |= opvals[index]
			elif ops[index] == '/':
				addr /= opvals[index]
			elif ops[index] == '*':
				addr *= opvals[index]
			elif ops[index] == '-':
				addr -= opvals[index]
			elif ops[index] == '+':
				addr += opvals[index]
			else:
				raise Exception('An arithmetic operation must be performed on the address. This is most likely a problem with the source.')
			addrs += [addr]
		if len(addrs) != 1:
			# there can only be One
			raise Exception('Multiple addresses found for symbol ' + name)
		values += [addrs[0]]
	# run through the list once more to objectify everything and store it
	for index, width in enumerate(widths):
		sizesym = 'I'
		if width == 'hword':
			sizesym = 'H'
		elif width == 'byte':
			sizesym = 'B'
		hooks += [Hook(offsets[index], values[index], sizesym)]
	return hooks

def main(hooksfile, inrom, inhax, inobj, outfile):
	copyfile(inrom, outfile)
	outbin = open(outfile, 'r+b')
	outraw = outbin.read()
	outbuf = bytearray(unpack_from('B' * len(outraw), outraw))
	inbin  = open(inhax, 'rb')
	inbuf  = inbin.read()
	# gather all of our hooks proper
	hooks = getHooks(hooksfile, inobj)
	for hook in hooks:
		if hook.sizesym == 'B':
			outbuf[hook.offset] = hook.value
		elif hook.sizesym == 'H':
			outbuf[hook.offset] = hook.bytes[0]
			outbuf[hook.offset + 1] = hook.bytes[1]
		elif hook.sizesym == 'I':
			outbuf[hook.offset]	 = hook.bytes[0]
			outbuf[hook.offset + 1] = hook.bytes[1]
			outbuf[hook.offset + 2] = hook.bytes[2]
			outbuf[hook.offset + 3] = hook.bytes[3]
	# pad the output binary to 32MiB
	outbuf += (b'\xFF' * (0x2000000 - len(outbuf)))
	# copy over the new binary blob in memory
	bloblen = len(inbuf)
	i = 0
	while(i < bloblen):
		outbuf[i + origin] = inbuf[i]
		i += 1
	
	# insert the binary blob
	outbin.seek(0)
	outbin.write(outbuf)
	outbin.close()

if __name__ == '__main__':
	main(argv[1], argv[2], argv[3], argv[4], argv[5])
