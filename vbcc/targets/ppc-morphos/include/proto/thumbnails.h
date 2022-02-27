#ifndef _PROTO_THUMBNAILS_H
#define _PROTO_THUMBNAILS_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_THUMBNAILS_PROTOS_H) && !defined(__GNUC__)
#include <clib/thumbnails_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *ThumbnailsBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/thumbnails.h>
#else
#include <inline/thumbnails.h>
#endif
#elif defined(__VBCC__)
#include <inline/thumbnails_protos.h>
#else
#include <pragma/thumbnails_lib.h>
#endif

#endif	/*  _PROTO_THUMBNAILS_H  */
