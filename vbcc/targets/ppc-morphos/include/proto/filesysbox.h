#ifndef _PROTO_FILESYSBOX_H
#define _PROTO_FILESYSBOX_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_FILESYSBOX_PROTOS_H) && !defined(__GNUC__)
#include <clib/filesysbox_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *FilesysboxBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/filesysbox.h>
#else
#include <inline/filesysbox.h>
#endif
#elif defined(__VBCC__)
#include <inline/filesysbox_protos.h>
#else
#include <pragma/filesysbox_lib.h>
#endif

#endif	/*  _PROTO_FILESYSBOX_H  */
