#ifndef _PROTO_CLIPBOARD_H
#define _PROTO_CLIPBOARD_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_CLIPBOARD_PROTOS_H) && !defined(__GNUC__)
#include <clib/clipboard_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *ClipboardBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/clipboard.h>
#else
#include <inline/clipboard.h>
#endif
#elif defined(__VBCC__)
#include <inline/clipboard_protos.h>
#else
#include <pragma/clipboard_lib.h>
#endif

#endif	/*  _PROTO_CLIPBOARD_H  */
