PetalburgCity_House3_MapScripts::
	.byte 0

PetalburgCity_House3_Person::
	lock
	faceplayer
	msgbox PetalburgCity_House3_Text_Person, MSGBOX_DEFAULT
	compare VAR_PETALBURG_STATE, 2
	call_if_eq PetalburgCity_House3_GivePapers
	release
	end

PetalburgCity_House3_GivePapers::
	msgbox PetalburgCity_House3_Text_GivePapers, MSGBOX_DEFAULT
	takeitem ITEM_OAKS_PARCEL, 1
	playfanfare MUS_ME_WAZA
	message PetalburgCity_House3_Text_GivePapers_Fanfare
	waitfanfare
	msgbox PetalburgCity_House3_Text_Thanks, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_STATE, 3
	return

PetalburgCity_House3_Text_Person:
	.string "Hey there! You're NORMAN'S kid,\n"
	.string "aren't you?\l"
	.string "I'm LIZZ, a close friend of his.$"

PetalburgCity_House3_Text_GivePapers:
	.string "Oh? You have some papers NORMAN sent\n"
	.string "you with?$"

PetalburgCity_House3_Text_GivePapers_Fanfare:
	.string "Delivered the DIV. PAPERS!$"

PetalburgCity_House3_Text_Thanks:
	.string "Thank you for bringing these.\n"
	.string "Hmm… this is quote interesting…$"
