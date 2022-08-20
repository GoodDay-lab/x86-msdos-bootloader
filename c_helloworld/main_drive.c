#include "include/stddef.h"
#include "include/stdio.h"
#include "include/drive.h"

void main()
{
	char *b = (char*)0x7e00;
	u8 *s = (u8*)0x7b00, *r = (u8*)0x7b01;
	read_sector(0, 0, 2, b, 1, s, r);
	printf(b);
}
