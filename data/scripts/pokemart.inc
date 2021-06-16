
UniversalMart_EventScript::
	lock
	faceplayer
	message UniversalMart_Text_Welcome
	waitmessage
	goto_if_set FLAG_BADGE08_GET, UniversalMart_8Badges
	goto_if_set FLAG_BADGE07_GET, UniversalMart_7Badges
	goto_if_set FLAG_BADGE06_GET, UniversalMart_6Badges
	goto_if_set FLAG_BADGE05_GET, UniversalMart_5Badges
	goto_if_set FLAG_BADGE04_GET, UniversalMart_4Badges
	goto_if_set FLAG_BADGE03_GET, UniversalMart_3Badges
	goto_if_set FLAG_BADGE02_GET, UniversalMart_2Badges
	goto_if_set FLAG_BADGE01_GET, UniversalMart_1Badges
	goto_if_set FLAG_ADVENTURE_STARTED, UniversalMart_0Badges
	pokemart UniversalMart_NoPokeballs_Items
	msgbox UniversalMart_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

UniversalMart_8Badges::
	pokemart UniversalMart_8Badges_Items
	msgbox UniversalMart_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

UniversalMart_7Badges::
	pokemart UniversalMart_7Badges_Items
	msgbox UniversalMart_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

UniversalMart_6Badges::
	pokemart UniversalMart_6Badges_Items
	msgbox UniversalMart_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

UniversalMart_5Badges::
	pokemart UniversalMart_5Badges_Items
	msgbox UniversalMart_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

UniversalMart_4Badges::
	pokemart UniversalMart_4Badges_Items
	msgbox UniversalMart_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

UniversalMart_3Badges::
	pokemart UniversalMart_3Badges_Items
	msgbox UniversalMart_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

UniversalMart_2Badges::
	pokemart UniversalMart_2Badges_Items
	msgbox UniversalMart_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

UniversalMart_1Badges::
	pokemart UniversalMart_1Badges_Items
	msgbox UniversalMart_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

// Only after adventure started, see below for no Poké Balls
UniversalMart_0Badges::
	pokemart UniversalMart_0Badges_Items
	msgbox UniversalMart_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

.align 2

UniversalMart_NoPokeballs_Items:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

UniversalMart_0Badges_Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

UniversalMart_1Badges_Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

UniversalMart_2Badges_Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end

UniversalMart_3Badges_Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

UniversalMart_4Badges_Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end

UniversalMart_5Badges_Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_REVIVE
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end

UniversalMart_6Badges_Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_REVIVE
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end

UniversalMart_7Badges_Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_REVIVE
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end

UniversalMart_8Badges_Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_REVIVE
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end

UniversalMart_Text_Welcome:
	.string "Welcome! How may I help you?$"

UniversalMart_Text_ComeAgain:
	.string "Come again!$"
