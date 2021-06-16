#include "global.h"
#include "strings.h"

ALIGNED( 4 )
const u8 gExpandedPlaceholder_Empty[]    = _( "" );
const u8 gExpandedPlaceholder_Kun[]      = _( "" );
const u8 gExpandedPlaceholder_Chan[]     = _( "" );
const u8 gExpandedPlaceholder_Sapphire[] = _( "SAPPHIRE" );
const u8 gExpandedPlaceholder_Ruby[]     = _( "RUBY" );
const u8 gExpandedPlaceholder_Emerald[]  = _( "EMERALD" );
const u8 gExpandedPlaceholder_Aqua[]     = _( "AQUA" );
const u8 gExpandedPlaceholder_Magma[]    = _( "MAGMA" );
const u8 gExpandedPlaceholder_Archie[]   = _( "ARCHIE" );
const u8 gExpandedPlaceholder_Maxie[]    = _( "MAXIE" );
const u8 gExpandedPlaceholder_Kyogre[]   = _( "KYOGRE" );
const u8 gExpandedPlaceholder_Groudon[]  = _( "GROUDON" );
const u8 gExpandedPlaceholder_Brendan[]  = _( "BRENDAN" );
const u8 gExpandedPlaceholder_May[]      = _( "MAY" );
const u8 gText_EggNickname[]             = _( "EGG" );
const u8 gText_Pokemon[]                 = _( "POKéMON" );
const u8 gProfBirchMatchCallName[]       = _( "PROF. BIRCH" );
const u8 gText_MainMenuNewGame[]         = _( "NEW GAME" );
const u8 gText_MainMenuContinue[]        = _( "CONTINUE" );
const u8 gText_MainMenuOption[]          = _( "OPTION" );
const u8 gText_MainMenuMysteryGift[]     = _( "MYSTERY GIFT" );
const u8 gText_MainMenuMysteryGift2[]    = _( "MYSTERY GIFT" );
const u8 gText_MainMenuMysteryEvents[]   = _( "MYSTERY EVENTS" );
const u8 gText_WirelessNotConnected[] =
	_( "The Wireless Adapter is not\nconnected." );
const u8 gText_MysteryGiftCantUse[] = _(
	"MYSTERY GIFT can't be used while\nthe Wireless Adapter is attached." );
const u8 gText_MysteryEventsCantUse[] = _(
	"MYSTERY EVENTS can't be used while\nthe Wireless Adapter is attached." );
const u8 gUnknown_085E836D[] =
	_( "Updating save file using external\ndata. Please wait." );
const u8 gUnknown_085E83A2[]       = _( "The save file has been updated." );
const u8 gText_SaveFileCorrupted[] = _(
	"The save file is corrupted. The\nprevious save file will be loaded." );
const u8 gText_SaveFileErased[] =
	_( "The save file has been erased\ndue to corruption or damage." );
const u8 gJPText_No1MSubCircuit[] = _( "1Mサブきばんが ささっていません！" );
const u8 gText_BatteryRunDry[] = _(
	"The internal battery has run dry.\nThe game can be played.\pHowever, clock-based events will\nno longer occur." );
const u8 gUnknown_085E84BF[]  = _( "PLAYER" );
const u8 gUnknown_085E84C6[]  = _( "POKéDEX" );
const u8 gText_MainMenuTime[] = _( "TIME" );
const u8 gUnknown_085E84D3[]  = _( "BADGES" );
const u8 gUnknown_085E84DA[]  = _( "A Button" );
const u8 gUnknown_085E84E3[]  = _( "B Button" );
const u8 gUnknown_085E84EC[]  = _( "R Button" );
const u8 gUnknown_085E84F5[]  = _( "L Button" );
const u8 gUnknown_085E84FE[]  = _( "START" );
const u8 gUnknown_085E8504[]  = _( "SELECT" );
const u8 gUnknown_085E850B[]  = _( "+ Control Pad" );
const u8 gUnknown_085E8519[]  = _( "L Button  R Button" );
const u8 gUnknown_085E852C[]  = _( "CONTROLS" );
ALIGNED( 4 )
const u8 gUnknown_085E8538[] = _( "{DPAD_UPDOWN}PICK {A_BUTTON}OK" );
ALIGNED( 4 ) const u8 gUnknown_085E8544[] = _( "{A_BUTTON}NEXT" );
ALIGNED( 4 )
const u8 gUnknown_085E854C[] = _( "{A_BUTTON}NEXT {B_BUTTON}BACK" );
ALIGNED( 4 )
const u8 gText_PickNextCancel[] =
	_( "{DPAD_UPDOWN}PICK {A_BUTTON}NEXT {B_BUTTON}CANCEL" );
ALIGNED( 4 )
const u8 gText_PickCancel[] =
	_( "{DPAD_UPDOWN}PICK {A_BUTTON}{B_BUTTON}CANCEL" );
ALIGNED( 4 ) const u8 gText_UnkCtrlF800Exit[] = _( "{A_BUTTON}EXIT" );
const u8 gText_BirchBoy[]                     = _( "BOY" );
const u8 gText_BirchGirl[]                    = _( "GIRL" );
const u8 gText_DefaultNameStu[]               = _( "STU" );
const u8 gText_DefaultNameMilton[]            = _( "MILTON" );
const u8 gText_DefaultNameTom[]               = _( "TOM" );
const u8 gText_DefaultNameKenny[]             = _( "KENNY" );
const u8 gText_DefaultNameReid[]              = _( "REID" );
const u8 gText_DefaultNameJude[]              = _( "JUDE" );
const u8 gText_DefaultNameJaxson[]            = _( "JAXSON" );
const u8 gText_DefaultNameEaston[]            = _( "EASTON" );
const u8 gText_DefaultNameWalker[]            = _( "WALKER" );
const u8 gText_DefaultNameTeru[]              = _( "TERU" );
const u8 gText_DefaultNameJohnny[]            = _( "JOHNNY" );
const u8 gText_DefaultNameBrett[]             = _( "BRETT" );
const u8 gText_DefaultNameSeth[]              = _( "SETH" );
const u8 gText_DefaultNameTerry[]             = _( "TERRY" );
const u8 gText_DefaultNameCasey[]             = _( "CASEY" );
const u8 gText_DefaultNameDarren[]            = _( "DARREN" );
const u8 gText_DefaultNameLandon[]            = _( "LANDON" );
const u8 gText_DefaultNameCollin[]            = _( "COLLIN" );
const u8 gText_DefaultNameStanley[]           = _( "STANLEY" );
const u8 gText_DefaultNameQuincy[]            = _( "QUINCY" );
const u8 gText_DefaultNameKimmy[]             = _( "KIMMY" );
const u8 gText_DefaultNameTiara[]             = _( "TIARA" );
const u8 gText_DefaultNameBella[]             = _( "BELLA" );
const u8 gText_DefaultNameJayla[]             = _( "JAYLA" );
const u8 gText_DefaultNameAllie[]             = _( "ALLIE" );
const u8 gText_DefaultNameLianna[]            = _( "LIANNA" );
const u8 gText_DefaultNameSara[]              = _( "SARA" );
const u8 gText_DefaultNameMonica[]            = _( "MONICA" );
const u8 gText_DefaultNameCamila[]            = _( "CAMILA" );
const u8 gText_DefaultNameAubree[]            = _( "AUBREE" );
const u8 gText_DefaultNameRuthie[]            = _( "RUTHIE" );
const u8 gText_DefaultNameHazel[]             = _( "HAZEL" );
const u8 gText_DefaultNameNadine[]            = _( "NADINE" );
const u8 gText_DefaultNameTanja[]             = _( "TANJA" );
const u8 gText_DefaultNameYasmin[]            = _( "YASMIN" );
const u8 gText_DefaultNameNicola[]            = _( "NICOLA" );
const u8 gText_DefaultNameLillie[]            = _( "LILLIE" );
const u8 gText_DefaultNameTerra[]             = _( "TERRA" );
const u8 gText_DefaultNameLucy[]              = _( "LUCY" );
const u8 gText_DefaultNameHalie[]             = _( "HALIE" );
const u8 gText_ThisIsAPokemon[] =
	_( "This is what we call a “POKéMON.”{PAUSE 96}\p" );
const u8 gText_5MarksPokemon[]       = _( "????? POKéMON" );
const u8 gText_UnkHeight[]           = _( "{CLEAR_TO 0x0C}??'??”" );
const u8 gText_UnkWeight[]           = _( "????.? lbs." );
const u8 gUnknown_085E86DC[]         = _( "                       POKéMON" );
const u8 gUnknown_085E86FB[]         = _( "{CLEAR_TO 0x0C}    '    ”" );
const u8 gUnknown_085E8709[]         = _( "        .   lbs." );
const u8 gUnknown_085E871A[]         = _( "" );
const u8 gText_CryOf[]               = _( "CRY OF" );
const u8 gUnknown_085E8722[]         = _( "" );
const u8 gText_SizeComparedTo[]      = _( "SIZE COMPARED TO " );
const u8 gText_PokedexRegistration[] = _( "POKéDEX registration completed." );
const u8 gText_HTHeight[]            = _( "HT" );
const u8 gText_WTWeight[]            = _( "WT" );
const u8 gText_SearchingPleaseWait[] = _( "Searching…\nPlease wait." );
const u8 gText_SearchCompleted[]     = _( "Search completed." );
const u8 gUnknown_085E8785[]         = _( "No matching POKéMON were found." );
const u8 gUnknown_085E87A5[] =
	_( "Search for POKéMON based on\nselected parameters." );
const u8 gUnknown_085E87D6[] = _( "Switch POKéDEX listings." );
const u8 gUnknown_085E87EF[] = _( "Return to the POKéDEX." );
const u8 gUnknown_085E8806[] = _( "Select the POKéDEX mode." );
const u8 gUnknown_085E881F[] = _( "Select the POKéDEX listing mode." );
const u8 gUnknown_085E8840[] =
	_( "List by the first letter in the name.\nSpotted POKéMON only." );
const u8 gUnknown_085E887C[] =
	_( "List by body color.\nSpotted POKéMON only." );
const u8 gUnknown_085E88A6[]   = _( "List by type.\nOwned POKéMON only." );
const u8 gUnknown_085E88C8[]   = _( "Execute search/switch." );
const u8 gText_DexHoennTitle[] = _( "HOENN DEX" );
const u8 gText_DexNatTitle[]   = _( "NATIONAL DEX" );
const u8 gText_DexSortNumericalTitle[] = _( "NUMERICAL MODE" );
const u8 gText_DexSortAtoZTitle[]      = _( "A TO Z MODE" );
const u8 gText_DexSortHeaviestTitle[]  = _( "HEAVIEST MODE" );
const u8 gText_DexSortLightestTitle[]  = _( "LIGHTEST MODE" );
const u8 gText_DexSortTallestTitle[]   = _( "TALLEST MODE" );
const u8 gText_DexSortSmallestTitle[]  = _( "SMALLEST MODE" );
const u8 gText_DexSearchAlphaABC[]     = _( "ABC" );
const u8 gText_DexSearchAlphaDEF[]     = _( "DEF" );
const u8 gText_DexSearchAlphaGHI[]     = _( "GHI" );
const u8 gText_DexSearchAlphaJKL[]     = _( "JKL" );
const u8 gText_DexSearchAlphaMNO[]     = _( "MNO" );
const u8 gText_DexSearchAlphaPQR[]     = _( "PQR" );
const u8 gText_DexSearchAlphaSTU[]     = _( "STU" );
const u8 gText_DexSearchAlphaVWX[]     = _( "VWX" );
const u8 gText_DexSearchAlphaYZ[]      = _( "YZ" );
const u8 gText_DexSearchColorRed[]     = _( "RED" );
const u8 gText_DexSearchColorBlue[]    = _( "BLUE" );
const u8 gText_DexSearchColorYellow[]  = _( "YELLOW" );
const u8 gText_DexSearchColorGreen[]   = _( "GREEN" );
const u8 gText_DexSearchColorBlack[]   = _( "BLACK" );
const u8 gText_DexSearchColorBrown[]   = _( "BROWN" );
const u8 gText_DexSearchColorPurple[]  = _( "PURPLE" );
const u8 gText_DexSearchColorGray[]    = _( "GRAY" );
const u8 gText_DexSearchColorWhite[]   = _( "WHITE" );
const u8 gText_DexSearchColorPink[]    = _( "PINK" );
const u8 gText_DexHoennDescription[]   = _( "HOENN region's POKéDEX" );
const u8 gText_DexNatDescription[]     = _( "National edition POKéDEX" );
const u8 gText_DexSortNumericalDescription[] =
	_( "POKéMON are listed according to their\nnumber." );
const u8 gText_DexSortAtoZDescription[] =
	_( "Spotted and owned POKéMON are listed\nalphabetically." );
const u8 gText_DexSortHeaviestDescription[] =
	_( "Owned POKéMON are listed from the\nheaviest to the lightest." );
const u8 gText_DexSortLightestDescription[] =
	_( "Owned POKéMON are listed from the\nlightest to the heaviest." );
const u8 gText_DexSortTallestDescription[] =
	_( "Owned POKéMON are listed from the\ntallest to the smallest." );
const u8 gText_DexSortSmallestDescription[] =
	_( "Owned POKéMON are listed from the\nsmallest to the tallest." );
const u8 gText_DexEmptyString[]       = _( "" );
const u8 gText_DexSearchDontSpecify[] = _( "DON'T SPECIFY." );
const u8 gText_DexSearchTypeNone[]    = _( "NONE" );
const u8 gText_SelectorArrow[]        = _( "▶" );
const u8 gUnknown_085E8B3C[]          = _( " " );
const u8 gText_WelcomeToHOF[]         = _( "Welcome to the HALL OF FAME!" );
const u8 gText_HOFDexRating[]         = _(
        "Spotted POKéMON: {STR_VAR_1}!\nOwned POKéMON: {STR_VAR_2}!\pPROF. BIRCH's POKéDEX rating!\pPROF. BIRCH: Let's see…\p" );
const u8 gText_HOFDexSaving[] = _( "SAVING…\nDON'T TURN OFF THE POWER." );
const u8 gText_HOFCorrupted[] = _( "The HALL OF FAME data is corrupted." );
const u8 gText_HOFNumber[]    = _( "HALL OF FAME No. {STR_VAR_1}" );
const u8 gText_LeagueChamp[]  = _( "LEAGUE CHAMPION!\nCONGRATULATIONS!" );
const u8 gText_Number[]       = _( "No. " );
const u8 gText_Level[]        = _( "Lv. " );
const u8 gUnknown_085E8C40[]  = _( "IDNo. /" );
const u8 gText_Name[]         = _( "NAME" );
const u8 gText_IDNumber[]     = _( "IDNo." );
const u8 gText_BirchInTrouble[] =
	_( "PROF. BIRCH is in trouble!\nRelease a POKéMON and rescue him!" );
const u8 gText_ConfirmStarterChoice[] = _( "Do you choose this POKéMON?" );
const u8 gUnknown_085E8CAC[]          = _( "POKéMON" );
const u8 gText_FlyToWhere[]           = _( "FLY to where?" );
const u8 gMenuText_Use[]              = _( "USE" );
const u8 gMenuText_Toss[]             = _( "TOSS" );
const u8 gMenuText_Register[]         = _( "REGISTER" );
const u8 gMenuText_Give[]             = _( "GIVE" );
const u8 gMenuText_CheckTag[]         = _( "CHECK TAG" );
const u8 gMenuText_Confirm[]          = _( "CONFIRM" );
const u8 gMenuText_Walk[]             = _( "WALK" );
const u8 gText_Cancel[]               = _( "CANCEL" );
const u8 gText_Cancel2[]              = _( "CANCEL" );
const u8 gMenuText_Show[]             = _( "SHOW" );
const u8 gText_EmptyString2[]         = _( "" );
const u8 gUnknown_085E8D04[]          = _( "CANCEL" );
const u8 gText_Item[]                 = _( "ITEM" );
const u8 gText_Mail[]                 = _( "MAIL" );
const u8 gText_Take[]                 = _( "TAKE" );
const u8 gText_Store[]                = _( "STORE" );
const u8 gMenuText_Check[]            = _( "CHECK" );
const u8 gText_None[]                 = _( "NONE" );
const u8 gMenuText_Deselect[]         = _( "DESELECT" );
const u8 gText_ThreeMarks[]           = _( "???" );
const u8 gText_FiveMarks[]            = _( "?????" );
const u8 gText_Slash[]                = _( "/" );
const u8 gText_OneDash[]              = _( "-" );
const u8 gText_TwoDashes[]            = _( "--" );
const u8 gText_ThreeDashes[]          = _( "---" );
const u8 gText_MaleSymbol[]           = _( "♂" );
const u8 gText_FemaleSymbol[]         = _( "♀" );
const u8 gText_LevelSymbol[]          = _( "{LV}" );
const u8 gText_UnkCtrlF908Clear01[]   = _( "{NO}{CLEAR 0x01}" );
const u8 gUnknown_085E8D55[]          = _( "+" );
const u8 gUnknown_085E8D57[]          = _( "{RIGHT_ARROW}" );
const u8 gText_UnkCtrlF907F908[]      = _( "{ID}{NO}" );
const u8 gText_Space[]                = _( " " );
const u8 gText_SelectorArrow2[]       = _( "▶" );
const u8 gText_GoBackPrevMenu[]       = _( "Go back to the\nprevious menu." );
const u8 gText_WhatWouldYouLike[]     = _( "What would you like to do?" );
const u8 gMenuText_Give2[]            = _( "GIVE" );
const u8 gText_xVar1[]                = _( "×{STR_VAR_1}" );
const u8 gUnknown_085E8DA4[]          = _( " BERRY" );
const u8 gText_Coins[]                = _( "{STR_VAR_1} COINS" );
const u8 gText_CloseBag[]             = _( "CLOSE BAG" );
const u8 gText_Var1IsSelected[]       = _( "{STR_VAR_1} is\nselected." );
const u8 gText_CantWriteMail[]        = _( "You can't write\nMAIL here." );
const u8 gText_NoPokemon[]            = _( "There is no\nPOKéMON." );
const u8 gText_MoveVar1Where[]        = _( "Move the\n{STR_VAR_1}\nwhere?" );
const u8 gText_Var1CantBeHeld[]       = _( "The {STR_VAR_1} can't be held." );
const u8 gText_Var1CantBeHeldHere[] =
	_( "The {STR_VAR_1} can't be held\nhere." );
const u8 gText_DepositHowManyVar1[] = _( "Deposit how many\n{STR_VAR_1}(s)?" );
const u8 gText_DepositedVar2Var1s[] =
	_( "Deposited {STR_VAR_2}\n{STR_VAR_1}(s)." );
const u8 gText_NoRoomForItems[] = _( "There's no room to\nstore items." );
const u8 gText_CantStoreImportantItems[] =
	_( "Important items\ncan't be stored in\nthe PC!" );
const u8 gText_TooImportantToToss[] =
	_( "That's much too\nimportant to toss\nout!" );
const u8 gText_TossHowManyVar1s[] = _( "Toss out how many\n{STR_VAR_1}(s)?" );
const u8 gText_ThrewAwayVar2Var1s[] =
	_( "Threw away {STR_VAR_2}\n{STR_VAR_1}(s)." );
const u8 gText_ConfirmTossItems[] =
	_( "Is it okay to\nthrow away {STR_VAR_2}\n{STR_VAR_1}(s)?" );
const u8 gText_DadsAdvice[] = _(
	"DAD's advice…\n{PLAYER}, there's a time and place for\leverything!{PAUSE_UNTIL_PRESS}" );
const u8 gText_CantDismountBike[] =
	_( "You can't dismount your BIKE here.{PAUSE_UNTIL_PRESS}" );
const u8 gText_ItemFinderNearby[] = _(
	"Huh?\nThe ITEMFINDER's responding!\pThere's an item buried around here!{PAUSE_UNTIL_PRESS}" );
const u8 gText_ItemFinderOnTop[] =
	_( "Oh!\nThe ITEMFINDER's shaking wildly!{PAUSE_UNTIL_PRESS}" );
const u8 gText_ItemFinderNothing[] =
	_( "… … … …Nope!\nThere's no response.{PAUSE_UNTIL_PRESS}" );
const u8 gText_CoinCase[] = _( "Your COINS:\n{STR_VAR_1}{PAUSE_UNTIL_PRESS}" );
const u8 gText_BootedUpTM[] = _( "Booted up a TM." );
const u8 gText_BootedUpHM[] = _( "Booted up an HM." );
const u8 gText_TMHMContainedVar1[] =
	_( "It contained\n{STR_VAR_1}.\pTeach {STR_VAR_1}\nto a POKéMON?" );
