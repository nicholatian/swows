#!/bin/sh
# -*- coding: utf-8 -*-

if [ "$1" = '' ]; then
	echo 'No name provided. Exiting...';
	exit 127;
fi

util/sablmap.py "data/map/$1.ini" "data/map/$1.owb" "data/map/$1.owm";
exit $?;
