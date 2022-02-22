// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		sys_processor.h
//		Purpose:	Processor Emulation (header)
//		Created:	1st October 2021
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#ifndef _PROCESSOR_H
#define _PROCESSOR_H

#define CYCLE_RATE 		(3540*1000)													// Cycles per second (3.54Mhz)

typedef unsigned short WORD16;														// 8 and 16 bit types.
typedef unsigned char  BYTE8;
typedef unsigned int   LONG32;														// 32 bit type.

void CPUReset(void);
BYTE8 CPUExecuteInstruction(void);
BYTE8 CPUWriteKeyboard(BYTE8 pattern);
BYTE8 CPUReadMemory(LONG32 address);
void CPUWriteMemory(LONG32 address,BYTE8 data);



#define PC 			(CPUGetStatus()->pc)

#ifdef INCLUDE_DEBUGGING_SUPPORT													// Only required for debugging

BYTE8 CPUExecute(LONG32 breakPoint1,LONG32 breakPoint2);
WORD16 CPUGetStepOverBreakpoint(void);
void CPUEndRun(void);
void CPULoadBinary(char *fileName);
void CPUExit(void);

typedef struct _CPUStatus {
	int a[8],d[8];
	int pc,sp,cycles;
	int sr,usp,isp;
} CPUSTATUS;

CPUSTATUS *CPUGetStatus(void);

#endif
#endif