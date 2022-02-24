vasmm68k_mot test.asm -align -Fsrec -o test.s68 -L test.lst -exec=start
srec_cat test.s68 -o test.hex -intel
