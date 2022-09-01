
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

/* source: https://stackoverflow.com/questions/4523497/typedef-fixed-length-array */
typedef partition parttable[4];

#define PART_TABLE(NAME) \
		parttable* NAME = (parttable*)0x7dbe


#endif
