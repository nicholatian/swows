#include "main_menu.h"
#include "wild_encounter.h"

enum
{
	/* Urbans */
	LOC_PETALBURG_CITY,
	LOC_DEWFORD_TOWN,
	LOC_SLATEPORT_CITY,
	LOC_LILYCOVE_CITY,
	LOC_MOSSDEEP_CITY,
	LOC_SOOTOPOLIS_CITY,
	LOC_PACIFIDLOG_TOWN,
	LOC_EVER_GRANDE_CITY,
	/* Routes */
	LOC_ROUTE_101,
	LOC_ROUTE_102,
	LOC_ROUTE_103,
	LOC_ROUTE_104,
	LOC_ROUTE_105,
	LOC_ROUTE_106,
	LOC_ROUTE_107,
	LOC_ROUTE_108,
	LOC_ROUTE_109,
	LOC_ROUTE_110,
	LOC_ROUTE_111,
	LOC_ROUTE_112,
	LOC_ROUTE_113,
	LOC_ROUTE_114,
	LOC_ROUTE_115,
	LOC_ROUTE_116,
	LOC_ROUTE_117,
	LOC_ROUTE_118,
	LOC_ROUTE_119,
	LOC_ROUTE_120,
	LOC_ROUTE_121,
	LOC_ROUTE_122,
	LOC_ROUTE_123,
	LOC_ROUTE_124,
	LOC_ROUTE_125,
	LOC_ROUTE_126,
	LOC_ROUTE_127,
	LOC_ROUTE_128,
	LOC_ROUTE_129,
	LOC_ROUTE_130,
	LOC_ROUTE_131,
	LOC_ROUTE_132,
	LOC_ROUTE_133,
	LOC_ROUTE_134,
	/* Additonal overworld places */
	LOC_SAFARI_ZONE_NORTH,
	LOC_SAFARI_ZONE_NORTHEAST,
	LOC_SAFARI_ZONE_NORTHWEST,
	LOC_SAFARI_ZONE_SOUTH,
	LOC_SAFARI_ZONE_SOUTHEAST,
	LOC_SAFARI_ZONE_SOUTHWEST,
	/* Begin dungeons */
	LOC_PETALBURG_WOODS,
	/* Begin caves */
	LOC_RUSTURF_TUNNEL,
	LOC_GRANITE_CAVE_1F,
	LOC_GRANITE_CAVE_B1F,
	LOC_GRANITE_CAVE_B2F,
	LOC_GRANITE_CAVE_STEVENS_ROOM,
	LOC_FIERY_PATH,
	LOC_JAGGED_PASS,
	LOC_METEOR_FALLS_1F_RM1,
	LOC_METEOR_FALLS_1F_RM2,
	LOC_METEOR_FALLS_B1F_RM1,
	LOC_METEOR_FALLS_B1F_RM2,
	LOC_METEOR_FALLS_STEVENS_ROOM,
	LOC_MT_PYRE_1F,
	LOC_MT_PYRE_2F,
	LOC_MT_PYRE_3F,
	LOC_MT_PYRE_4F,
	LOC_MT_PYRE_5F,
	LOC_MT_PYRE_6F,
	LOC_MT_PYRE_EXTERIOR,
	LOC_MT_PYRE_SUMMIT,
	LOC_VICTORY_ROAD_1F,
	LOC_VICTORY_ROAD_B1F,
	LOC_VICTORY_ROAD_B2F,
	LOC_SKY_PILLAR_1F,
	LOC_SKY_PILLAR_3F,
	LOC_SKY_PILLAR_5F,
	LOC_SEAFLOOR_CAVERN_ENTRANCE,
	LOC_SEAFLOOR_CAVERN_RM1,
	LOC_SEAFLOOR_CAVERN_RM2,
	LOC_SEAFLOOR_CAVERN_RM3,
	LOC_SEAFLOOR_CAVERN_RM4,
	LOC_SEAFLOOR_CAVERN_RM5,
	LOC_SEAFLOOR_CAVERN_RM6,
	LOC_SEAFLOOR_CAVERN_RM7,
	LOC_SEAFLOOR_CAVERN_RM8,
	LOC_CAVE_OF_ORIGIN_ENTRANCE,
	LOC_CAVE_OF_ORIGIN_B1F,
	LOC_SHOAL_CAVE_LO_ENTRANCE,
	LOC_SHOAL_CAVE_LO_STAIRS,
	LOC_SHOAL_CAVE_LO_LOWER,
	LOC_SHOAL_CAVE_LO_INNER,
	LOC_SHOAL_CAVE_ICE,
	LOC_MIRAGE_TOWER_1F,
	LOC_MIRAGE_TOWER_2F,
	LOC_MIRAGE_TOWER_3F,
	LOC_MIRAGE_TOWER_4F,
	LOC_DESERT_UNDERPASS,
	LOC_MAGMA_HIDEOUT_1F,
	LOC_MAGMA_HIDEOUT_2F_RM1,
	LOC_MAGMA_HIDEOUT_2F_RM2,
	LOC_MAGMA_HIDEOUT_2F_RM3,
	LOC_MAGMA_HIDEOUT_3F_RM1,
	LOC_MAGMA_HIDEOUT_3F_RM2,
	LOC_MAGMA_HIDEOUT_3F_RM3,
	LOC_MAGMA_HIDEOUT_4F,
	LOC_ARTISAN_CAVE_1F,
	LOC_ARTISAN_CAVE_B1F,
	LOC_ALTERING_CAVE_1,
	LOC_ALTERING_CAVE_2,
	LOC_ALTERING_CAVE_3,
	LOC_ALTERING_CAVE_4,
	LOC_ALTERING_CAVE_5,
	LOC_ALTERING_CAVE_6,
	LOC_ALTERING_CAVE_7,
	LOC_ALTERING_CAVE_8,
	LOC_ALTERING_CAVE_9,
	/* Begin underwater */
	LOC_UNDERWATER_1,
	LOC_UNDERWATER_2,
	/* Man-made dungeons */
	LOC_ABANDONED_SHIP_1F,
	LOC_ABANDONED_SHIP_CORRIDORS,
	LOC_NEW_MAUVILLE,
	LOC_NEW_MAUVILLE_ENTRANCE,
	MAX_LOC
};

