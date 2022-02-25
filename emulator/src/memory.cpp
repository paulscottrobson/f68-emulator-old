// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		memory.cpp
//		Purpose:	Memory functions
//		Created:	22nd February 2022
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include <includes.h>

static BYTE8 ramMemory[0x400000];													// SRAM Memory at $000000-$003FFFFF
static BYTE8 flashMemory[0x400000];													// Flash memory at $FC000000-$FFFFFFFF
static BYTE8 videoMemory[0x800000];													// VRAM at $00800000-$00FFFFFF
static BYTE8 hwMemory[HARDWARE_RAM]; 												// RAM space at FEC00000

// *******************************************************************************************************************************
//														Load Flash ROM
// *******************************************************************************************************************************

void MEMLoadFlashROM(void) {
	FILE *f = fopen(FLASH_ROM,"rb"); 												// Read Flash ROM
	if (f == NULL)
		exit(fprintf(stderr,"Flash rom %s missing",FLASH_ROM));
	fread(flashMemory,1,sizeof(flashMemory),f);
	fclose(f);	
	for (int i = 0;i < 64*1024;i++) { 												// Copy first 64k to SRAM
		ramMemory[i] = flashMemory[i];
	}
}

// *******************************************************************************************************************************
//														Dump Memory on exit
// *******************************************************************************************************************************

void MEMEndRun(void) {
	FILE *f = fopen("memory.dump","wb");
	fwrite(ramMemory,1,sizeof(ramMemory),f);
	fclose(f);
}

// *******************************************************************************************************************************
//														Render the display
// *******************************************************************************************************************************

void MEMRenderDisplay(void) {
	SDL_Rect rc; 
	rc.w = WIN_WIDTH;rc.h = WIN_HEIGHT;
	rc.x = WIN_WIDTH/2 - rc.w/2;rc.y = WIN_HEIGHT/2-rc.h/2;
	 													// Draw text screen.
	HWRenderTextScreen(hwMemory+0x40000,hwMemory+0x60000,hwMemory+0x68000,
							hwMemory+0x6C400,hwMemory+0x48000,&rc);
}

// *******************************************************************************************************************************
//													  Generic read routines
// *******************************************************************************************************************************

unsigned int  m68k_read_memory_8(unsigned int address){

	address &= ADDRESS_MASK;

	if (address < 0x40000) {
		return ramMemory[address];
	}

	if (address >= 0xFFC00000) {
		return flashMemory[address & 0x3FFFF];
	}

	if (address >= VRAM_START && address <= VRAM_END) {
		return videoMemory[address-VRAM_START];
	}

	if (ISHWADDR(address)) {
		#include "generated/hw_gavin_read_byte.h"
		#include "generated/hw_beatrix_read_byte.h"
		#include "generated/hw_vicky3a_read_byte.h"
		#include "generated/hw_vicky3b_read_byte.h"
		return hwMemory[address-HARDWARE_START];
	}
	return 0x00;
}

unsigned int  m68k_read_memory_16(unsigned int address){
	if (ISHWADDR(address)) {
		#include "generated/hw_gavin_read_word.h"
		#include "generated/hw_beatrix_read_word.h"
		#include "generated/hw_vicky3a_read_word.h"
		#include "generated/hw_vicky3b_read_word.h"
	}
	return m68k_read_memory_8(address+1) + (m68k_read_memory_8(address) << 8);
}

unsigned int  m68k_read_memory_32(unsigned int address){
	if (ISHWADDR(address)) {
		#include "generated/hw_gavin_read_long.h"
		#include "generated/hw_beatrix_read_long.h"
		#include "generated/hw_vicky3a_read_long.h"
		#include "generated/hw_vicky3b_read_long.h"
	}
	unsigned int r = m68k_read_memory_16(address+2) + (m68k_read_memory_16(address) << 16);
	return r;
}

// *******************************************************************************************************************************
//													 Generic write routines
// *******************************************************************************************************************************

void m68k_write_memory_8(unsigned int address, unsigned int value){

	address &= ADDRESS_MASK;

	if (address < 0x40000) {
		ramMemory[address] = value & 0xFF;
		return;
	}

	if (address >= VRAM_START && address <= VRAM_END) {
		videoMemory[address-VRAM_START] = value;
	}

	if (ISHWADDR(address)) {
		#include "generated/hw_gavin_write_byte.h"
		#include "generated/hw_beatrix_write_byte.h"
		#include "generated/hw_vicky3a_write_byte.h"
		#include "generated/hw_vicky3b_write_byte.h"
		hwMemory[address-HARDWARE_START] = value;
	}
}

void m68k_write_memory_16(unsigned int address, unsigned int value){
	if (ISHWADDR(address)) {
		#include "generated/hw_gavin_write_word.h"
		#include "generated/hw_beatrix_write_word.h"
		#include "generated/hw_vicky3a_write_word.h"
		#include "generated/hw_vicky3b_write_word.h"
	}
	m68k_write_memory_8(address+1,value & 0xFF);
	m68k_write_memory_8(address,value >> 8);
}

void m68k_write_memory_32(unsigned int address, unsigned int value){
	if (ISHWADDR(address)) {
		#include "generated/hw_gavin_write_long.h"
		#include "generated/hw_beatrix_write_long.h"
		#include "generated/hw_vicky3a_write_long.h"
		#include "generated/hw_vicky3b_write_long.h"
	}
	m68k_write_memory_16(address+2,value & 0xFFFF);
	m68k_write_memory_16(address,value >> 16);
}

// *******************************************************************************************************************************
//							Duplicate R/W routines required by the CPU core for some reason
// *******************************************************************************************************************************

unsigned int inline m68k_read_immediate_16(unsigned int address){
	return m68k_read_memory_16(address);
}

unsigned int inline m68k_read_immediate_32(unsigned int address){
	return m68k_read_memory_32(address);
}

unsigned int m68k_read_disassembler_8  (unsigned int address){
	return m68k_read_memory_8(address);
}

unsigned int m68k_read_disassembler_16 (unsigned int address){
	return m68k_read_memory_16(address);
}

unsigned int m68k_read_disassembler_32 (unsigned int address){
	return m68k_read_memory_32(address);
}

