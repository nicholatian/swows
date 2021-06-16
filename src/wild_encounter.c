#include "global.h"
#include "wild_encounter.h"
#include "pokemon.h"
#include "metatile_behavior.h"
#include "fieldmap.h"
#include "random.h"
#include "field_player_avatar.h"
#include "main_menu.h"
#include "event_data.h"
#include "safari_zone.h"
#include "overworld.h"
#include "pokeblock.h"
#include "battle_setup.h"
#include "roamer.h"
#include "tv.h"
#include "link.h"
#include "script.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "constants/abilities.h"
#include "constants/game_stat.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/maps.h"
#include "constants/species.h"

enum
{
	WILD_AREA_LAND,
	WILD_AREA_WATER,
	WILD_AREA_ROCKS,
	WILD_AREA_FISHING,
};

extern const u8 EventScript_RepelWoreOff[];

#define NUM_FEEBAS_SPOTS 6

// this file's functions
static u16 FeebasRandom( void );
static void FeebasSeedRng( u16 seed );
static bool8 IsWildLevelAllowedByRepel( u8 level );
static void ApplyFluteEncounterRateMod( u32* encRate );
static void ApplyCleanseTagEncounterRateMod( u32* encRate );
static bool8 TryGetAbilityInfluencedWildMonIndex(
	const struct WildPokemon* wildMon, u8 type, u8 ability, u8* monIndex );
static bool8 IsAbilityAllowingEncounter( u8 level );

// EWRAM vars
EWRAM_DATA static u8 sWildEncountersDisabled = 0;
EWRAM_DATA static u32 sFeebasRngValue        = 0;

#include "data/wild_encounters.h"

// Special Feebas-related data.
const struct WildPokemon gWildFeebasRoute119Data = {20, 25, SPECIES_FEEBAS};

const u16 gRoute119WaterTileData[] = {
	0,
	0x2D,
	0,
	0x2E,
	0x5B,
	0x83,
	0x5C,
	0x8B,
	0x12A,
};

void DisableWildEncounters( bool8 disabled )
{
	sWildEncountersDisabled = disabled;
}

static u16 GetRoute119WaterTileNum( s16 x, s16 y, u8 section )
{
	u16 xCur;
	u16 yCur;
	u16 yMin    = gRoute119WaterTileData[section * 3 + 0];
	u16 yMax    = gRoute119WaterTileData[section * 3 + 1];
	u16 tileNum = gRoute119WaterTileData[section * 3 + 2];

	for( yCur = yMin; yCur <= yMax; yCur++ )
	{
		for( xCur = 0; xCur < gMapHeader.mapLayout->width; xCur++ )
		{
			u8 tileBehaviorId = MapGridGetMetatileBehaviorAt(
				xCur + 7, yCur + 7 );
			if( MetatileBehavior_IsSurfableAndNotWaterfall(
				    tileBehaviorId ) == TRUE )
			{
				tileNum++;
				if( x == xCur && y == yCur )
					return tileNum;
			}
		}
	}
	return tileNum + 1;
}

