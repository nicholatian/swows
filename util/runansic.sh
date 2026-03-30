#!/bin/sh
########################################################################
##                           POKeMON SwowS!                           ##
##                                                                    ##
##                Copyright (C) 2021 Alexander Nicholi                ##
##                    Released under BSD-0-Clause.                    ##
########################################################################

echo=/bin/echo;
command -v gecho >/dev/null && echo=gecho;
command -v stdbuf >/dev/null && echo="stdbuf -o0 ${echo}";
rm=rm;
command -v grm >/dev/null && rm=grm;

command -v valac >/dev/null || {
	${echo} 'valac is not installed on your system.';
	${echo} 'Exiting...';
	exit 127;
};

srcpath="$1";
srcdir="${srcpath%/*}";
srcfile="${srcpath##*/}";
binpath="${srcdir}/${srcfile%%.*}.bin";

# do not recompile if already made
test -f "${binpath}" || cc -ansi -O2 -o"${binpath}" "${srcpath}";
args="${@:2}";
./"${binpath}" $args;
