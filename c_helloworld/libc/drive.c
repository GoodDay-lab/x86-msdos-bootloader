#include "../include/drive.h"

/*
 *  This lib provides some 
 * functions to read/write from/into mbr disk!
 */

/*
 * Make %es and %ds into zero
 */
void init_drive()
{
	__asm__ __volatile__ (
					"xorw %ax, %ax\n"
					"movw %ax, %es\n"
					"movw %ax, %ds\n");
}

/*
 * Reads from track, head, sector on your MBR disk
 */
void read_sector(u8 disk, u8 track, u8 head, u8 sector, char* buf, u8 count, u8 *status, u8 *readed)
{
	u16 code;
	__asm__ __volatile__ (
					"int $0x13\n"
					: "=a"(code)
					: "a"(0x0200 | count), "b"(buf), 
					"c"(track<<8 | sector), "d"(head<<8 | (0x80 | disk))
					: "memory");
	*status = (code >> 8);
	*readed = (code >> 0);
}

/*
 * Write to track, head, sector to your MBR disk
 */
void write_sector(u8 disk, u8 track, u8 head, u8 sector, char* buf, u8 count, u8 *status, u8 *wrote)
{
	u16 code;
	__asm__ __volatile__ (
					"int $0x13\n" 
					: "=a"(code)
					: "a"(0x0300 | count), "b"(buf),
					"c"(track<<8 | sector), "d"(head<<8 | (0x80 | disk))
					: "memory");
	*status = (code >> 8);
	*wrote = (code >> 0);
}
