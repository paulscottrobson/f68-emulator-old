#ifndef _VBCCINLINE_SENSORS_H
#define _VBCCINLINE_SENSORS_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EMUL_EMULREGS_H
#include <emul/emulregs.h>
#endif

APTR __AddSensor(void *, struct TagItem * taglist) =
	"\tlwz\t0,-28(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define AddSensor(taglist) __AddSensor(SensorsBase, (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __linearvarargs __AddSensorTags(void *, ...) =
	"\tlwz\t0,-28(3)\n"
	"\taddi\t4,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define AddSensorTags(...) __AddSensorTags(SensorsBase, __VA_ARGS__)
#endif

void __RemoveSensor(void *, APTR sensor, struct TagItem * taglist) =
	"\tlwz\t0,-34(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define RemoveSensor(sensor, taglist) __RemoveSensor(SensorsBase, (sensor), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __linearvarargs __RemoveSensorTags(void *, APTR sensor, ...) =
	"\tlwz\t0,-34(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define RemoveSensorTags(sensor, ...) __RemoveSensorTags(SensorsBase, (sensor), __VA_ARGS__)
#endif

APTR __ObtainSensorsList(void *, struct TagItem * taglist) =
	"\tlwz\t0,-40(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define ObtainSensorsList(taglist) __ObtainSensorsList(SensorsBase, (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __linearvarargs __ObtainSensorsListTags(void *, ...) =
	"\tlwz\t0,-40(3)\n"
	"\taddi\t4,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define ObtainSensorsListTags(...) __ObtainSensorsListTags(SensorsBase, __VA_ARGS__)
#endif

APTR __NextSensor(void *, APTR lastsensor, APTR sensorslist, struct TagItem * taglist) =
	"\tlwz\t0,-46(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define NextSensor(lastsensor, sensorslist, taglist) __NextSensor(SensorsBase, (lastsensor), (sensorslist), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __linearvarargs __NextSensorTags(void *, APTR lastsensor, APTR sensorslist, ...) =
	"\tlwz\t0,-46(3)\n"
	"\taddi\t6,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define NextSensorTags(lastsensor, sensorslist, ...) __NextSensorTags(SensorsBase, (lastsensor), (sensorslist), __VA_ARGS__)
#endif

void __ReleaseSensorsList(void *, APTR sensorslist, struct TagItem * taglist) =
	"\tlwz\t0,-52(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define ReleaseSensorsList(sensorslist, taglist) __ReleaseSensorsList(SensorsBase, (sensorslist), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __linearvarargs __ReleaseSensorsListTags(void *, APTR sensorslist, ...) =
	"\tlwz\t0,-52(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define ReleaseSensorsListTags(sensorslist, ...) __ReleaseSensorsListTags(SensorsBase, (sensorslist), __VA_ARGS__)
#endif

ULONG __GetSensorAttr(void *, APTR sensor, struct TagItem * taglist) =
	"\tlwz\t0,-58(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define GetSensorAttr(sensor, taglist) __GetSensorAttr(SensorsBase, (sensor), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __linearvarargs __GetSensorAttrTags(void *, APTR sensor, ...) =
	"\tlwz\t0,-58(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define GetSensorAttrTags(sensor, ...) __GetSensorAttrTags(SensorsBase, (sensor), __VA_ARGS__)
#endif

ULONG __SetSensorAttr(void *, APTR sensor, struct TagItem * taglist) =
	"\tlwz\t0,-64(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define SetSensorAttr(sensor, taglist) __SetSensorAttr(SensorsBase, (sensor), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __linearvarargs __SetSensorAttrTags(void *, APTR sensor, ...) =
	"\tlwz\t0,-64(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define SetSensorAttrTags(sensor, ...) __SetSensorAttrTags(SensorsBase, (sensor), __VA_ARGS__)
#endif

APTR __StartSensorNotify(void *, APTR sensor, struct TagItem * taglist) =
	"\tlwz\t0,-70(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define StartSensorNotify(sensor, taglist) __StartSensorNotify(SensorsBase, (sensor), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __linearvarargs __StartSensorNotifyTags(void *, APTR sensor, ...) =
	"\tlwz\t0,-70(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define StartSensorNotifyTags(sensor, ...) __StartSensorNotifyTags(SensorsBase, (sensor), __VA_ARGS__)
#endif

void __EndSensorNotify(void *, APTR notify, struct TagItem * taglist) =
	"\tlwz\t0,-76(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define EndSensorNotify(notify, taglist) __EndSensorNotify(SensorsBase, (notify), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __linearvarargs __EndSensorNotifyTags(void *, APTR notify, ...) =
	"\tlwz\t0,-76(3)\n"
	"\taddi\t5,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define EndSensorNotifyTags(notify, ...) __EndSensorNotifyTags(SensorsBase, (notify), __VA_ARGS__)
#endif

ULONG __GetSensorsCount(void *, struct TagItem * taglist) =
	"\tlwz\t0,-82(3)\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define GetSensorsCount(taglist) __GetSensorsCount(SensorsBase, (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __linearvarargs __GetSensorsCountTags(void *, ...) =
	"\tlwz\t0,-82(3)\n"
	"\taddi\t4,1,8\n"
	"\tmtctr\t0\n"
	"\tbctrl";
#define GetSensorsCountTags(...) __GetSensorsCountTags(SensorsBase, __VA_ARGS__)
#endif

#endif /*  _VBCCINLINE_SENSORS_H  */
