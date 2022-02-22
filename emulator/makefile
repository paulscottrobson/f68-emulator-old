ifeq ($(OS),Windows_NT)
include ..\documents\common.make
else
include ../documents/common.make
endif

APPNAME = f68$(APPSTEM)

SOURCES = 	framework$(S)main.o framework$(S)gfx.o framework$(S)debugger.o \
			src$(S)sys_debug_f68.o src$(S)sys_processor.o src$(S)memory.o \
			src$(S)hardware.o src$(S)gavin.o \
			cpu$(S)m68kcpu.o cpu$(S)m68kdasm.o cpu$(S)m68kops.o cpu$(S)softfloat.o
  			
CC = g++

.PHONY: all clean emulator test prebuild 

all: emulator
#	.$(S)$(APPNAME) 

run: emulator 
	.$(S)$(APPNAME) boot.rom go

debug: emulator 
	.$(S)$(APPNAME) boot.rom
	
emulator: prebuild $(APPNAME)

prebuild:
	make -C ..$(S)Musashi
	$(CCOPY) ..$(S)Musashi$(S)*.h cpu
	$(CCOPY) ..$(S)Musashi$(S)*.o cpu
	$(CCOPY) ..$(S)Musashi$(S)softfloat$(S)*.o cpu

%.o:%.cpp
	$(CC) $(CXXFLAGS) -g -D INCLUDE_DEBUGGING_SUPPORT -I cpu -I framework -I include -I roms -c -o $@ $<

clean:
	$(CDEL) $(APPNAME) 
	$(CDEL) src$(S)*.o 
	$(CDEL) framework$(S)*.o

$(APPNAME): $(SOURCES) 
	$(CC) $(SOURCES) $(LDFLAGS) $(SDL_LDFLAGS) -o $@
	

