
#ifndef _PARTTABLE_H_
#define _PARTTABLE_H_

#include "stddef.h"

typedef struct {
	u8 status;
	u8 begin_head;
	u8 begin_sector : 6;
	u16 begin_track : 10;
	u8 partition_code;
	u8 end_head;
	u8 end_sector : 6;
	u16 end_track : 10;
	u32 offset;
	u32 sectors_count;
} partition;

typedef struct {
	partition part0;
	partition part1;
	partition part2;
	partition part3;
} parttable;

#define PART_TABLE \
		static const parttable __attribute__((aligned(64))) __attribute__((section(".table"))) __attribute__((used))


#endif
