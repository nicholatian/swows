@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@                              POKeMON SwowS!                              @@
@@                                                                          @@
@@                   Copyright (C) 2021 Alexander Nicholi                   @@
@@                       Released under BSD-0-Clause.                       @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.globl blockset_outside
.balign 4, 0

blockset_outside:
	.byte 1 @ is compressed
	.byte 0 @ is secondary tileset
	.2byte 0 @ padding
	.4byte egdataExternMapTilesetOutside_imglz
	.4byte egdataExternMapBlocksetOutside_jasc
	.4byte egdataExternMapBlocksetOutside_bset
	.4byte egdataExternMapBlocksetOutside_bsa
	.4byte InitTilesetAnim_General+1
