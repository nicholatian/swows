@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@                              POKeMON SwowS!                              @@
@@                                                                          @@
@@                   Copyright (C) 2021 Alexander Nicholi                   @@
@@                       Released under BSD-0-Clause.                       @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.equ MUS_DUMMY, 0
.equ SE_KAIFUKU, 1 @ Healing Item
.equ SE_PC_LOGIN, 2 @ PC Logon
.equ SE_PC_OFF, 3 @ PC Shutdown
.equ SE_PC_ON, 4 @ PC Startup
.equ SE_SELECT, 5 @ Cursor Selection
.equ SE_WIN_OPEN, 6 @ Start Menu
.equ SE_WALL_HIT, 7 @ Wall Bump
.equ SE_DOOR, 8 @ Opening Door
.equ SE_KAIDAN, 9 @ Stairs
.equ SE_DANSA, 10 @ Ledge
.equ SE_JITENSYA, 11 @ Bicycle Bell
.equ SE_KOUKA_L, 12 @ Not Very Effective
.equ SE_KOUKA_M, 13 @ Normal Effectiveness
.equ SE_KOUKA_H, 14 @ Super Effective
.equ SE_BOWA2, 15 @ Pokémon Withdrawal
.equ SE_POKE_DEAD, 16 @ Pokémon Fainted
.equ SE_NIGERU, 17 @ Flee from Wild Battle
.equ SE_JIDO_DOA, 18 @ Pokémon Center Door
.equ SE_NAMINORI, 19 @ Briney's Ship
.equ SE_BAN, 20 @ Bang
.equ SE_PIN, 21 @ Exclamation Bubble
.equ SE_BOO, 22 @ Contest Jam
.equ SE_BOWA, 23 @ Giving Poké Ball to Nurse, Poké Ball Wiggle
.equ SE_JYUNI, 24 @ Places in Contest Appearing
.equ SE_A, 25 @ Bard A
.equ SE_I, 26 @ Bard I
.equ SE_U, 27 @ Bard U
.equ SE_E, 28 @ Bard E
.equ SE_O, 29 @ Bard O
.equ SE_N, 30 @ Bard N
.equ SE_SEIKAI, 31 @ Success
.equ SE_HAZURE, 32 @ Failure
.equ SE_EXP, 33 @ Exp. Bar
.equ SE_JITE_PYOKO, 34 @ Bunny Hop
.equ SE_MU_PACHI, 35
.equ SE_TK_KASYA, 36 @ Mossdeep Gym/Trick House Switch
.equ SE_FU_ZAKU, 37
.equ SE_FU_ZAKU2, 38
.equ SE_FU_ZUZUZU, 39 @ Lavaridge Gym Warp
.equ SE_RU_GASHIN, 40 @ Sootopolis Gym - Stairs Appear
.equ SE_RU_GASYAN, 41 @ Sootopolis Gym - Ice Breaking
.equ SE_RU_BARI, 42 @ Sootopolis Gym - Walking on Ice
.equ SE_RU_HYUU, 43 @ Falling Down
.equ SE_KI_GASYAN, 44
.equ SE_TK_WARPIN, 45 @ Warp In
.equ SE_TK_WARPOUT, 46 @ Warp Out
.equ SE_TU_SAA, 47 @ Repel
.equ SE_HI_TURUN, 48 @ Moving Obstacle in Fortree Gym
.equ SE_TRACK_MOVE, 49 @ Moving Truck
.equ SE_TRACK_STOP, 50 @ Moving Truck Stop
.equ SE_TRACK_HAIKI, 51 @ Moving Truck Unload
.equ SE_TRACK_DOOR, 52 @ Moving Truck Door
.equ SE_MOTER, 53
.equ SE_CARD, 54
.equ SE_SAVE, 55 @ Save
.equ SE_KON, 56 @ Poké Ball Bounce 1
.equ SE_KON2, 57 @ Poké Ball Bounce 2
.equ SE_KON3, 58 @ Poké Ball Bounce 3
.equ SE_KON4, 59 @ Poké Ball Bounce 4
.equ SE_SUIKOMU, 60 @ Poké Ball Trade
.equ SE_NAGERU, 61 @ Poké Ball Throw
.equ SE_TOY_C, 62 @ Note C
.equ SE_TOY_D, 63 @ Note D
.equ SE_TOY_E, 64 @ Note E
.equ SE_TOY_F, 65 @ Note F
.equ SE_TOY_G, 66 @ Note G
.equ SE_TOY_A, 67 @ Note A
.equ SE_TOY_B, 68 @ Note B
.equ SE_TOY_C1, 69 @ Note High C
.equ SE_MIZU, 70 @ Puddle
.equ SE_HASHI, 71 @ Boardwalk
.equ SE_DAUGI, 72 @ Slots Credits
.equ SE_PINPON, 73 @ Ding-dong!
.equ SE_FUUSEN1, 74 @ Red Balloon
.equ SE_FUUSEN2, 75 @ Blue Balloon
.equ SE_FUUSEN3, 76 @ Yellow Balloon
.equ SE_TOY_KABE, 77 @ Breakable Door
.equ SE_TOY_DANGO, 78 @ Mud Ball
.equ SE_DOKU, 79 @ Overworld Poison Damage
.equ SE_ESUKA, 80 @ Escalator
.equ SE_T_AME, 81 @ Rain
.equ SE_T_AME_E, 82 @ Rain Stop
.equ SE_T_OOAME, 83 @ Heavy Rain
.equ SE_T_OOAME_E, 84 @ Heavy Rain Stop
.equ SE_T_KOAME, 85 @ Light Rain
.equ SE_T_KOAME_E, 86 @ Light Rain Stop
.equ SE_T_KAMI, 87 @ Thunder
.equ SE_T_KAMI2, 88 @ Thunder 2
.equ SE_ELEBETA, 89 @ Elevator
.equ SE_HINSI, 90 @ Low Health
.equ SE_EXPMAX, 91 @ Exp. Max
.equ SE_TAMAKORO, 92 @ Roulette Ball
.equ SE_TAMAKORO_E, 93 @ Roulette Ball 2
.equ SE_BASABASA, 94
.equ SE_REGI, 95 @ Cash Register
.equ SE_C_GAJI, 96 @ Contest Hearts
.equ SE_C_MAKU_U, 97 @ Contest Curtain rise
.equ SE_C_MAKU_D, 98 @ Contest Curtain fall
.equ SE_C_PASI, 99
.equ SE_C_SYU, 100
.equ SE_C_PIKON, 101 @ Pokémon Appears in Contest
.equ SE_REAPOKE, 102 @ Shiny Pokémon
.equ SE_OP_BASYU, 103 @ Opening Movie -> Title Screen whoosh
.equ SE_BT_START, 104 @ Battle Mugshot whoosh
.equ SE_DENDOU, 105 @ Audience Cheering
.equ SE_JIHANKI, 106 @ Vending Machine
.equ SE_TAMA, 107 @ Orb Used
.equ SE_Z_SCROLL, 108 @ Pokédex Scrolling
.equ SE_Z_PAGE, 109 @ Pokédex Page
.equ SE_PN_ON, 110 @ PokéNav On
.equ SE_PN_OFF, 111 @ PokéNav Off
.equ SE_Z_SEARCH, 112 @ Pokédex Search
.equ SE_TAMAGO, 113 @ Egg hatch
.equ SE_TB_START, 114 @ Battle - Poké Ball Tray slide in
.equ SE_TB_KON, 115 @ Battle - Poké Ball Tray ball sound
.equ SE_TB_KARA, 116 @ Battle - Poké Ball Tray slide out
.equ SE_BIDORO, 117
.equ SE_W085, 118 @ Thunderbolt
.equ SE_W085B, 119 @ Thunderbolt 2
.equ SE_W231, 120 @ Harden
.equ SE_W171, 121 @ Nightmare
.equ SE_W233, 122 @ Vital Throw
.equ SE_W233B, 123 @ Vital Throw 2
.equ SE_W145, 124 @ Bubble
.equ SE_W145B, 125 @ Bubble 2
.equ SE_W145C, 126 @ Bubble 3
.equ SE_W240, 127 @ Rain Dance
.equ SE_W015, 128 @ Cut
.equ SE_W081, 129 @ String Shot
.equ SE_W081B, 130 @ String Shot 2
.equ SE_W088, 131 @ Rock Throw
.equ SE_W016, 132 @ Gust
.equ SE_W016B, 133 @ Gust 2
.equ SE_W003, 134 @ DoubleSlap
.equ SE_W104, 135 @ Double Team
.equ SE_W013, 136 @ Razor Wind
.equ SE_W196, 137 @ Icy Wind
.equ SE_W086, 138 @ Thunder Wave
.equ SE_W004, 139 @ Comet Punch
.equ SE_W025, 140 @ Mega Kick
.equ SE_W025B, 141 @ Mega Kick 2
.equ SE_W152, 142 @ Crabhammer
.equ SE_W026, 143 @ Jump Kick
.equ SE_W172, 144 @ Flame Wheel
.equ SE_W172B, 145 @ Flame Wheel 2
.equ SE_W053, 146 @ Flamethrower
.equ SE_W007, 147 @ Fire Punch
.equ SE_W092, 148 @ Toxic
.equ SE_W221, 149 @ Sacred Fire
.equ SE_W221B, 150 @ Sacred Fire 2
.equ SE_W052, 151 @ Ember
.equ SE_W036, 152 @ Take Down
.equ SE_W059, 153 @ Blizzard
.equ SE_W059B, 154 @ Blizzard 2
.equ SE_W010, 155 @ Scratch
.equ SE_W011, 156 @ Vicegrip
.equ SE_W017, 157 @ Wing Attack
.equ SE_W019, 158 @ Fly
.equ SE_W028, 159 @ Sand-Attack
.equ SE_W013B, 160 @ Razor Wind 2
.equ SE_W044, 161 @ Bite
.equ SE_W029, 162 @ Headbutt
.equ SE_W057, 163 @ Surf
.equ SE_W056, 164 @ Hydro Pump
.equ SE_W250, 165 @ Whirlpool
.equ SE_W030, 166 @ Horn Attack
.equ SE_W039, 167 @ Tail Whip
.equ SE_W054, 168 @ Mist
.equ SE_W077, 169 @ PoisonPowder
.equ SE_W020, 170 @ Bind
.equ SE_W082, 171 @ Dragon Rage
.equ SE_W047, 172 @ Sing
.equ SE_W195, 173 @ Perish Song
.equ SE_W006, 174 @ Pay Day
.equ SE_W091, 175 @ Dig
.equ SE_W146, 176 @ Dizzy Punch
.equ SE_W120, 177 @ Self-Destruct
.equ SE_W153, 178 @ Explosion
.equ SE_W071B, 179 @ Absorb 2
.equ SE_W071, 180 @ Absorb
.equ SE_W103, 181 @ Screech
.equ SE_W062, 182 @ BubbleBeam
.equ SE_W062B, 183 @ BubbleBeam 2
.equ SE_W048, 184 @ Supersonic
.equ SE_W187, 185 @ Belly Drum
.equ SE_W118, 186 @ Metronome
.equ SE_W155, 187 @ Bonemerang
.equ SE_W122, 188 @ Lick
.equ SE_W060, 189 @ Psybeam
.equ SE_W185, 190 @ Faint Attack
.equ SE_W014, 191 @ Swords Dance
.equ SE_W043, 192 @ Leer
.equ SE_W207, 193 @ Swagger
.equ SE_W207B, 194 @ Swagger 2
.equ SE_W215, 195 @ Heal Bell
.equ SE_W109, 196 @ Confuse Ray
.equ SE_W173, 197 @ Snore
.equ SE_W280, 198 @ Brick Break
.equ SE_W202, 199 @ Giga Drain
.equ SE_W060B, 200 @ Psybeam 2
.equ SE_W076, 201 @ SolarBeam
.equ SE_W080, 202 @ Petal Dance
.equ SE_W100, 203 @ Teleport
.equ SE_W107, 204 @ Minimize
.equ SE_W166, 205 @ Sketch
.equ SE_W129, 206 @ Swift
.equ SE_W115, 207 @ Reflect
.equ SE_W112, 208 @ Barrier
.equ SE_W197, 209 @ Detect
.equ SE_W199, 210 @ Lock-On
.equ SE_W236, 211 @ Moonlight
.equ SE_W204, 212 @ Charm
.equ SE_W268, 213 @ Charge
.equ SE_W070, 214 @ Strength
.equ SE_W063, 215 @ Hyper Beam
.equ SE_W127, 216 @ Waterfall
.equ SE_W179, 217 @ Reversal
.equ SE_W151, 218 @ Acid Armor
.equ SE_W201, 219 @ Sandstorm
.equ SE_W161, 220 @ Tri-Attack
.equ SE_W161B, 221 @ Tri-Attack 2
.equ SE_W227, 222 @ Encore
.equ SE_W227B, 223 @ Encore 2
.equ SE_W226, 224 @ Baton Pass
.equ SE_W208, 225 @ Milk Drink
.equ SE_W213, 226 @ Attract
.equ SE_W213B, 227 @ Attract 2
.equ SE_W234, 228 @ Morning Sun
.equ SE_W260, 229 @ Flatter
.equ SE_W328, 230 @ Sand Tomb
.equ SE_W320, 231 @ GrassWhistle
.equ SE_W255, 232 @ Spit Up
.equ SE_W291, 233 @ Dive
.equ SE_W089, 234 @ Earthquake
.equ SE_W239, 235 @ Twister
.equ SE_W230, 236 @ Sweet Scent
.equ SE_W281, 237 @ Yawn
.equ SE_W327, 238 @ Sky Uppercut
.equ SE_W287, 239 @ Stat Increased
.equ SE_W257, 240 @ Heat Wave
.equ SE_W253, 241 @ Uproar
.equ SE_W258, 242 @ Hail
.equ SE_W322, 243 @ Cosmic Power
.equ SE_W298, 244 @ Teeter Dance
.equ SE_W287B, 245 @ Stat Decreased
.equ SE_W114, 246 @ Haze
.equ SE_W063B, 247 @ Hyper Beam 2