static bool8 CheckFeebas( void )
{
	u8 i;
	u16 feebasSpots[NUM_FEEBAS_SPOTS];
	s16 x;
	s16 y;
	u8 route119Section = 0;
	u16 waterTileNum;

	if( gSaveBlock1Ptr->location.mapGroup == MAP_GROUP( ROUTE119 ) &&
		gSaveBlock1Ptr->location.mapNum == MAP_NUM( ROUTE119 ) )
	{
		GetXYCoordsOneStepInFrontOfPlayer( &x, &y );
		x -= 7;
		y -= 7;

		if( y >= gRoute119WaterTileData[3 * 0 + 0] &&
			y <= gRoute119WaterTileData[3 * 0 + 1] )
			route119Section = 0;
		if( y >= gRoute119WaterTileData[3 * 1 + 0] &&
			y <= gRoute119WaterTileData[3 * 1 + 1] )
			route119Section = 1;
		if( y >= gRoute119WaterTileData[3 * 2 + 0] &&
			y <= gRoute119WaterTileData[3 * 2 + 1] )
			route119Section = 2;

		if( Random( ) % 100 > 49 ) // 50% chance of encountering Feebas
			return FALSE;

		FeebasSeedRng( gSaveBlock1Ptr->easyChatPairs[0].unk2 );
		for( i = 0; i != NUM_FEEBAS_SPOTS; )
		{
			feebasSpots[i] = FeebasRandom( ) % 447;
			if( feebasSpots[i] == 0 )
				feebasSpots[i] = 447;
			if( feebasSpots[i] < 1 || feebasSpots[i] >= 4 )
				i++;
		}
		waterTileNum =
			GetRoute119WaterTileNum( x, y, route119Section );
		for( i = 0; i < NUM_FEEBAS_SPOTS; i++ )
		{
			if( waterTileNum == feebasSpots[i] )
				return TRUE;
		}
	}
	return FALSE;
}

// The number 1103515245 comes from the example implementation of rand and
// srand in the ISO C standard.

static u16 FeebasRandom( void )
{
	sFeebasRngValue = ( 1103515245 * sFeebasRngValue ) + 12345;
	return sFeebasRngValue >> 16;
}

static void FeebasSeedRng( u16 seed ) { sFeebasRngValue = seed; }

static u8 get_wmon_index_land( void )
{
	switch( Random( ) >> 11 )
	{
	case 0:
		return 11; /* 3.125% */
	case 1:
		return 10; /* 3.125% */
	case 2:
	case 3:
		return 9; /* 6.25% */
	case 4:
	case 5:
		return 8; /* 6.25% */
	case 6:
	case 7:
		return 7; /* 6.25% */
	case 8:
	case 9:
	case 10:
		return 6; /* 9.375% */
	case 11:
	case 12:
	case 13:
		return 5; /* 9.375% */
	case 14:
	case 15:
	case 16:
		return 4; /* 9.375% */
	case 17:
	case 18:
	case 19:
		return 3; /* 9.375% */
	case 20:
	case 21:
	case 22:
	case 23:
		return 2; /* 12.5% */
	case 24:
	case 25:
	case 26:
	case 27:
		return 1; /* 12.5% */
	default:
		return 0; /* 12.5% */
	}
}

static u8 get_wmon_index_water_rock( void )
{
	switch( Random( ) >> 12 )
	{
	case 0:
		return 4; /* 6.25% */
	case 1:
		return 3; /* 6.25% */
	case 2:
	case 3:
		return 2; /* 12.5% */
	case 4:
	case 5:
	case 6:
	case 7:
		return 1; /* 25% */
	default:
		return 0; /* 50% */
	}
}

enum
{
	OLD_ROD = 0,
	GOOD_ROD,
	SUPER_ROD,
	ROD_MAX
};

static u8 get_wmon_index_fish_old( void )
{
	/* 62.5% chance of 0 */
	return ( Random( ) >> 12 ) <= 10 ? 0 : 1;
}

static u8 get_wmon_index_fish_good( void )
{
	switch( Random( ) >> 13 )
	{
	case 0:
		return 4; /* 12.5% */
	case 1:
	case 2:
	case 3:
		return 3; /* 37.5% */
	default:
		return 2; /* 50% */
	}
}

static u8 get_wmon_index_fish_super( void )
{
	switch( Random( ) >> 12 )
	{
	case 0:
		return 9; /* 6.25% */
	case 1:
	case 2:
		return 8; /* 12.5% */
	case 3:
	case 4:
	case 5:
		return 7; /* 18.75% */
	case 6:
	case 7:
	case 8:
	case 9:
		return 6; /* 25% */
	default:
		return 5; /* 37.5% */
	}
}

typedef u8 ( *fishing_Fn )( void );

