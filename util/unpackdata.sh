#!/bin/sh
# -*- coding: utf-8 -*-

echo 'Unpacking the lzipped tarball into the data/ folder...' >/dev/stderr;
lzip -dqc data.tar.lz | tar -xf -;
