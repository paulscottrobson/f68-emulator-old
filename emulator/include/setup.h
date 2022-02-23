// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		setup.h
//		Purpose:	Configuration
//		Created:	22nd February 2022
//		Author:		Paul Robson (paul@robsons->org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#ifndef _SETUP_H
#define _SETUP_H

#include <m68k.h>
#define ADDRESS_MASK 	(0xFFFFFFFF)
#define PROCESSOR_TYPE  (M68K_CPU_TYPE_68040)

#define ADDR_GAVIN 		(0xFEC00000)
#define ADDR_BEATRIX	(0xFEC20000)
#define ADDR_VICKY3A  	(0xFEC40000)
#define ADDR_VICKY3B  	(0xFEC80000)

#define ISHWADDR(a)  	((a) >=  0xFE000000)
#define ISDEVICE(a,d)  	((((a)) & 0xFFFE0000) == (d))

#endif
