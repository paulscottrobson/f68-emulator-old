#ifndef _PROTO_SPELLCHECKER_H
#define _PROTO_SPELLCHECKER_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#if !defined(CLIB_SPELLCHECKER_PROTOS_H) && !defined(__GNUC__)
#include <clib/spellchecker_protos.h>
#endif

#ifndef __NOLIBBASE__
extern struct Library *SpellCheckerBase;
#endif

#ifdef __GNUC__
#ifdef __AROS__
#include <defines/spellchecker.h>
#else
#include <inline/spellchecker.h>
#endif
#elif defined(__VBCC__)
#include <inline/spellchecker_protos.h>
#else
#include <pragma/spellchecker_lib.h>
#endif

#endif	/*  _PROTO_SPELLCHECKER_H  */
