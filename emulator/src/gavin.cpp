// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		hardware.c
//		Purpose:	Hardware Emulation
//		Created:	1st October 2021
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include "sys_processor.h"
#include "hardware.h"
#include <stdio.h>

static BYTE8 icr[6];
static BYTE8 mauQueue = 0;

// *******************************************************************************************************************************
//
//													Read Gavin Memory
//
// *******************************************************************************************************************************

int GAVIN_Read(int offset,BYTE8 *memory) {
	//printf("GAVIN:Reading offset %04x\n",offset);
	if (offset >= 0x100 && offset < 0x106) { 				// Reading interrupt control registers
		//printf("Read ICR %02x\n",icr[offset-0x100]);
		return icr[offset-0x100];
	}
	if (offset >= 0x40 && offset < 0x44) { 					// Reading MAU register.
		if (offset == 0x40) { 								// Reading first MAU.
			int next = mauQueue;							// Next to go.
			memory[offset] = 0x00;
			memory[offset+1] = 0x00;
			memory[offset+2] = (next == 0) ? 0 : 0xFF;
			memory[offset+3] = next;
			mauQueue = 0;									// Pop from queue.
		}		
	}
	return memory[offset];
}

// *******************************************************************************************************************************
//
//										Write Gavin Memory - return true if write done.
//
// *******************************************************************************************************************************

int GAVIN_Write(int offset,BYTE8 *memory,int value) {
	//printf("GAVIN:Writing offset %04x %02x\n",offset,value);
	if (offset >= 0x100 && offset < 0x106) { 				// And write interrupt control registers
		icr[offset-0x100] &= value;
	}
	if (offset == 0x2060 || offset == 0x2064) { 			// PS/2 always return 0.
		return 1;
	}
	return 0;
}

// *******************************************************************************************************************************
//
//													Gavin - Flag Interrupt
//
// *******************************************************************************************************************************

void GAVIN_FlagInterrupt(int offset,int bitMask) {
	icr[offset] |= bitMask;
}

// *******************************************************************************************************************************
//
//											  Gavin - insert into MAU Fifo Queue
//
// *******************************************************************************************************************************

void GAVIN_InsertMauFIFO(int mau) {
	mauQueue = mau;
}
