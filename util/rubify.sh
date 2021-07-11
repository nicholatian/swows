#!/bin/sh
# -*- coding: utf-8 -*-

MAPRUBY=etc/mapruby;
R_MAPDATA=${MAPRUBY}/data/layouts;
R_BLOCKSET=${MAPRUBY}/data/tilesets;
MAPDATA=data/extern/map;
TILESET=data/extern/map/tileset;
BLOCKSET=data/extern/map/blockset;

blockset() {
	cp ${R_BLOCKSET}/$1/metatiles.bin ${BLOCKSET}/$2.bset;
	cp ${R_BLOCKSET}/$1/metatile_attributes.bin ${BLOCKSET}/$2.bsa;
cp ${R_BLOCKSET}/$1/tiles.png ${TILESET}/$2.4tn.il.png;
}

mapdata() {
	cp ${R_MAPDATA}/$1/map.bin ${MAPDATA}/$2.map;
	cp ${R_MAPDATA}/$1/border.bin ${MAPDATA}/$2.mapb;
}

mkdir -p ${TILESET};
mkdir -p ${BLOCKSET};
blockset primary/general outside;
blockset secondary/petalburg petalburg;
mapdata LittlerootTown littleroot;
mapdata PetalburgCity petalburg;
