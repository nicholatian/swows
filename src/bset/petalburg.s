@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@                              POKeMON SwowS!                              @@
@@                                                                          @@
@@                   Copyright (C) 2021 Alexander Nicholi                   @@
@@                       Released under BSD-0-Clause.                       @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.globl blockset_petalburg
.balign 4, 0

blockset_petalburg:
	.byte 1 @ is compressed
	.byte 1 @ is secondary tileset
	.2byte 0 @ padding
	.4byte extern_map_tileset_petalburg_img_lz
	.4byte egdataExternMapBlocksetPetalburg_jasc
	.4byte egdataExternMapBlocksetPetalburg_bset
	.4byte egdataExternMapBlocksetPetalburg_bsa
	.4byte InitTilesetAnim_Petalburg
