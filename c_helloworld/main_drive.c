#include "include/init.h"
#include "include/stddef.h"
#include "include/stdio.h"
#include "include/drive.h"

SET_OEM_NAME("MSDOS52");
SET_SECTOR_SIZE(512);

void main()
{
	char *b = (char*)0x7e00;
	u8 s, r;
	read_sector(1, 0, 0, 1, b, 1, &s, &r); 
	printf(GET_OEM_NAME);
}
