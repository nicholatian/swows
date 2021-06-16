
GraniteCave_1F_MapScripts:: @ 822DA5D
	.byte 0

GraniteCave_1F_EventScript_22DA5E:: @ 822DA5E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM70, GraniteCave_1F_EventScript_22DA8A
	msgbox GraniteCave_1F_Text_22DA94, MSGBOX_DEFAULT
	giveitem_std ITEM_TM70
	setflag FLAG_RECEIVED_TM70
	msgbox GraniteCave_1F_Text_22DBB7, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_22DA8A:: @ 822DA8A
	msgbox GraniteCave_1F_Text_22DBB7, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_22DA94: @ 822DA94
	.string "Hey, you.\p"
	.string "Out there in the cold, getting lonely\n"
	.string "getting old… can you hear me?$"

GraniteCave_1F_Text_22DBB7: @ 822DBB7
	.string "Teach that move FLASH to a POKéMON\n"
	.string "and use it.\p"
	.string "It lights up even the inky darkness\n"
	.string "of caves.$"
