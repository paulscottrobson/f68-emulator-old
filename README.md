# f68-emulator
A2560K Emulator

Standard make, requires SDL2 only. Should build on Windows with the SDL2 directory in C:\SDL2 but I haven't tried it yet.

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