struct WildEncounter
{
	u8 land_rate, water_rate, fish_rate, rock_rate;
	struct WildPokemon land[12];
	struct WildPokemon water[5];
	struct WildPokemon fish[10];
	struct WildPokemon rock[5];
};

/* NOTE: The #includes must be in the same order as the enum above */
const struct WildEncounter k_wild_mons[MAX_LOC][MAX_BADGES + 1] = {
#include "wild/petalburgcity.h"
#include "wild/dewfordtown.h"
#include "wild/slateportcity.h"
#include "wild/lilycovecity.h"
#include "wild/mossdeepcity.h"
#include "wild/sootopoliscity.h"
#include "wild/pacifidlogtown.h"
#include "wild/evergrandecity.h"
#include "wild/route101.h"
#include "wild/route102.h"
#include "wild/route103.h"
#include "wild/route104.h"
#include "wild/route105.h"
#include "wild/route106.h"
#include "wild/route107.h"
#include "wild/route108.h"
#include "wild/route109.h"
#include "wild/route110.h"
#include "wild/route111.h"
#include "wild/route112.h"
#include "wild/route113.h"
#include "wild/route114.h"
#include "wild/route115.h"
#include "wild/route116.h"
#include "wild/route117.h"
#include "wild/route118.h"
#include "wild/route119.h"
#include "wild/route120.h"
#include "wild/route121.h"
#include "wild/route122.h"
#include "wild/route123.h"
#include "wild/route124.h"
#include "wild/route125.h"
#include "wild/route126.h"
#include "wild/route127.h"
#include "wild/route128.h"
#include "wild/route129.h"
#include "wild/route130.h"
#include "wild/route131.h"
#include "wild/route132.h"
#include "wild/route133.h"
#include "wild/route134.h"
#include "wild/safarizone_north.h"
#include "wild/safarizone_northeast.h"
#include "wild/safarizone_northwest.h"
#include "wild/safarizone_south.h"
#include "wild/safarizone_southeast.h"
#include "wild/safarizone_southwest.h"
#include "wild/petalburgwoods.h"
#include "wild/rusturftunnel.h"
#include "wild/granitecave_1f.h"
#include "wild/granitecave_b1f.h"
#include "wild/granitecave_b2f.h"
#include "wild/granitecave_stevensroom.h"
#include "wild/fierypath.h"
#include "wild/jaggedpass.h"
#include "wild/meteorfalls_1f_rm1.h"
#include "wild/meteorfalls_1f_rm2.h"
#include "wild/meteorfalls_b1f_rm1.h"
#include "wild/meteorfalls_b1f_rm2.h"
#include "wild/meteorfalls_stevensroom.h"
#include "wild/mtpyre_1f.h"
#include "wild/mtpyre_2f.h"
#include "wild/mtpyre_3f.h"
#include "wild/mtpyre_4f.h"
#include "wild/mtpyre_5f.h"
#include "wild/mtpyre_6f.h"
#include "wild/mtpyre_exterior.h"
#include "wild/mtpyre_summit.h"
#include "wild/victoryroad_1f.h"
#include "wild/victoryroad_b1f.h"
#include "wild/victoryroad_b2f.h"
#include "wild/skypillar_1f.h"
#include "wild/skypillar_3f.h"
#include "wild/skypillar_5f.h"
#include "wild/seafloorcavern_entrance.h"
#include "wild/seafloorcavern_rm1.h"
#include "wild/seafloorcavern_rm2.h"
#include "wild/seafloorcavern_rm3.h"
#include "wild/seafloorcavern_rm4.h"
#include "wild/seafloorcavern_rm5.h"
#include "wild/seafloorcavern_rm6.h"
#include "wild/seafloorcavern_rm7.h"
#include "wild/seafloorcavern_rm8.h"
#include "wild/caveoforigin_entrance.h"
#include "wild/caveoforigin_b1f.h"
#include "wild/shoalcave_lo_entrance.h"
#include "wild/shoalcave_lo_stairs.h"
#include "wild/shoalcave_lo_lower.h"
#include "wild/shoalcave_lo_inner.h"
#include "wild/shoalcave_ice.h"
#include "wild/miragetower_1f.h"
#include "wild/miragetower_2f.h"
#include "wild/miragetower_3f.h"
#include "wild/miragetower_4f.h"
#include "wild/desertunderpass.h"
#include "wild/magmahideout_1f.h"
#include "wild/magmahideout_2f_rm1.h"
#include "wild/magmahideout_2f_rm2.h"
#include "wild/magmahideout_2f_rm3.h"
#include "wild/magmahideout_3f_rm1.h"
#include "wild/magmahideout_3f_rm2.h"
#include "wild/magmahideout_3f_rm3.h"
#include "wild/magmahideout_4f.h"
#include "wild/artisancave_1f.h"
#include "wild/artisancave_b1f.h"
#include "wild/alteringcave1.h"
#include "wild/alteringcave2.h"
#include "wild/alteringcave3.h"
#include "wild/alteringcave4.h"
#include "wild/alteringcave5.h"
#include "wild/alteringcave6.h"
#include "wild/alteringcave7.h"
#include "wild/alteringcave8.h"
#include "wild/alteringcave9.h"
#include "wild/underwater1.h"
#include "wild/underwater2.h"
#include "wild/abandonedship_b1f.h"
#include "wild/abandonedship_corridors.h"
#include "wild/newmauville.h"
#include "wild/newmauville_entrance.h"
};
