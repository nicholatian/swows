#!/bin/sh
# -*- coding: utf-8 -*-

# these aliases help hasten the search for offsets of symbols and the
# locations that hook into them.

alias hgrep='arm-none-eabi-nm pokeemerald.elf | grep ';
alias higrep='arm-none-eabi-nm pokeemerald.elf | grep -i ';
alias romdump='xxd -u -ps -c 16 -g 1 pokeemerald.gba';
alias romgrep='xxd -u -ps -c 16 -g 1 pokeemerald.gba | grep ';
alias romigrep='xxd -u -ps -c 16 -g 1 pokeemerald.gba | grep -i ';
