#!/bin/sh
# -*- coding: utf-8 -*-

echo 'Packing the data/ folder into an lzipped tarball...' >/dev/stderr;
tar -cf - data | lzip -9q > data.tar.lz;
