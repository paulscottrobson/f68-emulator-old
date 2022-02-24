// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		hardware.h
//		Purpose:	Hardware Emulation Header
//		Created:	22nd February 2022
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#ifndef _HARDWARE_H
#define _HARDWARE_H

#define IRQ_VICKY_B 		(6)
#define IRQ_VICKY_A  		(5)
#define IRQ_GAVIN_SUPERIO 	(4)
#define IRQ_GAVIN_TIMER 	(3)
#define IRQ_BEATRIX_IDESDYAM (2)
#define IRQ_BEATRIX_DAC  	(1)

void HWReset(void);
void HWSync(void);

int Gavin_Read(int offset,BYTE8 *memory,int size);
int Gavin_Write(int offset,BYTE8 *memory,int value,int size);

void GAVIN_FlagInterrupt(int offset,int bitMask);
void GAVIN_InsertMauFIFO(int mau);
void GAVIN_UpdateTimers(int cycles,int frames);

void MEMRenderDisplay(void);
void HWRenderTextScreen(BYTE8 *vicky,BYTE8 *charMem,BYTE8 *colMem,BYTE8 *lutMem,BYTE8 *fontMem,int width,int height);

void  HWScanCodeHandler(int scancode,int keydown);

#ifdef LINUX
#define FILESEP '/'
#else
#define FILESEP '\\'
#endif

#endif
