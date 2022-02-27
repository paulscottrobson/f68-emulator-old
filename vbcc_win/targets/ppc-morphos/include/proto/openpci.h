#ifndef _PROTO_OPENPCI_H
#define _PROTO_OPENPCI_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_OPENPCI_PROTOS_H) && !defined(__GNUC__)
#include <clib/openpci_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *OpenPciBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/openpci.h>
#else
#include <inline/openpci.h>
#endif
#elif defined(__VBCC__)
#include <inline/openpci_protos.h>
#else
#include <pragma/openpci_lib.h>
#endif

#endif	/*  _PROTO_OPENPCI_H  */
