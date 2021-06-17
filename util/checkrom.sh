#!/bin/sh
# -*- coding: utf-8 -*-

if [ ! -f 3rdparty/emer.gba ]; then
	echo 'ROM file not found. Exiting...' >/dev/stderr;
	exit 127;
fi

util/checksum.py 3rdparty/emer.gba -f etc/emer.gba.sha256sum;
exit $?;
