#!/usr/bin/env make
# -*- coding: utf-8 -*-

include $(DEVKITARM)/base_tools

UNAME := $(shell uname -s)

ifeq ($(UNAME),Darwin)
export HOSTCC  := /usr/bin/clang
export HOSTCXX := /usr/bin/clang++
export ECHO    := $(shell which gecho) # use GNU binutils echo
export FIND    := $(shell which gfind)
else
export HOSTCC  := gcc
export HOSTCXX := g++
export ECHO    := /bin/echo # for Debian
export FIND    := find
endif

export DKA  := $(DEVKITARM)
export DKPT := $(DEVKITPRO)/tools
export PRET := /opt/pret

export AS   := $(DKA)/bin/arm-none-eabi-as
export CC   := $(DKA)/bin/arm-none-eabi-gcc
export CXX  := $(DKA)/bin/arm-none-eabi-g++
export CPP  := $(DKA)/bin/arm-none-eabi-cpp
export LD   := $(DKA)/bin/arm-none-eabi-ld

export LZSS := $(DKPT)/bin/gbalzss
export GRIT := $(DKPT)/bin/grit

export GFX       := $(PRET)/bin/gbagfx
export AIF       := $(PRET)/bin/aif2pcm
export MID       := $(PRET)/bin/mid2agb
export SCANINC   := $(PRET)/bin/scaninc
export PREPROC   := $(PRET)/bin/preproc
export RAMSCRGEN := $(PRET)/bin/ramscrgen
export MAPJSON   := $(PRET)/bin/mapjson
export JSONPROC  := $(PRET)/bin/jsonproc
export FIX       := $(PRET)/bin/gbafix

include comwrap.mk

TITLE       := POKEMONSWOWS
GAME_CODE   := BPEE
MAKER_CODE  := 01
REVISION    := 0

ROM := swows.gba
OBJ_DIR := build/swows

ELF = $(ROM:.gba=.elf)
MAP = $(ROM:.gba=.map)

C_SUBDIR = src
ASM_SUBDIR = asm
DATA_SRC_SUBDIR = src/data
DATA_ASM_SUBDIR = data
SONG_SUBDIR = sound/songs
MID_SUBDIR = sound/songs/midi

C_BUILDDIR = $(OBJ_DIR)/$(C_SUBDIR)
ASM_BUILDDIR = $(OBJ_DIR)/$(ASM_SUBDIR)
DATA_ASM_BUILDDIR = $(OBJ_DIR)/$(DATA_ASM_SUBDIR)
SONG_BUILDDIR = $(OBJ_DIR)/$(SONG_SUBDIR)
MID_BUILDDIR = $(OBJ_DIR)/$(MID_SUBDIR)

ASFLAGS := -mcpu=arm7tdmi

CC1             := $(PRET)/bin/agbcc
override CFLAGS += -mthumb-interwork -Wimplicit -Wparentheses -Werror -O2 -fhex-asm

CPPFLAGS := -I $(PRET)/agbcc/include -I include -I $(PRET)/include -Wno-trigraphs

LDFLAGS = -Map ../../$(MAP)

LIB := -L $(PRET)/lib -lgcc -lc

SHA1 := $(shell { command -v sha1sum || command -v shasum; } 2>/dev/null) -c


# Clear the default suffixes
.SUFFIXES:
# Don't delete intermediate files
.SECONDARY:
# Delete files that weren't built properly
.DELETE_ON_ERROR:
# Secondary expansion is required for dependency variables in object rules.
.SECONDEXPANSION:

.PHONY: all clean tidy lint utils

all: $(ROM)

utils: util/bin2asm util/scrip2o

util/bin2asm: util/bin2asm.c
	$(HOSTCC) -ansi -O2 -fPIC -pipe -o$@ $^
	strip -s $@

util/scrip2o: util/scrip2o.c
	$(HOSTCC) -ansi -O2 -g -fPIC -pipe -o$@ $^
#	strip -s $@

C_SRCS := $(wildcard $(C_SUBDIR)/*.c $(C_SUBDIR)/*/*.c $(C_SUBDIR)/*/*/*.c)
C_OBJS := $(patsubst $(C_SUBDIR)/%.c,$(C_BUILDDIR)/%.o,$(C_SRCS))

