/****************************************************************************\
 *                              POKeMON SwowS!                              *
 *                                                                          *
 *                   Copyright (C) 2021 Alexander Nicholi                   *
 *                       Released under BSD-0-Clause.                       *
\****************************************************************************/

#ifndef INC__SWOWS_SAVBLOCK_H
#define INC__SWOWS_SAVBLOCK_H

#include "types.h"

#define SAVBLOCK2PTR 0x3005D90

#if 0
struct SaveBlock2
{
    /*0x00*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
    /*0x08*/ u8 playerGender; // MALE, FEMALE
    /*0x09*/ u8 specialSaveWarpFlags;
    /*0x0A*/ u8 playerTrainerId[TRAINER_ID_LENGTH];
    /*0x0E*/ u16 playTimeHours;
    /*0x10*/ u8 playTimeMinutes;
    /*0x11*/ u8 playTimeSeconds;
    /*0x12*/ u8 playTimeVBlanks;
    /*0x13*/ u8 optionsButtonMode;  // OPTIONS_BUTTON_MODE_[NORMAL/LR/L_EQUALS_A]
    /*0x14*/ u16 optionsTextSpeed:3; // OPTIONS_TEXT_SPEED_[SLOW/MID/FAST]
             u16 optionsWindowFrameType:5; // Specifies one of the 20 decorative borders for text boxes
             u16 optionsSound:1; // OPTIONS_SOUND_[MONO/STEREO]
             u16 optionsBattleStyle:1; // OPTIONS_BATTLE_STYLE_[SHIFT/SET]
             u16 optionsBattleSceneOff:1; // whether battle animations are disabled
             u16 regionMapZoom:1; // whether the map is zoomed in
    /*0x18*/ struct Pokedex pokedex;
    /*0x90*/ u8 filler_90[0x8];
    /*0x98*/ struct Time localTimeOffset;
    /*0xA0*/ struct Time lastBerryTreeUpdate;
    /*0xA8*/ u32 field_A8; // Written to, but never read.
    /*0xAC*/ u32 encryptionKey;
    /*0xB0*/ struct PlayersApprentice playerApprentice;
    /*0xDC*/ struct Apprentice apprentices[4]; // From record mixing.
    /*0x1EC*/ struct BerryCrush berryCrush;
    /*0x1FC*/ struct PokemonJumpResults pokeJump;
    /*0x20C*/ struct BerryPickingResults berryPick;
    /*0x21C*/ struct RankingHall1P hallRecords1P[HALL_FACILITIES_COUNT][2][3]; // From record mixing.
    /*0x57C*/ struct RankingHall2P hallRecords2P[2][3]; // From record mixing.
    /*0x624*/ u16 contestLinkResults[5][4]; // 4 positions for 5 categories.
    /*0x64C*/ struct BattleFrontier frontier;
}; // sizeof=0xF2C
#endif /* 0 */

#endif /* INC__SWOWS_SAVBLOCK_H */
