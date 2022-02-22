ENTRY(_start)

SECTIONS
{
  /* Read-only sections, merged into text segment: */
  . = 0x8048000 + SIZEOF_HEADERS;
  PROVIDE(__executable_start = 0x8048000);

  .init           : { *(.init) } = 0x90909090
  .plt            : { *(.plt) }
  .text           : { *(.text) }
  .fini           : { *(.fini) } = 0x90909090
  PROVIDE(__etext = .);
  PROVIDE(_etext = .);
  PROVIDE(etext = .);
  .note.netbsd.ident : { *(.note.netbsd.ident) }
  .rodata         : { *(.rodata .rodata.*) }
  .got            : { *(.got) }

  /* data segment: */
  . = ALIGN(16) + 0x10000;

  .got.plt        : { *(.got.plt) }
  .data           : {
    *(.data .data.*)
    VBCC_CONSTRUCTORS_ELF
  }
  _edata = .;
  PROVIDE(edata = .);

  __bss_start = .;
  .bss            : {
    *(.bss .bss.*)
    *(COMMON)
   . = ALIGN(32 / 8);
  }
  . = ALIGN(32 / 8);
  _end = .;
  __HEAPSTART = 0x89c4000;
  PROVIDE(end = .);

  .comment      0 : { *(.comment) }

  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
}