@ FRLG SFX below

.equ SE_RG_W_DOOR, 248 @ Door
.equ SE_RG_CARD1, 249 @ Trainer Card 1
.equ SE_RG_CARD2, 250 @ Trainer Card 2
.equ SE_RG_CARD3, 251 @ Trainer Card 3
.equ SE_RG_BAG1, 252 @ Bag Scroll
.equ SE_RG_BAG2, 253 @ Bag Pocket Change
.equ SE_RG_GETTING, 254
.equ SE_RG_SHOP, 255 @ Cash Register
.equ SE_RG_KITEKI, 256 @ S.S. Anne Horn
.equ SE_RG_HELP_OP, 257 @ Help Menu Open
.equ SE_RG_HELP_CL, 258 @ Help Menu Close
.equ SE_RG_HELP_NG, 259 @ Help Menu Error
.equ SE_RG_DEOMOV, 260 @ Deoxys Moves
.equ SE_RG_EXCELLENT, 261
.equ SE_RG_NAWAMISS, 262

@ end FRLG SFX

.equ SE_TOREEYE, 263 @ Trainer's Eye Call
.equ SE_TOREOFF, 264 @ Trainer's Eye Hang Up
.equ SE_HANTEI1, 265 @ Battle Arena Time's Up 1
.equ SE_HANTEI2, 266 @ Battle Arena Time's Up 2
.equ SE_CURTAIN, 267 @ Battle Pike Curtain Open
.equ SE_CURTAIN1, 268 @ Battle Pike Curtain Close
.equ SE_USSOKI, 269 @ Sudowoodo

