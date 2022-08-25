#include "include/init.h"
#include "include/stddef.h"
#include "include/stdio.h"
#include "include/drive.h"

SET_OEM_NAME("selfdos");
SET_SECTOR_SIZE(0x1111);
SET_CLUSTER_SIZE(0x22);
SET_RESERVED_SECTORS(0x3333);
SET_NUMBER_OF_FATS(0x44);
SET_ROOT_ENTRIES(0x5555);
SET_SMALL_SECTORS(0x6666);
SET_MEDIA_TYPE(0x77);
SET_SECTORS_PER_FAT(0x8888);
SET_SECTORS_PER_TRACK(0x9999);
SET_NUMBER_OF_HEADS(0xAAAA);
SET_HIDDEN_SECTORS(0xBBBBBBBB);
SET_LARGE_SECTORS(0xCCCCCCCC);

void main()
{
	char *b = (char*)0x7e00;
	u8 s, r;
	read_sector(1, 0, 0, 1, b, 1, &s, &r); 
	printf(GET_OEM_NAME);
}
