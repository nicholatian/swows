@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@                              POKeMON SwowS!                              @@
@@                                                                          @@
@@                   Copyright (C) 2021 Alexander Nicholi                   @@
@@                       Released under BSD-0-Clause.                       @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.include "const/music.s"
.include "const/weather.s"
.include "const/maptypes.s"

.globl layout_littleroot
.balign 4, 0

layout_littleroot:
	.4byte 36
	.4byte 40
	.4byte egdataExternMapLittleroot_mapb
	.4byte egdataExternMapLittleroot_map
	.4byte blockset_outside
	.4byte blockset_petalburg
