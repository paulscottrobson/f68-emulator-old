# f68-emulator
A2560K Emulator

Standard make, requires SDL2 only. 

Builds on Windows with mingw32, SDL2 64 bit installed in c:\sdl2 and needs SDL2.dll and libwinpthread-1.dll - I will try to keep this
up to date - ish as I can build it on Virtual box. Seems to run okay. 

When building a pull do a make clean first so old .o files from another OS don't get in the way, then build with MAKE -B

Running. Can't load external files, yet, it just runs boot.rom which is a current build of the A2560K bios unmodified except for
the use of Polled Keyboard (Int version seems to be partially done ?)

The long pause at the start is because it makes a bong noise and displays a bitmap, there's no bitmap code yet. 

In the emulator directory either 

./f68 boot.rom 					(debug)
or
./f68 boot.rom go 				(run)

Debug keys
==========

0-9A-F 			Change code position (doesn't change PC)
With Shift 		Change data position
Ctrl key 		Display text not hex bytes
ESC 			Quit

F1 				Reset
F2 				Set viewed code to PC.
F5 				Run
F6 				Stop
F7 				Single Step
F8 				Step over JSR/BSR/Trap
F9 				Set Breakpoint

