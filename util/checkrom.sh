#!/bin/sh
# -*- coding: utf-8 -*-
########################################################################
##                           POKeMON SwowS!                           ##
##                                                                    ##
##                Copyright (C) 2021 Alexander Nicholi                ##
##                    Released under BSD-0-Clause.                    ##
########################################################################

echo=/bin/echo; # avoid shell builtins
command -v gecho >/dev/null && echo=gecho; # for macOS
command -v stdbuf >/dev/null && echo="stdbuf -o0 ${echo}";
echon="${echo} -n";
test=/bin/test; # avoid shell builtins
command -v gtest >/dev/null && test=gtest;

cmd='';
command -v sha256sum >/dev/null && cmd=sha256sum;
${test} "$cmd" = '' && command -v shasum >/dev/null && \
	cmd='shasum -f 256';
${test} "$cmd" = '' && {
	${echo} 'No suitable SHA-256 checksumming utility found.';
	${echo} 'Are you on some weird BSD or some shit? Exiting...';
	exit 1;
};

if [ ! -f 3rdparty/emer.gba ]; then
	${echo} 'ROM file not found. Exiting...' >/dev/stderr;
	exit 127;
fi

${echon} 'Checking... ';
${cmd} -c etc/emer.gba.sha256sum >/dev/null;
${echo} 'done.';
r="$?";
${test} "$r" = '0' && ${echo} 'Passed';
${test} "$r" != '0' && ${echo} 'FAILED';
exit $?;