@ begin MUSIC

.equ MUS_TETSUJI, 350 @ Littleroot Town Test 'TETSUJI'
.equ MUS_FIELD13, 351 @ GSC - Route 38
.equ MUS_KACHI22, 352 @ Wild Pokémon Defeated
.equ MUS_KACHI2, 353 @ Wild Pokémon Defeated with Intro
.equ MUS_KACHI3, 354 @ Gym Leader Defeated
.equ MUS_KACHI5, 355 @ Victory! Elite Four
.equ MUS_PCC, 356 @ Crystal - Pokémon Communication Center
.equ MUS_NIBI, 357 @ GSC - Viridian/Saffron/Pewter/etc
.equ MUS_SUIKUN, 358 @ Crystal - Battle! Legendary Beasts
.equ MUS_DOORO1, 359 @ Route 101
.equ MUS_DOORO_X1, 360 @ Route 110
.equ MUS_DOORO_X3, 361 @ Route 120
.equ MUS_MACHI_S2, 362 @ Petalburg City
.equ MUS_MACHI_S4, 363 @ Oldale/Lavaridge Town
.equ MUS_GIM, 364 @ Gym
.equ MUS_NAMINORI, 365 @ Surfing
.equ MUS_DAN01, 366 @ Caves and Darkness
.equ MUS_FANFA1, 367 @ Level Up!
.equ MUS_ME_ASA, 368 @ Pokémon Healed
.equ MUS_ME_BACHI, 369 @ Obtained a Badge!
.equ MUS_FANFA4, 370 @ Obtained an Item!
.equ MUS_FANFA5, 371 @ Your Pokémon Just Evolved!
.equ MUS_ME_WAZA, 372 @ Obtained a TM/HM!
.equ MUS_BIJYUTU, 373 @ Lilycove Museum
.equ MUS_DOORO_X4, 374 @ Route 122/Intro
.equ MUS_FUNE_KAN, 375 @ Slateport Museum
.equ MUS_ME_SHINKA, 376 @ Evolution Intro
.equ MUS_SHINKA, 377 @ Evolution
.equ MUS_ME_WASURE, 378 @ Move Deleted/Messed Up Appeal
.equ MUS_SYOUJOEYE, 379 @ Encounter! Tuber
.equ MUS_BOYEYE, 380 @ Encounter! Boy
.equ MUS_DAN02, 381 @ Abandoned Ship/Southern Island
.equ MUS_MACHI_S3, 382 @ Fortree City/Pacifidlog Town
.equ MUS_ODAMAKI, 383 @ Professor Birch's Lab
.equ MUS_B_TOWER, 384 @ Battle Tower (RS)
.equ MUS_SWIMEYE, 385 @ Encounter! Swimmer
.equ MUS_DAN03, 386 @ Meteor Falls/Cave of Origin
.equ MUS_ME_KINOMI, 387 @ Obtained a Berry!
.equ MUS_ME_TAMA, 388 @ Awakening the Super-Ancient Pokémon
.equ MUS_ME_B_BIG, 389 @ Slots Jackpot!
.equ MUS_ME_B_SMALL, 390 @ Slots Victory!
.equ MUS_ME_ZANNEN, 391 @ Too bad!
.equ MUS_BD_TIME, 392 @ Roulette!
.equ MUS_TEST1, 393 @ Contest Test 1
.equ MUS_TEST2, 394 @ Contest Test 2
.equ MUS_TEST3, 395 @ Contest Test 3
.equ MUS_TEST4, 396 @ Contest Test 4
.equ MUS_TEST, 397 @ Encounter! Gentleman
.equ MUS_GOMACHI0, 398 @ Verdanturf Town
.equ MUS_GOTOWN, 399 @ Rustboro/Mauville/Mossdeep City
.equ MUS_POKECEN, 400 @ Pokémon Center
.equ MUS_NEXTROAD, 401 @ Route 104
.equ MUS_GRANROAD, 402 @ Route 119
.equ MUS_CYCLING, 403 @ Cycling
.equ MUS_FRIENDLY, 404 @ Pokémart
.equ MUS_MISHIRO, 405 @ Littleroot Town
.equ MUS_TOZAN, 406 @ Sky Pillar
.equ MUS_GIRLEYE, 407 @ Encounter! Girl
.equ MUS_MINAMO, 408 @ Lilycove City
.equ MUS_ASHROAD, 409 @ Route 111
.equ MUS_EVENT0, 410 @ Help me!
.equ MUS_DEEPDEEP, 411 @ Underwater
.equ MUS_KACHI1, 412 @ Victory! Trainer
.equ MUS_TITLE3, 413 @ Title Screen
.equ MUS_DEMO1, 414 @ Opening Movie
.equ MUS_GIRL_SUP, 415 @ Encounter! May
.equ MUS_HAGESHII, 416 @ Encounter! Biker
.equ MUS_KAKKOII, 417 @ Encounter! Electric Trainer
.equ MUS_KAZANBAI, 418 @ Route 113
.equ MUS_AQA_0, 419 @ Encounter! Team Aqua
.equ MUS_TSURETEK, 420 @ Follow Me!
.equ MUS_BOY_SUP, 421 @ Encounter! Brendan
.equ MUS_RAINBOW, 422 @ Ever Grande City
.equ MUS_AYASII, 423 @ Encounter! Psychic
.equ MUS_KACHI4, 424 @ Victory! Aqua/Magma Grunt
.equ MUS_ROPEWAY, 425 @ Cable Car
.equ MUS_CASINO, 426 @ Game Corner
.equ MUS_HIGHTOWN, 427 @ Dewford Town
.equ MUS_SAFARI, 428 @ Safari Zone
.equ MUS_C_ROAD, 429 @ Victory Road
.equ MUS_AJITO, 430 @ Aqua/Magma Hideout
.equ MUS_M_BOAT, 431 @ Sailing
.equ MUS_M_DUNGON, 432 @ Mt. Pyre (Inside)
.equ MUS_FINECITY, 433 @ Slateport City
.equ MUS_MACHUPI, 434 @ Mt. Pyre (Outside)
.equ MUS_P_SCHOOL, 435 @ Pokémon Trainer's School
.equ MUS_DENDOU, 436 @ You're the Champion!
.equ MUS_TONEKUSA, 437 @ Fallarbor Town
.equ MUS_MABOROSI, 438 @ Sealed Chamber
.equ MUS_CON_FAN, 439 @ Obtained a Contest Ribbon!
.equ MUS_CONTEST0, 440 @ Pokémon Contest
.equ MUS_MGM0, 441 @ Encounter! Team Magma
.equ MUS_T_BATTLE, 442 @ Opening Battle
.equ MUS_OOAME, 443 @ The Flood
.equ MUS_HIDERI, 444 @ The Drought
.equ MUS_RUNECITY, 445 @ Sootopolis City
.equ MUS_CON_K, 446 @ Contest/Berry Blending Results
.equ MUS_EIKOU_R, 447 @ Hall of Fame
.equ MUS_KARAKURI, 448 @ Trick House
.equ MUS_HUTAGO, 449 @ Encounter! Kid
.equ MUS_SITENNOU, 450 @ Encounter! Elite Four
.equ MUS_YAMA_EYE, 451 @ Encounter! Hiker
.equ MUS_CONLOBBY, 452 @ Contest Lobby
.equ MUS_INTER_V, 453 @ Encounter! Gabby and Ty
.equ MUS_DAIGO, 454 @ Encounter! Wallace
.equ MUS_THANKFOR, 455 @ Credits
.equ MUS_END, 456 @ The End
.equ MUS_B_FRONTIER, 457 @ Battle Frontier
.equ MUS_B_ARENA, 458 @ Battle Arena
.equ MUS_ME_POINTGET, 459 @ Obtained Battle Points!
.equ MUS_ME_TORE_EYE, 460 @ Registered Trainer!
.equ MUS_PYRAMID, 461 @ Battle Pyramid
.equ MUS_PYRAMID_TOP, 462 @ Top of the Battle Pyramid
.equ MUS_B_PALACE, 463 @ Battle Palace
.equ MUS_REKKUU_KOURIN, 464 @ Rayquaza Enters
.equ MUS_SATTOWER, 465 @ Battle Tower (Emerald)
.equ MUS_ME_SYMBOLGET, 466 @ Obtained a Frontier Symbol!
.equ MUS_B_DOME, 467 @ Battle Dome
.equ MUS_B_TUBE, 468 @ Battle Pike
.equ MUS_B_FACTORY, 469 @ Battle Factory
.equ MUS_VS_REKKU, 470 @ Battle! Legendary Pokémon
.equ MUS_VS_FRONT, 471 @ Battle! Frontier Brain
.equ MUS_VS_MEW, 472 @ Battle! Mew
.equ MUS_B_DOME1, 473 @ Battle Dome Lobby
.equ MUS_BATTLE27, 474 @ Battle! Wild Pokémon
.equ MUS_BATTLE31, 475 @ Battle! Team Aqua/Magma
.equ MUS_BATTLE20, 476 @ Battle! Trainer
.equ MUS_BATTLE32, 477 @ Battle! Gym Leader
.equ MUS_BATTLE33, 478 @ Battle! Champion
.equ MUS_BATTLE36, 479 @ Battle! Regi Trio
.equ MUS_BATTLE34, 480 @ Battle! Legendary Pokémon (dupe)
.equ MUS_BATTLE35, 481 @ Battle! Rival
.equ MUS_BATTLE38, 482 @ Battle! Elite Four
.equ MUS_BATTLE30, 483 @ Battle! Archie/Maxie

