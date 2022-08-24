
#ifndef _INIT_H_
#define _INIT_H_

#include "stddef.h"

#define SET_OEM_NAME(NAME) \
		static const char oem_name[] \
		__attribute__((used)) __attribute__((aligned(8))) \
		__attribute__((section(".info.oem_name"))) \
		= NAME
#define GET_OEM_NAME \
		(char*)0x7c03

#define SET_SECTOR_SIZE(SIZE) \
		static const u16 sector_size \
		__attribute__((used)) __attribute__((section(".info.bios_param_block.sector_size"))) \
		= SIZE
#define GET_SECTOR_SIZE \
		(u16)sector_size

#endif 
