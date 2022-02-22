#ifndef _PROTO_GUIGFX_H
#define _PROTO_GUIGFX_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_GUIGFX_PROTOS_H) && !defined(__GNUC__)
#include <clib/guigfx_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *GuiGFXBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/guigfx.h>
#else
#include <inline/guigfx.h>
#endif
#elif defined(__VBCC__)
#include <inline/guigfx_protos.h>
#else
#include <pragma/guigfx_lib.h>
#endif

#endif	/*  _PROTO_GUIGFX_H  */
