//
//	Automatically generated.
//
#define BUILD_TIME ("Sun 27-Feb-2022 09:48")

#define ADDRESS_MASK (0xFFFFFFFF)

#define HARDWARE_START (0xFEC00000)

#define PROCESSOR_TYPE (M68K_CPU_TYPE_68040)

#define VRAM_START (0x00800000)
#define VRAM_END (0x00FFFFFF)

#define FLASH_ROM ("a2560k.rom")

#define HARDWARE_RAM 0x100000

#define ISHWADDR(a) (((a) & 0xfff00000) == 0xfec00000)

#define ADDR_GAVIN	(0xFEC00000)
#define IS_GAVIN(a)	(((a) & 0xfffe0000) == 0xfec00000)

#define ADDR_BEATRIX	(0xFEC20000)
#define IS_BEATRIX(a)	(((a) & 0xfffe0000) == 0xfec20000)

#define ADDR_VICKY3A	(0xFEC40000)
#define IS_VICKY3A(a)	(((a) & 0xfffe0000) == 0xfec40000)

#define ADDR_VICKY3B	(0xFEC80000)
#define IS_VICKY3B(a)	(((a) & 0xfffe0000) == 0xfec80000)

#define HW_IS_GAVIN_READMAU(a)  ((a) == 0x40)
#define HW_IS_GAVIN_RTC(a)  (((a) >= 0x80) && ((a) < 0x8a))
#define HW_IS_GAVIN_INTERRUPTCTRL(a)  (((a) >= 0x100) && ((a) < 0x106))
#define HW_IS_GAVIN_TIMERS(a)  (((a) >= 0x208) && ((a) < 0x230))
#define HW_IS_GAVIN_READPS2(a)  (((a) >= 0x2060) && ((a) < 0x2068))
