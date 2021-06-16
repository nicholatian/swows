Route102_House1_MapScripts::
	.byte 0

Route102_House1_Sign::
	msgbox Route102_House1_SignText, MSGBOX_SIGN
	end

Route102_House1_ArtistScript::
	msgbox Route102_House1_ArtistText, MSGBOX_NPC
	applymovement 1, Route102_House1_ArtistFace
	end

Route102_House1_SignText:
	.string "A thick hemp-sewn scroll guards a\n"
	.string "pitch-black foyer behind.\l"
	.string "It reads: “403 FORBIDDEN”$"

Route102_House1_ArtistText:
	.string "Hello there! I'm an ARTIST.\n"
	.string "My work is in pottery mostly.\p"
	.string "I know, the impression isn't much.\p"
	.string "A fat man in a smock, living all by\n"
	.string "his lonesome on ROUTE 102.\l"
	.string "I don't care for pity.\p"
	.string "Say, if you could find a way for\n"
	.string "my art to get more exposure…\l"
	.string "I would be eternally grateful!$"

Route102_House1_ArtistFace:
	walk_in_place_fastest_left
	step_end
