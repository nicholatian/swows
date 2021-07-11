@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@                              POKeMON SwowS!                              @@
@@                                                                          @@
@@                   Copyright (C) 2021 Alexander Nicholi                   @@
@@                       Released under BSD-0-Clause.                       @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.include "const/music.s"
.include "const/weather.s"
.include "const/maptypes.s"

.extern egdataExternMapLittleroot_map
.extern egdataExternMapLittleroot_mapb
.extern blockset_outside
.extern blockset_petalburg

.globl map_littleroot

.balign 4, 0
map_littleroot:
	.4byte Lmap_littleroot_mapdata
	.4byte LittlerootTown_MapEvents
	.4byte LittlerootTown_MapScripts
	.4byte LittlerootTown_MapConnections
	.2byte MUS_MISHIRO
	.2byte 10
	.byte 0 @ MAPSEC_LITTLEROOT_TOWN
	.byte 0
	.byte WEATHER_SUNNY
	.byte MAP_TYPE_TOWN
	.2byte 0
	.byte 1
	.byte MAP_BATTLE_SCENE_NORMAL

Lmap_littleroot_mapdata:
	.4byte 36
	.4byte 40
	.4byte egdataExternMapLittleroot_mapb
	.4byte egdataExternMapLittleroot_map
	.4byte blockset_outside
	.4byte blockset_petalburg
