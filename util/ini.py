#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

def parse(text):
	ret = {'': {}}
	cur_s = '' # Empty string is the global section
	lines = text.splitlines()
	lines_sz = len(lines)
	i = 0
	while i < lines_sz:
		# Remove comments, anywhere they appear
		line = lines[i].split(';', 1)[0]
		if '[' in line and ']' in line:
			s = line.lstrip(' \t\v\f\r').rstrip(' \t\v\f\r')
			if s[0] != '[' or s[-1] != ']':
				# Bad section
				raise Exception('Malformed section heading on line ' + \
					str(i + 1) + '\n\nLine contents: ' + line)
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
				if ch != ' ' and ch != '\t' and ch != '\v' and ch != '\f' \
				and ch != '\r':
					raise Exception('Malformed syntax on line ' + str(i + 1) \
						+ '\n\nLine contents: ' + line)
				j += 1
			# don't try to parse this, there's nothing here
			i += 1
			continue
		# NOTE: no whitespace stripping is done. this is deliberate
		p = line.split('=', 1)
		key = p[0]
		val = p[1]
		if key == '' or val == '':
			# either the key name or value (or both) are empty
			raise Exception('Bad key/value pair on line ' + str(i + 1) \
				+ '\n\nLine contents: ' + line)
		ret[cur_s][key] = val
		i += 1
	return ret
