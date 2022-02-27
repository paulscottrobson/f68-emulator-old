#ifndef _PROTO_OPENURL_H
#define _PROTO_OPENURL_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_OPENURL_PROTOS_H) && !defined(__GNUC__)
#include <clib/openurl_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *OpenURLBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/openurl.h>
#else
#include <inline/openurl.h>
#endif
#elif defined(__VBCC__)
#include <inline/openurl_protos.h>
#else
#include <pragma/openurl_lib.h>
#endif

#endif	/*  _PROTO_OPENURL_H  */
