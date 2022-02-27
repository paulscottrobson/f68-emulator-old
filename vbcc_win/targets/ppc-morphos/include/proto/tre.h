#ifndef _PROTO_TRE_H
#define _PROTO_TRE_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_TRE_PROTOS_H) && !defined(__GNUC__)
#include <clib/tre_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *TREBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/tre.h>
#else
#include <inline/tre.h>
#endif
#elif defined(__VBCC__)
#include <inline/tre_protos.h>
#else
#include <pragma/tre_lib.h>
#endif

#endif	/*  _PROTO_TRE_H  */
