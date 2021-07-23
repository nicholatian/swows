#!/bin/sh
# -*- coding: utf-8 -*-

# these aliases help hasten the search for offsets of symbols and the
# locations that hook into them.

alias hgrep='arm-none-eabi-nm 3rdparty/emer.elf | grep ';
alias higrep='arm-none-eabi-nm 3rdparty/emer.elf | grep -i ';
alias hxdump='xxd -u -c 16 -g 1 ';
alias romdump='xxd -u -c 16 -g 1 3rdparty/emer.gba';
alias romgrep='xxd -u -c 16 -g 1 3rdparty/emer.gba | grep ';
alias romigrep='xxd -u -c 16 -g 1 3rdparty/emer.gba | grep -i ';
