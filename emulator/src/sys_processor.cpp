// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		sys_processor.cpp
//		Purpose:	Processor Emulation.
//		Created:	1st October 2021
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include <stdio.h>
#include "sys_processor.h"
#include "sys_debug_system.h"
#include "hardware.h"
#include "m68k.h"
#include <setup.h>

// *******************************************************************************************************************************
//														   Timing
// *******************************************************************************************************************************

#define FRAME_RATE		(60)														// Frames per second (50 arbitrary)
#define CYCLES_PER_FRAME (CYCLE_RATE / FRAME_RATE) 									// Cycles per frame.

// *******************************************************************************************************************************
//														CPU / Memory
// *******************************************************************************************************************************

static int cycles;																	// Cycle Count.

// *******************************************************************************************************************************
//														Reset the CPU
// *******************************************************************************************************************************

void CPUReset(void) {
	m68k_init();
	m68k_set_cpu_type(PROCESSOR_TYPE);		 										// Select CPU type.
	m68k_pulse_reset();																// Reset
	m68k_set_reg(M68K_REG_PC,m68k_read_memory_32(0xFFC00004));
	HWReset();																		// Reset Hardware
	cycles = CYCLES_PER_FRAME;
}

// *******************************************************************************************************************************
//					Called on exit, does nothing on ESP32 but required for compilation
// *******************************************************************************************************************************

#ifdef INCLUDE_DEBUGGING_SUPPORT
#include "gfx.h"
void CPUExit(void) {	
	printf("Exited via $FFFFFFFF");
	GFXExit();
}
#else
void CPUExit(void) {}
#endif

// *******************************************************************************************************************************
//												Execute a single instruction
// *******************************************************************************************************************************

BYTE8 CPUExecuteInstruction(void) {
	#ifdef INCLUDE_DEBUGGING_SUPPORT
	if (PC == 0xFFFFFFFF) CPUExit();
	#endif
	cycles -= m68k_execute(1);
	if (cycles >= 0 ) return 0;														// Not completed a frame.
	cycles = cycles + CYCLES_PER_FRAME;												// Adjust this frame rate, up to x16 on HS
	HWSync();																		// Update any hardware
	return FRAME_RATE;																// Return frame rate.
}

// *******************************************************************************************************************************
//												Read/Write Memory
// *******************************************************************************************************************************

BYTE8 CPUReadMemory(LONG32 address) {
	return m68k_read_memory_8(address);
}

void CPUWriteMemory(LONG32 address,BYTE8 data) {
	m68k_write_memory_8(address,data);
}

#ifdef INCLUDE_DEBUGGING_SUPPORT

// *******************************************************************************************************************************
//		Execute chunk of code, to either of two break points or frame-out, return non-zero frame rate on frame, breakpoint 0
// *******************************************************************************************************************************

BYTE8 CPUExecute(LONG32 breakPoint1,LONG32 breakPoint2) { 
	BYTE8 next;
	do {
		BYTE8 r = CPUExecuteInstruction();											// Execute an instruction
		if (r != 0) return r; 														// Frame out.
	} while (PC != breakPoint1 && PC != breakPoint2);								// Stop on breakpoint or $76 HALT break
	return 0; 
}

// *******************************************************************************************************************************
//									Return address of breakpoint for step-over, or 0 if N/A
// *******************************************************************************************************************************

WORD16 CPUGetStepOverBreakpoint(void) {
	BYTE8 op = CPUReadMemory(PC); 	
	if (op == 0xCD || (op & 0xC7) == 0xC4) return PC+3; 							// CALL/CALL xx
	if ((op & 0xC7) == 0xC7) return PC+1;											// RST
	return 0;																		// Do a normal single step
}

// *******************************************************************************************************************************
//														Get CPU Status
// *******************************************************************************************************************************

static CPUSTATUS st;

CPUSTATUS *CPUGetStatus(void) {
	st.cycles = cycles;
	st.pc = m68k_get_reg(NULL, M68K_REG_PC);
	st.sp = m68k_get_reg(NULL, M68K_REG_SP);
	st.sr = m68k_get_reg(NULL, M68K_REG_SR);
	st.usp = m68k_get_reg(NULL, M68K_REG_USP);
	st.isp = m68k_get_reg(NULL, M68K_REG_ISP);
	st.a[0] = m68k_get_reg(NULL,M68K_REG_A0);
	st.a[1] = m68k_get_reg(NULL,M68K_REG_A1);
	st.a[2] = m68k_get_reg(NULL,M68K_REG_A2);
	st.a[3] = m68k_get_reg(NULL,M68K_REG_A3);
	st.a[4] = m68k_get_reg(NULL,M68K_REG_A4);
	st.a[5] = m68k_get_reg(NULL,M68K_REG_A5);
	st.a[6] = m68k_get_reg(NULL,M68K_REG_A6);
	st.a[7] = m68k_get_reg(NULL,M68K_REG_A7);
	st.d[0] = m68k_get_reg(NULL,M68K_REG_D0);
	st.d[1] = m68k_get_reg(NULL,M68K_REG_D1);
	st.d[2] = m68k_get_reg(NULL,M68K_REG_D2);
	st.d[3] = m68k_get_reg(NULL,M68K_REG_D3);
	st.d[4] = m68k_get_reg(NULL,M68K_REG_D4);
	st.d[5] = m68k_get_reg(NULL,M68K_REG_D5);
	st.d[6] = m68k_get_reg(NULL,M68K_REG_D6);
	st.d[7] = m68k_get_reg(NULL,M68K_REG_D7);
	return &st;
}

#endif