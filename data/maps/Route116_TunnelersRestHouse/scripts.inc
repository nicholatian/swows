Route116_TunnelersRestHouse_MapScripts:: @ 822B850
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition: @ 822B856
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_22B85A:: @ 822B85A
	msgbox Route116_TunnelersRestHouse_Text_22B88B, MSGBOX_NPC_FACE
	end

Route116_TunnelersRestHouse_EventScript_22B863:: @ 822B863
	msgbox Route116_TunnelersRestHouse_Text_22B99F, MSGBOX_NPC_FACE
	end

Route116_TunnelersRestHouse_EventScript_22B86C:: @ 822B86C
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_22B881
	msgbox Route116_TunnelersRestHouse_Text_22BAAF, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_22B881:: @ 822B881
	msgbox Route116_TunnelersRestHouse_Text_22BB3B, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_WorkerFarTable::
	msgbox Route116_TunnelersRestHouse_Text_WorkerFarTable, MSGBOX_NPC_FACE
	end

Route116_TunnelersRestHouse_EventScript_Foreman::
	msgbox Route116_TunnelersRestHouse_Text_Foreman, MSGBOX_NPC_FACE
	end

Route116_TunnelersRestHouse_EventScript_Geologist::
	msgbox Route116_TunnelersRestHouse_Text_Geologist, MSGBOX_NPC_FACE
	end

Route116_TunnelersRestHouse_EventScript_Agent::
	msgbox Route116_TunnelersRestHouse_Text_Agent, MSGBOX_NPC_FACE
	end

Route116_TunnelersRestHouse_EventScript_Worker::
	msgbox Route116_TunnelersRestHouse_Text_Worker, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Cook::
	msgbox Route116_TunnelersRestHouse_Text_Cook, MSGBOX_NPC_FACE
	end

Route116_TunnelersRestHouse_Text_Cook:
	.string "I haven't got much left to cook\n"
	.string "around here for the crew.\p"
	.string "They're tapping out leave, but the\n"
	.string "company didn't supply more food.\l"
	.string "Soon I'll have to turn them away.$"

Route116_TunnelersRestHouse_Text_Worker:
	.string "The TUNNEL project's cancelation\n"
	.string "couldn't have had worse timing.\p"
	.string "We were almost finished digging,\n"
	.string "with a few more rocks to move.\p"
	.string "From there we were gonna move on\n"
	.string "to tiling and weathering it all.$"

Route116_TunnelersRestHouse_Text_Agent:
	.string "Hi there. I'm a hiring agent.\n"
	.string "I recruit tunnelers for work.\p"
	.string "Since the TUNNEL was canceled, I've\n"
	.string "been recruiting for a new project.\p"
	.string "Out on ROUTE 115, a much larger\n"
	.string "tunnel network is being dug.\l"
	.string "Some odd group is funding it.$"

Route116_TunnelersRestHouse_Text_Geologist:
	.string "Hey there. I'm a geologist.\n"
	.string "I specialise in seismic activity.\p"
	.string "The press has it that the loud noise\n"
	.string "disturbed the WHISMUR, leading to\l"
	.string "the TUNNEL's cancellation.\p"
	.string "However, I discovered something\n"
	.string "else in addition to that.\p"
	.string "The heavy machinery was creating\n"
	.string "intense vibrations in the rock.\p"
	.string "Those vibes were interacting very\n"
	.string "badly with the magma chambers\l"
	.string "forming MT. CHIMNEY farther north.\p"
	.string "If we kept digging, we ran the risk\n"
	.string "of “popping a blood vessel”.\l"
	.string "In more blunt terms, an eruption.\p"
	.string "The WHISMUR provide a nice cover,\n"
	.string "but I think this decided it.\p"
	.string "Some very important folks came out\n"
	.string "of the woodwork over this.\p"
	.string "But hey, I guess it's whatever\n"
	.string "gets you there, right?$"

Route116_TunnelersRestHouse_Text_Foreman:
	.string "Hi! I'm the CONSTRUCTION FOREMAN.\n"
	.string "I manage the build site here.\p"
	.string "Well, the work on RUSTURF is over,\n"
	.string "so I'm not actually doing much.\p"
	.string "Most of the guys here are on terminal\n"
	.string "leave, or are burning vacation time.\l"
	.string "Benefits of the UNION.\p"
	.string "I heard there was some other project\n"
	.string "going on, though?$"

Route116_TunnelersRestHouse_Text_WorkerFarTable:
	.string "Ever since the RUSTURF project ended,\n"
	.string "there have been postings for new jobs.\l"
	.string "You know, for tunneling work.\p"
	.string "I checked it out, but the people\n"
	.string "running it were kinda sketchy.\p"
	.string "I'm on paid leave with the company,\n"
	.string "so I don't need the dough.\l"
	.string "Lotta guys here are taking it though.$"

Route116_TunnelersRestHouse_Text_22B88B: @ 822B88B
	.string "That RUSTURF TUNNEL there…\p"
	.string "At first, we had a huge work crew boring\n"
	.string "through rock with the latest machinery.\l"
	.string "But, we had to stop.\p"
	.string "It turns out that we would have had\n"
	.string "a negative effect on wild POKéMON in\l"
	.string "the area.\p"
	.string "So, we've got nothing to do but loll\n"
	.string "around here doing nothing. lol$"

Route116_TunnelersRestHouse_Text_22B99F: @ 822B99F
	.string "There's a man digging his way to\n"
	.string "VERDANTURF all by his lonesome.\l"
	.string "He's desperate to get through.\p"
	.string "He says that if he digs little by little\n"
	.string "without using machines, he won't\l"
	.string "disturb POKéMON, and he'll avoid\l"
	.string "harming the natural environment.\p"
	.string "I wonder if he made it through yet.$"

Route116_TunnelersRestHouse_Text_22BAAF: @ 822BAAF
	.string "To get to VERDANTURF without using\n"
	.string "this TUNNEL, you'd have to cross the\l"
	.string "sea to DEWFORD, sail on to SLATEPORT,\l"
	.string "then travel through MAUVILLE.$"

Route116_TunnelersRestHouse_Text_22BB3B: @ 822BB3B
	.string "Did you hear? The TUNNEL to VERDANTURF\n"
	.string "has gone through!\p"
	.string "Sometimes, if you hope strongly enough,\n"
	.string "dreams do come true.$"
