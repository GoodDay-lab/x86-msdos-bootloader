
#ifndef _INIT_H_
#define _INIT_H_

#include "stddef.h"

#define USED \
		__attribute__((used))
#define SECTION(NAME) \
		__attribute__((section(NAME)))
#define ALIGNED(N) \
		__attribute__((aligned(N)))
#define STCST \
		static const

#define SET_OEM_NAME(NAME) \
		static const char oem_name[8] \
		USED ALIGNED(8) \
		SECTION(".info.oem_name") \
		= NAME
#define GET_OEM_NAME \
		(char*)0x7c03

#define SET_SECTOR_SIZE(SIZE_W) \
		STCST u16 sector_size \
		USED SECTION(".info.pbs.sector_size") \
		= SIZE_W
#define GET_SECTOR_SIZE \
		(u16)sector_size

#define SET_CLUSTER_SIZE(SIZE_B) \
		STCST u8 cluster_size \
		USED SECTION(".info.pbs.cluster_size") \
		= SIZE_B
#define GET_CLUSTER_SIZE \
		(u8)cluster_size

#define SET_RESERVED_SECTORS(SIZE_W) \
		STCST u16 reserved_sectors \
		USED SECTION(".info.pbs.reserved_sectors") \
		= SIZE_W
#define GET_RESERVED_SECTORS \
		(u16)reserved_sectors

#define SET_NUMBER_OF_FATS(SIZE_B) \
		STCST u8 number_of_fats \
		USED SECTION(".info.pbs.number_of_fats") \
		= SIZE_B

#define SET_ROOT_ENTRIES(SIZE_W) \
		STCST u16 root_entries \
		USED SECTION(".info.pbs.root_entries") \
		= SIZE_W

#define SET_SMALL_SECTORS(SIZE_W) \
		STCST u16 small_sectors \
		USED SECTION(".info.pbs.small_sectors") \
		= SIZE_W

#define SET_MEDIA_TYPE(SIZE_B) \
		STCST u8 media_type \
		USED SECTION(".info.pbs.media_type") \
		= SIZE_B

#define SET_SECTORS_PER_FAT(SIZE_W) \
		STCST u16 sectors_per_fat \
		USED SECTION(".info.pbs.sectors_per_fat") \
		= SIZE_W

#define SET_SECTORS_PER_TRACK(SIZE_W) \
		STCST u16 sectors_per_track \
		USED SECTION(".info.pbs.sectors_per_track") \
		= SIZE_W

#define SET_NUMBER_OF_HEADS(SIZE_W) \
		STCST u16 number_of_heads \
		USED SECTION(".info.pbs.number_of_heads") \
		= SIZE_W

#define SET_HIDDEN_SECTORS(SIZE_D) \
		STCST u32 hidden_sectors \
		USED SECTION(".info.pbs.hidden_sectors") \
		= SIZE_D

#define SET_LARGE_SECTORS(SIZE_D) \
		STCST u32 large_sectors \
		USED SECTION(".info.pbs.large_sectors") \
		= SIZE_D


#endif 
