@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@                              POKeMON SwowS!                              @@
@@                                                                          @@
@@                   Copyright (C) 2021 Alexander Nicholi                   @@
@@                       Released under BSD-0-Clause.                       @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.globl mapbankh
.globl mapbank_outside
.globl mapbank_littleroot

.balign 4, 0

mapbank_outside:
	.4byte PetalburgCity_Layout
	.4byte SlateportCity_Layout
	.4byte MauvilleCity_Layout
	.4byte RustboroCity_Layout
	.4byte FortreeCity_Layout
	.4byte LilycoveCity_Layout
	.4byte MossdeepCity_Layout
	.4byte SootopolisCity_Layout
	.4byte EverGrandeCity_Layout
	.4byte map_littleroot @ modified
	.4byte OldaleTown_Layout
	.4byte DewfordTown_Layout
	.4byte LavaridgeTown_Layout
	.4byte FallarborTown_Layout
	.4byte VerdanturfTown_Layout
	.4byte PacifidlogTown_Layout
	.4byte Route101_Layout
	.4byte Route102_Layout
	.4byte Route103_Layout
	.4byte Route104_Layout
	.4byte Route105_Layout
	.4byte Route106_Layout
	.4byte Route107_Layout
	.4byte Route108_Layout
	.4byte Route109_Layout
	.4byte Route110_Layout
	.4byte Route111_Layout
	.4byte Route112_Layout
	.4byte Route113_Layout
	.4byte Route114_Layout
	.4byte Route115_Layout
	.4byte Route116_Layout
	.4byte Route117_Layout
	.4byte Route118_Layout
	.4byte Route119_Layout
	.4byte Route120_Layout
	.4byte Route121_Layout
	.4byte Route122_Layout
	.4byte Route123_Layout
	.4byte Route124_Layout
	.4byte Route125_Layout
	.4byte Route126_Layout
	.4byte Route127_Layout
	.4byte Route128_Layout
	.4byte Route129_Layout
	.4byte Route130_Layout
	.4byte Route131_Layout
	.4byte Route132_Layout
	.4byte Route133_Layout
	.4byte Route134_Layout
	.4byte Underwater1_Layout
	.4byte Underwater2_Layout
	.4byte Underwater3_Layout
	.4byte Underwater4_Layout
	.4byte Underwater5_Layout
	.4byte Underwater6_Layout
	.4byte Underwater7_Layout

.balign 4, 0

mapbank_littleroot:
	.4byte LittlerootTown_BrendansHouse_1F_Layout
	.4byte LittlerootTown_BrendansHouse_2F_Layout
	.4byte LittlerootTown_MaysHouse_1F_Layout
	.4byte LittlerootTown_MaysHouse_2F_Layout
	.4byte LittlerootTown_ProfessorBirchsLab_Layout

.balign 4, 0

mapbankh:
	.4byte mapbank_outside
	.4byte mapbank_littleroot
	.4byte gMapGroup1
	.4byte gMapGroup2
	.4byte gMapGroup3
	.4byte gMapGroup4
	.4byte gMapGroup5
	.4byte gMapGroup6
	.4byte gMapGroup7
	.4byte gMapGroup8
	.4byte gMapGroup9
	.4byte gMapGroup10
	.4byte gMapGroup11
	.4byte gMapGroup12
	.4byte gMapGroup13
	.4byte gMapGroup14
	.4byte gMapGroup15
	.4byte gMapGroup16
	.4byte gMapGroup17
	.4byte gMapGroup18
	.4byte gMapGroup19
	.4byte gMapGroup20
	.4byte gMapGroup21
	.4byte gMapGroup22
	.4byte gMapGroup23
	.4byte gMapGroup24
	.4byte gMapGroup25
	.4byte gMapGroup26
	.4byte gMapGroup27
	.4byte gMapGroup28
	.4byte gMapGroup29
	.4byte gMapGroup30
	.4byte gMapGroup31
	.4byte gMapGroup32
	.4byte gMapGroup33
