#ifndef _PROTO_FONTCONFIG_H
#define _PROTO_FONTCONFIG_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_FONTCONFIG_PROTOS_H) && !defined(__GNUC__)
#include <clib/fontconfig_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *FontConfigBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/fontconfig.h>
#else
#include <inline/fontconfig.h>
#endif
#elif defined(__VBCC__)
#include <inline/fontconfig_protos.h>
#else
#include <pragma/fontconfig_lib.h>
#endif

#endif	/*  _PROTO_FONTCONFIG_H  */