static const fishing_Fn fishing_functions[ROD_MAX] = {
	( fishing_Fn )( get_wmon_index_fish_old ),
	( fishing_Fn )( get_wmon_index_fish_good ),
	( fishing_Fn )( get_wmon_index_fish_super )};

static u8 get_wmon_index_fish( u8 rod ) { return fishing_functions[rod]( ); }

static u8 get_wmon_level( unsigned locid, u8 badge_ct, u8 area, u8 index )
{
	u8 min, max, r;

	switch( area )
	{
	case WILD_AREA_WATER:
		if( index >= 5 )
		{
			return 0;
		}
		min = k_wild_mons[locid][badge_ct].rock[index].min;
		max = k_wild_mons[locid][badge_ct].rock[index].max;
		break;
	case WILD_AREA_ROCKS:
		if( index >= 5 )
		{
			return 0;
		}
		min = k_wild_mons[locid][badge_ct].rock[index].min;
		max = k_wild_mons[locid][badge_ct].rock[index].max;
		break;
	case WILD_AREA_FISHING:
		if( index >= 10 )
		{
			return 0;
		}
		min = k_wild_mons[locid][badge_ct].fish[index].min;
		max = k_wild_mons[locid][badge_ct].fish[index].max;
		break;
	case WILD_AREA_LAND:
	default:
		if( index >= 12 )
		{
			return 0;
		}
		min = k_wild_mons[locid][badge_ct].land[index].min;
		max = k_wild_mons[locid][badge_ct].land[index].max;
		break;
	}

	/* Make sure the minimum level is less than the maximum level */
	if( max > min )
	{
		u8 tmp;

		tmp = min;
		min = max;
		max = tmp;
	}

	r = Random( ) % ( max - min + 1 );

	if( !GetMonData( &gPlayerParty[0], MON_DATA_SANITY_IS_EGG ) )
	{
		u8 abil = GetMonAbility( &gPlayerParty[0] );

		if( abil == ABILITY_HUSTLE || abil == ABILITY_VITAL_SPIRIT ||
			abil == ABILITY_PRESSURE )
		{
			if( ( Random( ) & 1 ) == 0 )
			{
				return max;
			}

			if( r > 0 )
			{
				r--;
			}
		}
	}

	return min + r;
}

