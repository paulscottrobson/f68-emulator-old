#ifndef _PROTO_XADMASTER_H
#define _PROTO_XADMASTER_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_XADMASTER_PROTOS_H) && !defined(__GNUC__)
#include <clib/xadmaster_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct xadMasterBase *xadMasterBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/xadmaster.h>
#else
#include <inline/xadmaster.h>
#endif
#elif defined(__VBCC__)
#include <inline/xadmaster_protos.h>
#else
#include <pragma/xadmaster_lib.h>
#endif

#endif	/*  _PROTO_XADMASTER_H  */