ASM_SRCS := $(wildcard $(ASM_SUBDIR)/*.s)
ASM_OBJS := $(patsubst $(ASM_SUBDIR)/%.s,$(ASM_BUILDDIR)/%.o,$(ASM_SRCS))

DATA_ASM_SRCS := $(wildcard $(DATA_ASM_SUBDIR)/*.s)
DATA_ASM_OBJS := $(patsubst $(DATA_ASM_SUBDIR)/%.s,$(DATA_ASM_BUILDDIR)/%.o,$(DATA_ASM_SRCS))

SONG_SRCS := $(wildcard $(SONG_SUBDIR)/*.s)
SONG_OBJS := $(patsubst $(SONG_SUBDIR)/%.s,$(SONG_BUILDDIR)/%.o,$(SONG_SRCS))

MID_SRCS := $(wildcard $(MID_SUBDIR)/*.mid)
MID_OBJS := $(patsubst $(MID_SUBDIR)/%.mid,$(MID_BUILDDIR)/%.o,$(MID_SRCS))

OBJS     := $(C_OBJS) $(ASM_OBJS) $(DATA_ASM_OBJS) $(SONG_OBJS) $(MID_OBJS)
OBJS_REL := $(patsubst $(OBJ_DIR)/%,%,$(OBJS))

SUBDIRS  := $(sort $(dir $(OBJS)))

AUTO_GEN_TARGETS :=

$(shell mkdir -p $(SUBDIRS))

clean: tidy
	$(call COMWRAP,rm -f sound/direct_sound_samples/*.bin ; rm -f $(SONG_OBJS) $(MID_OBJS) $(MID_SUBDIR)/*.s ; $(FIND) . \( -iname '*.1bpp' -o -iname '*.4bpp' -o -iname '*.8bpp' -o -iname '*.gbapal' -o -iname '*.lz' -o -iname '*.latfont' -o -iname '*.hwjpnfont' -o -iname '*.fwjpnfont' \) -exec rm {} + ; rm -f $(DATA_ASM_SUBDIR)/layouts/layouts.inc $(DATA_ASM_SUBDIR)/layouts/layouts_table.inc ; rm -f $(DATA_ASM_SUBDIR)/maps/connections.inc $(DATA_ASM_SUBDIR)/maps/events.inc $(DATA_ASM_SUBDIR)/maps/groups.inc $(DATA_ASM_SUBDIR)/maps/headers.inc ; $(FIND) $(DATA_ASM_SUBDIR)/maps \( -iname 'connections.inc' -o -iname 'events.inc' -o -iname 'header.inc' \) -exec rm {} + ; rm -f $(AUTO_GEN_TARGETS),$(COMWRAP_CLEAN))

tidy:
	$(call COMWRAP,rm -f $(ROM) $(ELF) $(MAP) ; rm -r build/*,$(COMWRAP_TIDY))

lint:
	@$(FIND) src -type f -name '*.c' -exec clang-format -i -style=file {} \; -exec $(ECHO) -ne '\033[37mLinting\033[0m \033[1m{}\033[0m ...\n' \;
	@$(FIND) src -type f -name '*.h' -exec clang-format -i -style=file {} \; -exec $(ECHO) -ne '\033[37mLinting\033[0m \033[1m{}\033[0m ...\n' \;
	@$(FIND) include -type f -name '*.h' -exec clang-format -i -style=file {} \; -exec $(ECHO) -ne '\033[37mLinting\033[0m \033[1m{}\033[0m ...\n' \;

include graphics_file_rules.mk
include map_data_rules.mk
include spritesheet_rules.mk
include json_data_rules.mk
include songs.mk

%.s: ;
%.png: ;
%.pal: ;
%.aif: ;

%.1bpp: %.png ; $(call COMWRAP,$(GFX) $< $@,$(COMWRAP_GFX))
%.4bpp: %.png ; $(call COMWRAP,$(GFX) $< $@,$(COMWRAP_GFX))
%.8bpp: %.png ; $(call COMWRAP,$(GFX) $< $@,$(COMWRAP_GFX))
%.gbapal: %.pal ; $(call COMWRAP,$(GFX) $< $@,$(COMWRAP_GFX))
%.gbapal: %.png ; $(call COMWRAP,$(GFX) $< $@,$(COMWRAP_GFX))
%.lz: % ; $(call COMWRAP,$(GFX) $< $@,$(COMWRAP_GFX))
%.rl: % ; $(call COMWRAP,$(GFX) $< $@,$(COMWRAP_GFX))
sound/direct_sound_samples/cry_%.bin: sound/direct_sound_samples/cry_%.aif ; $(call COMWRAP,$(AIF) $< $@ --compress,$(COMWRAP_MUSIC))
sound/%.bin: sound/%.aif ; $(call COMWRAP,$(AIF) $< $@,$(COMWRAP_SND_AS))

$(C_BUILDDIR)/libc.o: CC1 := $(PRET)/bin/old_agbcc
$(C_BUILDDIR)/libc.o: CFLAGS := -O2

$(C_BUILDDIR)/siirtc.o: CFLAGS := -mthumb-interwork

$(C_BUILDDIR)/agb_flash.o: CFLAGS := -O -mthumb-interwork
$(C_BUILDDIR)/agb_flash_1m.o: CFLAGS := -O -mthumb-interwork
$(C_BUILDDIR)/agb_flash_mx.o: CFLAGS := -O -mthumb-interwork

$(C_BUILDDIR)/m4a.o: CC1 := $(PRET)/bin/old_agbcc

$(C_BUILDDIR)/record_mixing.o: CFLAGS += -ffreestanding

ifeq ($(NODEP),1)
$(C_BUILDDIR)/%.o: c_dep :=
else
$(C_BUILDDIR)/%.o: c_dep = $(shell $(SCANINC) -I $(PRET)/agbcc/include -I $(PRET)/include -I include $(C_SUBDIR)/$*.c)
endif

ifeq ($(DINFO),1)
override CFLAGS += -g
endif

$(C_BUILDDIR)/%.o : $(C_SUBDIR)/%.c $$(c_dep)
	$(call COMWRAP,$(CPP) $(CPPFLAGS) $< -o $(C_BUILDDIR)/$*.i ; $(PREPROC) $(C_BUILDDIR)/$*.i charmap.txt | $(CC1) $(CFLAGS) -o $(C_BUILDDIR)/$*.s ; $(ECHO) -e '.text\n\t.align\t2$(COMMA) 0\n' >> $(C_BUILDDIR)/$*.s ; $(AS) $(ASFLAGS) -o $@ $(C_BUILDDIR)/$*.s,$(COMWRAP_CC))

ifeq ($(NODEP),1)
$(ASM_BUILDDIR)/%.o: asm_dep :=
else
$(ASM_BUILDDIR)/%.o: asm_dep = $(shell $(SCANINC) -I "" $(ASM_SUBDIR)/$*.s)
endif
ifeq ($(NODEP),1)

$(DATA_ASM_BUILDDIR)/%.o: data_dep :=
else
$(DATA_ASM_BUILDDIR)/%.o: data_dep = $(shell $(SCANINC) -I include -I "" $(DATA_ASM_SUBDIR)/$*.s)
endif

$(ASM_BUILDDIR)/%.o: $(ASM_SUBDIR)/%.s $$(asm_dep)
	$(call COMWRAP,$(AS) $(ASFLAGS) -o $@ $<,$(COMWRAP_ASM))

$(DATA_ASM_BUILDDIR)/%.o: $(DATA_ASM_SUBDIR)/%.s $$(data_dep)
	$(call COMWRAP,$(PREPROC) $< charmap.txt | $(CPP) -I include | $(AS) $(ASFLAGS) -o $@,$(COMWRAP_DAT_AS))

$(SONG_BUILDDIR)/%.o: $(SONG_SUBDIR)/%.s
	$(call COMWRAP,$(AS) $(ASFLAGS) -I sound -o $@ $<,$(COMWRAP_SND_AS))

$(OBJ_DIR)/sym_bss.ld: sym_bss.txt
	$(call COMWRAP,$(RAMSCRGEN) .bss $< ENGLISH > $@,$(COMWRAP_ADJ))

$(OBJ_DIR)/sym_common.ld: sym_common.txt $(C_OBJS) $(wildcard common_syms/*.txt)
	$(call COMWRAP,$(RAMSCRGEN) COMMON $< ENGLISH -c $(C_BUILDDIR)$(COMMA)common_syms > $@,$(COMWRAP_ADJ))

$(OBJ_DIR)/sym_ewram.ld: sym_ewram.txt
	$(call COMWRAP,$(RAMSCRGEN) ewram_data $< ENGLISH > $@,$(COMWRAP_ADJ))

$(OBJ_DIR)/ld_script.ld: ld_script.txt $(OBJ_DIR)/sym_bss.ld $(OBJ_DIR)/sym_common.ld $(OBJ_DIR)/sym_ewram.ld
	@cd $(OBJ_DIR) && sed 's#tools/#../../tools/#g' ../../ld_script.txt > ld_script.ld

$(ELF): $(OBJ_DIR)/ld_script.ld $(OBJS)
	$(call COMWRAP,cd $(OBJ_DIR) && $(LD) $(LDFLAGS) -T ld_script.ld -o ../../$@ $(OBJS_REL) $(LIB),$(COMWRAP_LINK))

$(ROM): $(ELF)
	$(call COMWRAP,$(OBJCOPY) -O binary $< $@,$(COMWRAP_OCPY))
	$(call COMWRAP,$(FIX) $@ -p -t'$(TITLE)' -c$(GAME_CODE) -m$(MAKER_CODE) -r$(REVISION) --silent,$(COMWRAP_FIX))