const u8 gText_PlayerUsedVar2[] =
	_( "{PLAYER} used the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}" );
const u8 gText_RepelEffectsLingered[] = _(
	"But the effects of a REPEL\nlingered from earlier.{PAUSE_UNTIL_PRESS}" );
const u8 gText_UsedVar2WildLured[] = _(
	"{PLAYER} used the\n{STR_VAR_2}.\pWild POKéMON will be lured.{PAUSE_UNTIL_PRESS}" );
const u8 gText_UsedVar2WildRepelled[] = _(
	"{PLAYER} used the\n{STR_VAR_2}.\pWild POKéMON will be repelled.{PAUSE_UNTIL_PRESS}" );
const u8 gText_BoxFull[]   = _( "The BOX is full.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PowderQty[] = _( "POWDER QTY: {STR_VAR_1}{PAUSE_UNTIL_PRESS}" );
const u8 gText_TheField[]  = _( "the field" );
const u8 gText_TheBattle[] = _( "the battle" );
const u8 gText_ThePokemonList[] = _( "the POKéMON LIST" );
const u8 gText_TheShop[]        = _( "the shop" );
const u8 gText_ThePC[]          = _( "the PC" );

const u8* const gReturnToXStringsTable[] = {gText_TheField,
	gText_TheBattle,
	gText_ThePokemonList,
	gText_TheShop,
	gText_TheField,
	gText_TheField,
	gText_ThePC,
	gText_TheField,
	gText_TheField,
	gText_TheField,
	gText_TheBattle,
	gText_ThePC};

const u8* const gReturnToXStringsTable2[] = {
	gText_TheField, gText_TheBattle, gText_ThePokemonList, gText_TheField};

const u8 gText_ReturnToVar1[]    = _( "Return to\n{STR_VAR_1}." );
const u8 gText_ItemsPocket[]     = _( "ITEMS" );
const u8 gText_PokeBallsPocket[] = _( "POKé BALLS" );
const u8 gText_TMHMPocket[]      = _( "TMs & HMs" );
const u8 gText_BerriesPocket[]   = _( "BERRIES" );
const u8 gText_KeyItemsPocket[]  = _( "KEY ITEMS" );

const u8* const gPocketNamesStringsTable[] = {gText_ItemsPocket,
	gText_PokeBallsPocket,
	gText_TMHMPocket,
	gText_BerriesPocket,
	gText_KeyItemsPocket};

const u8 gText_UnkF908Var1Clear7Var2[] =
	_( "{NO}{STR_VAR_1}{CLEAR 0x07}{STR_VAR_2}" );
const u8 gText_ClearTo11Var1Clear5Var2[] =
	_( "{CLEAR_TO 0x11}{STR_VAR_1}{CLEAR 0x05}{STR_VAR_2}" );
const u8 gText_SizeSlash[]   = _( "SIZE /" );
const u8 gText_FirmSlash[]   = _( "FIRM /" );
const u8 gText_Var1DotVar2[] = _( "{STR_VAR_1}.{STR_VAR_2}”" );

// Berry firmness strings
const u8 gBerryFirmnessString_VerySoft[]  = _( "Very soft" );
const u8 gBerryFirmnessString_Soft[]      = _( "Soft" );
const u8 gBerryFirmnessString_Hard[]      = _( "Hard" );
const u8 gBerryFirmnessString_VeryHard[]  = _( "Very hard" );
const u8 gBerryFirmnessString_SuperHard[] = _( "Super hard" );

const u8 gText_UnkF908Var1Var2[]   = _( "{NO}{STR_VAR_1} {STR_VAR_2}" );
const u8 gText_BerryTag[]          = _( "BERRY TAG" );
const u8 gText_RedPokeblock[]      = _( "RED {POKEBLOCK}" );
const u8 gText_BluePokeblock[]     = _( "BLUE {POKEBLOCK}" );
const u8 gText_PinkPokeblock[]     = _( "PINK {POKEBLOCK}" );
const u8 gText_GreenPokeblock[]    = _( "GREEN {POKEBLOCK}" );
const u8 gText_YellowPokeblock[]   = _( "YELLOW {POKEBLOCK}" );
const u8 gText_PurplePokeblock[]   = _( "PURPLE {POKEBLOCK}" );
const u8 gText_IndigoPokeblock[]   = _( "INDIGO {POKEBLOCK}" );
const u8 gText_BrownPokeblock[]    = _( "BROWN {POKEBLOCK}" );
const u8 gText_LiteBluePokeblock[] = _( "LITEBLUE {POKEBLOCK}" );
const u8 gText_OlivePokeblock[]    = _( "OLIVE {POKEBLOCK}" );
const u8 gText_GrayPokeblock[]     = _( "GRAY {POKEBLOCK}" );
const u8 gText_BlackPokeblock[]    = _( "BLACK {POKEBLOCK}" );
const u8 gText_WhitePokeblock[]    = _( "WHITE {POKEBLOCK}" );
const u8 gText_GoldPokeblock[]     = _( "GOLD {POKEBLOCK}" );
const u8 gText_Spicy[]             = _( "SPICY" );
const u8 gText_Dry[]               = _( "DRY" );
const u8 gText_Sweet[]             = _( "SWEET" );
const u8 gText_Bitter[]            = _( "BITTER" );
const u8 gText_Sour[]              = _( "SOUR" );
const u8 gUnknown_085E9339[]       = _( "TASTY" );
const u8 gUnknown_085E933F[]       = _( "FEEL" );
const u8 gText_StowCase[]          = _( "Stow CASE." );
const u8 gText_LvVar1[]            = _( "{LV}{STR_VAR_1}" );
const u8 gText_ThrowAwayVar1[]     = _( "Throw away this\n{STR_VAR_1}?" );
const u8 gText_Var1ThrownAway[]    = _( "The {STR_VAR_1}\nwas thrown away." );
const u8 gText_Var1AteTheVar2[] =
	_( "{STR_VAR_1} ate the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}" );
const u8 gText_Var1HappilyAteVar2[] =
	_( "{STR_VAR_1} happily ate the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}" );
const u8 gText_Var1DisdainfullyAteVar2[] = _(
	"{STR_VAR_1} disdainfully ate the\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}" );
const u8 gText_ShopBuy[]      = _( "BUY" );
const u8 gText_ShopSell[]     = _( "SELL" );
const u8 gText_ShopQuit[]     = _( "QUIT" );
const u8 gText_InBagVar1[]    = _( "IN BAG: {STR_VAR_1}" );
const u8 gText_QuitShopping[] = _( "Quit shopping." );
const u8 gText_Var1CertainlyHowMany[] =
	_( "{STR_VAR_1}? Certainly.\nHow many would you like?" );
const u8 gText_Var1CertainlyHowMany2[] =
	_( "{STR_VAR_1}? Certainly.\nHow many would you like?" );
const u8 gText_Var1AndYouWantedVar2[] = _(
	"{STR_VAR_1}? And you wanted {STR_VAR_2}?\nThat will be ¥{STR_VAR_3}." );
const u8 gText_Var1IsItThatllBeVar2[] =
	_( "{STR_VAR_1}, is it?\nThat'll be ¥{STR_VAR_2}. Do you want it?" );
const u8 gText_YouWantedVar1ThatllBeVar2[] = _(
	"You wanted {STR_VAR_1}?\nThat'll be ¥{STR_VAR_2}. Will that be okay?" );
const u8 gText_HereYouGoThankYou[] = _( "Here you go!\nThank you very much." );
const u8 gText_ThankYouIllSendItHome[] =
	_( "Thank you!\nI'll send it to your home PC." );
const u8 gText_ThanksIllSendItHome[] =
	_( "Thanks!\nI'll send it to your PC at home." );
const u8 gText_YouDontHaveMoney[] =
	_( "You don't have enough money.{PAUSE_UNTIL_PRESS}" );
const u8 gText_NoMoreRoomForThis[] =
	_( "You have no more room for this\nitem.{PAUSE_UNTIL_PRESS}" );
const u8 gText_SpaceForVar1Full[] =
	_( "The space for {STR_VAR_1} is full.{PAUSE_UNTIL_PRESS}" );
const u8 gText_AnythingElseICanHelp[] =
	_( "Is there anything else I can help\nyou with?" );
const u8 gText_CanIHelpWithAnythingElse[] =
	_( "Can I help you with anything else?" );
const u8 gText_ThrowInPremierBall[] =
	_( "I'll throw in a PREMIER BALL, too.{PAUSE_UNTIL_PRESS}" );
const u8 gText_CantBuyKeyItem[] =
	_( "{STR_VAR_2}? Oh, no.\nI can't buy that.{PAUSE_UNTIL_PRESS}" );
const u8 gText_HowManyToSell[] =
	_( "{STR_VAR_2}?\nHow many would you like to sell?" );
const u8 gText_ICanPayVar1[] =
	_( "I can pay ¥{STR_VAR_1}.\nWould that be okay?" );
const u8 gText_TurnedOverVar1ForVar2[] =
	_( "Turned over the {STR_VAR_2}\nand received ¥{STR_VAR_1}." );
const u8 gText_PokedollarVar1[] = _( "¥{STR_VAR_1}" );
const u8 gText_Shift[]          = _( "SHIFT" );
const u8 gText_SendOut[]        = _( "SEND OUT" );
const u8 gText_Switch2[]        = _( "SWITCH" );
const u8 gText_Summary5[]       = _( "SUMMARY" );
const u8 gUnknown_085E96BE[]    = _( "MOVES" );
const u8 gText_Enter[]          = _( "ENTER" );
const u8 gText_NoEntry[]        = _( "NO ENTRY" );
const u8 gText_Take2[]          = _( "TAKE" );
const u8 gText_Read2[]          = _( "READ" );
const u8 gText_Trade4[]         = _( "TRADE" );
const u8 gText_HP3[]            = _( "HP" );
const u8 gText_SpAtk3[]         = _( "SP. ATK" );
const u8 gText_SpDef3[]         = _( "SP. DEF" );
const u8 gText_WontHaveEffect[] =
	_( "It won't have any effect.{PAUSE_UNTIL_PRESS}" );
const u8 gText_CantBeUsedOnPkmn[] =
	_( "This can't be used on\nthat POKéMON.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnCantSwitchOut[] =
	_( "{STR_VAR_1} can't be switched\nout!{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnAlreadyInBattle[] =
	_( "{STR_VAR_1} is already\nin battle!{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnAlreadySelected[] =
	_( "{STR_VAR_1} has already been\nselected.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnHasNoEnergy[] =
	_( "{STR_VAR_1} has no energy\nleft to battle!{PAUSE_UNTIL_PRESS}" );
const u8 gText_CantSwitchWithAlly[] = _(
	"You can't switch {STR_VAR_1}'s\nPOKéMON with one of yours!{PAUSE_UNTIL_PRESS}" );
const u8 gText_EggCantBattle[] =
	_( "An EGG can't battle!{PAUSE_UNTIL_PRESS}" );
const u8 gText_CantUseUntilNewBadge[] = _(
	"This can't be used until a new\nBADGE is obtained.{PAUSE_UNTIL_PRESS}" );
const u8 gText_NoMoreThanVar1Pkmn[] =
	_( "No more than {STR_VAR_1} POKéMON\nmay enter.{PAUSE_UNTIL_PRESS}" );
const u8 gText_SendMailToPC[] = _( "Send the removed MAIL to\nyour PC?" );
const u8 gText_MailSentToPC[] =
	_( "The MAIL was sent to your PC.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PCMailboxFull[] =
	_( "Your PC's MAILBOX is full.{PAUSE_UNTIL_PRESS}" );
const u8 gText_MailMessageWillBeLost[] =
	_( "If the MAIL is removed, the\nmessage will be lost. Okay?" );
const u8 gText_RemoveMailBeforeItem[] = _(
	"MAIL must be removed before\nholding an item.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnWasGivenItem[] = _(
	"{STR_VAR_1} was given the\n{STR_VAR_2} to hold.{PAUSE_UNTIL_PRESS}" );
const u8 gText_SwitchPkmnItem[] = _(
	"{STR_VAR_1} is already holding\none {STR_VAR_2}.\pWould you like to switch the\ntwo items?" );
const u8 gText_PkmnNotHolding[] =
	_( "{STR_VAR_1} isn't holding\nanything.{PAUSE_UNTIL_PRESS}" );
const u8 gText_ReceivedItemFromPkmn[] =
	_( "Received the {STR_VAR_2}\nfrom {STR_VAR_1}.{PAUSE_UNTIL_PRESS}" );
const u8 gText_MailTakenFromPkmn[] =
	_( "MAIL was taken from the\nPOKéMON.{PAUSE_UNTIL_PRESS}" );
const u8 gText_SwitchedPkmnItem[] = _(
	"The {STR_VAR_2} was taken and\nreplaced with the {STR_VAR_1}.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnHoldingItemCantHoldMail[] = _(
	"This POKéMON is holding an\nitem. It cannot hold MAIL.{PAUSE_UNTIL_PRESS}" );
const u8 gText_MailTransferredFromMailbox[] =
	_( "MAIL was transferred from\nthe MAILBOX.{PAUSE_UNTIL_PRESS}" );
const u8 gText_BagFullCouldNotRemoveItem[] = _(
	"The BAG is full. The POKéMON's\nitem could not be removed.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnLearnedMove3[]  = _( "{STR_VAR_1} learned\n{STR_VAR_2}!" );
const u8 gText_PkmnCantLearnMove[] = _(
	"{STR_VAR_1} and {STR_VAR_2}\nare not compatible.\p{STR_VAR_2} can't be\nlearned.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnNeedsToReplaceMove[] = _(
	"{STR_VAR_1} wants to learn the\nmove {STR_VAR_2}.\pHowever, {STR_VAR_1} already\nknows four moves.\pShould a move be deleted and\nreplaced with {STR_VAR_2}?" );
const u8 gText_StopLearningMove2[] = _( "Stop trying to teach\n{STR_VAR_2}?" );
const u8 gText_MoveNotLearned[]    = _(
        "{STR_VAR_1} did not learn the\nmove {STR_VAR_2}.{PAUSE_UNTIL_PRESS}" );
const u8 gText_WhichMoveToForget[] =
	_( "Which move should be forgotten?{PAUSE_UNTIL_PRESS}" );
const u8 gText_12PoofForgotMove[] = _(
	"1, {PAUSE 15}2, and{PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE 0x0038}Poof!\p{STR_VAR_1} forgot how to\nuse {STR_VAR_2}.\pAnd…{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnAlreadyKnows[] =
	_( "{STR_VAR_1} already knows\n{STR_VAR_2}.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnHPRestoredByVar2[] = _(
	"{STR_VAR_1}'s HP was restored\nby {STR_VAR_2} point(s).{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnCuredOfPoison[] =
	_( "{STR_VAR_1} was cured of its\npoisoning.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnCuredOfParalysis[] =
	_( "{STR_VAR_1} was cured of\nparalysis.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnWokeUp2[] = _( "{STR_VAR_1} woke up.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnBurnHealed[] =
	_( "{STR_VAR_1}'s burn was healed.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnThawedOut[] =
	_( "{STR_VAR_1} was thawed out.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PPWasRestored[] = _( "PP was restored.{PAUSE_UNTIL_PRESS}" );
const u8 gUnknown_085E9CCA[] =
	_( "{STR_VAR_1} regained health.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnBecameHealthy[] =
	_( "{STR_VAR_1} became healthy.{PAUSE_UNTIL_PRESS}" );
const u8 gText_MovesPPIncreased[] =
	_( "{STR_VAR_1}'s PP increased.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnElevatedToLvVar2[] =
	_( "{STR_VAR_1} was elevated to\nLv. {STR_VAR_2}." );
const u8 gText_PkmnBaseVar2StatIncreased[] = _(
	"{STR_VAR_1}'s base {STR_VAR_2}\nstat was raised.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnFriendlyBaseVar2Fell[] = _(
	"{STR_VAR_1} turned friendly.\nThe base {STR_VAR_2} fell!{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnAdoresBaseVar2Fell[] = _(
	"{STR_VAR_1} adores you!\nThe base {STR_VAR_2} fell!{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnFriendlyBaseVar2CantFall[] = _(
	"{STR_VAR_1} turned friendly.\nThe base {STR_VAR_2} can't fall!{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnSnappedOutOfConfusion[] =
	_( "{STR_VAR_1} snapped out of its\nconfusion.{PAUSE_UNTIL_PRESS}" );
const u8 gText_PkmnGotOverInfatuation[] =
	_( "{STR_VAR_1} got over its\ninfatuation.{PAUSE_UNTIL_PRESS}" );
const u8 gText_ThrowAwayItem[] = _( "Throw away this\n{STR_VAR_1}?" );
const u8 gText_ItemThrownAway[] =
	_( "The {STR_VAR_1}\nwas thrown away.{PAUSE_UNTIL_PRESS}" );
const u8 gUnknown_085E9E2E[]        = _( "Teach which POKéMON?" );
const u8 gText_ChoosePokemon[]      = _( "Choose a POKéMON." );
const u8 gText_MoveToWhere[]        = _( "Move to where?" );
const u8 gText_TeachWhichPokemon[]  = _( "Teach which POKéMON?" );
const u8 gText_UseOnWhichPokemon[]  = _( "Use on which POKéMON?" );
const u8 gText_GiveToWhichPokemon[] = _( "Give to which POKéMON?" );
const u8 gText_DoWhatWithPokemon[]  = _( "Do what with this {PKMN}?" );
const u8 gText_NothingToCut[]       = _( "There's nothing to CUT." );
const u8 gText_CantSurfHere[]       = _( "You can't SURF here." );
const u8 gText_AlreadySurfing[]     = _( "You're already SURFING." );
const u8 gText_CantUseHere[]        = _( "Can't use that here." );
const u8 gText_RestoreWhichMove[]   = _( "Restore which move?" );
const u8 gText_BoostPp[]            = _( "Boost PP of which move?" );
const u8 gText_DoWhatWithItem[]     = _( "Do what with an item?" );
const u8 gText_NoPokemonForBattle[] = _( "No POKéMON for battle!" );
const u8 gText_ChoosePokemon2[]     = _( "Choose a POKéMON." );
const u8 gText_NotEnoughHp[]        = _( "Not enough HP…" );
const u8 gText_PokemonAreNeeded[]   = _( "{STR_VAR_1} POKéMON are needed." );
const u8 gText_PokemonCantBeSame[]  = _( "POKéMON can't be the same." );
const u8 gText_NoIdenticalHoldItems[] = _( "No identical hold items." );
const u8 gText_CurrentIsTooFast[]     = _( "The current is much too fast!" );
const u8 gText_DoWhatWithMail[]       = _( "Do what with the MAIL?" );
const u8 gText_ChoosePokemonCancel[]  = _( "Choose POKéMON or CANCEL." );
const u8 gText_ChoosePokemonConfirm[] = _( "Choose POKéMON and confirm." );
const u8 gText_EnjoyCycling[]         = _( "Let's enjoy cycling!" );
const u8 gText_InUseAlready_PM[]      = _( "This is in use already." );
const u8 gText_AlreadyHoldingOne[] =
	_( "{STR_VAR_1} is already holding\none {STR_VAR_2}." );
const u8 gText_NoUse[]     = _( "No use." );
const u8 gText_Able[]      = _( "ABLE" );
const u8 gText_First_PM[]  = _( "FIRST" );
const u8 gText_Second_PM[] = _( "SECOND" );
const u8 gText_Third_PM[]  = _( "THIRD" );
const u8 gText_Able2[]     = _( "ABLE" );
const u8 gText_NotAble[]   = _( "NOT ABLE" );
const u8 gText_Able3[]     = _( "ABLE!" );
const u8 gText_NotAble2[]  = _( "NOT ABLE!" );
const u8 gText_Learned[]   = _( "LEARNED" );
const u8 gText_Have[]      = _( "HAVE" );
const u8 gText_DontHave[]  = _( "DON'T HAVE" );
const u8 gText_Fourth[]    = _( "FOURTH" );
const u8 gText_PkmnCantParticipate[] =
	_( "That POKéMON can't participate.{PAUSE_UNTIL_PRESS}" );
const u8 gText_CancelParticipation[] = _( "Cancel participation?" );
const u8 gText_CancelBattle[]        = _( "Cancel the battle?" );
const u8 gText_ReturnToWaitingRoom[] = _( "Return to the WAITING ROOM?" );
const u8 gText_CancelChallenge[]     = _( "Cancel the challenge?" );
const u8 gText_EscapeFromHere[] =
	_( "Want to escape from here and return\nto {STR_VAR_1}?" );
const u8 gText_ReturnToHealingSpot[] =
	_( "Want to return to the healing spot\nused last in {STR_VAR_1}?" );
const u8 gText_PauseUntilPress[] = _( "{PAUSE_UNTIL_PRESS}" );
const u8 gJPText_PutVar1IntoSpinner[] =
	_( "{STR_VAR_1}を ぐるぐるこうかんに\nだして よろしいですか？" );
ALIGNED( 4 )
const u8 gText_OnlyPkmnForBattle[] =
	_( "That's your only\nPOKéMON for battle." );
ALIGNED( 4 )
const u8 gText_PkmnCantBeTradedNow[] =
	_( "That POKéMON can't be traded\nnow." );
ALIGNED( 4 )
const u8 gText_EggCantBeTradedNow[] = _( "An EGG can't be traded now." );
ALIGNED( 4 )
const u8 gText_OtherTrainersPkmnCantBeTraded[] =
	_( "The other TRAINER's POKéMON\ncan't be traded now." );
ALIGNED( 4 )
const u8 gText_OtherTrainerCantAcceptPkmn[] =
	_( "The other TRAINER can't accept\nthat POKéMON now." );
ALIGNED( 4 )
const u8 gText_CantTradeWithTrainer[] =
	_( "You can't trade with that\nTRAINER now." );
ALIGNED( 4 )
const u8 gText_NotPkmnOtherTrainerWants[] =
	_( "That isn't the type of POKéMON\nthat the other TRAINER wants." );
ALIGNED( 4 ) const u8 gText_ThatIsntAnEgg[] = _( "That isn't an EGG." );
const u8 gText_Register[]                   = _( "REGISTER" );
const u8 gText_Attack3[]                    = _( "ATTACK" );
const u8 gText_Defense3[]                   = _( "DEFENSE" );
const u8 gText_SpAtk4[]                     = _( "SP. ATK" );
const u8 gText_SpDef4[]                     = _( "SP. DEF" );
const u8 gText_Speed2[]                     = _( "SPEED" );
const u8 gText_HP4[]                        = _( "HP" );
const u8 gUnknown_085EA364[]                = _( "" );
const u8 gText_OTSlash[]                    = _( "OT/" );
const u8 gText_RentalPkmn[]                 = _( "RENTAL POKéMON" );
const u8 gText_TypeSlash[]                  = _( "TYPE/" );
const u8 gText_Power[]                      = _( "POWER" );
const u8 gText_Accuracy2[]                  = _( "ACCURACY" );
const u8 gText_Appeal[]                     = _( "APPEAL" );
const u8 gText_Jam[]                        = _( "JAM" );
const u8 gText_Status[]                     = _( "STATUS" );
const u8 gText_ExpPoints[]                  = _( "EXP. POINTS" );
const u8 gText_NextLv[]                     = _( "NEXT LV." );
const u8 gText_RibbonsVar1[]                = _( "RIBBONS: {STR_VAR_1}" );
const u8 gText_EmptyString5[]               = _( "" );
const u8 gUnknown_085EA3C1[]                = _( "EVENTS" );
const u8 gText_Switch[]                     = _( "SWITCH" );
const u8 gText_PkmnInfo[]                   = _( "POKéMON INFO" );
const u8 gText_PkmnSkills[]                 = _( "POKéMON SKILLS" );
const u8 gText_BattleMoves[]                = _( "BATTLE MOVES" );
const u8 gText_ContestMoves[]               = _( "C0NTEST MOVES" );
const u8 gText_Info[]                       = _( "INFO" );
const u8 gText_EggWillTakeALongTime[] =
	_( "It looks like this EGG will\ntake a long time to hatch." );
const u8 gText_EggWillTakeSomeTime[] =
	_( "What will hatch from this?\nIt will take some time." );
const u8 gText_EggWillHatchSoon[] =
	_( "It moves occasionally.\nIt should hatch soon." );
const u8 gText_EggAboutToHatch[] =
	_( "It's making sounds.\nIt's about to hatch!" );
const u8 gText_HMMovesCantBeForgotten2[] =
	_( "HM moves can't be\nforgotten now." );
const u8 gText_XNatureMetAtYZ[] = _(
	"{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature,\nmet at {LV_2}{SPECIAL_F7 0x00}{SPECIAL_F7 0x03}{SPECIAL_F7 0x01},\n{SPECIAL_F7 0x00}{SPECIAL_F7 0x04}{SPECIAL_F7 0x01}." );
const u8 gText_XNatureHatchedAtYZ[] = _(
	"{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature,\nhatched at {LV_2}{SPECIAL_F7 0x00}{SPECIAL_F7 0x03}{SPECIAL_F7 0x01},\n{SPECIAL_F7 0x00}{SPECIAL_F7 0x04}{SPECIAL_F7 0x01}." );
const u8 gText_XNatureObtainedInTrade[] = _(
	"{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature,\nobtained in a trade." );
const u8 gText_XNatureFatefulEncounter[] = _(
	"{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature,\nobtained in a fateful\nencounter at {LV_2}{SPECIAL_F7 0x00}{SPECIAL_F7 0x03}{SPECIAL_F7 0x01}." );
const u8 gText_XNatureProbablyMetAt[] = _(
	"{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature,\nprobably met at {LV_2}{SPECIAL_F7 0x00}{SPECIAL_F7 0x03}{SPECIAL_F7 0x01},\n{SPECIAL_F7 0x00}{SPECIAL_F7 0x04}{SPECIAL_F7 0x01}." );
const u8 gText_XNature[] = _(
	"{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature" );
const u8 gText_XNatureMetSomewhereAt[] = _(
	"{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature,\nmet somewhere at {LV_2}{SPECIAL_F7 0x00}{SPECIAL_F7 0x03}{SPECIAL_F7 0x01}." );
const u8 gText_XNatureHatchedSomewhereAt[] = _(
	"{SPECIAL_F7 0x00}{SPECIAL_F7 0x02}{SPECIAL_F7 0x01}{SPECIAL_F7 0x05} nature,\nhatched somewhere at {LV_2}{SPECIAL_F7 0x00}{SPECIAL_F7 0x03}{SPECIAL_F7 0x01}." );
const u8 gText_OddEggFoundByCouple[] =
	_( "An odd POKéMON EGG found\nby the DAY CARE couple." );
const u8 gText_PeculiarEggNicePlace[] =
	_( "A peculiar POKéMON EGG\nobtained at the nice place." );
const u8 gText_PeculiarEggTrade[] =
	_( "A peculiar POKéMON EGG\nobtained in a trade." );
const u8 gText_EggFromHotSprings[] =
	_( "A POKéMON EGG obtained\nat the hot springs." );
const u8 gText_EggFromTraveler[] =
	_( "An odd POKéMON EGG\nobtained from a traveler." );
const u8 gText_ApostropheSBase[] = _( "'s BASE" );
const u8 gText_OkayToDeleteFromRegistry[] =
	_( "Is it okay to delete {STR_VAR_1}\nfrom the REGISTRY?" );
const u8 gText_RegisteredDataDeleted[] =
	_( "The registered data was deleted.{PAUSE_UNTIL_PRESS}" );
const u8 gText_NoRegistry[]  = _( "There is no REGISTRY.{PAUSE_UNTIL_PRESS}" );
const u8 gText_DelRegist[]   = _( "DEL REGIST." );
const u8 gUnknown_085EA7A9[] = _( "{STR_VAR_3}{STR_VAR_1}/{STR_VAR_2}" );
const u8 gText_Decorate[]    = _( "DECORATE" );
const u8 gText_PutAway[]     = _( "PUT AWAY" );
const u8 gText_Toss2[]       = _( "TOSS" );
const u8 gText_Color161Shadow161[] = _( "{COLOR 161}{SHADOW 161}" );
const u8 gText_PutOutSelectedDecorItem[] =
	_( "Put out the selected decoration item." );
const u8 gText_StoreChosenDecorInPC[] =
	_( "Store the chosen decoration in the PC." );
const u8 gText_ThrowAwayUnwantedDecors[] =
	_( "Throw away unwanted decorations." );
const u8 gText_NoDecorations[] =
	_( "There are no decorations.{PAUSE_UNTIL_PRESS}" );
const u8 gText_Desk[]              = _( "DESK" );
const u8 gText_Chair[]             = _( "CHAIR" );
const u8 gText_Plant[]             = _( "PLANT" );
const u8 gText_Ornament[]          = _( "ORNAMENT" );
const u8 gText_Mat[]               = _( "MAT" );
const u8 gText_Poster[]            = _( "POSTER" );
const u8 gText_Doll[]              = _( "DOLL" );
const u8 gText_Cushion[]           = _( "CUSHION" );
const u8 gText_Gold[]              = _( "GOLD" );
const u8 gText_Silver[]            = _( "SILVER" );
const u8 gText_PlaceItHere[]       = _( "Place it here?" );
const u8 gText_CantBePlacedHere[]  = _( "It can't be placed here." );
const u8 gText_CancelDecorating[]  = _( "Cancel decorating?" );
const u8 gText_InUseAlready[]      = _( "This is in use already." );
const u8 gText_NoMoreDecorations[] = _(
	"No more decorations can be placed.\nThe most that can be placed are {STR_VAR_1}." );
const u8 gText_NoMoreDecorations2[] = _(
	"No more decorations can be placed.\nThe most that can be placed are {STR_VAR_1}." );
const u8 gUnknown_085EA978[] =
	_( "This can't be placed here.\nIt must be on a DESK, etc." );
const u8 gText_CantPlaceInRoom[] =
	_( "This decoration can't be placed in\nyour own room." );
const u8 gText_CantThrowAwayInUse[] =
	_( "This decoration is in use.\nIt can't be thrown away." );
const u8 gText_DecorationWillBeDiscarded[] =
	_( "This {STR_VAR_1} will be discarded.\nIs that okay?" );
const u8 gText_DecorationThrownAway[] =
	_( "The decoration item was thrown away." );
const u8 gText_StopPuttingAwayDecorations[] =
	_( "Stop putting away decorations?" );
const u8 gText_NoDecorationHere[] = _( "There is no decoration item here." );
const u8 gText_ReturnDecorationToPC[] =
	_( "Return this decoration to the PC?" );
const u8 gText_DecorationReturnedToPC[] =
	_( "The decoration was returned to the PC." );
const u8 gText_NoDecorationsInUse[] =
	_( "There are no decorations in use.{PAUSE_UNTIL_PRESS}" );
const u8 gText_Tristan[]            = _( "TRISTAN" );
const u8 gText_Philip[]             = _( "PHILIP" );
const u8 gText_Dennis[]             = _( "DENNIS" );
const u8 gText_Roberto[]            = _( "ROBERTO" );
const u8 gText_TurnOff[]            = _( "TURN OFF" );
const u8 gText_Decoration[]         = _( "DECORATION" );
const u8 gText_ItemStorage[]        = _( "ITEM STORAGE" );
const u8 gText_Mailbox[]            = _( "MAILBOX" );
const u8 gText_DepositItem[]        = _( "DEPOSIT ITEM" );
const u8 gText_WithdrawItem[]       = _( "WITHDRAW ITEM" );
const u8 gText_TossItem[]           = _( "TOSS ITEM" );
const u8 gText_StoreItemsInPC[]     = _( "Store items in the PC." );
const u8 gText_TakeOutItemsFromPC[] = _( "Take out items from the PC." );
const u8 gText_ThrowAwayItemsInPC[] =
	_( "Throw away items stored in the PC." );
const u8 gText_NoItems[]     = _( "There are no items.{PAUSE_UNTIL_PRESS}" );
const u8 gText_NoRoomInBag[] = _( "There is no more\nroom in the BAG." );
const u8 gText_WithdrawHowManyItems[] =
	_( "Withdraw how many\n{STR_VAR_1}(s)?" );
const u8 gText_WithdrawXItems[] = _( "Withdrew {STR_VAR_2}\n{STR_VAR_1}(s)." );
const u8 gText_Read[]           = _( "READ" );
const u8 gText_MoveToBag[]      = _( "MOVE TO BAG" );
const u8 gText_Give2[]          = _( "GIVE" );
const u8 gText_NoMailHere[] = _( "There's no MAIL here.{PAUSE_UNTIL_PRESS}" );
const u8 gText_WhatToDoWithVar1sMail[] =
	_( "What would you like to do with\n{STR_VAR_1}'s MAIL?" );
const u8 gText_MessageWillBeLost[] =
	_( "The message will be lost.\nIs that okay?" );
const u8 gText_BagIsFull[] = _( "The BAG is full.{PAUSE_UNTIL_PRESS}" );
const u8 gText_MailToBagMessageErased[] = _(
	"The MAIL was returned to the BAG\nwith its message erased.{PAUSE_UNTIL_PRESS}" );
const u8 gText_Dad[]               = _( "DAD" );
const u8 gText_Mom[]               = _( "MOM" );
const u8 gText_Wallace[]           = _( "WALLACE" );
const u8 gText_Steven[]            = _( "STEVEN" );
const u8 gText_Brawly[]            = _( "BRAWLY" );
const u8 gText_Winona[]            = _( "WINONA" );
const u8 gText_Phoebe[]            = _( "PHOEBE" );
const u8 gText_Glacia[]            = _( "GLACIA" );
const u8 gUnknown_085EAD37[]       = _( "PETALBURG" );
const u8 gUnknown_085EAD41[]       = _( "SLATEPORT" );
const u8 gUnknown_085EAD4B[]       = _( "LITTLEROOT" );
const u8 gUnknown_085EAD56[]       = _( "LILYCOVE" );
const u8 gUnknown_085EAD5F[]       = _( "DEWFORD" );
const u8 gUnknown_085EAD67[]       = _( "ENTER" );
const u8 gUnknown_085EAD6D[]       = _( "INFO" );
const u8 gUnknown_085EAD72[]       = _( "What's a CONTEST?" );
const u8 gUnknown_085EAD84[]       = _( "Types of CONTESTS" );
const u8 gUnknown_085EAD96[]       = _( "Ranks" );
const u8 gUnknown_085EAD9C[]       = _( "Judging" );
const u8 gUnknown_085EADA4[]       = _( "COOLNESS CONTEST" );
const u8 gUnknown_085EADB5[]       = _( "BEAUTY CONTEST" );
const u8 gUnknown_085EADC4[]       = _( "CUTENESS CONTEST" );
const u8 gUnknown_085EADD5[]       = _( "SMARTNESS CONTEST" );
const u8 gUnknown_085EADE7[]       = _( "TOUGHNESS CONTEST" );
const u8 gUnknown_085EADF9[]       = _( "DECORATION" );
const u8 gUnknown_085EAE04[]       = _( "PACK UP" );
const u8 gUnknown_085EAE0C[]       = _( "COUNT" );
const u8 gUnknown_085EAE12[]       = _( "REGISTRY" );
const u8 gUnknown_085EAE1B[]       = _( "INFORMATION" );
const u8 gUnknown_085EAE27[]       = _( "MACH" );
const u8 gUnknown_085EAE2C[]       = _( "ACRO" );
const u8 gUnknown_085EAE31[]       = _( "PSN" );
const u8 gUnknown_085EAE35[]       = _( "PAR" );
const u8 gUnknown_085EAE39[]       = _( "SLP" );
const u8 gUnknown_085EAE3D[]       = _( "BRN" );
const u8 gUnknown_085EAE41[]       = _( "FRZ" );
const u8 gUnknown_085EAE45[]       = _( "TOXIC" );
const u8 gUnknown_085EAE4B[]       = _( "OK" );
const u8 gUnknown_085EAE4E[]       = _( "QUIT" );
const u8 gUnknown_085EAE53[]       = _( "Saw it" );
const u8 gUnknown_085EAE5A[]       = _( "Not yet" );
const u8 gText_Yes[]               = _( "YES" );
const u8 gText_No[]                = _( "NO" );
const u8 gUnknown_085EAE69[]       = _( "INFO" );
const u8 gUnknown_085EAE6E[]       = _( "SINGLE BATTLE" );
const u8 gUnknown_085EAE7C[]       = _( "DOUBLE BATTLE" );
const u8 gUnknown_085EAE8A[]       = _( "MULTI BATTLE" );
const u8 gUnknown_085EAE97[]       = _( "MR. BRINEY" );
const u8 gUnknown_085EAEA2[]       = _( "CHALLENGE" );
const u8 gUnknown_085EAEAC[]       = _( "INFO" );
const u8 gText_Lv50[]              = _( "LV. 50" );
const u8 gText_OpenLevel[]         = _( "OPEN LEVEL" );
const u8 gUnknown_085EAEC3[]       = _( "FRESH WATER{CLEAR_TO 0x48}¥200" );
const u8 gUnknown_085EAED6[]       = _( "SODA POP{CLEAR_TO 0x48}¥300" );
const u8 gUnknown_085EAEE6[]       = _( "LEMONADE{CLEAR_TO 0x48}¥350" );
const u8 gUnknown_085EAEF6[]       = _( "HOW TO RIDE" );
const u8 gUnknown_085EAF02[]       = _( "HOW TO TURN" );
const u8 gUnknown_085EAF0E[]       = _( "SANDY SLOPES" );
const u8 gUnknown_085EAF1B[]       = _( "WHEELIES" );
const u8 gUnknown_085EAF24[]       = _( "BUNNY-HOPS" );
const u8 gUnknown_085EAF2F[]       = _( "JUMP" );
const u8 gUnknown_085EAF34[]       = _( "Satisfied" );
const u8 gUnknown_085EAF3E[]       = _( "Dissatisfied" );
const u8 gUnknown_085EAF4B[]       = _( "DEEPSEATOOTH" );
const u8 gUnknown_085EAF58[]       = _( "DEEPSEASCALE" );
const u8 gUnknown_085EAF65[]       = _( "BLUE FLUTE" );
const u8 gUnknown_085EAF70[]       = _( "YELLOW FLUTE" );
const u8 gUnknown_085EAF7D[]       = _( "RED FLUTE" );
const u8 gUnknown_085EAF87[]       = _( "WHITE FLUTE" );
const u8 gUnknown_085EAF93[]       = _( "BLACK FLUTE" );
const u8 gUnknown_085EAF9F[]       = _( "GLASS CHAIR" );
const u8 gUnknown_085EAFAB[]       = _( "GLASS DESK" );
const u8 gUnknown_085EAFB6[]       = _( "TREECKO DOLL 1,000 COINS" );
const u8 gUnknown_085EAFCF[]       = _( "TORCHIC DOLL 1,000 COINS" );
const u8 gUnknown_085EAFE8[]       = _( "MUDKIP DOLL   1,000 COINS" );
const u8 gUnknown_085EB002[]       = _( "  50 COINS    ¥1,000" );
const u8 gUnknown_085EB017[]       = _( "500 COINS  ¥10,000" );
const u8 gUnknown_085EB02A[]       = _( "Excellent" );
const u8 gUnknown_085EB034[]       = _( "Not so good" );
const u8 gUnknown_085EB040[]       = _( "RED SHARD" );
const u8 gUnknown_085EB04A[]       = _( "YELLOW SHARD" );
const u8 gUnknown_085EB057[]       = _( "BLUE SHARD" );
const u8 gUnknown_085EB062[]       = _( "GREEN SHARD" );
const u8 gText_BattleFrontier[]    = _( "BATTLE FRONTIER" );
const u8 gUnknown_085EB07E[]       = _( "Right" );
const u8 gUnknown_085EB084[]       = _( "Left" );
const u8 gUnknown_085EB089[]       = _( "TM32{CLEAR_TO 0x48}1,500 COINS" );
const u8 gUnknown_085EB09C[]       = _( "TM29{CLEAR_TO 0x48}3,500 COINS" );
const u8 gUnknown_085EB0AF[]       = _( "TM35{CLEAR_TO 0x48}4,000 COINS" );
const u8 gUnknown_085EB0C2[]       = _( "TM24{CLEAR_TO 0x48}4,000 COINS" );
const u8 gUnknown_085EB0D5[]       = _( "TM13{CLEAR_TO 0x48}4,000 COINS" );
const u8 gText_Cool[]              = _( "COOL" );
const u8 gText_Beauty[]            = _( "BEAUTY" );
const u8 gText_Cute[]              = _( "CUTE" );
const u8 gText_Smart[]             = _( "SMART" );
const u8 gText_Tough[]             = _( "TOUGH" );
const u8 gText_Normal[]            = _( "NORMAL" );
const u8 gText_Super[]             = _( "SUPER" );
const u8 gText_Hyper[]             = _( "HYPER" );
const u8 gText_Master[]            = _( "MASTER" );
const u8 gText_Cool2[]             = _( "COOL" );
const u8 gText_Beauty2[]           = _( "BEAUTY" );
const u8 gText_Cute2[]             = _( "CUTE" );
const u8 gText_Smart2[]            = _( "SMART" );
const u8 gText_Tough2[]            = _( "TOUGH" );
const u8 gText_Items[]             = _( "ITEMS" );
const u8 gText_Key_Items[]         = _( "KEY ITEMS" );
const u8 gText_Poke_Balls[]        = _( "POKé BALLS" );
const u8 gText_TMs_Hms[]           = _( "TMs & HMs" );
const u8 gText_Berries2[]          = _( "BERRIES" );
const u8 gText_SomeonesPC[]        = _( "SOMEONE'S PC" );
const u8 gText_LanettesPC[]        = _( "LANETTE'S PC" );
const u8 gText_PlayersPC[]         = _( "{PLAYER}'s PC" );
const u8 gText_HallOfFame[]        = _( "HALL OF FAME" );
const u8 gText_LogOff[]            = _( "LOG OFF" );
const u8 gText_Opponent[]          = _( "OPPONENT" );
const u8 gText_Tourney_Tree[]      = _( "TOURNEY TREE" );
const u8 gText_ReadyToStart[]      = _( "READY TO START" );
const u8 gText_NormalRank[]        = _( "NORMAL RANK" );
const u8 gText_SuperRank[]         = _( "SUPER RANK" );
const u8 gText_HyperRank[]         = _( "HYPER RANK" );
const u8 gText_MasterRank[]        = _( "MASTER RANK" );
const u8 gText_Single2[]           = _( "SINGLE" );
const u8 gText_Double2[]           = _( "DOUBLE" );
const u8 gText_Multi[]             = _( "MULTI" );
const u8 gText_MultiLink[]         = _( "MULTI-LINK" );
const u8 gText_BattleBag[]         = _( "BATTLE BAG" );
const u8 gText_HeldItem[]          = _( "HELD ITEM" );
const u8 gText_LinkContest[]       = _( "LINK CONTEST" );
const u8 gText_AboutE_Mode[]       = _( "ABOUT E-MODE" );
const u8 gText_AboutG_Mode[]       = _( "ABOUT G-MODE" );
const u8 gText_E_Mode[]            = _( "E-MODE" );
const u8 gText_G_Mode[]            = _( "G-MODE" );
const u8 gText_MenuOptionPokedex[] = _( "POKéDEX" );
const u8 gText_MenuOptionPokemon[] = _( "POKéMON" );
const u8 gText_MenuOptionBag[]     = _( "BAG" );
const u8 gText_MenuOptionPokenav[] = _( "POKéNAV" );
const u8 gUnknown_085EB278[]       = _( "" );
const u8 gText_MenuOptionSave[]    = _( "SAVE" );
const u8 gText_MenuOptionOption[]  = _( "OPTION" );
const u8 gText_MenuOptionExit[]    = _( "EXIT" );
const u8 gUnknown_085EB28A[]       = __( "  " );
const u8 gUnknown_085EB28C[]       = _( "5BP" );
const u8 gUnknown_085EB290[]       = _( "10BP" );
const u8 gUnknown_085EB295[]       = _( "15BP" );
const u8 gUnknown_085EB29A[]       = _( "RED TENT" );
const u8 gUnknown_085EB2A3[]       = _( "BLUE TENT" );
const u8 gText_SouthernIsland[]    = _( "SOUTHERN ISLAND" );
const u8 gText_BirthIsland[]       = _( "BIRTH ISLAND" );
const u8 gText_FarawayIsland[]     = _( "FARAWAY ISLAND" );
const u8 gText_NavelRock[]         = _( "NAVEL ROCK" );
const u8 gUnknown_085EB2E4[]       = _( "CLAW FOSSIL" );
const u8 gUnknown_085EB2F0[]       = _( "ROOT FOSSIL" );
const u8 gUnknown_085EB2FC[]       = _( "NO" );
const u8 gUnknown_085EB2FF[]       = _( "I'll battle now!" );
const u8 gUnknown_085EB310[]       = _( "I won!" );
const u8 gUnknown_085EB317[]       = _( "I lost!" );
const u8 gUnknown_085EB31F[]       = _( "I won't tell." );
const u8 gText_NormalTagMatch[]    = _( "NORMAL TAG MATCH" );
const u8 gText_VarietyTagMatch[]   = _( "VARIETY TAG MATCH" );
const u8 gText_UniqueTagMatch[]    = _( "UNIQUE TAG MATCH" );
const u8 gText_ExpertTagMatch[]    = _( "EXPERT TAG MATCH" );
const u8 gUnknown_085EB372[]       = _( "TRADE CENTER" );
const u8 gUnknown_085EB37F[]       = _( "COLOSSEUM" );
const u8 gUnknown_085EB389[]       = _( "RECORD CORNER" );
const u8 gUnknown_085EB397[]       = _( "BERRY CRUSH" );
const u8 gUnknown_085EB3A3[]       = _( "" );
const u8 gUnknown_085EB3A4[]       = _( "POKéMON JUMP" );
const u8 gUnknown_085EB3B1[]       = _( "DODRIO BERRY-PICKING" );
const u8 gUnknown_085EB3C6[]       = _( "BECOME LEADER" );
const u8 gUnknown_085EB3D4[]       = _( "JOIN GROUP" );
const u8 gUnknown_085EB3DF[]       = _( "TWO STYLES" );
const u8 gUnknown_085EB3EA[]       = _( "LV. 50" );
const u8 gUnknown_085EB3F1[]       = _( "OPEN LEVEL" );
const u8 gUnknown_085EB3FC[]       = _( "{PKMN} TYPE & NO." );
const u8 gUnknown_085EB40A[]       = _( "HOLD ITEMS" );
const u8 gUnknown_085EB415[]       = _( "SYMBOLS" );
const u8 gUnknown_085EB41D[]       = _( "RECORD" );
const u8 gUnknown_085EB424[]       = _( "BATTLE PTS" );
const u8 gUnknown_085EB42F[]       = _( "TOWER INFO" );
const u8 gUnknown_085EB43A[]       = _( "BATTLE {PKMN}" );
const u8 gUnknown_085EB444[]       = _( "BATTLE SALON" );
const u8 gUnknown_085EB451[]       = _( "MULTI-LINK" );
const u8 gUnknown_085EB45C[]       = _( "BATTLE RULES" );
const u8 gUnknown_085EB469[]       = _( "JUDGE: MIND" );
const u8 gUnknown_085EB475[]       = _( "JUDGE: SKILL" );
const u8 gUnknown_085EB482[]       = _( "JUDGE: BODY" );
const u8 gUnknown_085EB48E[]       = _( "MATCHUP" );
const u8 gUnknown_085EB496[]       = _( "TOURNEY TREE" );
const u8 gUnknown_085EB4A3[]       = _( "DOUBLE KO" );
const u8 gUnknown_085EB4AD[]       = _( "BASIC RULES" );
const u8 gUnknown_085EB4B9[]       = _( "SWAP: PARTNER" );
const u8 gUnknown_085EB4C7[]       = _( "SWAP: NUMBER" );
const u8 gUnknown_085EB4D4[]       = _( "SWAP: NOTES" );
const u8 gUnknown_085EB4E0[]       = _( "OPEN LEVEL" );
const u8 gText_BattleBasics[]      = _( "BATTLE BASICS" );
const u8 gText_PokemonNature[]     = _( "POKéMON NATURE" );
const u8 gText_PokemonMoves[]      = _( "POKéMON MOVES" );
const u8 gText_Underpowered[]      = _( "UNDERPOWERED" );
const u8 gText_WhenInDanger[]      = _( "WHEN IN DANGER" );
const u8 gUnknown_085EB532[]       = _( "PYRAMID: POKéMON" );
const u8 gUnknown_085EB543[]       = _( "PYRAMID: TRAINERS" );
const u8 gUnknown_085EB555[]       = _( "PYRAMID: MAZE" );
const u8 gUnknown_085EB563[]       = _( "BATTLE BAG" );
const u8 gUnknown_085EB56E[]       = _( "POKéNAV AND BAG" );
const u8 gUnknown_085EB57E[]       = _( "HELD ITEMS" );
const u8 gUnknown_085EB589[]       = _( "POKéMON ORDER" );
const u8 gUnknown_085EB597[]       = _( "BATTLE POKéMON" );
const u8 gText_BattleTrainers[]    = _( "BATTLE TRAINERS" );
const u8 gUnknown_085EB5B6[]       = _( "GO ON" );
const u8 gUnknown_085EB5BC[]       = _( "RECORD" );
const u8 gUnknown_085EB5C3[]       = _( "REST" );
const u8 gUnknown_085EB5C8[]       = _( "RETIRE" );
const u8 gText_99TimesPlus[]       = _( "99 times +" );
const u8 gText_1MinutePlus[]       = _( "1 minute +" );
const u8 gText_SpaceSeconds[]      = _( " seconds" );
const u8 gText_SpaceTimes[]        = _( " time(s)" );
const u8 gUnknown_085EB5F7[]       = _( "." );
const u8 gText_BigGuy[]            = _( "Big guy" );
const u8 gText_BigGirl[]           = _( "Big girl" );
const u8 gText_Son[]               = _( "son" );
const u8 gText_Daughter[]          = _( "daughter" );
const u8 gText_BlueFlute[]         = _( "BLUE FLUTE" );
const u8 gText_YellowFlute[]       = _( "YELLOW FLUTE" );
const u8 gText_RedFlute[]          = _( "RED FLUTE" );
const u8 gText_WhiteFlute[]        = _( "WHITE FLUTE" );
const u8 gText_BlackFlute[]        = _( "BLACK FLUTE" );
const u8 gText_PrettyChair[]       = _( "PRETTY CHAIR" );
const u8 gText_PrettyDesk[]        = _( "PRETTY DESK" );
const u8 gText_1F[]                = _( "1F" );
const u8 gText_2F[]                = _( "2F" );
const u8 gText_3F[]                = _( "3F" );
const u8 gText_4F[]                = _( "4F" );
const u8 gText_5F[]                = _( "5F" );
const u8 gText_6F[]                = _( "6F" );
const u8 gText_7F[]                = _( "7F" );
const u8 gText_8F[]                = _( "8F" );
const u8 gText_9F[]                = _( "9F" );
const u8 gText_10F[]               = _( "10F" );
const u8 gText_11F[]               = _( "11F" );
const u8 gText_B1F[]               = _( "B1F" );
const u8 gText_B2F[]               = _( "B2F" );
const u8 gText_B3F[]               = _( "B3F" );
const u8 gText_B4F[]               = _( "B4F" );
const u8 gText_Rooftop[]           = _( "ROOFTOP" );
const u8 gText_ElevatorNowOn[]     = _( "Now on:" );
const u8 gText_BP[]                = _( "BP" );
const u8 gText_EnergyPowder50[] = _( "ENERGYPOWDER{CLEAR_TO 0x72}{SIZE 0}50" );
const u8 gText_EnergyRoot80[]   = _( "ENERGY ROOT{CLEAR_TO 0x72}{SIZE 0}80" );
const u8 gText_HealPowder50[]   = _( "HEAL POWDER{CLEAR_TO 0x72}{SIZE 0}50" );
const u8 gText_RevivalHerb300[] =
	_( "REVIVAL HERB{CLEAR_TO 0x6C}{SIZE 0}300" );
const u8 gText_Protein1000[]     = _( "PROTEIN{CLEAR_TO 0x63}{SIZE 0}1,000" );
const u8 gText_Iron1000[]        = _( "IRON{CLEAR_TO 0x63}{SIZE 0}1,000" );
const u8 gText_Carbos1000[]      = _( "CARBOS{CLEAR_TO 0x63}{SIZE 0}1,000" );
const u8 gText_Calcium1000[]     = _( "CALCIUM{CLEAR_TO 0x63}{SIZE 0}1,000" );
const u8 gText_Zinc1000[]        = _( "ZINC{CLEAR_TO 0x63}{SIZE 0}1,000" );
const u8 gText_HPUp1000[]        = _( "HP UP{CLEAR_TO 0x63}{SIZE 0}1,000" );
const u8 gText_PPUp3000[]        = _( "PP UP{CLEAR_TO 0x63}{SIZE 0}3,000" );
const u8 gText_RankingHall[]     = _( "RANKING HALL" );
const u8 gText_ExchangeService[] = _( "EXCHANGE SERVICE" );
const u8 gText_LilycoveCity[]    = _( "LILYCOVE CITY" );
const u8 gText_SlateportCity[]   = _( "SLATEPORT CITY" );
const u8 gText_CaveOfOrigin[]    = _( "CAVE OF ORIGIN" );
const u8 gText_MtPyre[]          = _( "MT. PYRE" );
const u8 gText_SkyPillar[]       = _( "SKY PILLAR" );
const u8 gText_DontRemember[]    = _( "Don't remember" );
const u8 gText_Exit[]            = _( "EXIT" );
const u8 gText_ExitFromBox[]     = _( "Exit from the BOX?" );
const u8 gText_WhatDoYouWantToDo[]   = _( "What do you want to do?" );
const u8 gText_PleasePickATheme[]    = _( "Please pick a theme." );
const u8 gText_PickTheWallpaper[]    = _( "Pick the wallpaper." );
const u8 gText_PkmnIsSelected[]      = _( "{SPECIAL_F7 0x00} is selected." );
const u8 gText_JumpToWhichBox[]      = _( "Jump to which BOX?" );
const u8 gText_DepositInWhichBox[]   = _( "Deposit in which BOX?" );
const u8 gText_PkmnWasDeposited[]    = _( "{SPECIAL_F7 0x00} was deposited." );
const u8 gText_BoxIsFull2[]          = _( "The BOX is full." );
const u8 gText_ReleaseThisPokemon[]  = _( "Release this POKéMON?" );
const u8 gText_PkmnWasReleased[]     = _( "{SPECIAL_F7 0x00} was released." );
const u8 gText_ByeByePkmn[]          = _( "Bye-bye, {SPECIAL_F7 0x00}!" );
const u8 gText_MarkYourPkmn[]        = _( "Mark your POKéMON." );
const u8 gText_ThatsYourLastPkmn[]   = _( "That's your last POKéMON!" );
const u8 gText_YourPartysFull[]      = _( "Your party's full!" );
const u8 gText_YoureHoldingAPkmn[]   = _( "You're holding a POKéMON!" );
const u8 gText_WhichOneWillYouTake[] = _( "Which one will you take?" );
const u8 gText_YouCantReleaseAnEgg[] = _( "You can't release an EGG." );
const u8 gText_ContinueBoxOperations[]   = _( "Continue BOX operations?" );
const u8 gText_PkmnCameBack[]            = _( "{SPECIAL_F7 0x00} came back!" );
const u8 gText_WasItWorriedAboutYou[]    = _( "Was it worried about you?" );
const u8 gText_FourEllipsesExclamation[] = _( "… … … … !" );
const u8 gText_PleaseRemoveTheMail[]     = _( "Please remove the MAIL." );
const u8 gText_GiveToAPkmn[]             = _( "GIVE to a POKéMON?" );
const u8 gText_PlacedItemInBag[]         = _( "Placed item in the BAG." );
const u8 gText_BagIsFull2[]              = _( "The BAG is full." );
const u8 gText_PutItemInBag[]            = _( "Put this item in the BAG?" );
const u8 gText_ItemIsNowHeld[]    = _( "{SPECIAL_F7 0x00} is now held." );
const u8 gText_ChangedToNewItem[] = _( "Changed to {SPECIAL_F7 0x00}." );
const u8 gText_MailCantBeStored[] = _( "MAIL can't be stored!" );
const u8 gPCText_Cancel[]         = _( "CANCEL" );
const u8 gPCText_Store[]          = _( "STORE" );
const u8 gPCText_Withdraw[]       = _( "WITHDRAW" );
const u8 gPCText_Shift[]          = _( "SHIFT" );
const u8 gPCText_Move[]           = _( "MOVE" );
const u8 gPCText_Place[]          = _( "PLACE" );
const u8 gPCText_Summary[]        = _( "SUMMARY" );
const u8 gPCText_Release[]        = _( "RELEASE" );
const u8 gPCText_Mark[]           = _( "MARK" );
const u8 gPCText_Name[]           = _( "NAME" );
const u8 gPCText_Jump[]           = _( "JUMP" );
const u8 gPCText_Wallpaper[]      = _( "WALLPAPER" );
const u8 gPCText_Take[]           = _( "TAKE" );
const u8 gPCText_Give[]           = _( "GIVE" );
const u8 gPCText_Switch[]         = _( "SWITCH" );
const u8 gPCText_Bag[]            = _( "BAG" );
const u8 gPCText_Info[]           = _( "INFO" );
const u8 gPCText_Scenery1[]       = _( "SCENERY 1" );
const u8 gPCText_Scenery2[]       = _( "SCENERY 2" );
const u8 gPCText_Scenery3[]       = _( "SCENERY 3" );
const u8 gPCText_Etcetera[]       = _( "ETCETERA" );
const u8 gPCText_Friends[]        = _( "FRIENDS" );
const u8 gPCText_Forest[]         = _( "FOREST" );
const u8 gPCText_City[]           = _( "CITY" );
const u8 gPCText_Desert[]         = _( "DESERT" );
const u8 gPCText_Savanna[]        = _( "SAVANNA" );
const u8 gPCText_Crag[]           = _( "CRAG" );
const u8 gPCText_Volcano[]        = _( "VOLCANO" );
const u8 gPCText_Snow[]           = _( "SNOW" );
const u8 gPCText_Cave[]           = _( "CAVE" );
const u8 gPCText_Beach[]          = _( "BEACH" );
const u8 gPCText_Seafloor[]       = _( "SEAFLOOR" );
const u8 gPCText_River[]          = _( "RIVER" );
const u8 gPCText_Sky[]            = _( "SKY" );
const u8 gPCText_PolkaDot[]       = _( "POLKA-DOT" );
const u8 gPCText_Pokecenter[]     = _( "POKéCENTER" );
const u8 gPCText_Machine[]        = _( "MACHINE" );
const u8 gPCText_Simple[]         = _( "SIMPLE" );
const u8 gUnknown_085EBB56[]      = _( "What would you like to do?" );
const u8 gText_WithdrawPokemon[]  = _( "WITHDRAW POKéMON" );
const u8 gText_DepositPokemon[]   = _( "DEPOSIT POKéMON" );
const u8 gText_MovePokemon[]      = _( "MOVE POKéMON" );
const u8 gText_MoveItems[]        = _( "MOVE ITEMS" );
const u8 gText_SeeYa[]            = _( "SEE YA!" );
const u8 gText_WithdrawMonDescription[] =
	_( "Move POKéMON stored in BOXES to\nyour party." );
const u8 gText_DepositMonDescription[] =
	_( "Store POKéMON in your party in BOXES." );
const u8 gText_MoveMonDescription[] =
	_( "Organize the POKéMON in BOXES and\nin your party." );
const u8 gText_MoveItemsDescription[] =
	_( "Move items held by any POKéMON\nin a BOX or your party." );
const u8 gText_SeeYaDescription[] = _( "Return to the previous menu." );
const u8 gText_JustOnePkmn[]     = _( "There is just one POKéMON with you." );
const u8 gText_PartyFull[]       = _( "Your party is full!" );
const u8 gText_Box[]             = _( "BOX" );
const u8 gUnknown_085EBCC5[]     = _( "Check the map of the HOENN region." );
const u8 gUnknown_085EBCE8[]     = _( "Check POKéMON in detail." );
const u8 gUnknown_085EBD01[]     = _( "Call a registered TRAINER." );
const u8 gUnknown_085EBD1C[]     = _( "Check obtained RIBBONS." );
const u8 gUnknown_085EBD34[]     = _( "Put away the POKéNAV." );
const u8 gText_NoRibbonWinners[] = _( "There are no RIBBON winners." );
const u8 gUnknown_085EBD67[]     = _( "No TRAINERS are registered." );
const u8 gUnknown_085EBD83[]     = _( "Check party POKéMON in detail." );
const u8 gUnknown_085EBDA2[]     = _( "Check all POKéMON in detail." );
const u8 gUnknown_085EBDBF[]     = _( "Return to the POKéNAV menu." );
const u8 gUnknown_085EBDDB[]     = _( "Find cool POKéMON." );
const u8 gUnknown_085EBDEE[]     = _( "Find beautiful POKéMON." );
const u8 gUnknown_085EBE06[]     = _( "Find cute POKéMON." );
const u8 gUnknown_085EBE19[]     = _( "Find smart POKéMON." );
const u8 gUnknown_085EBE2D[]     = _( "Find tough POKéMON." );
const u8 gUnknown_085EBE41[]     = _( "Return to the CONDITION menu." );
const u8 gText_NumberRegistered[]          = _( "No. registered" );
const u8 gText_NumberOfBattles[]           = _( "No. of battles" );
const u8 gUnknown_085EBE7D[]               = _( "DETAIL" );
const u8 gUnknown_085EBE84[]               = _( "CALL" );
const u8 gUnknown_085EBE89[]               = _( "EXIT" );
const u8 gUnknown_085EBE8E[]               = _( "Can't call opponent here." );
const u8 gText_PokenavMatchCall_Strategy[] = _( "STRATEGY" );
const u8 gText_PokenavMatchCall_TrainerPokemon[]   = _( "TRAINER'S POKéMON" );
const u8 gText_PokenavMatchCall_SelfIntroduction[] = _( "SELF-INTRODUCTION" );
const u8 gText_Pokenav_ClearButtonList[]           = _( "{CLEAR 0x80}" );
const u8 gText_PokenavMap_ZoomedOutButtons[] =
	_( "{A_BUTTON}ZOOM {B_BUTTON}CANCEL" );
const u8 gText_PokenavMap_ZoomedInButtons[] =
	_( "{A_BUTTON}FULL {B_BUTTON}CANCEL" );
const u8 gText_PokenavCondition_MonListButtons[] =
	_( "{A_BUTTON}CONDITION {B_BUTTON}CANCEL" );
const u8 gText_PokenavCondition_MonStatusButtons[] =
	_( "{A_BUTTON}MARKINGS {B_BUTTON}CANCEL" );
const u8 gText_PokenavCondition_MarkingButtons[] =
	_( "{A_BUTTON}SELECT MARK {B_BUTTON}CANCEL" );
const u8 gText_PokenavMatchCall_TrainerListButtons[] =
	_( "{A_BUTTON}MENU {B_BUTTON}CANCEL" );
const u8 gText_PokenavMatchCall_CallMenuButtons[] =
	_( "{A_BUTTON}OK {B_BUTTON}CANCEL" );
const u8 gText_PokenavMatchCall_CheckTrainerButtons[] =
	_( "{B_BUTTON}CANCEL" );
const u8 gText_PokenavRibbons_MonListButtons[] =
	_( "{A_BUTTON}RIBBONS {B_BUTTON}CANCEL" );
const u8 gText_PokenavRibbons_RibbonListButtons[] =
	_( "{A_BUTTON}CHECK {B_BUTTON}CANCEL" );
const u8 gText_PokenavRibbons_RibbonCheckButtons[] = _( "{B_BUTTON}CANCEL" );
const u8 gText_NatureSlash[]                       = _( "NATURE/" );
const u8 gText_TrainerCloseBy[] =
	_( "That TRAINER is close by.\nTalk to the TRAINER in person!" );
const u8 gText_InParty[]     = _( "IN PARTY" );
const u8 gText_Number2[]     = _( "No. " );
const u8 gUnknown_085EBFDC[] = _( "RIBBONS" );
const u8 gUnknown_085EBFE4[] = _(
	"{SPECIAL_F7 0x00}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GREY WHITE LIGHT_GREY}/{LV}{SPECIAL_F7 0x01}" );
const u8 gUnknown_085EBFF6[] = _(
	"{SPECIAL_F7 0x00}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GREY WHITE LIGHT_GREY}/{LV}{SPECIAL_F7 0x01}" );
const u8 gUnknown_085EC008[] = _( "{SPECIAL_F7 0x00}/{LV}{SPECIAL_F7 0x01}" );
const u8 gText_Unknown[]     = _( "UNKNOWN" );
const u8 gUnknown_085EC017[] = _( "CALL" );
const u8 gUnknown_085EC01C[] = _( "CHECK" );
const u8 gUnknown_085EC022[] = _( "CANCEL" );
const u8 gText_NumberF700[]  = _( "No. {SPECIAL_F7 0x00}" );
const u8 gText_RibbonsF700[] = _( "RIBBONS {SPECIAL_F7 0x00}" );
const u8 gUnknown_085EC03B[] = _(
	"{SPECIAL_F7 0x00}{COLOR_HIGHLIGHT_SHADOW LIGHT_RED WHITE GREEN}♂{COLOR_HIGHLIGHT_SHADOW DARK_GREY WHITE LIGHT_GREY}/{LV}{SPECIAL_F7 0x01}{SPECIAL_F7 0x02}" );
const u8 gUnknown_085EC04F[] = _(
	"{SPECIAL_F7 0x00}{COLOR_HIGHLIGHT_SHADOW LIGHT_GREEN WHITE BLUE}♀{COLOR_HIGHLIGHT_SHADOW DARK_GREY WHITE LIGHT_GREY}/{LV}{SPECIAL_F7 0x01}{SPECIAL_F7 0x02}" );
const u8 gUnknown_085EC063[] =
	_( "{SPECIAL_F7 0x00}/{LV}{SPECIAL_F7 0x01}{SPECIAL_F7 0x02}" );
const u8 gText_CombineFourWordsOrPhrases[] =
	_( "Combine four words or phrases" );
const u8 gText_AndMakeYourProfile[] = _( "and make your profile." );
const u8 gText_CombineSixWordsOrPhrases[] =
	_( "Combine six words or phrases" );
const u8 gText_AndMakeAMessage[] = _( "and make a message." );
const u8 gText_FindWordsThatDescribeYour[] =
	_( "Find words that describe your" );
const u8 gText_FeelingsRightNow[] = _( "feelings right now." );
const u8 gUnknown_085EC104[]      = _( "With four phrases," );
const u8 gText_CombineNineWordsOrPhrases[] =
	_( "Combine nine words or phrases" );
const u8 gText_AndMakeAMessage2[] = _( "and make a message." );
const u8 gText_ChangeJustOneWordOrPhrase[] =
	_( "Change just one word or phrase" );
const u8 gText_AndImproveTheBardsSong[] = _( "and improve the BARD's song." );
const u8 gText_YourProfile[]            = _( "Your profile" );
const u8 gText_YourFeelingAtTheBattlesStart[] =
	_( "Your feeling at the battle's start" );
const u8 gText_WhatYouSayIfYouWin[] = _( "What you say if you win a battle" );
const u8 gText_WhatYouSayIfYouLose[] =
	_( "What you say if you lose a battle" );
const u8 gText_TheAnswer[]      = _( "The answer" );
const u8 gText_TheMailMessage[] = _( "The MAIL message" );
const u8 gUnknown_085EC214[]    = _( "The MAIL salutation" );
const u8 gText_TheBardsSong2[]  = _( "The new song" );
const u8 gText_CombineTwoWordsOrPhrases[] =
	_( "Combine two words or phrases" );
const u8 gText_AndMakeATrendySaying[] = _( "and make a trendy saying." );
const u8 gText_TheTrendySaying[]      = _( "The trendy saying" );
const u8 gText_IsAsShownOkay[]        = _( "is as shown. Okay?" );
const u8 gText_CombineTwoWordsOrPhrases2[] =
	_( "Combine two words or phrases" );
const u8 gText_ToTeachHerAGoodSaying[] = _( "to teach her a good saying." );
const u8 gText_FindWordsWhichFit[]     = _( "Find words which fit" );
const u8 gText_TheTrainersImage[]      = _( "the TRAINER's image." );
const u8 gText_TheImage[]              = _( "The image:" );
const u8 gText_OutOfTheListedChoices[] = _( "Out of the listed choices," );
const u8 gText_SelectTheAnswerToTheQuiz[] =
	_( "select the answer to the quiz!" );
const u8 gText_AndCreateAQuiz[]       = _( "and create a quiz!" );
const u8 gText_PickAWordOrPhraseAnd[] = _( "Pick a word or phrase and" );
const u8 gText_SetTheQuizAnswer[]     = _( "set the quiz answer." );
const u8 gText_TheAnswerColon[]       = _( "The answer:" );
const u8 gUnknown_085EC387[]          = _( "The quiz:" );
const u8 gText_ApprenticePhrase[]     = _( "Apprentice's phrase:" );
const u8 gText_QuitEditing[]          = _( "Quit editing?" );
const u8 gText_StopGivingPkmnMail[]   = _( "Stop giving the POKéMON MAIL?" );
const u8 gText_AndFillOutTheQuestionnaire[] =
	_( "and fill out the questionnaire." );
const u8 gText_LetsReplyToTheInterview[] =
	_( "Let's reply to the interview!" );
const u8 gText_AllTextBeingEditedWill[] =
	_( "All the text being edited will" );
const u8 gText_BeDeletedThatOkay[] = _( "be deleted. Is that okay?" );
const u8 gUnknown_085EC449[]       = _( "Quit editing?" );
const u8 gUnknown_085EC457[]       = _( "The edited text will not be saved." );
const u8 gUnknown_085EC47A[]       = _( "Is that okay?" );
const u8 gUnknown_085EC488[]       = _( "Please enter a phrase or word." );
const u8 gUnknown_085EC4A7[]       = _( "The entire text can't be deleted." );
const u8 gText_OnlyOnePhrase[]     = _( "Only one phrase may be changed." );
const u8 gText_OriginalSongWillBeUsed[] =
	_( "The original song will be used." );
const u8 gUnknown_085EC509[] = _( "That's trendy already!" );
const u8 gText_CombineTwoWordsOrPhrases3[] =
	_( "Combine two words or phrases." );
const u8 gUnknown_085EC53E[]          = _( "Quit giving information?" );
const u8 gUnknown_085EC557[]          = _( "Stop giving the POKéMON MAIL?" );
const u8 gUnknown_085EC575[]          = _( "Create a quiz!" );
const u8 gUnknown_085EC584[]          = _( "Set the answer!" );
const u8 gUnknown_085EC594[]          = _( "Cancel the selection?" );
const u8 gText_Profile[]              = _( "PROFILE" );
const u8 gText_AtTheBattlesStart[]    = _( "At the battle's start:" );
const u8 gText_UponWinningABattle[]   = _( "Upon winning a battle:" );
const u8 gText_UponLosingABattle[]    = _( "Upon losing a battle:" );
const u8 gText_TheBardsSong[]         = _( "The BARD's Song" );
const u8 gText_WhatsHipAndHappening[] = _( "What's hip and happening?" );
const u8 gText_Interview[]            = _( "Interview" );
const u8 gText_GoodSaying[]           = _( "Good saying" );
const u8 gText_FansQuestion[]         = _( "Fan's question" );
const u8 gUnknown_085EC645[]          = _( "クイズの こたえは？" );
const u8 gText_ApprenticesPhrase[]    = _( "Apprentice's phrase" );
const u8 gText_Questionnaire[]        = _( "QUESTIONNAIRE" );
const u8 gText_YouCannotQuitHere[]    = _( "You cannot quit here." );
const u8 gText_SectionMustBeCompleted[] =
	_( "This section must be completed." );
const u8 gText_F700sQuiz[]               = _( "{SPECIAL_F7 0x00}'s quiz" );
const u8 gText_Lady[]                    = _( "Lady" );
const u8 gText_AfterYouHaveReadTheQuiz[] = _( "After you have read the quiz" );
const u8 gText_QuestionPressTheAButton[] =
	_( "question, press the A Button." );
const u8 gText_TheQuizAnswerIs[] = _( "The quiz answer is?" );
const u8 gText_LikeToQuitQuiz[]  = _( "Would you like to quit this quiz" );
const u8 gText_ChallengeQuestionMark[]  = _( "challenge?" );
const u8 gText_IsThisQuizOK[]           = _( "Is this quiz OK?" );
const u8 gText_CreateAQuiz[]            = _( "Create a quiz!" );
const u8 gText_SelectTheAnswer[]        = _( "Select the answer!" );
const u8 gText_LyricsCantBeDeleted[]    = _( "The lyrics can't be deleted." );
const u8 gText_PokemonLeague[]          = _( "POKéMON LEAGUE" );
const u8 gText_PokemonCenter[]          = _( "POKéMON CENTER" );
const u8 gText_GetsAPokeBlockQuestion[] = _( " gets a {POKEBLOCK}?" );
const u8 gText_Coolness[]               = _( "Coolness " );
const u8 gText_Beauty3[]                = _( "Beauty " );
const u8 gText_Cuteness[]               = _( "Cuteness " );
const u8 gText_Smartness[]              = _( "Smartness " );
const u8 gText_Toughness[]              = _( "Toughness " );
const u8 gText_WasEnhanced[]            = _( "was enhanced!" );
const u8 gText_NothingChanged[]         = _( "Nothing changed!" );
const u8 gText_WontEatAnymore[]         = _( "It won't eat anymore…" );
const u8 gText_SaveFailedCheckingBackup[] = _(
	"Save failed. Checking the backup\nmemory… Please wait.\n{COLOR RED}“Time required: about 1 minute”" );
const u8 gText_BackupMemoryDamaged[] = _(
	"The backup memory is damaged, or\nthe internal battery has run dry.\nYou can still play, but not save." );
const u8 gText_GamePlayCannotBeContinued[] = _(
	"{COLOR RED}“Game play cannot be continued.\nReturning to the title screen…”" );
const u8 gText_CheckCompleted[] =
	_( "Check completed.\nAttempting to save again.\nPlease wait." );
const u8 gText_SaveCompleteGameCannotContinue[] = _(
	"Save completed.\n{COLOR RED}“Game play cannot be continued.\nReturning to the title screen.”" );
const u8 gText_SaveCompletePressA[] =
	_( "Save completed.\n{COLOR RED}“Please press the A Button.”" );
const u8 gText_Ferry[]      = _( "FERRY" );
const u8 gText_SecretBase[] = _( "SECRET BASE" );
const u8 gText_Hideout[]    = _( "HIDEOUT" );
const u8 gText_ResetRTCConfirmCancel[] =
	_( "Reset RTC?\nA: Confirm, B: Cancel" );
const u8 gText_PresentTime[]     = _( "Present time in game" );
const u8 gText_PreviousTime[]    = _( "Previous time in game" );
const u8 gText_PleaseResetTime[] = _( "Please reset the time." );
const u8 gText_ClockHasBeenReset[] =
	_( "The clock has been reset.\nData will be saved. Please wait." );
const u8 gText_SaveCompleted[] = _( "Save completed." );
const u8 gText_SaveFailed[]    = _( "Save failed…" );
const u8 gText_NoSaveFileCantSetTime[] =
	_( "There is no save file, so the time\ncan't be set." );
const u8 gText_InGameClockUsable[] =
	_( "The in-game clock adjustment system\nis now useable." );
const u8 gText_Slots[]             = _( "SLOTS" );
const u8 gText_Roulette[]          = _( "ROULETTE" );
const u8 gText_Good[]              = _( "Good" );
const u8 gText_VeryGood[]          = _( "Very good" );
const u8 gText_Excellent[]         = _( "Excellent" );
const u8 gText_SoSo[]              = _( "So-so" );
const u8 gText_Bad[]               = _( "Bad" );
const u8 gText_TheWorst[]          = _( "The worst" );
const u8 gText_Spicy2[]            = _( "spicy" );
const u8 gText_Dry2[]              = _( "dry" );
const u8 gText_Sweet2[]            = _( "sweet" );
const u8 gText_Bitter2[]           = _( "bitter" );
const u8 gText_Sour2[]             = _( "sour" );
const u8 gText_Single[]            = _( "SINGLE" );
const u8 gText_Double[]            = _( "DOUBLE" );
const u8 gText_Jackpot[]           = _( "jackpot" );
const u8 gText_First[]             = _( "first" );
const u8 gText_Second[]            = _( "second" );
const u8 gText_Third[]             = _( "third" );
const u8 gText_0Pts[]              = _( "0 pts" );
const u8 gText_10Pts[]             = _( "10 pts" );
const u8 gText_20Pts[]             = _( "20 pts" );
const u8 gText_30Pts[]             = _( "30 pts" );
const u8 gText_40Pts[]             = _( "40 pts" );
const u8 gText_50Pts[]             = _( "50 pts" );
const u8 gText_60Pts[]             = _( "60 pts" );
const u8 gText_70Pts[]             = _( "70 pts" );
const u8 gText_80Pts[]             = _( "80 pts" );
const u8 gText_90Pts[]             = _( "90 pts" );
const u8 gText_100Pts[]            = _( "100 pts" );
const u8 gText_QuestionMark[]      = _( "?" );
const u8 gText_KissPoster16BP[]    = _( "KISS POSTER{CLEAR_TO 0x5E}16BP" );
const u8 gText_KissCushion32BP[]   = _( "KISS CUSHION{CLEAR_TO 0x5E}32BP" );
const u8 gText_SmoochumDoll32BP[]  = _( "SMOOCHUM DOLL{CLEAR_TO 0x5E}32BP" );
const u8 gText_TogepiDoll48BP[]    = _( "TOGEPI DOLL{CLEAR_TO 0x5E}48BP" );
const u8 gText_MeowthDoll48BP[]    = _( "MEOWTH DOLL{CLEAR_TO 0x5E}48BP" );
const u8 gText_ClefairyDoll48BP[]  = _( "CLEFAIRY DOLL{CLEAR_TO 0x5E}48BP" );
const u8 gText_DittoDoll48BP[]     = _( "DITTO DOLL{CLEAR_TO 0x5E}48BP" );
const u8 gText_CyndaquilDoll80BP[] = _( "CYNDAQUIL DOLL{CLEAR_TO 0x5E}80BP" );
const u8 gText_ChikoritaDoll80BP[] = _( "CHIKORITA DOLL{CLEAR_TO 0x5E}80BP" );
const u8 gText_TotodileDoll80BP[]  = _( "TOTODILE DOLL{CLEAR_TO 0x5E}80BP" );
const u8 gText_LaprasDoll128BP[]   = _( "LAPRAS DOLL{CLEAR_TO 0x58}128BP" );
const u8 gText_SnorlaxDoll128BP[]  = _( "SNORLAX DOLL{CLEAR_TO 0x58}128BP" );
const u8 gText_VenusaurDoll256BP[] = _( "VENUSAUR DOLL{CLEAR_TO 0x58}256BP" );
const u8 gText_CharizardDoll256BP[] =
	_( "CHARIZARD DOLL{CLEAR_TO 0x58}256BP" );
const u8 gText_BlastoiseDoll256BP[] =
	_( "BLASTOISE DOLL{CLEAR_TO 0x58}256BP" );
const u8 gText_Protein1BP[]         = _( "PROTEIN{CLEAR_TO 0x64}1BP" );
const u8 gText_Calcium1BP[]         = _( "CALCIUM{CLEAR_TO 0x64}1BP" );
const u8 gText_Iron1BP[]            = _( "IRON{CLEAR_TO 0x64}1BP" );
const u8 gText_Zinc1BP[]            = _( "ZINC{CLEAR_TO 0x64}1BP" );
const u8 gText_Carbos1BP[]          = _( "CARBOS{CLEAR_TO 0x64}1BP" );
const u8 gText_HpUp1BP[]            = _( "HP UP{CLEAR_TO 0x64}1BP" );
const u8 gText_Leftovers48BP[]      = _( "LEFTOVERS{CLEAR_TO 0x5E}48BP" );
const u8 gText_WhiteHerb48BP[]      = _( "WHITE HERB{CLEAR_TO 0x5E}48BP" );
const u8 gText_QuickClaw48BP[]      = _( "QUICK CLAW{CLEAR_TO 0x5E}48BP" );
const u8 gText_MentalHerb48BP[]     = _( "MENTAL HERB{CLEAR_TO 0x5E}48BP" );
const u8 gText_BrightPowder64BP[]   = _( "BRIGHTPOWDER{CLEAR_TO 0x5E}64BP" );
const u8 gText_ChoiceBand64BP[]     = _( "CHOICE BAND{CLEAR_TO 0x5E}64BP" );
const u8 gText_KingsRock64BP[]      = _( "KING'S ROCK{CLEAR_TO 0x5E}64BP" );
const u8 gText_FocusBand64BP[]      = _( "FOCUS BAND{CLEAR_TO 0x5E}64BP" );
const u8 gText_ScopeLens64BP[]      = _( "SCOPE LENS{CLEAR_TO 0x5E}64BP" );
const u8 gText_Softboiled16BP[]     = _( "SOFTBOILED{CLEAR_TO 0x4E}16BP" );
const u8 gText_SeismicToss24BP[]    = _( "SEISMIC TOSS{CLEAR_TO 0x4E}24BP" );
const u8 gText_DreamEater24BP[]     = _( "DREAM EATER{CLEAR_TO 0x4E}24BP" );
const u8 gText_MegaPunch24BP[]      = _( "MEGA PUNCH{CLEAR_TO 0x4E}24BP" );
const u8 gText_MegaKick48BP[]       = _( "MEGA KICK{CLEAR_TO 0x4E}48BP" );
const u8 gText_BodySlam48BP[]       = _( "BODY SLAM{CLEAR_TO 0x4E}48BP" );
const u8 gText_RockSlide48BP[]      = _( "ROCK SLIDE{CLEAR_TO 0x4E}48BP" );
const u8 gText_Counter48BP[]        = _( "COUNTER{CLEAR_TO 0x4E}48BP" );
const u8 gText_ThunderWave48BP[]    = _( "THUNDER WAVE{CLEAR_TO 0x4E}48BP" );
const u8 gText_SwordsDance48BP[]    = _( "SWORDS DANCE{CLEAR_TO 0x4E}48BP" );
const u8 gText_DefenseCurl16BP[]    = _( "DEFENSE CURL{CLEAR_TO 0x4E}16BP" );
const u8 gText_Snore24BP[]          = _( "SNORE{CLEAR_TO 0x4E}24BP" );
const u8 gText_MudSlap24BP[]        = _( "MUD-SLAP{CLEAR_TO 0x4E}24BP" );
const u8 gText_Swift24BP[]          = _( "SWIFT{CLEAR_TO 0x4E}24BP" );
const u8 gText_IcyWind24BP[]        = _( "ICY WIND{CLEAR_TO 0x4E}24BP" );
const u8 gText_Endure48BP[]         = _( "ENDURE{CLEAR_TO 0x4E}48BP" );
const u8 gText_PsychUp48BP[]        = _( "PSYCH UP{CLEAR_TO 0x4E}48BP" );
const u8 gText_IcePunch48BP[]       = _( "ICE PUNCH{CLEAR_TO 0x4E}48BP" );
const u8 gText_ThunderPunch48BP[]   = _( "THUNDERPUNCH{CLEAR_TO 0x4E}48BP" );
const u8 gText_FirePunch48BP[]      = _( "FIRE PUNCH{CLEAR_TO 0x4E}48BP" );
const u8 gText_PkmnFainted3[]       = _( "{STR_VAR_1} fainted…\p\n" );
const u8 gText_Marco[]              = _( "MARCO" );
const u8 gText_TrainerCardName[]    = _( "NAME: " );
const u8 gText_TrainerCardIDNo[]    = _( "IDNo." );
const u8 gText_TrainerCardMoney[]   = _( "MONEY" );
const u8 gUnknown_085ECF84[]        = _( "¥" );
const u8 gText_TrainerCardPokedex[] = _( "POKéDEX" );
const u8 gText_EmptyString6[]       = _( "" );
const u8 gText_Colon2[]             = _( ":" );
const u8 gUnknown_085ECF91[]        = _( " points" );
const u8 gText_TrainerCardTime[]    = _( "TIME" );
const u8 gUnknown_085ECF9E[]        = _( "ゲ-ムポイント" );
const u8 gText_Var1sTrainerCard[]   = _( "{STR_VAR_1}'s TRAINER CARD" );
const u8 gText_HallOfFameDebut[]    = _( "HALL OF FAME DEBUT  " );
const u8 gText_LinkBattles[]        = _( "LINK BATTLES" );
const u8 gText_LinkCableBattles[]   = _( "LINK CABLE BATTLES" );
const u8 gText_WinsLosses[]         = _(
        "W:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}  L:{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}" );
const u8 gText_PokemonTrades[]               = _( "POKéMON TRADES" );
const u8 gText_UnionTradesAndBattles[]       = _( "UNION TRADES & BATTLES" );
const u8 gText_BerryCrush[]                  = _( "BERRY CRUSH" );
const u8 gText_WaitingTrainerFinishReading[] = _(
	"Waiting for the other TRAINER to\nfinish reading your TRAINER CARD." );
const u8 gText_PokeblocksWithFriends[] = _( "{POKEBLOCK}S W/FRIENDS" );
const u8 gText_Var1DarkGreyShadowLightGrey[] =
	_( "{STR_VAR_1}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}" );
const u8 gText_WonContestsWFriends[] = _( "WON CONTESTS W/FRIENDS" );
const u8 gText_BattlePtsWon[]        = _( "BATTLE POINTS WON" );
const u8 gText_Var1DarkLightGreyBP[] =
	_( "{STR_VAR_1}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}BP" );
const u8 gText_BattleTower[]         = _( "BATTLE TOWER" );
const u8 gText_WSlashStraightSlash[] = _(
	"W/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}  STRAIGHT/{COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}" );
const u8 gText_BattleTower2[]  = _( "BATTLE TOWER" );
const u8 gText_BattleDome[]    = _( "BATTLE DOME" );
const u8 gText_BattlePalace[]  = _( "BATTLE PALACE" );
const u8 gText_BattleFactory[] = _( "BATTLE FACTORY" );
const u8 gText_BattleArena[]   = _( "BATTLE ARENA" );
const u8 gText_BattlePike[]    = _( "BATTLE PIKE" );
const u8 gText_BattlePyramid[] = _( "BATTLE PYRAMID" );

ALIGNED( 4 ) const u8 gUnknown_085ED164[] = _( "{STR_VAR_1} SINGLE" );
ALIGNED( 4 ) const u8 gUnknown_085ED170[] = _( "{STR_VAR_1} DOUBLE" );
ALIGNED( 4 ) const u8 gUnknown_085ED17C[] = _( "{STR_VAR_1} MULTI" );
ALIGNED( 4 ) const u8 gUnknown_085ED188[] = _( "{STR_VAR_1} LINK" );
ALIGNED( 4 ) const u8 gUnknown_085ED190[] = _( "{STR_VAR_1}" );

const u8 gText_Give[]   = _( "Give" );
const u8 gText_NoNeed[] = _( "No need" );
const u8 gText_ColorLightShadowDarkGrey[] =
	_( "{COLOR LIGHT_GREY}{SHADOW DARK_GREY}" );
const u8 gText_ColorBlue[] = _( "{COLOR BLUE}" );
const u8 gText_ColorTransparent[] =
	_( "{HIGHLIGHT TRANSPARENT}{COLOR TRANSPARENT}" );
const u8 gText_CDot[]                 = _( "C." );
const u8 gText_BDot[]                 = _( "B." );
const u8 gText_AnnouncingResults[]    = _( "Announcing the results!" );
const u8 gText_PreliminaryResults[]   = _( "The preliminary results!" );
const u8 gText_Round2Results[]        = _( "Round 2 results!" );
const u8 gText_Var1sVar2Won[]         = _( "{STR_VAR_1}'s {STR_VAR_2} won!" );
const u8 gText_CommunicationStandby[] = _( "Communication standby…" );
const u8 gText_ColorDarkGrey[]        = _( "{COLOR DARK_GREY}" );
const u8 gUnknown_085ED222[] =
	_( "{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR6 WHITE DYNAMIC_COLOR5}" );
const u8 gText_HighlightDarkGrey[] = _( "{HIGHLIGHT DARK_GREY}" );
const u8 gUnknown_085ED22C[]       = _( " " );
const u8 gText_DynColor2Male[]     = _( "{COLOR DYNAMIC_COLOR2}♂" );
const u8 gText_DynColor1Female[]   = _( "{COLOR DYNAMIC_COLOR1}♀" );
const u8 gText_DynColor2[]         = _( "{COLOR DYNAMIC_COLOR2}" );
const u8 gText_Upper[]             = _( "UPPER" );
const u8 gText_Lower[]             = _( "lower" );
const u8 gText_Others[]            = _( "OTHERS" );
const u8 gText_Symbols[]           = _( "SYMBOLS" );
const u8 gText_Register2[]         = _( "REGISTER" );
const u8 gText_Exit2[]             = _( "EXIT" );
const u8 gText_QuitChatting[]      = _( "Quit chatting?" );
const u8 gText_RegisterTextWhere[] = _( "Register text where?" );
const u8 gText_RegisterTextHere[]  = _( "Register text here?" );
const u8 gText_InputText[]         = _( "Input text." );
const u8 gText_F700JoinedChat[]    = _( "{SPECIAL_F7 0x00} joined the chat!" );
const u8 gText_F700LeftChat[]      = _( "{SPECIAL_F7 0x00} left the chat." );
const u8 gUnknown_085ED2CF[] =
	_( "{SPECIAL_F7 0x00}の{SPECIAL_F7 0x01}ひきめ:" );
const u8 gUnknown_085ED2D9[] =
	_( "{SPECIAL_F7 0x00}の{SPECIAL_F7 0x01}ひきめは いません" );
const u8 gText_ExitingChat[] = _( "Exiting the chat…" );
const u8 gText_LeaderLeftEndingChat[] =
	_( "The LEADER, {SPECIAL_F7 0x00}, has\nleft, ending the chat." );
const u8 gText_RegisteredTextChanged[] = _(
	"The registered text has been changed.\nIs it okay to save the game?" );
const u8 gText_AlreadySavedFile_Unused[] =
	_( "There is already a saved file.\nIs it okay to overwrite it?" );
const u8 gText_SavingDontTurnOff_Unused[] =
	_( "SAVING…\nDON'T TURN OFF THE POWER." );
const u8 gText_PlayerSavedGame_Unused[] =
	_( "{SPECIAL_F7 0x00} saved the game." );
const u8 gText_IfLeaderLeavesChatEnds[] =
	_( "If the LEADER leaves, the chat\nwill end. Is that okay?" );
const u8 gText_Hello[]                  = _( "HELLO" );
const u8 gText_Pokemon2[]               = _( "POKéMON" );
const u8 gText_Trade[]                  = _( "TRADE" );
const u8 gText_Battle[]                 = _( "BATTLE" );
const u8 gText_Lets[]                   = _( "LET'S" );
const u8 gText_Ok[]                     = _( "OK!" );
const u8 gText_Sorry[]                  = _( "SORRY" );
const u8 gText_YayUnkF9F9[]             = _( "YAY{EMOJI_BIGSMILE}" );
const u8 gText_ThankYou[]               = _( "THANK YOU" );
const u8 gText_ByeBye[]                 = _( "BYE-BYE!" );
const u8 gMatchCallStevenStrategyText[] = _( "Attack the weak points!" );
const u8 gMatchCall_StevenTrainersPokemonText[] =
	_( "Ultimate STEEL POKéMON." );
const u8
	gMatchCall_StevenSelfIntroductionText_Line1_BeforeMeteorFallsBattle[] =
		_( "I'd climb even waterfalls" );
const u8
	gMatchCall_StevenSelfIntroductionText_Line2_BeforeMeteorFallsBattle[] =
		_( "to find a rare stone!" );
const u8 gMatchCall_StevenSelfIntroductionText_Line1_AfterMeteorFallsBattle[] =
	_( "I'm the strongest and most" );
const u8 gMatchCall_StevenSelfIntroductionText_Line2_AfterMeteorFallsBattle[] =
	_( "energetic after all!" );
const u8 gMatchCall_BrendanStrategyText[] = _( "Battle with knowledge!" );
const u8 gMatchCall_BrendanTrainersPokemonText[] =
	_( "I will use various POKéMON." );
const u8 gMatchCall_BrendanSelfIntroductionText_Line1[] =
	_( "I'll be a better POKéMON" );
const u8 gMatchCall_BrendanSelfIntroductionText_Line2[] =
	_( "prof than my father is!" );
const u8 gMatchCall_MayStrategyText[] = _( "I'm not so good at battles." );
const u8 gMatchCall_MayTrainersPokemonText[] = _( "I'll use any POKéMON!" );
const u8 gMatchCall_MaySelfIntroductionText_Line1[] =
	_( "My POKéMON and I help" );
const u8 gMatchCall_MaySelfIntroductionText_Line2[] =
	_( "my father's research." );
const u8 gText_HatchedFromEgg[] = _( "{STR_VAR_1} hatched from the EGG!" );
const u8 gText_NickHatchPrompt[] =
	_( "Would you like to nickname the newly\nhatched {STR_VAR_1}?" );
ALIGNED( 4 )
const u8 gText_ReadyToBerryCrush[] =
	_( "Are you ready to BERRY-CRUSH?\nPlease pick a BERRY for use.\p" );
ALIGNED( 4 )
const u8 gText_WaitForAllChooseBerry[] =
	_( "Please wait while each member\nchooses a BERRY." );
ALIGNED( 4 )
const u8 gText_EndedWithXUnitsPowder[] = _(
	"{PAUSE_MUSIC}{PLAY_BGM MUS_FANFA1}You ended up with {STR_VAR_1} units of\nsilky-smooth BERRY POWDER.{RESUME_MUSIC}\pYour total amount of BERRY POWDER\nis {STR_VAR_2}.\p" );
ALIGNED( 4 )
const u8 gText_RecordingGameResults[] =
	_( "Recording your game results in the\nsave file.\lPlease wait." );
ALIGNED( 4 )
const u8 gText_PlayBerryCrushAgain[] = _( "Want to play BERRY CRUSH again?" );
ALIGNED( 4 )
const u8 gText_YouHaveNoBerries[] =
	_( "You have no BERRIES.\nThe game will be canceled." );
ALIGNED( 4 )
const u8 gText_MemberDroppedOut[] =
	_( "A member dropped out.\nThe game will be canceled." );
ALIGNED( 4 )
const u8 gText_TimesUpNoGoodPowder[] =
	_( "Time's up.\pGood BERRY POWDER could not be\nmade…\p" );
ALIGNED( 4 )
const u8 gText_CommunicationStandby2[] = _( "Communication standby…" );
ALIGNED( 4 )
const u8 gText_1DotBlueF700[] =
	_( "1. {COLOR BLUE}{SHADOW LIGHT_BLUE}{SPECIAL_F7 0x00}" );
ALIGNED( 4 ) const u8 gText_1DotF700[]        = _( "1. {SPECIAL_F7 0x00}" );
ALIGNED( 4 ) const u8 gText_SpaceTimes2[]     = _( " time(s)" );
ALIGNED( 4 ) const u8 gText_XDotY[]           = _( "{STR_VAR_1}.{STR_VAR_2}" );
ALIGNED( 4 ) const u8 gText_Var1Berry[]       = _( "{STR_VAR_1} BERRY" );
ALIGNED( 4 ) const u8 gText_TimeColon[]       = _( "Time:" );
ALIGNED( 4 ) const u8 gText_PressingSpeed[]   = _( "Pressing Speed:" );
ALIGNED( 4 ) const u8 gText_Silkiness[]       = _( "Silkiness:" );
ALIGNED( 4 ) const u8 gText_StrVar1[]         = _( "{STR_VAR_1}" );
ALIGNED( 4 ) const u8 gText_SpaceMin[]        = _( " min. " );
ALIGNED( 4 ) const u8 gText_XDotY2[]          = _( "{STR_VAR_1}.{STR_VAR_2}" );
ALIGNED( 4 ) const u8 gText_SpaceSec[]        = _( " sec." );
ALIGNED( 4 ) const u8 gText_XDotY3[]          = _( "{STR_VAR_1}.{STR_VAR_2}" );
ALIGNED( 4 ) const u8 gText_TimesPerSec[]     = _( " Times/sec." );
ALIGNED( 4 ) const u8 gText_Var1Percent[]     = _( "{STR_VAR_1}%" );
ALIGNED( 4 ) const u8 gText_PressesRankings[] = _( "No. of Presses Rankings" );
ALIGNED( 4 ) const u8 gText_CrushingResults[] = _( "Crushing Results" );
ALIGNED( 4 ) const u8 gText_NeatnessRankings[] = _( "Neatness Rankings" );
ALIGNED( 4 ) const u8 gText_CoopRankings[]     = _( "Cooperative Rankings" );
ALIGNED( 4 )
const u8 gText_PressingPowerRankings[] = _( "Pressing-Power Rankings" );
const u8 gText_BerryCrush2[]           = _( "BERRY CRUSH" );
const u8 gText_PressingSpeedRankings[] = _( "Pressing-Speed Rankings" );
const u8 gText_Var1Players[]           = _( "{STR_VAR_1} PLAYERS" );
const u8 gText_SymbolsEarned[]         = _( "Symbols Earned" );
const u8 gText_BattleRecord[]          = _( "Battle Record" );
const u8 gText_BattlePoints[]          = _( "Battle Points" );
const u8 gUnknown_085ED92A[]           = _( "CANCEL" );
const u8 gUnknown_085ED931[]           = _( "" );
const u8 gUnknown_085ED932[]           = _( "Check BATTLE FRONTIER MAP." );
const u8 gUnknown_085ED94D[]           = _( "Check TRAINER CARD." );
const u8 gUnknown_085ED961[]           = _( "View recorded battle." );
const u8 gUnknown_085ED977[]           = _( "Put away the FRONTIER PASS." );
const u8 gUnknown_085ED993[]           = _( "Your current Battle Points." );
const u8 gUnknown_085ED9AF[]           = _( "Your collected Symbols." );
const u8 gUnknown_085ED9C7[]           = _( "Battle Tower - Ability Symbol" );
const u8 gUnknown_085ED9E5[]           = _( "Battle Dome - Tactics Symbol" );
const u8 gUnknown_085EDA02[]           = _( "Battle Palace - Spirits Symbol" );
const u8 gUnknown_085EDA21[]           = _( "Battle Arena - Guts Symbol" );
const u8 gUnknown_085EDA3C[] = _( "Battle Factory - Knowledge Symbol" );
const u8 gUnknown_085EDA5E[] = _( "Battle Pike - Luck Symbol" );
const u8 gUnknown_085EDA78[] = _( "Battle Pyramid - Brave Symbol" );
const u8 gUnknown_085EDA96[] = _( "There is no Battle Record." );
const u8 gUnknown_085EDAB1[] = _( "BATTLE TOWER" );
const u8 gUnknown_085EDABE[] = _( "BATTLE DOME" );
const u8 gUnknown_085EDACA[] = _( "BATTLE PALACE" );
const u8 gUnknown_085EDAD8[] = _( "BATTLE ARENA" );
const u8 gUnknown_085EDAE5[] = _( "BATTLE FACTORY" );
const u8 gUnknown_085EDAF4[] = _( "BATTLE PIKE" );
const u8 gUnknown_085EDB00[] = _( "BATTLE PYRAMID" );
const u8 gUnknown_085EDB0F[] =
	_( "KO opponents and aim for the top!\nYour ability will be tested." );
const u8 gUnknown_085EDB4E[] =
	_( "Keep winning at the tournament!\nYour tactics will be tested." );
const u8 gUnknown_085EDB8B[] =
	_( "Watch your POKéMON battle!\nYour spirit will be tested." );
const u8 gUnknown_085EDBC2[] =
	_( "Win battles with teamed-up POKéMON!\nYour guts will be tested." );
const u8 gUnknown_085EDC00[] = _(
	"Aim for victory using rental POKéMON!\nYour knowledge will be tested." );
const u8 gUnknown_085EDC45[] =
	_( "Select one of three paths to battle!\nYour luck will be tested." );
const u8 gUnknown_085EDC84[] =
	_( "Aim for the top with exploration!\nYour bravery will be tested." );
const u8 gText_ContinueMenuPlayer[]  = _( "PLAYER" );
const u8 gText_ContinueMenuTime[]    = _( "TIME" );
const u8 gText_ContinueMenuPokedex[] = _( "POKéDEX" );
const u8 gText_ContinueMenuBadges[]  = _( "BADGES" );
const u8 gText_Powder[]              = _( "POWDER" );
const u8 gText_BerryPickingRecords[] = _( "DODRIO BERRY-PICKING RECORDS" );
const u8 gText_BerriesPicked[]       = _( "BERRIES picked:" );
const u8 gText_BestScore[]           = _( "Best score:" );
const u8 gText_BerriesInRowFivePlayers[] =
	_( "BERRIES picked in a row with\nfive players:" );
const u8 gText_BerryPickingResults[] =
	_( "Announcing BERRY-PICKING results!" );
const u8 gText_10P30P50P50P[] = _(
	"{CLEAR_TO 0x03}10P{CLEAR_TO 0x2B}30P{CLEAR_TO 0x53}50P{CLEAR_TO 0x77}{EMOJI_MINUS}50P" );
const u8 gText_AnnouncingRankings[] = _( "Announcing rankings!" );
const u8 gText_AnnouncingPrizes[]   = _( "Announcing prizes!" );
const u8 gText_1Colon[]             = _( "1:" );
const u8 gText_2Colon[]             = _( "2:" );
const u8 gText_3Colon[]             = _( "3:" );
const u8 gText_4Colon[]             = _( "4:" );
const u8 gText_5Colon[]             = _( "5:" );
const u8 gText_FirstPlacePrize[] =
	_( "The first-place winner gets\nthis {SPECIAL_F7 0x00}!" );
const u8 gText_CantHoldAnyMore[]    = _( "You can't hold any more!" );
const u8 gText_FilledStorageSpace[] = _( "It filled its storage space." );
const u8 gText_WantToPlayAgain[]    = _( "Want to play again?" );
const u8 gText_SomeoneDroppedOut[] =
	_( "Somebody dropped out.\nThe link will be canceled." );
const u8 gText_SpacePoints[]           = _( " points" );
const u8 gText_CommunicationStandby3[] = _( "Communication standby…" );
const u8 gText_SpacePoints2[]          = _( " points" );
const u8 gText_SpaceTimes3[]           = _( " time(s)" );
const u8 gText_PkmnJumpRecords[]       = _( "POKéMON JUMP RECORDS" );
const u8 gText_JumpsInARow[]           = _( "Jumps in a row:" );
const u8 gText_BestScore2[]            = _( "Best score:" );
const u8 gText_ExcellentsInARow[]      = _( "EXCELLENTS in a row:" );
const u8 gText_AwesomeWonF701F700[] =
	_( "Awesome score! You've\nwon {SPECIAL_F7 0x01} {SPECIAL_F7 0x00}!" );
const u8 gText_FilledStorageSpace2[] = _( "It filled its storage space." );
const u8 gText_CantHoldMore[]        = _( "You can't hold any more!" );
const u8 gText_WantToPlayAgain2[]    = _( "Want to play again?" );
const u8 gText_SomeoneDroppedOut2[] =
	_( "Somebody dropped out.\nThe link will be canceled." );
const u8 gText_CommunicationStandby4[] = _( "Communication standby…" );
const u8 gText_LinkContestResults[] = _( "{PLAYER}'s Link Contest Results" );
const u8 gText_1st[]                = _( "1st" );
const u8 gText_2nd[]                = _( "2nd" );
const u8 gText_3rd[]                = _( "3rd" );
const u8 gText_4th[]                = _( "4th" );
const u8 gText_Friend[]             = _( "Friend" );
const u8 gUnknown_085EDFB7[]        = _( "POKeMON" );
const u8 gJPText_MysteryGift[]      = _( "ふしぎなもらいもの" );
const u8 gJPText_DecideStop[] = _( "{A_BUTTON}けってい {B_BUTTON}やめる" );
const u8 gUnknown_085EDFD6[] =
	_( "カードeリーダー{PLUS}　で\nふしぎなもらいものを　よみこみます" );
const u8 gUnknown_085EDFF5[] =
	_( "カードeリーダー{PLUS}の　メニューから\n‘つうしん'を　えらび" );
const u8 gUnknown_085EE014[] =
	_( "‘ゲームボーイアドバンスとつうしん'\nを　せんたく　してください" );
const u8 gUnknown_085EE035[] = _(
	"カードeリーダー{PLUS}の　‘つうしん'を\nえらんで　Aボタンを　おしてください" );
const u8 gUnknown_085EE05C[] = _( "せつぞくが　まちがっています" );
const u8 gUnknown_085EE06B[] = _( "カードの　よみこみを\nちゅうし　しました" );
const u8 gUnknown_085EE080[] =
	_( "カードeリーダー{PLUS}と\nつうしん　できません" );
const u8 gUnknown_085EE097[] = _( "つうしん　ちゅう　です" );
const u8 gUnknown_085EE0A3[] =
	_( "つうしん　エラーです\nせつぞくを　たしかめて　ください" );
const u8 gUnknown_085EE0BF[] =
	_( "つうしん　エラーです\nはじめから　やりなおして　ください" );
const u8 gUnknown_085EE0DC[] =
	_( "カードeリーダー{PLUS}　に\nカードを　よみこませて　ください" );
const u8 gUnknown_085EE0FA[] = _( "つうしん　しゅうりょう！" );
const u8 gUnknown_085EE107[] =
	_( "あらたな　トレーナーが\nホウエンに　やってきた！" );
const u8 gUnknown_085EE120[] = _( "しばらく　おまちください" );
const u8 gUnknown_085EE12D[] =
	_( "かきこみ　エラー　です\nデータが　ほぞん　できませんでした" );
const u8 gUnknown_085EE14B[] = _( "RED" );
const u8 gUnknown_085EE14F[] = _( "BLUE" );
const u8 gUnknown_085EE154[] = _( "---" );
const u8 gText_SingleBattleRoomResults[] =
	_( "{PLAYER}'s Single Battle Room Results" );
const u8 gText_DoubleBattleRoomResults[] =
	_( "{PLAYER}'s Double Battle Room Results" );
const u8 gText_MultiBattleRoomResults[] =
	_( "{PLAYER}'s Multi Battle Room Results" );
const u8 gText_LinkMultiBattleRoomResults[] =
	_( "{PLAYER}'s Link Multi Battle Room Results" );
const u8 gText_SingleBattleTourneyResults[] =
	_( "{PLAYER}'s Single Battle Tourney Results" );
const u8 gText_DoubleBattleTourneyResults[] =
	_( "{PLAYER}'s Double Battle Tourney Results" );
const u8 gText_SingleBattleHallResults[] =
	_( "{PLAYER}'s Single Battle Hall Results" );
const u8 gText_DoubleBattleHallResults[] =
	_( "{PLAYER}'s Double Battle Hall Results" );
const u8 gText_BattleChoiceResults[] = _( "{PLAYER}'s Battle Choice Results" );
const u8 gText_SetKOTourneyResults[] =
	_( "{PLAYER}'s Set KO Tourney Results" );
const u8 gText_BattleSwapSingleResults[] =
	_( "{PLAYER}'s Battle Swap Single Results" );
const u8 gText_BattleSwapDoubleResults[] =
	_( "{PLAYER}'s Battle Swap Double Results" );
const u8 gText_BattleQuestResults[] = _( "{PLAYER}'s Battle Quest Results" );
const u8 gText_Lv502[]              = _( "LV. 50" );
const u8 gText_OpenLv[]             = _( "OPEN LV." );
const u8 gText_WinStreak[]          = _( "Win streak: {STR_VAR_1}" );
const u8 gText_Current[]            = _( "CURRENT" );
const u8 gText_Record[]             = _( "RECORD" );
const u8 gText_Prev[]               = _( "PREV." );
const u8 gText_RentalSwap[]         = _( "Rental/Swap" );
const u8 gText_Total[]              = _( "Total" );
const u8 gText_ClearStreak[]        = _( "Clear streak: {STR_VAR_1}" );
const u8 gText_Championships[]      = _( "Championships: {STR_VAR_1}" );
const u8 gText_RoomsCleared[]       = _( "Rooms cleared: {STR_VAR_1}" );
const u8 gText_TimesCleared[]  = _( "Times cleared:{CLEAR 0x05}{STR_VAR_1}" );
const u8 gText_KOsInARow[]     = _( "KOs in a row: {STR_VAR_1}" );
const u8 gText_TimesVar1[]     = _( "Times: {STR_VAR_1}" );
const u8 gText_FloorsCleared[] = _( "Floors cleared: {STR_VAR_1}" );

ALIGNED( 4 ) const u8 gText_RecordsLv50[]      = _( "LV. 50" );
ALIGNED( 4 ) const u8 gText_RecordsOpenLevel[] = _( "OPEN LEVEL" );
ALIGNED( 4 )
const u8 gText_FrontierFacilityWinStreak[] = _( "Win streak: {STR_VAR_2}" );
ALIGNED( 4 )
const u8 gText_FrontierFacilityClearStreak[] =
	_( "Clear streak: {STR_VAR_2}" );
ALIGNED( 4 )
const u8 gText_FrontierFacilityRoomsCleared[] =
	_( "Rooms cleared: {STR_VAR_2}" );
ALIGNED( 4 )
const u8 gText_FrontierFacilityKOsStreak[] = _( "KOs in a row: {STR_VAR_2}" );
ALIGNED( 4 )
const u8 gText_FrontierFacilityFloorsCleared[] =
	_( "Floors cleared: {STR_VAR_2}" );
ALIGNED( 4 ) const u8 gText_123Dot[][3] = {_( "1." ), _( "2." ), _( "3." )};

const u8 gText_SavingDontTurnOff2[] =
	_( "SAVING…\nDON'T TURN OFF THE POWER." );
const u8 gText_BlenderMaxSpeedRecord[] =
	_( "BERRY BLENDER\nMAXIMUM SPEED RECORD!" );
const u8 gText_234Players[]     = _( "2 PLAYERS\n3 PLAYERS\n4 PLAYERS" );
const u8 gText_YesNo[]          = _( "YES\nNO" );
const u8 gText_SelectorArrow3[] = _( "▶" );
const u8 gText_Peekaboo[]       = _( "PEEKABOO!" );
const u8 gText_CommErrorCheckConnections[] = _(
	"Communication error…\nPlease check all connections,\nthen turn the power OFF and ON." );
const u8 gText_CommErrorEllipsis[]       = _( "Communication error…" );
const u8 gText_MoveCloserToLinkPartner[] = _(
	"Move closer to your link partner(s).\nAvoid obstacles between partners." );
const u8 gText_ABtnRegistrationCounter[] =
	_( "A Button: Registration Counter" );
const u8 gText_ABtnTitleScreen[]  = _( "A Button: Title Screen" );
const u8 gText_Option[]           = _( "OPTION" );
const u8 gText_TextSpeed[]        = _( "TEXT SPEED" );
const u8 gText_BattleScene[]      = _( "BATTLE SCENE" );
const u8 gText_BattleStyle[]      = _( "BATTLE STYLE" );
const u8 gText_Sound[]            = _( "SOUND" );
const u8 gText_Frame[]            = _( "FRAME" );
const u8 gText_OptionMenuCancel[] = _( "CANCEL" );
const u8 gText_ButtonMode[]       = _( "BUTTON MODE" );
const u8 gText_TextSpeedSlow[]  = _( "{COLOR GREEN}{SHADOW LIGHT_GREEN}SLOW" );
const u8 gText_TextSpeedMid[]   = _( "{COLOR GREEN}{SHADOW LIGHT_GREEN}MID" );
const u8 gText_TextSpeedFast[]  = _( "{COLOR GREEN}{SHADOW LIGHT_GREEN}FAST" );
const u8 gText_BattleSceneOn[]  = _( "{COLOR GREEN}{SHADOW LIGHT_GREEN}ON" );
const u8 gText_BattleSceneOff[] = _( "{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF" );
const u8 gText_BattleStyleShift[] =
	_( "{COLOR GREEN}{SHADOW LIGHT_GREEN}SHIFT" );
const u8 gText_BattleStyleSet[] = _( "{COLOR GREEN}{SHADOW LIGHT_GREEN}SET" );
const u8 gText_SoundMono[]      = _( "{COLOR GREEN}{SHADOW LIGHT_GREEN}MONO" );
const u8 gText_SoundStereo[] = _( "{COLOR GREEN}{SHADOW LIGHT_GREEN}STEREO" );
const u8 gText_FrameType[]   = _( "{COLOR GREEN}{SHADOW LIGHT_GREEN}TYPE" );
const u8 gText_FrameTypeNumber[] = _( "{COLOR GREEN}{SHADOW LIGHT_GREEN}" );
const u8 gText_ButtonTypeNormal[] =
	_( "{COLOR GREEN}{SHADOW LIGHT_GREEN}NORMAL" );
const u8 gText_ButtonTypeLR[] = _( "{COLOR GREEN}{SHADOW LIGHT_GREEN}LR" );
const u8 gText_ButtonTypeLEqualsA[] =
	_( "{COLOR GREEN}{SHADOW LIGHT_GREEN}L=A" );
const u8 gText_XPLink[]             = _( "{STR_VAR_1}P LINK" );
const u8 gText_BronzeCard[]         = _( "BRONZE" );
const u8 gText_CopperCard[]         = _( "COPPER" );
const u8 gText_SilverCard[]         = _( "SILVER" );
const u8 gText_GoldCard[]           = _( "GOLD" );
const u8 gText_Day[]                = _( "DAY" );
const u8 gText_Colon3[]             = _( ":" );
const u8 gText_Confirm2[]           = _( "CONFIRM" );
const u8 gUnknown_085EE698[]        = _( "Days" );
const u8 gUnknown_085EE69D[]        = _( "Time:" );
const u8 gUnknown_085EE6A3[]        = _( "Game time" );
const u8 gUnknown_085EE6AD[]        = _( "RTC time" );
const u8 gUnknown_085EE6B6[]        = _( "Updated time" );
const u8 gText_MenuPokedex[]        = _( "POKéDEX" );
const u8 gText_MenuPokemon[]        = _( "POKéMON" );
const u8 gText_MenuBag[]            = _( "BAG" );
const u8 gText_MenuPokenav[]        = _( "POKéNAV" );
const u8 gText_MenuPlayer[]         = _( "{PLAYER}" );
const u8 gText_MenuSave[]           = _( "SAVE" );
const u8 gText_MenuOption[]         = _( "OPTION" );
const u8 gText_MenuExit[]           = _( "EXIT" );
const u8 gText_MenuRetire[]         = _( "RETIRE" );
const u8 gText_MenuRest[]           = _( "REST" );
const u8 gText_SafariBallStock[]    = _( "SAFARI BALLS\nStock: {STR_VAR_1}" );
const u8 gText_BattlePyramidFloor[] = _( "Battle Pyramid\n{STR_VAR_1}" );
const u8 gText_Floor1[]             = _( "Floor 1" );
const u8 gText_Floor2[]             = _( "Floor 2" );
const u8 gText_Floor3[]             = _( "Floor 3" );
const u8 gText_Floor4[]             = _( "Floor 4" );
const u8 gText_Floor5[]             = _( "Floor 5" );
const u8 gText_Floor6[]             = _( "Floor 6" );
const u8 gText_Floor7[]             = _( "Floor 7" );
const u8 gText_Peak[]               = _( "Peak" );
const u8 gText_LinkStandby2[] = _( "Link standby…\n… … B Button: Cancel" );
const u8 gText_PressAToLoadEvent[] =
	_( "Press the A Button to load event.\n… … B Button: Cancel" );
const u8 gText_LoadingEvent[] = _( "Loading event…" );
const u8 gText_DontRemoveCableTurnOff[] =
	_( "Don't remove the Game Link cable.\nDon't turn off the power." );
const u8 gText_EventSafelyLoaded[] = _( "The event was safely loaded." );
const u8 gText_LoadErrorEndingSession[] =
	_( "Loading error.\nEnding session." );
const u8 gUnknown_085EE846[]    = _( "プレイヤー" );
const u8 gUnknown_085EE84C[]    = _( "さま" );
const u8 gText_DexHoenn[]       = _( "HOENN" );
const u8 gText_DexNational[]    = _( "NATIONAL" );
const u8 gText_PokedexDiploma[] = _(
	"PLAYER: {CLEAR 0x10}{COLOR RED}{SHADOW LIGHT_RED}{PLAYER}{COLOR DARK_GREY}{SHADOW LIGHT_GREY}\n\nThis document certifies\nthat you have successfully\ncompleted your\n{STR_VAR_1} POKéDEX.\n\n{CLEAR_TO 0x42}{COLOR RED}{SHADOW LIGHT_RED}GAME FREAK" );
const u8 gUnknown_085EE8DC[] =
	_( "{COLOR RED}{SHADOW LIGHT_RED}ゲ-ムフリ-ク" );
const u8 gUnknown_085EE8EA[] = _( "{COLOR RED}{SHADOW LIGHT_RED}" );
const u8 gText_Hoenn[]       = _( "HOENN" );
const u8 gText_OhABite[]     = _( "Oh! A bite!" );
const u8 gText_PokemonOnHook[] =
	_( "A POKéMON's on the hook!{PAUSE_UNTIL_PRESS}" );
const u8 gText_NotEvenANibble[] = _( "Not even a nibble…{PAUSE_UNTIL_PRESS}" );
const u8 gText_ItGotAway[]      = _( "It got away…{PAUSE_UNTIL_PRESS}" );
const u8 gText_XWillBeSentToY[] =
	_( "{STR_VAR_2} will be\nsent to {STR_VAR_1}." );
const u8 gText_ByeByeVar1[]      = _( "Bye-bye, {STR_VAR_2}!" );
const u8 gText_XSentOverY[]      = _( "{STR_VAR_1} sent over {STR_VAR_3}." );
const u8 gText_TakeGoodCareOfX[] = _( "Take good care of {STR_VAR_3}!" );

// Easy chat group names
const u8 gEasyChatGroupName_Pokemon[]      = _( "POKéMON" );
const u8 gEasyChatGroupName_Trainer[]      = _( "TRAINER" );
const u8 gEasyChatGroupName_Status[]       = _( "STATUS" );
const u8 gEasyChatGroupName_Battle[]       = _( "BATTLE" );
const u8 gEasyChatGroupName_Greetings[]    = _( "GREETINGS" );
const u8 gEasyChatGroupName_People[]       = _( "PEOPLE" );
const u8 gEasyChatGroupName_Voices[]       = _( "VOICES" );
const u8 gEasyChatGroupName_Speech[]       = _( "SPEECH" );
const u8 gEasyChatGroupName_Endings[]      = _( "ENDINGS" );
const u8 gEasyChatGroupName_Feelings[]     = _( "FEELINGS" );
const u8 gEasyChatGroupName_Conditions[]   = _( "CONDITIONS" );
const u8 gEasyChatGroupName_Actions[]      = _( "ACTIONS" );
const u8 gEasyChatGroupName_Lifestyle[]    = _( "LIFESTYLE" );
const u8 gEasyChatGroupName_Hobbies[]      = _( "HOBBIES" );
const u8 gEasyChatGroupName_Time[]         = _( "TIME" );
const u8 gEasyChatGroupName_Misc[]         = _( "MISC." );
const u8 gEasyChatGroupName_Adjectives[]   = _( "ADJECTIVES" );
const u8 gEasyChatGroupName_Events[]       = _( "EVENTS" );
const u8 gEasyChatGroupName_Move1[]        = _( "MOVE 1" );
const u8 gEasyChatGroupName_Move2[]        = _( "MOVE 2" );
const u8 gEasyChatGroupName_TrendySaying[] = _( "TRENDY SAYING" );
const u8 gEasyChatGroupName_Pokemon2[]     = _( "POKéMON2" );

const u8 gText_ThreeQuestionMarks[] = _( "???" );
const u8 gUnknown_085EEA46[]        = _( "MAX. HP" );
const u8 gUnknown_085EEA4E[]        = _( "ATTACK" );
const u8 gUnknown_085EEA55[]        = _( "DEFENSE" );
const u8 gUnknown_085EEA5D[]        = _( "SPEED" );
const u8 gUnknown_085EEA63[]        = _( "SP. ATK" );
const u8 gUnknown_085EEA6B[]        = _( "SP. DEF" );
const u8 gText_UnkCtrlF904[]        = _( "{PLUS}" );
const u8 gText_Dash[]               = _( "-" );
const u8 gText_FromSpace[]          = _( "From " );
const u8 gText_MixingRecords[]      = _( "Mixing records…" );
const u8 gText_RecordMixingComplete[] =
	_( "Record mixing completed.\nThank you for waiting." );
const u8 gText_YourName[]        = _( "YOUR NAME?" );
const u8 gText_BoxName[]         = _( "BOX NAME?" );
const u8 gText_PkmnsNickname[]   = _( "{STR_VAR_1}'s nickname?" );
const u8 gText_TellHimTheWords[] = _( "Tell him the words." );
const u8 gText_MoveOkBack[] =
	_( "{DPAD_NONE}MOVE  {A_BUTTON}OK  {B_BUTTON}BACK" );
const u8 gText_CallCantBeMadeHere[] = _( "A call can't be made from here." );
const u8 gUnknown_085EEB2B[]        = _( "HANDSOME" );
const u8 gUnknown_085EEB34[]        = _( "VINNY" );
const u8 gUnknown_085EEB3A[]        = _( "MOREME" );
const u8 gUnknown_085EEB41[]        = _( "IRONHARD" );
const u8 gUnknown_085EEB4A[]        = _( "MUSCLE" );
const u8 gUnknown_085EEB51[]        = _( "coolness" );
const u8 gUnknown_085EEB5A[]        = _( "beauty" );
const u8 gUnknown_085EEB61[]        = _( "cuteness" );
const u8 gUnknown_085EEB6A[]        = _( "smartness" );
const u8 gUnknown_085EEB74[]        = _( "toughness" );
const u8 gText_Lady2[]              = _( "Lady" );
const u8 gUnknown_085EEB83[]        = _( "slippery" );
const u8 gUnknown_085EEB8C[]        = _( "roundish" );
const u8 gUnknown_085EEB95[]        = _( "wham-ish" );
const u8 gUnknown_085EEB9E[]        = _( "shiny" );
const u8 gUnknown_085EEBA4[]        = _( "sticky" );
const u8 gUnknown_085EEBAB[]        = _( "pointy" );
const u8 gText_RentalPkmn2[]        = _( "RENTAL POKéMON" );
const u8 gText_SelectFirstPkmn[]    = _( "Select the first POKéMON." );
const u8 gText_SelectSecondPkmn[]   = _( "Select the second POKéMON." );
const u8 gText_SelectThirdPkmn[]    = _( "Select the third POKéMON." );
const u8 gText_Rent[]               = _( "RENT" );
const u8 gText_Summary[]            = _( "SUMMARY" );
const u8 gText_Others2[]            = _( "OTHERS" );
const u8 gText_Deselect[]           = _( "DESELECT" );
const u8 gText_TheseThreePkmnOkay[] = _( "Are these three POKéMON OK?" );
const u8 gText_Yes2[]               = _( "YES" );
const u8 gText_No2[]                = _( "NO" );
const u8 gText_CantSelectSamePkmn[] = _( "Can't select same {PKMN}." );
const u8 gText_PkmnSwap[]           = _( "POKéMON SWAP" );
const u8 gText_SelectPkmnToSwap[]   = _( "Select POKéMON to swap." );
const u8 gText_SelectPkmnToAccept[] = _( "Select POKéMON to accept." );
const u8 gText_Swap[]               = _( "SWAP" );
const u8 gText_Summary2[]           = _( "SUMMARY" );
const u8 gText_Rechoose[]           = _( "RECHOOSE" );
const u8 gText_QuitSwapping[]       = _( "Quit swapping?" );
const u8 gText_Yes3[]               = _( "YES" );
const u8 gText_No3[]                = _( "NO" );
const u8 gText_PkmnForSwap[]        = _( "{PKMN} FOR SWAP" );
const u8 gText_Cancel3[]            = _( "CANCEL" );
const u8 gUnknown_085EECE4[]        = _( "SWAP" );
const u8 gUnknown_085EECE9[]        = _( "ACCEPT" );
const u8 gText_AcceptThisPkmn[]     = _( "Accept this POKéMON?" );
const u8 gUnknown_085EED05[]        = _( "    " );
const u8 gText_SamePkmnInPartyAlready[] = _( "Same {PKMN} in party already." );
const u8 gText_DecimalPoint[]           = _( "." );
const u8 gText_SavingPlayer[]           = _( "PLAYER" );
const u8 gText_SavingBadges[]           = _( "BADGES" );
const u8 gText_SavingPokedex[]          = _( "POKéDEX" );
const u8 gText_SavingTime[]             = _( "TIME" );
const u8 gText_WirelessCommStatus[]     = _( "Wireless Communication Status" );
const u8 gText_PeopleTrading[]          = _( "People trading:" );
const u8 gText_PeopleBattling[]         = _( "People battling:" );
const u8 gText_PeopleInUnionRoom[]      = _( "People in the UNION ROOM:" );
const u8 gText_PeopleCommunicating[]    = _( "People communicating:" );
const u8 gText_F700Players[]            = _( "{SPECIAL_F7 0} players" );
const u8 gText_F701Players[]            = _( "{SPECIAL_F7 1} players" );
const u8 gText_F702Players[]            = _( "{SPECIAL_F7 2} players" );
const u8 gText_F703Players[]            = _( "{SPECIAL_F7 3} players" );

const u8* const gTextTable_Players[] = {gText_F700Players,
	gText_F701Players,
	gText_F702Players,
	gText_F703Players};

ALIGNED( 4 ) const u8 gText_WonderCards[] = _( "WONDER CARDS" );
ALIGNED( 4 ) const u8 gText_WonderNews[]  = _( "WONDER NEWS" );
ALIGNED( 4 )
const u8 gText_WirelessCommunication[] = _( "WIRELESS COMMUNICATION" );
ALIGNED( 4 ) const u8 gText_Friend2[]  = _( "FRIEND" );
ALIGNED( 4 ) const u8 gText_Exit3[]    = _( "EXIT" );
ALIGNED( 4 ) const u8 gText_Receive[]  = _( "RECEIVE" );
ALIGNED( 4 ) const u8 gText_Send[]     = _( "SEND" );
ALIGNED( 4 ) const u8 gText_Toss[]     = _( "TOSS" );
ALIGNED( 4 )
const u8 gText_VarietyOfEventsImportedWireless[] = _(
	"A variety of events will be imported\nover Wireless Communication." );
ALIGNED( 4 )
const u8 gText_WonderCardsInPossession[] =
	_( "Read the WONDER CARDS in your\npossession." );
ALIGNED( 4 )
const u8 gText_ReadNewsThatArrived[] = _( "Read the NEWS that arrived." );
ALIGNED( 4 )
const u8 gText_ReturnToTitle[] = _( "Return to the title screen." );
ALIGNED( 4 )
const u8 gText_DontHaveCardNewOneInput[] =
	_( "You don't have a WONDER CARD,\nso a new CARD will be input." );
ALIGNED( 4 )
const u8 gText_DontHaveNewsNewOneInput[] =
	_( "You don't have any WONDER NEWS,\nso new NEWS will be input." );
ALIGNED( 4 )
const u8 gText_WhereShouldCardBeAccessed[] =
	_( "Where should the WONDER CARD\nbe accessed?" );
ALIGNED( 4 )
const u8 gText_WhereShouldNewsBeAccessed[] =
	_( "Where should the WONDER NEWS\nbe accessed?" );
ALIGNED( 4 )
const u8 gUnknown_085EEFC0[] = _( "Communication standby…\nB Button: Cancel" );
ALIGNED( 4 ) const u8 gText_Communicating[] = _( "Communicating…" );
ALIGNED( 4 )
const u8 gText_CommunicationCompleted[] = _( "Communication completed." );
ALIGNED( 4 ) const u8 gText_CommunicationError[] = _( "Communication error." );
ALIGNED( 4 )
const u8 gText_CommunicationCanceled[] =
	_( "Communication has been canceled." );
ALIGNED( 4 )
const u8 gText_ThrowAwayWonderCard[] =
	_( "Throw away the WONDER CARD\nand input a new CARD?" );
ALIGNED( 4 )
const u8 gText_HaventReceivedCardsGift[] = _(
	"You haven't received the CARD's gift\nyet. Input a new CARD anyway?" );
ALIGNED( 4 )
const u8 gText_WonderCardReceivedFrom[] =
	_( "A WONDER CARD has been received\nfrom {STR_VAR_1}." );
ALIGNED( 4 )
const u8 gText_WonderNewsReceivedFrom[] =
	_( "A WONDER NEWS item has been\nreceived from {STR_VAR_1}." );
ALIGNED( 4 )
const u8 gText_WonderCardReceived[] =
	_( "A new WONDER CARD has been\nreceived." );
ALIGNED( 4 )
const u8 gText_WonderNewsReceived[] =
	_( "A new WONDER NEWS item has been\nreceived." );
ALIGNED( 4 )
const u8 gText_NewStampReceived[] = _( "A new STAMP has been received." );
ALIGNED( 4 )
const u8 gText_NewTrainerReceived[] = _( "A new TRAINER has arrived." );
ALIGNED( 4 )
const u8 gText_AlreadyHadCard[] = _( "You already had that\nWONDER CARD." );
ALIGNED( 4 )
const u8 gText_AlreadyHadNews[] =
	_( "You already had that\nWONDER NEWS item." );
ALIGNED( 4 )
const u8 gText_AlreadyHadStamp[] = _( "You already had that\nSTAMP." );
ALIGNED( 4 )
const u8 gText_NoMoreRoomForStamps[] =
	_( "There's no more room for adding\nSTAMPS." );
ALIGNED( 4 )
const u8 gText_RecordUploadedViaWireless[] =
	_( "Your record has been uploaded via\nWIRELESS COMMUNICATION." );
ALIGNED( 4 )
const u8 gText_CantAcceptCardFromTrainer[] =
	_( "You can't accept a WONDER CARD\nfrom this TRAINER." );
ALIGNED( 4 )
const u8 gText_CantAcceptNewsFromTrainer[] =
	_( "You can't accept WONDER NEWS\nfrom this TRAINER." );
ALIGNED( 4 ) const u8 gText_NothingSentOver[] = _( "Nothing was sent over…" );
ALIGNED( 4 )
const u8 gText_WhatToDoWithCards[] =
	_( "What would you like to do\nwith the WONDER CARDS?" );
ALIGNED( 4 )
const u8 gText_WhatToDoWithNews[] =
	_( "What would you like to do\nwith the WONDER NEWS?" );
ALIGNED( 4 )
const u8 gText_SendingWonderCard[] = _( "Sending your WONDER CARD…" );
ALIGNED( 4 )
const u8 gText_SendingWonderNews[] = _( "Sending your WONDER NEWS item…" );
ALIGNED( 4 )
const u8 gText_WonderCardSentTo[] =
	_( "Your WONDER CARD has been sent\nto {STR_VAR_1}." );
ALIGNED( 4 )
const u8 gText_WonderNewsSentTo[] =
	_( "Your WONDER NEWS item has been\nsent to {STR_VAR_1}." );
ALIGNED( 4 )
const u8 gText_StampSentTo[] = _( "A STAMP has been sent to {STR_VAR_1}." );
ALIGNED( 4 )
const u8 gText_GiftSentTo[] = _( "A GIFT has been sent to {STR_VAR_1}." );
ALIGNED( 4 )
const u8 gText_OtherTrainerHasCard[] =
	_( "The other TRAINER has the same\nWONDER CARD already." );
ALIGNED( 4 )
const u8 gText_OtherTrainerHasNews[] =
	_( "The other TRAINER has the same\nWONDER NEWS already." );
ALIGNED( 4 )
const u8 gText_OtherTrainerHasStamp[] =
	_( "The other TRAINER has the same\nSTAMP already." );
ALIGNED( 4 )
const u8 gText_OtherTrainerCanceled[] =
	_( "The other TRAINER canceled\ncommunication." );
ALIGNED( 4 )
const u8 gText_CantSendGiftToTrainer[] =
	_( "You can't send a MYSTERY GIFT to\nthis TRAINER." );
ALIGNED( 4 )
const u8 gText_IfThrowAwayCardEventWontHappen[] =
	_( "If you throw away the CARD,\nits event won't happen. Okay?" );
ALIGNED( 4 )
const u8 gText_OkayToDiscardNews[] =
	_( "Is it okay to discard this\nNEWS item?" );
ALIGNED( 4 )
const u8 gText_HaventReceivedGiftOkayToDiscard[] =
	_( "You haven't received the\nGIFT. Is it okay to discard?" );
ALIGNED( 4 )
const u8 gText_DataWillBeSaved[] = _( "Data will be saved.\nPlease wait." );
ALIGNED( 4 )
const u8 gText_SaveCompletedPressA[] =
	_( "Save completed.\nPlease press the A Button." );
ALIGNED( 4 )
const u8 gText_WonderCardThrownAway[] =
	_( "The WONDER CARD was thrown away." );
ALIGNED( 4 )
const u8 gText_WonderNewsThrownAway[] =
	_( "The WONDER NEWS was thrown away." );
ALIGNED( 4 ) const u8 gText_MysteryGift[] = _( "MYSTERY GIFT" );
ALIGNED( 4 )
const u8 gText_PickOKExit[] =
	_( "{DPAD_UPDOWN}PICK {A_BUTTON}OK {B_BUTTON}EXIT" );
ALIGNED( 4 )
const u8 gText_PickOKCancel[] =
	_( "{DPAD_UPDOWN}PICK {A_BUTTON}OK {B_BUTTON}CANCEL" );
const u8 gText_PlayersBattleResults[] = _( "{PLAYER}'s BATTLE RESULTS" );
const u8 gText_TotalRecordWLD[] =
	_( "TOTAL RECORD W:{STR_VAR_1} L:{STR_VAR_2} D:{STR_VAR_3}" );
const u8 gText_WinLoseDraw[] =
	_( "{CLEAR_TO 0x53}WIN{CLEAR_TO 0x80}LOSE{CLEAR_TO 0xB0}DRAW" );
const u8 gText_CommunicationStandby5[] = _( "Communication standby…" );
const u8 gText_QuitTheGame[]           = _( "Quit the game?" );
const u8 gText_YouveGot9999Coins[]     = _( "You've got 9,999 COINS." );
const u8 gText_YouveRunOutOfCoins[] =
	_( "You've run out of COINS.\nGame over!" );
const u8 gText_YouDontHaveThreeCoins[] = _( "You don't have three COINS." );
const u8 gText_ReelTimeHelp[]          = _(
        "REEL TIME\nHere's your chance to take\naim and nail marks!\nReel Time continues for the\nawarded number of spins.\nIt all ends on a Big Bonus." );
const u8 gDaycareText_GetAlongVeryWell[] =
	_( "The two seem to get along\nvery well." );
const u8 gDaycareText_GetAlong[] = _( "The two seem to get along." );
const u8 gDaycareText_DontLikeOther[] =
	_( "The two don't seem to like\neach other much." );
const u8 gDaycareText_PlayOther[] =
	_( "The two prefer to play with other\nPOKéMON than each other." );
const u8 gText_NewLine2[]    = _( "\n" );
const u8 gText_Exit4[]       = _( "EXIT" );
const u8 gText_Lv[]          = _( "{LV}" );
const u8 gText_TimeBoard[]   = _( "TIME BOARD" );
const u8 gText_TimeCleared[] = _( "TIME CLEARED " );
const u8 gText_XMinYDotZSec[] =
	_( "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec." );
const u8 gText_TrainerHill1F[] = _( "1F" );
const u8 gText_TrainerHill2F[] = _( "2F" );
const u8 gText_TrainerHill3F[] = _( "3F" );
const u8 gText_TrainerHill4F[] = _( "4F" );
const u8 gText_TeachWhichMoveToPkmn[] =
	_( "Teach which move to {STR_VAR_1}?" );
const u8 gText_MoveRelearnerTeachMoveConfirm[] = _( "Teach {STR_VAR_2}?" );
const u8 gText_MoveRelearnerPkmnLearnedMove[] =
	_( "{STR_VAR_1} learned\n{STR_VAR_2}!" );
const u8 gText_MoveRelearnerPkmnTryingToLearnMove[] = _(
	"{STR_VAR_1} is trying to learn\n{STR_VAR_2}.\pBut {STR_VAR_1} can't learn more\nthan four moves.\pDelete an older move to make\nroom for {STR_VAR_2}?" );
const u8 gText_MoveRelearnerStopTryingToTeachMove[] =
	_( "Stop trying to teach\n{STR_VAR_2}?" );
const u8 gText_MoveRelearnerAndPoof[] = _(
	"{PAUSE 32}1, {PAUSE 15}2, and {PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE 0x0038}Poof!\p" );
const u8 gText_MoveRelearnerPkmnForgotMoveAndLearnedNew[] = _(
	"{STR_VAR_1} forgot {STR_VAR_3}.\pAnd…\p{STR_VAR_1} learned {STR_VAR_2}." );
const u8 gUnknown_085EF9C8[] =
	_( "{STR_VAR_1} did not learn the\nmove {STR_VAR_2}." );
const u8 gText_MoveRelearnerGiveUp[] =
	_( "Give up trying to teach a new\nmove to {STR_VAR_1}?" );
const u8 gText_MoveRelearnerWhichMoveToForget[] =
	_( "Which move should be\nforgotten?\p" );
const u8 gText_MoveRelearnerBattleMoves[]       = _( "BATTLE MOVES" );
const u8 gText_MoveRelearnerContestMovesTitle[] = _( "CONTEST MOVES" );
const u8 gUnknown_085EFA4C[]                    = _( "TYPE/" );
const u8 gText_MoveRelearnerPP[]                = _( "PP/" );
const u8 gText_MoveRelearnerPower[]             = _( "POWER/" );
const u8 gText_MoveRelearnerAccuracy[]          = _( "ACCURACY/" );
const u8 gText_MoveRelearnerAppeal[]            = _( "APPEAL" );
const u8 gText_MoveRelearnerJam[]               = _( "JAM" );
const u8 gText_Kira[]                           = _( "KIRA" );
const u8 gText_Amy[]                            = _( "AMY" );
const u8 gText_John[]                           = _( "JOHN" );
const u8 gText_Roy[]                            = _( "ROY" );
const u8 gText_Gabby[]                          = _( "GABBY" );
const u8 gText_Anna[]                           = _( "ANNA" );
const u8 gText_ClearAllSaveData[]     = _( "Clear all save data areas?" );
const u8 gText_ClearingData[]         = _( "Clearing data…\nPlease wait." );
const u8 gText_IsThisTheCorrectTime[] = _( "Is this the correct time?" );
const u8 gText_Confirm3[]             = _( "CONFIRM" );
const u8 gText_Cancel4[]              = _( "CANCEL" );
const u8 gMrStoneMatchCallDesc[]      = _( "DEVON PRES" );
const u8 gMrStoneMatchCallName[]      = _( "MR. STONE" );
const u8 gStevenMatchCallDesc[]       = _( "HARD AS ROCK" );
const u8 gStevenMatchCallName[]       = _( "STEVEN" );
const u8 gMayBrendanMatchCallDesc[]   = _( "RAD NEIGHBOR" );
const u8 gNormanMatchCallDesc[]       = _( "RELIABLE ONE" );
const u8 gMomMatchCallDesc[]          = _( "CALM & KIND" );
const u8 gWallyMatchCallDesc[]        = _( "{PKMN} LOVER" );
const u8 gNormanMatchCallName[]       = _( "DAD" );
const u8 gMomMatchCallName[]          = _( "MOM" );
const u8 gScottMatchCallDesc[]        = _( "ELUSIVE EYES" );
const u8 gScottMatchCallName[]        = _( "SCOTT" );
const u8 gRoxanneMatchCallDesc[]      = _( "ROCKIN' WHIZ" );
const u8 gBrawlyMatchCallDesc[]       = _( "THE BIG HIT" );
const u8 gWattsonMatchCallDesc[]      = _( "SWELL SHOCK" );
const u8 gFlanneryMatchCallDesc[]     = _( "PASSION BURN" );
const u8 gWinonaMatchCallDesc[]       = _( "SKY TAMER" );
const u8 gTateLizaMatchCallDesc[]     = _( "MYSTIC DUO" );
const u8 gJuanMatchCallDesc[]         = _( "DANDY CHARM" );
const u8 gEliteFourMatchCallDesc[]    = _( "ELITE FOUR" );
const u8 gChampionMatchCallDesc[]     = _( "CHAMPION" );
const u8 gProfBirchMatchCallDesc[]    = _( "{PKMN} PROF." );
const u8 gText_CommStandbyAwaitingOtherPlayer[] =
	_( "Communication standby…\nAwaiting another player to choose." );
const u8 gText_BattleWasRefused[] = _( "The battle was refused.{PAUSE 60}" );
const u8 gText_RefusedBattle[]    = _( "Refused the battle.{PAUSE 60}" );
const u8 gUnknown_085EFC3E[]      = _( "NO WEATHER" );
const u8 gUnknown_085EFC49[]      = _( "SUNNY" );
const u8 gUnknown_085EFC4F[]      = _( "SUNNY2" );
const u8 gUnknown_085EFC56[]      = _( "RAIN" );
const u8 gUnknown_085EFC5B[]      = _( "SNOW" );
const u8 gUnknown_085EFC60[]      = _( "LIGHTNING" );
const u8 gUnknown_085EFC6A[]      = _( "FOG" );
const u8 gUnknown_085EFC6E[]      = _( "VOLCANO ASH" );
const u8 gUnknown_085EFC7A[]      = _( "SANDSTORM" );
const u8 gUnknown_085EFC84[]      = _( "FOG2" );
const u8 gUnknown_085EFC89[]      = _( "SEAFLOOR" );
const u8 gUnknown_085EFC92[]      = _( "CLOUDY" );
const u8 gUnknown_085EFC99[]      = _( "SUNNY3" );
const u8 gUnknown_085EFCA0[]      = _( "HEAVY RAIN" );
const u8 gUnknown_085EFCAB[]      = _( "SEAFLOOR2" );
const u8 gText_DelAll[]           = _( "DEL. ALL" );
const u8 gText_Cancel5[]          = _( "CANCEL" );
const u8 gText_Ok2[]              = _( "OK" );
const u8 gText_Quiz[]             = _( "QUIZ" );
const u8 gText_Answer[]           = _( "ANSWER" );
const u8 gText_PokeBalls[]        = _( "POKé BALLS" );
const u8 gText_Berry[]            = _( "BERRY" );
const u8 gText_Berries[]          = _( "BERRIES" );
