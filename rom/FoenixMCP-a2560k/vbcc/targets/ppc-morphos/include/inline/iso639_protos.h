#ifndef _VBCCINLINE_ISO639_H
#define _VBCCINLINE_ISO639_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EMUL_EMULREGS_H
#include <emul/emulregs.h>
#endif

Class * __ISO639_GetClass(void *) =
	"\tlwz\t11,100(2)\n"
	"\tstw\t3,56(2)\n"
	"\tmtctr\t11\n"
	"\tli\t3,-30\n"
	"\tbctrl";
#define ISO639_GetClass() __ISO639_GetClass(ISO639Base)

#endif /*  _VBCCINLINE_ISO639_H  */