static const u16 k_map_wpkmn_ids[MAX_LOC] = {MAP_PETALBURG_CITY,
	MAP_DEWFORD_TOWN,
	MAP_SLATEPORT_CITY,
	MAP_LILYCOVE_CITY,
	MAP_MOSSDEEP_CITY,
	MAP_SOOTOPOLIS_CITY,
	MAP_PACIFIDLOG_TOWN,
	MAP_EVER_GRANDE_CITY,
	/* Routes */
	MAP_ROUTE101,
	MAP_ROUTE102,
	MAP_ROUTE103,
	MAP_ROUTE104,
	MAP_ROUTE105,
	MAP_ROUTE106,
	MAP_ROUTE107,
	MAP_ROUTE108,
	MAP_ROUTE109,
	MAP_ROUTE110,
	MAP_ROUTE111,
	MAP_ROUTE112,
	MAP_ROUTE113,
	MAP_ROUTE114,
	MAP_ROUTE115,
	MAP_ROUTE116,
	MAP_ROUTE117,
	MAP_ROUTE118,
	MAP_ROUTE119,
	MAP_ROUTE120,
	MAP_ROUTE121,
	MAP_ROUTE122,
	MAP_ROUTE123,
	MAP_ROUTE124,
	MAP_ROUTE125,
	MAP_ROUTE126,
	MAP_ROUTE127,
	MAP_ROUTE128,
	MAP_ROUTE129,
	MAP_ROUTE130,
	MAP_ROUTE131,
	MAP_ROUTE132,
	MAP_ROUTE133,
	MAP_ROUTE134,
	/* Additonal overworld places */
	MAP_SAFARI_ZONE_NORTH,
	MAP_SAFARI_ZONE_NORTHEAST,
	MAP_SAFARI_ZONE_NORTHWEST,
	MAP_SAFARI_ZONE_SOUTH,
	MAP_SAFARI_ZONE_SOUTHEAST,
	MAP_SAFARI_ZONE_SOUTHWEST,
	/* Begin dungeons */
	MAP_PETALBURG_WOODS,
	/* Begin caves */
	MAP_RUSTURF_TUNNEL,
	MAP_GRANITE_CAVE_1F,
	MAP_GRANITE_CAVE_B1F,
	MAP_GRANITE_CAVE_B2F,
	MAP_GRANITE_CAVE_STEVENS_ROOM,
	MAP_FIERY_PATH,
	MAP_JAGGED_PASS,
	MAP_METEOR_FALLS_1F_1R,
	MAP_METEOR_FALLS_1F_2R,
	MAP_METEOR_FALLS_B1F_1R,
	MAP_METEOR_FALLS_B1F_2R,
	MAP_METEOR_FALLS_STEVENS_CAVE,
	MAP_MT_PYRE_1F,
	MAP_MT_PYRE_2F,
	MAP_MT_PYRE_3F,
	MAP_MT_PYRE_4F,
	MAP_MT_PYRE_5F,
	MAP_MT_PYRE_6F,
	MAP_MT_PYRE_EXTERIOR,
	MAP_MT_PYRE_SUMMIT,
	MAP_VICTORY_ROAD_1F,
	MAP_VICTORY_ROAD_B1F,
	MAP_VICTORY_ROAD_B2F,
	MAP_SKY_PILLAR_1F,
	MAP_SKY_PILLAR_3F,
	MAP_SKY_PILLAR_5F,
	MAP_SEAFLOOR_CAVERN_ENTRANCE,
	MAP_SEAFLOOR_CAVERN_ROOM1,
	MAP_SEAFLOOR_CAVERN_ROOM2,
	MAP_SEAFLOOR_CAVERN_ROOM3,
	MAP_SEAFLOOR_CAVERN_ROOM4,
	MAP_SEAFLOOR_CAVERN_ROOM5,
	MAP_SEAFLOOR_CAVERN_ROOM6,
	MAP_SEAFLOOR_CAVERN_ROOM7,
	MAP_SEAFLOOR_CAVERN_ROOM8,
	MAP_CAVE_OF_ORIGIN_ENTRANCE,
	MAP_CAVE_OF_ORIGIN_B1F,
	MAP_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM,
	MAP_SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM,
	MAP_SHOAL_CAVE_LOW_TIDE_LOWER_ROOM,
	MAP_SHOAL_CAVE_LOW_TIDE_INNER_ROOM,
	MAP_SHOAL_CAVE_LOW_TIDE_ICE_ROOM,
	MAP_MIRAGE_TOWER_1F,
	MAP_MIRAGE_TOWER_2F,
	MAP_MIRAGE_TOWER_3F,
	MAP_MIRAGE_TOWER_4F,
	MAP_DESERT_UNDERPASS,
	MAP_MAGMA_HIDEOUT_1F,
	MAP_MAGMA_HIDEOUT_2F_1R,
	MAP_MAGMA_HIDEOUT_2F_2R,
	MAP_MAGMA_HIDEOUT_2F_3R,
	MAP_MAGMA_HIDEOUT_3F_1R,
	MAP_MAGMA_HIDEOUT_3F_2R,
	MAP_MAGMA_HIDEOUT_3F_3R,
	MAP_MAGMA_HIDEOUT_4F,
	MAP_ARTISAN_CAVE_1F,
	MAP_ARTISAN_CAVE_B1F,
	MAP_ALTERING_CAVE,
	MAP_ALTERING_CAVE,
	MAP_ALTERING_CAVE,
	MAP_ALTERING_CAVE,
	MAP_ALTERING_CAVE,
	MAP_ALTERING_CAVE,
	MAP_ALTERING_CAVE,
	MAP_ALTERING_CAVE,
	MAP_ALTERING_CAVE,
	/* Begin underwater */
	MAP_UNDERWATER1,
	MAP_UNDERWATER2,
	/* Man-made dungeons */
	MAP_ABANDONED_SHIP_ROOMS_1F,
	MAP_ABANDONED_SHIP_CORRIDORS_B1F,
	MAP_NEW_MAUVILLE_INSIDE,
	MAP_NEW_MAUVILLE_ENTRANCE};

