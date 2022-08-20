#include "include/stddef.h"
#include "include/stdio.h"
#include "include/drive.h"

void main()
{
	char *b = (char*)0x7e00;
	u8 s, r;
	read_sector(1, 0, 0, 1, b, 1, &s, &r); 
	printf(b + 0x2b);
}
