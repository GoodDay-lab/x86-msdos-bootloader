#include "libc/drive.h"
#include "libc/stdio.h"

void init_drive(char *ptr)
{
	__asm__ __volatile__ ("movw $0x7E00, %bx\n");
}

void read_sector(int cil, int head, int sec, char *buf, int count)
{
	int status = 0;
	__asm__ __volatile__ (
					"xorw %%bx, %%bx\n"
					"movw %%bx, %%es\n"
					"movw $0x7e00, %%bx\n"
					"movb $0x02, %%ah\n" //;function
					"movb $0x1, %%al\n"  //;sectors to read
					"movb $0x0, %%ch\n"  //;tracks
					"movb $0x2, %%cl\n"  //;sector
					"movb $0x0, %%dh\n"  //;head
					"int $0x13\n" : "=al"(status));
	// __asm__ __volatile__ ("int $0x13\n" : "=al"(status): "ah"(0x02), "al"(count), "ch"(cil), "cl"(sec), "dh"(head));
	printf("status: ");
	if (status == count) {
		printf("success\n\r");
	} else {
		printf("fail\n\r");
	}
}
