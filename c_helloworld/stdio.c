#include "stdio.h"

void printf(const char *string)
{
	while (*string) {
		__asm__ __volatile__ ("int $0x10\n" : : "a"(0x0e00 | *string), "b"(0x0007));
		string++;
	}
}
