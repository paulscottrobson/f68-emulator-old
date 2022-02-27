#ifndef _PROTO_TRANCE_H
#define _PROTO_TRANCE_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_TRANCE_PROTOS_H) && !defined(__GNUC__)
#include <clib/trance_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *TranceBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/trance.h>
#else
#include <inline/trance.h>
#endif
#elif defined(__VBCC__)
#include <inline/trance_protos.h>
#else
#include <pragma/trance_lib.h>
#endif

#endif	/*  _PROTO_TRANCE_H  */
