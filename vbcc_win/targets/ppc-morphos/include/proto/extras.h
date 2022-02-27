#ifndef _PROTO_EXTRAS_H
#define _PROTO_EXTRAS_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_EXTRAS_PROTOS_H) && !defined(__GNUC__)
#include <clib/extras_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *ExtrasBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/extras.h>
#else
#include <inline/extras.h>
#endif
#elif defined(__VBCC__)
#include <inline/extras_protos.h>
#else
#include <pragma/extras_lib.h>
#endif

#endif	/*  _PROTO_EXTRAS_H  */
