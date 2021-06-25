#!/bin/sh
# -*- coding: utf-8 -*-

cc -o util/sablmap util/sablmap.c -luni_str -luni_log -luni_err -luni_himem \
	-luni_futils
