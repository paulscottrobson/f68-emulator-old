// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		hardware.c
//		Purpose:	Hardware Emulation
//		Created:	22nd February 2022
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include <includes.h>

static BYTE8 icr[6];
static BYTE8 mauQueue = 0;

// *******************************************************************************************************************************
//
//													Read Gavin Memory
//
// *******************************************************************************************************************************

int Gavin_Read(int offset,BYTE8 *memory,int size) {
//	printf("GAVIN:Reading memory %04x %d\n",offset,size);
//	printf("Gavin Address %x\n",memory);

	//
	//		We manage the ICR ourselves
	//
	if (HW_IS_GAVIN_INTERRUPTCTRL(offset)) {
		return icr[offset-0x100];
	}
	//
	// 		Reading the PS/2 port always returns zero, it's dead.
	//
	if (HW_IS_GAVIN_READPS2(offset)) {
		return 0;
	}
	//
	//		Read the head of the MAU FIFO Queue
	//
	if (HW_IS_GAVIN_READMAU(offset)) {
		int qHead = mauQueue;
		mauQueue = 0;
		return qHead;
	}
	//
	//		Default
	//
	return memory[offset];
}

// *******************************************************************************************************************************
//
//										Write Gavin Memory - return true if write done.
//
// *******************************************************************************************************************************

int Gavin_Write(int offset,BYTE8 *memory,int value,int size) {
//	printf("GAVIN:Writing memory %04x value %02x %d\n",offset,value,size);
//	printf("Gaving Address %x\n",memory);
	//
	//		Writing to ICR ands the bits with the value. 
	//
	if (HW_IS_GAVIN_INTERRUPTCTRL(offset)) {
		icr[offset - 0x100] &= value;
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
