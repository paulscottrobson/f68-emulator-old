// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		hardware.h
//		Purpose:	Hardware Emulation Header
//		Created:	1st October 2021
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#ifndef _HARDWARE_H
#define _HARDWARE_H

void HWReset(void);
void HWSync(void);

int GAVIN_Read(int offset,BYTE8 *memory);
int GAVIN_Write(int offset,BYTE8 *memory,int value);
void GAVIN_FlagInterrupt(int offset,int bitMask);

void MEMRenderDisplay(void);
void HWRenderTextScreen(BYTE8 *vicky,BYTE8 *charMem,BYTE8 *colMem,BYTE8 *lutMem,BYTE8 *fontMem,int width,int height);


#ifdef LINUX
#define FILESEP '/'
#else
#define FILESEP '\\'
#endif

#endif