static int get_cur_map_locid( void )
{
	int i;
	s8 cur_map_g, cur_map_n;

	cur_map_g = gSaveBlock1Ptr->location.mapGroup;
	cur_map_n = gSaveBlock1Ptr->location.mapNum;

	for( i = 0; i < MAX_LOC; ++i )
	{
		s8 map_g, map_n;

		map_g = k_map_wpkmn_ids[i] >> 8;
		map_n = k_map_wpkmn_ids[i] & 0xFF;

		if( map_g == cur_map_g && map_n == cur_map_n )
		{
			return i;
		}
	}

	return -1;
}

static u8 get_wmon_nature( void )
{
	u8 i;
	u8 j;
	struct Pokeblock* safariPokeblock;
	u8 natures[25];

	if( GetSafariZoneFlag( ) == TRUE && Random( ) % 100 < 80 )
	{
		safariPokeblock = SafariZoneGetActivePokeblock( );
		if( safariPokeblock != NULL )
		{
			for( i = 0; i < 25; i++ )
				natures[i] = i;
			for( i = 0; i < 24; i++ )
			{
				for( j = i + 1; j < 25; j++ )
				{
					if( Random( ) & 1 )
					{
						u8 temp = natures[i];

						natures[i] = natures[j];
						natures[j] = temp;
					}
				}
			}
			for( i = 0; i < 25; i++ )
			{
				if( PokeblockGetGain(
					    natures[i], safariPokeblock ) > 0 )
					return natures[i];
			}
		}
	}
	// check synchronize for a pokemon with the same ability
	if( !GetMonData( &gPlayerParty[0], MON_DATA_SANITY_IS_EGG ) &&
		GetMonAbility( &gPlayerParty[0] ) == ABILITY_SYNCHRONIZE &&
		Random( ) % 2 == 0 )
	{
		return GetMonData( &gPlayerParty[0], MON_DATA_PERSONALITY ) %
			25;
	}

	// random nature
	return Random( ) % 25;
}

static void create_wildmon( u16 species, u8 level )
{
	ZeroEnemyPartyMons( );
	CreateMonWithNature(
		&gEnemyParty[0], species, level, 32, get_wmon_nature( ) );
}

#define WILD_CHECK_REPEL 0x1
#define WILD_CHECK_KEEN_EYE 0x2

static int try_gen_wildmon(
	unsigned locid, u8 badge_ct, u8 area, u8 flags, u8 rod )
{
	u8 wmon_i, level;
	u16 species;

	wmon_i = 0;

	switch( area )
	{
	case WILD_AREA_FISHING:
		wmon_i  = get_wmon_index_fish( rod );
		species = k_wild_mons[locid][badge_ct].fish[wmon_i].species;
		break;
	case WILD_AREA_WATER:
		wmon_i  = get_wmon_index_water_rock( );
		species = k_wild_mons[locid][badge_ct].water[wmon_i].species;
		break;
	case WILD_AREA_ROCKS:
		wmon_i  = get_wmon_index_water_rock( );
		species = k_wild_mons[locid][badge_ct].rock[wmon_i].species;
		break;
	case WILD_AREA_LAND:
	default:
		wmon_i  = get_wmon_index_land( );
		species = k_wild_mons[locid][badge_ct].land[wmon_i].species;
		break;
	}

	level = get_wmon_level( locid, badge_ct, area, wmon_i );

	if( ( ( flags & WILD_CHECK_REPEL ) &&
		    !IsWildLevelAllowedByRepel( level ) ) ||
		( ( flags & WILD_CHECK_KEEN_EYE ) &&
			!IsAbilityAllowingEncounter( level ) ) )
	{
		return 0;
	}

	create_wildmon( species, level );

	return 1;
}

