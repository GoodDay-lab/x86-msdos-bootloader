## BIOS graphics!

	I readed this http://un.uobasrah.edu.iq/lectures/8108.pdf. 
	There's some info about graphic in BIOS and how to draw pixels using bios interrupts.

## Issue

No issue! I did it!

## Soultion

	I used objdump to check a sections order and seen that .text (funtion) start before entry point (main)
	so I just changed script ld. *.text.sturtup* is entry point, *.text* some functions. 
	That's really cool! I understood a little in linking and assembling!

## HOW it works (my mind):

	- gcc (GNU compiler) makes assembly code using source codes written on C (to check: gcc -S foo.c -o asm.S)
	- as (GNU assembler) makes from source written on assembly a *(object file)* (to check: as asm.S -o code.o | gcc -c foo.c -o code.o)
	- ld (GNU linker) makes a elf/binary executable files using *(object file(s))* (to check: ld -m elf_i386 code.o -o code)
	- objcopy (GNU objcopy) can convert elf executable files to binary

	Notes:
	- assembler/compiler provides a capability to change a target machine (x86/x86_64):
		- In assembler you can define (.code32)
		- In compiler by argument (-m 32)
	- linker provides a capability to change executable format (elf_i386/elf_x86_64/binary)
		- Also linker provides a script.ld to make custom executable file
	 

## Defines:
	- object file: assembled code that contains labels and machine, code necessary for linker
