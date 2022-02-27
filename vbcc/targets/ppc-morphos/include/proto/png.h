#ifndef _PROTO_PNG_H
#define _PROTO_PNG_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_PNG_PROTOS_H) && !defined(__GNUC__)
#include <clib/png_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *PNGBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/png.h>
#else
#include <inline/png.h>
#endif
#elif defined(__VBCC__)
#include <inline/png_protos.h>
#else
#include <pragma/png_lib.h>
#endif

#endif	/*  _PROTO_PNG_H  */
