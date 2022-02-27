ifeq ($(OS),Windows_NT)
include ..\documents\common.make
else
include ../documents/common.make
endif

export VBCC=$(ROOTDIR)$(S)rom$(S)FoenixMCP-a2560k$(S)vbcc
export PATH+=:$(VBCC)$(S)bin
SOURCE=FoenixMCP-a2560k$(S)src$(S)

all:rom

rom	:
	make -C $(SOURCE) UNIT=a2560k MEMORY=flash 
	$(CCOPY) $(SOURCE)foenixmcp.s68 ..$(S)emulator$(S)a2560k.rom

clean:
	make -C $(SOURCE) clean

#
# 		FoenixMCP-a2560k is a clone of the repository, however the 
#		text_init() at 301 of foenixmcp.c has been uncommented so that
# 		it switches back to text mode at the end.
#
#		The vbcc directory in there has had the compiler expanded over it
# 		and the vbcc folder *ONLY* from Foenix_vbcc_target_main.zip expanded
# 		over that.
#
# 		DON'T COPY THE SRC DIRECTORY WHICH IS SOMETHING ELSE
#