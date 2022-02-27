#ifndef _PROTO_USBCLASS_H
#define _PROTO_USBCLASS_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_USBCLASS_PROTOS_H) && !defined(__GNUC__)
#include <clib/usbclass_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *UsbClsBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/usbclass.h>
#else
#include <inline/usbclass.h>
#endif
#elif defined(__VBCC__)
#include <inline/usbclass_protos.h>
#else
#include <pragma/usbclass_lib.h>
#endif

#endif	/*  _PROTO_USBCLASS_H  */
