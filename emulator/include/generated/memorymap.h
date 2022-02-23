//
//	Automatically generated.
//
#define ADDRESS_MASK (0xFFFFFFFF)
#define PROCESSOR_TYPE (M68K_CPU_TYPE_68040)

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

