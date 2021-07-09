#!/bin/sh
# -*- coding: utf-8 -*-

mapbin() {
	util/mapbin2ow.py b \
	etc/mapruby/data/layouts/$1/map.bin \
	data/extern/map/$2.owb;
	util/mapbin2ow.py m \
		etc/mapruby/data/layouts/$1/map.bin \
		data/extern/map/$2.owm;
	util/mapbin2ow.py b \
		etc/mapruby/data/layouts/$1/border.bin \
		data/extern/map/$2.mapb;
}

mkdir -p data/extern/map;
mapbin LittlerootTown littleroot;
