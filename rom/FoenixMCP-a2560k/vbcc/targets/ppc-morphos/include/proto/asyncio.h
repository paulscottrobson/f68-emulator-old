#ifndef _PROTO_ASYNCIO_H
#define _PROTO_ASYNCIO_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_ASYNCIO_PROTOS_H) && !defined(__GNUC__)
#include <clib/asyncio_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *AsyncIOBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/asyncio.h>
#else
#include <inline/asyncio.h>
#endif
#elif defined(__VBCC__)
#include <inline/asyncio_protos.h>
#else
#include <pragma/asyncio_lib.h>
#endif

#endif	/*  _PROTO_ASYNCIO_H  */
