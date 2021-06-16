#ifndef GUARD_WILD_ENCOUNTER_H
#define GUARD_WILD_ENCOUNTER_H

#include "main_menu.h"

#define LAND_WILD_COUNT 12
#define WATER_WILD_COUNT 5
#define ROCK_WILD_COUNT 5
#define FISH_WILD_COUNT 10

struct WildPokemon
{
	u8 min;
	u8 max;
	u16 species;
};

struct WildPokemonInfo
{
	u8 encounterRate;
	const struct WildPokemon* wildPokemon;
};

struct WildPokemonHeader
{
	u8 mapGroup;
	u8 mapNum;
	const struct WildPokemonInfo* landMonsInfo;
	const struct WildPokemonInfo* waterMonsInfo;
	const struct WildPokemonInfo* rockSmashMonsInfo;
	const struct WildPokemonInfo* fishingMonsInfo;
};

void DisableWildEncounters( bool8 disabled );
bool8 StandardWildEncounter( u16, u16, u8 );
void ScrSpecial_RockSmashWildEncounter( void );
bool8 SweetScentWildEncounter( void );
bool8 DoesCurrentMapHaveFishingMons( void );
void FishingWildEncounter( u8 rod );
u16 GetLocalWildMon( bool8* isWaterMon );
u16 GetLocalWaterMon( void );
bool8 UpdateRepelCounter( void );

#endif // GUARD_WILD_ENCOUNTER_H
