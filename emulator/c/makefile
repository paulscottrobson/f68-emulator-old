ifeq ($(OS),Windows_NT)
include ..\..\documents\common.make
else
include ../../documents/common.make
endif

export VBCC=$(ROOTDIR)$(S)rom$(S)FoenixMCP-a2560k$(S)vbcc
export PATH+=:$(VBCC)$(S)bin

all:
	vc +$(VBCC)/config/a2560-s28 -o hello.s28 hello.c

clean:
	$(CDEL) hello.s28
	$(CDEL) mapfile

