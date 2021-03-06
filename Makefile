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
	src/hnam.s
CFILES    :=
CPPFILES  :=
PUBHFILES :=
PRVHFILES :=

# assets
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

# this defines all our usual targets
include etc/targets.mk