#if 0
static bool8 SetUpMassOutbreakEncounter( u8 flags )
{
	return FALSE;
}

static bool8 DoMassOutbreakEncounterTest( void )
{
	return FALSE;
}

static bool8 DoWildEncounterRateDiceRoll( u16 encounterRate )
{
	if( Random( ) % 2880 < encounterRate )
		return TRUE;
	else
		return FALSE;
}

static bool8 DoWildEncounterRateTest( u32 encounterRate, bool8 ignoreAbility )
{
	encounterRate *= 16;
	if( TestPlayerAvatarFlags(
	       PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE ) )
		encounterRate = encounterRate * 80 / 100;
	ApplyFluteEncounterRateMod( &encounterRate );
	ApplyCleanseTagEncounterRateMod( &encounterRate );
	if( !ignoreAbility &&
	   !GetMonData( &gPlayerParty[0], MON_DATA_SANITY_IS_EGG ) )
	{
		u32 ability = GetMonAbility( &gPlayerParty[0] );

		if( ability == ABILITY_STENCH &&
		   gMapHeader.mapLayoutId ==
		      LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_EMPTY_SQUARE )
			encounterRate = encounterRate * 3 / 4;
		else if( ability == ABILITY_STENCH )
			encounterRate /= 2;
		else if( ability == ABILITY_ILLUMINATE )
			encounterRate *= 2;
		else if( ability == ABILITY_WHITE_SMOKE )
			encounterRate /= 2;
		else if( ability == ABILITY_ARENA_TRAP )
			encounterRate *= 2;
		else if( ability == ABILITY_SAND_VEIL && gSaveBlock1Ptr->weather == 8 )
			encounterRate /= 2;
	}
	if( encounterRate > 2880 )
		encounterRate = 2880;
	return DoWildEncounterRateDiceRoll( encounterRate );
}
#endif /* 0 */

static int is_sootopolis_warring( void )
{
	return gSaveBlock1Ptr->location.mapGroup ==
		MAP_GROUP( SOOTOPOLIS_CITY ) &&
		gSaveBlock1Ptr->location.mapNum ==
		MAP_NUM( SOOTOPOLIS_CITY ) &&
		FlagGet( FLAG_LEGENDARIES_IN_SOOTOPOLIS );
}

static bool8 roll_wild_enc( u8 rate ) { return ( Random( ) % 100 ) <= rate; }

/* this is for lure ball functionality
 * set to 1 while fishing */
extern u8 battle_bits;

void FishingWildEncounter( u8 rod )
{
	battle_bits |= 1;
	StandardWildEncounter( 0, 0, rod + 1 );
	battle_bits &= ~1;
}

