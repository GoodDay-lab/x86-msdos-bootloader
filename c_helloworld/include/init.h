
#ifndef _INIT_H_
#define _INIT_H_

/* Attention
 *
 * I a little changed places of fields in FAT Boot Sectors Partition,
 * because C compiler make a offset for char fields. (u8 field takes 16 bit).
 */

/*
 * WARNING! DEPRECATED
 *
 * This header doesn't work,
 * It takes a lot memory, so I deicided to remove this.
 */

#include "stddef.h"

#define USED \
		__attribute__((used))
#define SECTION(NAME) \
		__attribute__((section(NAME)))
#define ALIGNED(N) \
		__attribute__((aligned(N)))

typedef struct {
	char 	OEM_name[8];
	u16 	bytes_per_sector;
	u8 		sectors_per_cluster;
	u8		number_of_fat;
	u16		reserved_sectors;
	u16		root_entries;
	u16		small_sectors;
	u16		sectors_per_fat;
	u16		sectors_per_track;
	u16		number_of_heads;
	u32		hidden_sectors;
	u32		large_sectors;
	u8		media_type;
	u8		phydisk_number;
	u8		current_head;
	u8		NT_signature;
	char	vol_serial[4];
	char	vol_label[8];
	char	system_ID[8];
} FAT_BootInfo;

#define BOOTINFO \
		static const FAT_BootInfo USED SECTION(".info.fat")

#endif 
