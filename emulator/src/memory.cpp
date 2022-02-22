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

#include <stdio.h>
#include "sys_processor.h"
#include "sys_debug_system.h"
#include "hardware.h"
#include "m68k.h"

static BYTE8 ramMemory[0x10000];													// Memory at $0000 upwards, 64k off

void CPULoadBinary(char *fileName) {
	FILE *f = fopen(fileName,"rb");
	if (f != NULL) {
		fread(ramMemory,1,0x10000,f); 												// Load binary to $4000
		fclose(f);
		ramMemory[7] = 0xC0;
		printf("*** PATCH ***\n");
		CPUReset();
	}
}

void CPUEndRun(void) {
	FILE *f = fopen("memory.dump","wb");
	fwrite(ramMemory,1,sizeof(ramMemory),f);
	fclose(f);
}


unsigned int  m68k_read_memory_8(unsigned int address){
	return ramMemory[address & 0xFFFF];
}

unsigned int  m68k_read_memory_16(unsigned int address){
	return m68k_read_memory_8(address+1) + (m68k_read_memory_8(address) << 8);
}

unsigned int  m68k_read_memory_32(unsigned int address){
	return m68k_read_memory_16(address+2) + (m68k_read_memory_16(address) << 16);
}


unsigned int  m68k_read_immediate_16(unsigned int address){
	return m68k_read_memory_16(address);
}

unsigned int  m68k_read_immediate_32(unsigned int address){
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



void m68k_write_memory_8(unsigned int address, unsigned int value){
	ramMemory[address & 0xFFFF] = value & 0xFF;
}

void m68k_write_memory_16(unsigned int address, unsigned int value){
	m68k_write_memory_8(address+1,value & 0xFF);
	m68k_write_memory_8(address,value >> 8);
}

void m68k_write_memory_32(unsigned int address, unsigned int value){
	m68k_write_memory_8(address+2,value & 0xFFFF);
	m68k_write_memory_8(address,value >> 16);
}