bool8 StandardWildEncounter( u16 cur_mtbehav, u16 prev_mtbehav, u8 rod )
{
	int locid;
	u8 badge_ct;

	if( sWildEncountersDisabled == TRUE )
	{
		return FALSE;
	}

	badge_ct = count_badges( );
	locid    = get_cur_map_locid( );

	if( locid == -1 )
	{
		return FALSE;
	}

	if( rod )
	{
		if( k_wild_mons[locid][badge_ct].fish_rate == 0 ||
			roll_wild_enc(
				k_wild_mons[locid][badge_ct].fish_rate ) ==
				FALSE )
		{
			return FALSE;
		}

		/* Checks pass, try to generate a mon */
		if( try_gen_wildmon( locid,
			    badge_ct,
			    WILD_AREA_FISHING,
			    WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE,
			    rod - 1 ) == TRUE )
		{
			BattleSetup_StartWildBattle( );
			return TRUE;
		}
	}
	else if( TILE_LAND_WILD_ENC( cur_mtbehav ) )
	{
		if( cur_mtbehav != prev_mtbehav ||
			k_wild_mons[locid][badge_ct].land_rate == 0 ||
			roll_wild_enc(
				k_wild_mons[locid][badge_ct].land_rate ) ==
				FALSE )
		{
			return FALSE;
		}

		/* Checks pass, try to generate a mon */
		if( try_gen_wildmon( locid,
			    badge_ct,
			    WILD_AREA_LAND,
			    WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE,
			    0 ) == TRUE )
		{
			BattleSetup_StartWildBattle( );
			return TRUE;
		}
	}
	else if( TILE_WATER_WILD_ENC( cur_mtbehav ) ||
		TILE_WATER_BRIDGE_WILD_ENC( cur_mtbehav ) )
	{
		if( cur_mtbehav != prev_mtbehav || is_sootopolis_warring( ) ||
			k_wild_mons[locid][badge_ct].water_rate == 0 ||
			roll_wild_enc(
				k_wild_mons[locid][badge_ct].land_rate ) ==
				FALSE )
		{
			return FALSE;
		}

		/* Checks pass, try to generate a mon */
		if( try_gen_wildmon( locid,
			    badge_ct,
			    WILD_AREA_WATER,
			    WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE,
			    0 ) == TRUE )
		{
			BattleSetup_StartWildBattle( );
			return TRUE;
		}
	}

	return FALSE;
}

void RockSmashWildEncounter( void )
{
	int locid;
	u8 badge_ct;

	badge_ct = count_badges( );
	locid    = get_cur_map_locid( );

	if( locid == -1 || k_wild_mons[locid][badge_ct].rock_rate == 0 ||
		roll_wild_enc( k_wild_mons[locid][badge_ct].rock_rate ) ==
			FALSE )
	{
		gSpecialVar_Result = FALSE;

		return;
	}

	/* Checks pass, try to generate a mon */
	if( try_gen_wildmon( locid,
		    badge_ct,
		    WILD_AREA_ROCKS,
		    WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE,
		    0 ) == TRUE )
	{
		BattleSetup_StartWildBattle( );
		gSpecialVar_Result = TRUE;

		return;
	}

	gSpecialVar_Result = FALSE;
}

bool8 SweetScentWildEncounter( void )
{
	s16 x, y;

	PlayerGetDestCoords( &x, &y );

	return StandardWildEncounter(
		MapGridGetMetatileBehaviorAt( x, y ), 0, 0 );
}

bool8 DoesCurrentMapHaveFishingMons( void )
{
	return k_wild_mons[get_cur_map_locid( )][count_badges( )].fish_rate ==
		0;
}

u16 GetLocalWildMon( bool8* is_water )
{
	int locid;
	u8 badge_ct;

	badge_ct = count_badges( );
	locid    = get_cur_map_locid( );

	if( locid == -1 )
	{
		return SPECIES_NONE;
	}

	if( ( Random( ) & 3 ) == 0 )
	{
		/* 25% chance of water mon */
		*is_water = TRUE;

		return k_wild_mons[locid][badge_ct]
			.water[get_wmon_index_water_rock( )]
			.species;
	}
	else
	{
		/* 75% chance of land mon */
		*is_water = FALSE;

		return k_wild_mons[locid][badge_ct]
			.land[get_wmon_index_land( )]
			.species;
	}
}

u16 GetLocalWaterMon( void )
{
	int locid;
	u8 badge_ct;

	badge_ct = count_badges( );
	locid    = get_cur_map_locid( );

	if( locid == -1 )
	{
		return SPECIES_NONE;
	}

	return k_wild_mons[locid][badge_ct]
		.water[get_wmon_index_water_rock( )]
		.species;
}

