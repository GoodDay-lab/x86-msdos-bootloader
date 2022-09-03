
#ifndef _FAT_FAT_H_
#define _FAT_FAT_H_

#include "FAT_def.h"
#include "FAT_bpb.h"

#define FAT12 0b001
#define FAT16 0b010
#define FAT32 0b100

bool get_fat_type(FAT_BPB);



#endif