@ FRLG Music Below

.equ MUS_RG_ANNAI, 484 @ Follow Me!
.equ MUS_RG_SLOT, 485 @ Game Corner
.equ MUS_RG_AJITO, 486 @ Rocket Hideout
.equ MUS_RG_GYM, 487 @ Gym
.equ MUS_RG_PURIN, 488 @ Jigglypuff's Song
.equ MUS_RG_DEMO, 489 @ Opening Movie
.equ MUS_RG_TITLE, 490 @ Title Screen
.equ MUS_RG_GUREN, 491 @ Cinnabar Island
.equ MUS_RG_SHION, 492 @ Lavender Town
.equ MUS_RG_KAIHUKU, 493 @ RBY Pokémon Center Healing
.equ MUS_RG_CYCLING, 494 @ Cycling
.equ MUS_RG_ROCKET, 495 @ Encounter! Team Rocket
.equ MUS_RG_SHOUJO, 496 @ Encounter! Girl
.equ MUS_RG_SHOUNEN, 497 @ Encounter! Boy
.equ MUS_RG_DENDOU, 498 @ You're the Champion!
.equ MUS_RG_T_MORI, 499 @ Viridian Forest
.equ MUS_RG_OTSUKIMI, 500 @ Mt. Moon
.equ MUS_RG_POKEYASHI, 501 @ Pokémon Mansion
.equ MUS_RG_ENDING, 502 @ Credits
.equ MUS_RG_LOAD01, 503 @ Route 1
.equ MUS_RG_OPENING, 504 @ Route 24/Intro
.equ MUS_RG_LOAD02, 505 @ Route 3
.equ MUS_RG_LOAD03, 506 @ Route 11
.equ MUS_RG_CHAMP_R, 507 @ Victory Road/Indigo Plateau
.equ MUS_RG_VS_GYM, 508 @ Battle! Gym Leader/Elite Four
.equ MUS_RG_VS_TORE, 509 @ Battle! Trainer
.equ MUS_RG_VS_YASEI, 510 @ Battle! Wild Pokémon
.equ MUS_RG_VS_LAST, 511 @ Battle! Champion
.equ MUS_RG_MASARA, 512 @ Pallet Town
.equ MUS_RG_KENKYU, 513 @ Professor Oak's Lab
.equ MUS_RG_OHKIDO, 514 @ Professor Oak's Theme
.equ MUS_RG_POKECEN, 515 @ Pokémon Center
.equ MUS_RG_SANTOAN, 516 @ S.S. Anne
.equ MUS_RG_NAMINORI, 517 @ Surfing
.equ MUS_RG_P_TOWER, 518 @ Pokémon Tower
.equ MUS_RG_SHIRUHU, 519 @ Silph Co.
.equ MUS_RG_HANADA, 520 @ Cerulean/Fuschia City
.equ MUS_RG_TAMAMUSI, 521 @ Celadon City
.equ MUS_RG_WIN_TRE, 522 @ Victory! Trainer
.equ MUS_RG_WIN_YASEI, 523 @ Victory! Wild Pokémon
.equ MUS_RG_WIN_GYM, 524 @ Victory! Gym Leader
.equ MUS_RG_KUCHIBA, 525 @ Vermillion City
.equ MUS_RG_NIBI, 526 @ Viridian/Saffron/Pewter City
.equ MUS_RG_RIVAL1, 527 @ Encounter! Rival
.equ MUS_RG_RIVAL2, 528 @ Rival's Exit
.equ MUS_RG_FAN2, 529 @ Fanfare 2
.equ MUS_RG_FAN5, 530 @ Obtained a Starter!
.equ MUS_RG_FAN6, 531 @ Pokémon Caught! (Used in Emerald)
.equ MUS_ME_RG_PHOTO, 532 @ Trainer Photo
.equ MUS_RG_TITLEROG, 533 @ Game Freak
.equ MUS_RG_GET_YASEI, 534 @ Pokémon Caught Victory Theme
.equ MUS_RG_SOUSA, 535 @ Starting Tutorial
.equ MUS_RG_SEKAIKAN, 536 @ Starting Tutorial 2
.equ MUS_RG_SEIBETU, 537 @ Starting Tutorial 3
.equ MUS_RG_JUMP, 538 @ Pokemon Jump Minigame
.equ MUS_RG_UNION, 539 @ Union Room
.equ MUS_RG_NETWORK, 540 @ Network Center
.equ MUS_RG_OKURIMONO, 541 @ Mystery Gift
.equ MUS_RG_KINOMIKUI, 542 @ Dodrio Berry Picking
.equ MUS_RG_NANADUNGEON, 543 @ Sevii Caves/Altering Cave (Mt. Moon)
.equ MUS_RG_OSHIE_TV, 544 @ Follow Me!
.equ MUS_RG_NANASHIMA, 545 @ Sevii Islands Routes (Lake of Rage)
.equ MUS_RG_NANAISEKI, 546 @ Sevii Forests (Viridian Forest)
.equ MUS_RG_NANA123, 547 @ Sevii Islands 1-3 (Viridian/Saffron/Pewter)
.equ MUS_RG_NANA45, 548 @ Sevii Islands 4-5 (Azalea Town)
.equ MUS_RG_NANA67, 549 @ Sevii Islands 6-7 (Violet City)
.equ MUS_RG_POKEFUE, 550 @ Poké Flute
.equ MUS_RG_VS_DEO, 551 @ Battle! Deoxys
.equ MUS_RG_VS_MYU2, 552 @ Battle! Mewtwo
.equ MUS_RG_VS_DEN, 553 @ Battle! Legendary Birds
.equ MUS_RG_EXEYE, 554 @ Encounter! Gym Leader
.equ MUS_RG_DEOEYE, 555 @ Encounter! Deoxys
.equ MUS_RG_T_TOWER, 556 @ Trainer Tower (Gym)
.equ MUS_RG_SLOWMASARA, 557 @ Pallet Town (Hall of Fame remix)
.equ MUS_RG_TVNOIZE, 558 @ Teachy TV
.equ PH_TRAP_BLEND, 559
.equ PH_TRAP_HELD, 560
.equ PH_TRAP_SOLO, 561
.equ PH_FACE_BLEND, 562
.equ PH_FACE_HELD, 563
.equ PH_FACE_SOLO, 564
.equ PH_CLOTH_BLEND, 565
.equ PH_CLOTH_HELD, 566
.equ PH_CLOTH_SOLO, 567
.equ PH_DRESS_BLEND, 568
.equ PH_DRESS_HELD, 569
.equ PH_DRESS_SOLO, 570
.equ PH_FLEECE_BLEND, 571
.equ PH_FLEECE_HELD, 572
.equ PH_FLEECE_SOLO, 573
.equ PH_KIT_BLEND, 574
.equ PH_KIT_HELD, 575
.equ PH_KIT_SOLO, 576
.equ PH_PRICE_BLEND, 577
.equ PH_PRICE_HELD, 578
.equ PH_PRICE_SOLO, 579
.equ PH_LOT_BLEND, 580
.equ PH_LOT_HELD, 581
.equ PH_LOT_SOLO, 582
.equ PH_GOAT_BLEND, 583
.equ PH_GOAT_HELD, 584
.equ PH_GOAT_SOLO, 585
.equ PH_THOUGHT_BLEND, 586
.equ PH_THOUGHT_HELD, 587
.equ PH_THOUGHT_SOLO, 588
.equ PH_CHOICE_BLEND, 589
.equ PH_CHOICE_HELD, 590
.equ PH_CHOICE_SOLO, 591
.equ PH_MOUTH_BLEND, 592
.equ PH_MOUTH_HELD, 593
.equ PH_MOUTH_SOLO, 594
.equ PH_FOOT_BLEND, 595
.equ PH_FOOT_HELD, 596
.equ PH_FOOT_SOLO, 597
.equ PH_GOOSE_BLEND, 598
.equ PH_GOOSE_HELD, 599
.equ PH_GOOSE_SOLO, 600
.equ PH_STRUT_BLEND, 601
.equ PH_STRUT_HELD, 602
.equ PH_STRUT_SOLO, 603
.equ PH_CURE_BLEND, 604
.equ PH_CURE_HELD, 605
.equ PH_CURE_SOLO, 606
.equ PH_NURSE_BLEND, 607
.equ PH_NURSE_HELD, 608
.equ PH_NURSE_SOLO, 609

@ map is split into 2 music sections
@ controlled by GetCurrLocationDefaultMusic().

.equ MUS_ROUTE_118, 0x7FFF

.equ MUS_NONE, 0xFFFF