bool8 UpdateRepelCounter( void )
{
	u16 steps;

	if( InBattlePike( ) || InBattlePyramid( ) || InUnionRoom( ) == TRUE )
		return FALSE;

	steps = VarGet( VAR_REPEL_STEP_COUNT );

	if( steps != 0 )
	{
		steps--;
		VarSet( VAR_REPEL_STEP_COUNT, steps );
		if( steps == 0 )
		{
			ScriptContext1_SetupScript( EventScript_RepelWoreOff );
			return TRUE;
		}
	}
	return FALSE;
}

static bool8 IsWildLevelAllowedByRepel( u8 wildLevel )
{
	u8 i;

	if( !VarGet( VAR_REPEL_STEP_COUNT ) )
		return TRUE;

	for( i = 0; i < PARTY_SIZE; i++ )
	{
		if( GetMonData( &gPlayerParty[i], MON_DATA_HP ) &&
			!GetMonData( &gPlayerParty[i], MON_DATA_IS_EGG ) )
		{
			u8 ourLevel =
				GetMonData( &gPlayerParty[i], MON_DATA_LEVEL );

			if( wildLevel < ourLevel )
				return FALSE;
			else
				return TRUE;
		}
	}

	return FALSE;
}

static bool8 IsAbilityAllowingEncounter( u8 level )
{
	u8 ability;

	if( GetMonData( &gPlayerParty[0], MON_DATA_SANITY_IS_EGG ) )
		return TRUE;

	ability = GetMonAbility( &gPlayerParty[0] );
	if( ability == ABILITY_KEEN_EYE || ability == ABILITY_INTIMIDATE )
	{
		u8 playerMonLevel =
			GetMonData( &gPlayerParty[0], MON_DATA_LEVEL );
		if( playerMonLevel > 5 && level <= playerMonLevel - 5 &&
			!( Random( ) % 2 ) )
			return FALSE;
	}

	return TRUE;
}

static bool8 TryGetRandomWildMonIndexByType(
	const struct WildPokemon* wildMon, u8 type, u8 numMon, u8* monIndex )
{
	u8 validIndexes[numMon]; // variable length array, an interesting
				 // feature
	u8 i, validMonCount;
	u8 badge_ct = count_badges( );

	for( i = 0; i < numMon; i++ )
		validIndexes[i] = 0;

	for( validMonCount = 0, i = 0; i < numMon; i++ )
	{
		if( gBaseStats[wildMon[i].species].type1 == type ||
			gBaseStats[wildMon[i].species].type2 == type )
			validIndexes[validMonCount++] = i;
	}

	if( validMonCount == 0 || validMonCount == numMon )
		return FALSE;

	*monIndex = validIndexes[Random( ) % validMonCount];
	return TRUE;
}

static bool8 TryGetAbilityInfluencedWildMonIndex(
	const struct WildPokemon* wildMon, u8 type, u8 ability, u8* monIndex )
{
	if( GetMonData( &gPlayerParty[0], MON_DATA_SANITY_IS_EGG ) )
		return FALSE;
	else if( GetMonAbility( &gPlayerParty[0] ) != ability )
		return FALSE;
	else if( Random( ) % 2 != 0 )
		return FALSE;

	return TryGetRandomWildMonIndexByType(
		wildMon, type, LAND_WILD_COUNT, monIndex );
}

static void ApplyFluteEncounterRateMod( u32* encRate )
{
	if( FlagGet( FLAG_SYS_ENC_UP_ITEM ) == TRUE )
		*encRate += *encRate / 2;
	else if( FlagGet( FLAG_SYS_ENC_DOWN_ITEM ) == TRUE )
		*encRate = *encRate / 2;
}

static void ApplyCleanseTagEncounterRateMod( u32* encRate )
{
	if( GetMonData( &gPlayerParty[0], MON_DATA_HELD_ITEM ) ==
		ITEM_CLEANSE_TAG )
		*encRate = *encRate * 2 / 3;
}
