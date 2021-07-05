#!/usr/bin/env python3
# -*- coding: utf-8 -*-
##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

from typing import List, Tuple, Dict

from PIL import Image as PILImage

from ctypes import byref as Ref
import sdl2.ext as SDL2Ext
import os as OS
import re as RegExp
import sdl2 as SDL2
import jascpal as JASC
import chkascii as CheckASCII

MAPVIEW_W = 640
MAPVIEW_H = 400

BLOCKVIEW_W = 256
BLOCKVIEW_H = 400

FRAME_W = 960
FRAME_H = 416

FRAME_RECT = SDL2.SDL_Rect(0, 0, FRAME_W, FRAME_H)
MAPVIEW_RECT = SDL2.SDL_Rect(0, 0, MAPVIEW_W, MAPVIEW_H)
BLOCKVIEW_RECT = SDL2.SDL_Rect(0, 0, BLOCKVIEW_W, BLOCKVIEW_H)

WSPACE_EXPR = RegExp.compile('[ \t\v\f\r]+')

# Bitmasks for RGBA colour (needed for SDL2)
MASK_R = 0x000000FF
MASK_G = 0x0000FF00
MASK_B = 0x00FF0000
MASK_A = 0xFF000000

HELP_TEXT = '''
SABLMAP map editor
Copyright \u00A9 2021 Alexander Nicholi.
Released under BSD 0-Clause licence, a.k.a. the public domain.

Usage:-
	sablmap [flags] <map.ini> <map.owb> <map.owm>

If -s or --silent is provided, the program will not send anything to
stdout nor stderr. Otherwise, it will print status info updates as it
works to stderr. stdin and stdout are never used.
'''
