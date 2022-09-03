
#ifndef _MBR_H_
#define _MBR_H_

#include "def.h"

typedef struct {
	u8 MBR_Stat;
	u8 MBR_BegHead;
	u8 MBR_BegSctr : 6;
	u16 MBR_BegTrack : 10;
	u8 MBR_PartCode;
	u8 MBR_EndHead;
	u8 MBR_EndSctr : 6;
	u16 MBR_EndTrack : 10;
	u32 MBR_Offset;
	u32 MBR_SctrCnt;
} MBR_Partition;

/* source: https://stackoverflow.com/questions/4523497/typedef-fixed-length-array */
typedef MBR_Partition MBR_Table[4];

#define MBR_TABLE(NAME) \
	    static MBR_Table* NAME = (MBR_Table*)0x7dbe;


#endif
