##############################################################################
##                              POKeMON SwowS!                              ##
##                                                                          ##
##                   Copyright (C) 2021 Alexander Nicholi                   ##
##                       Released under BSD-0-Clause.                       ##
##############################################################################

ifeq ($(strip $(AQ)),)
$(error "AQ was not found in your environment. You need to install the Slick Makefiles from github.com/aquefir/slick to continue.")
endif

TP := GBASP

include etc/base.mk

# name of project. used in output binary naming
PROJECT := swows

# put a '1' for the desired target types to compile
EXEFILE := 1
SOFILE  :=
AFILE   :=

# space-separated path list for #includes
# <system> includes
INCLUDES :=
# "local" includes
INCLUDEL := src

# space-separated library name list
LIBS    :=
LIBDIRS :=

# '3P' are in-tree 3rd-party dependencies
# 3PLIBDIR is the base directory
# 3PLIBS is the folder names in the base directory for each library
3PLIBDIR :=
3PLIBS   :=

# frameworks (macOS target only)
FWORKS :=

# sources
SFILES    := \
	src/bset/outside.s \
	src/bset/petalburg.s \
	src/map/littleroot.s \
	src/hnam.s \
	src/map.s
CFILES    :=
CPPFILES  :=
PUBHFILES :=
PRVHFILES :=

# assets
JASCFILES := \
	data/extern/map/blockset/outside.jasc \
	data/extern/map/blockset/petalburg.jasc
MAPFILES  := \
	data/extern/map/littleroot.map
MAPBFILES := \
	data/extern/map/littleroot.mapb
BSETFILES := \
	data/extern/map/blockset/outside.bset \
	data/extern/map/blockset/petalburg.bset
BSAFILES  := \
	data/extern/map/blockset/outside.bsa \
	data/extern/map/blockset/petalburg.bsa
IMGFILES  := \
	data/extern/map/tileset/outside.4tn.il.png \
	data/extern/map/tileset/petalburg.4tn.il.png
SNIPFILES := \
	data/blendan.snip \
	data/maylene.snip

# test suite sources
TES_CFILES    :=
TES_CPPFILES  :=
TES_PUBHFILES :=
TES_PRVHFILES :=

# custom scripts
SNIP2BIN := $(PY) util/snip2bin.py
JASC2BIN := $(PY) util/jasc2gba.py
GFX2O    := $(PY) util/gfx2o.py

# this defines all our usual targets
include etc/targets.mk
