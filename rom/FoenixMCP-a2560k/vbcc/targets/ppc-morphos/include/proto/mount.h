#ifndef _PROTO_MOUNT_H
#define _PROTO_MOUNT_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_MOUNT_PROTOS_H) && !defined(__GNUC__)
#include <clib/mount_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *MountBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/mount.h>
#else
#include <inline/mount.h>
#endif
#elif defined(__VBCC__)
#include <inline/mount_protos.h>
#else
#include <pragma/mount_lib.h>
#endif

#endif	/*  _PROTO_MOUNT_H  */
