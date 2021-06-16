Route107_MapScripts:: @ 81EE594
	.byte 0

Route107_EventScript_1EE595:: @ 81EE595
	trainerbattle_single TRAINER_DARRIN, Route107_Text_2966E5, Route107_Text_29672F
	msgbox Route107_Text_29675B, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_1EE5AC:: @ 81EE5AC
	trainerbattle_single TRAINER_TONY_1, Route107_Text_2967AD, Route107_Text_2967D8, Route107_EventScript_1EE5D8
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route107_EventScript_1EE5F7
	msgbox Route107_Text_2967FF, MSGBOX_DEFAULT
	release
	end

Route107_EventScript_1EE5D8:: @ 81EE5D8
	special sub_80B4808
	waitmovement 0
	msgbox Route107_Text_29685A, MSGBOX_DEFAULT
	register_matchcall TRAINER_TONY_1
	release
	end

Route107_EventScript_1EE5F7:: @ 81EE5F7
	trainerbattle_rematch TRAINER_TONY_1, Route107_Text_296897, Route107_Text_2968D5
	msgbox Route107_Text_296923, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_1EE60E:: @ 81EE60E
	trainerbattle_single TRAINER_DENISE, Route107_Text_296974, Route107_Text_29699E
	msgbox Route107_Text_2969AB, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_1EE625:: @ 81EE625
	trainerbattle_single TRAINER_BETH, Route107_Text_2969E4, Route107_Text_296A17
	msgbox Route107_Text_296A35, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_1EE63C:: @ 81EE63C
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_296A77, Route107_Text_296AA7, Route107_Text_296B1E
	msgbox Route107_Text_296ADC, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_1EE657:: @ 81EE657
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_296B57, Route107_Text_296BB3, Route107_Text_296C34
	msgbox Route107_Text_296BE1, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_1EE672:: @ 81EE672
	trainerbattle_single TRAINER_CAMRON, Route107_Text_296C6F, Route107_Text_296CAD
	msgbox Route107_Text_296CC0, MSGBOX_AUTOCLOSE
	end

Route107_Trigger_A::
	applymovement EVENT_OBJ_ID_PLAYER, Route107_Movement_A
	waitmovement 0
	goto Route107_Trigger_B
	end

Route107_Trigger_C::
	applymovement EVENT_OBJ_ID_PLAYER, Route107_Movement_C
	waitmovement 0
	goto Route107_Trigger_B
	end

Route107_Trigger_B::
	fadeoutbgm 1
	delay 20
	playbgm MUS_OOAME, 0
	applymovement 10, Common_Movement_FaceRight
	applymovement 9, Common_Movement_FaceUp
	applymovement 8, Common_Movement_WalkInPlaceRight
	waitmovement 0
	lockall
	msgbox Route107_Text_Sammi1, MSGBOX_DEFAULT
	applymovement 8, Common_Movement_QuestionMark
	delay 10
	applymovement 9, Common_Movement_ExclamationMark
	applymovement 10, Common_Movement_ExclamationMark
	playse SE_PIN
	delay 20
	waitmovement 0
	applymovement 10, Route107_Movement_Grunt2Pardon
	applymovement 9, Common_Movement_FaceLeft
	applymovement 8, Route107_Movement_SammiToPlayer
	waitmovement 0
	msgbox Route107_Text_Sammi2, MSGBOX_DEFAULT
	fadescreen 1
	playse SE_KAIDAN
	delay 20
	setvar VAR_QUAZ1_DEWFORD, 1
	setflag FLAG_QUAZ_DEWFORD
	removeobject 8, MAP_ROUTE107
	removeobject 9, MAP_ROUTE107
	removeobject 10, MAP_ROUTE107
	closemessage
	delay 10
	fadescreen 0
	fadedefaultbgm
	releaseall
	end

Route107_Text_Sammi1:
	.string "Hmm…"
	.byte 0xFC, 0x08, 0x40
	.string " …"
	.byte 0xFC, 0x08, 0x10
	.string " …"
	.byte 0xFC, 0x08, 0x10
	.string " …"
	.byte 0xFC, 0x08, 0x10
	.string " …!"
	.byte 0xFC, 0x08, 0x50
	.string "\nThis is super interesting.\p"
	.string "If this stone is as old as I think\n"
	.string "it is, that's very good news.\l"
	.string "The BOSS will be happy to hear it.$"

Route107_Text_Sammi2:
	.string "…and who might you be?\p"
	.string "… … … … … … … … … …\n"
	.string "… … … … … … … … … …\p"
	.string "Very well. My name is SAMMI.\n"
	.string "I'm an ADMIN of TEAM QUAZ.\p"
	.string "There are a lot of troublemakers\n"
	.string "running amok, you know.\l"
	.string "You should be careful.\p"
	.string "If you stay out of trouble,\n"
	.string "everyone will be better off.\p"
	.string "Take care now!$"

Route107_Movement_A:
	walk_down
	face_right
	step_end

Route107_Movement_C:
	walk_up
	face_right
	step_end

Route107_Movement_Grunt2Pardon:
	walk_up
	face_down
	step_end

Route107_Movement_SammiToPlayer:
	walk_slow_down
	walk_left
	walk_left
	step_end

Route107_Movement_SammiExit:
	walk_slow_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route107_Movement_Grunt1Exit:
	walk_left
	walk_left
	delay_1
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route107_Movement_Grunt2Exit:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route107_Sign_Rock::
	msgbox Route107_Text_Rock, MSGBOX_SIGN
	end

Route107_Text_Rock:
	.string "It's a greyish-purple hued rock.$"
