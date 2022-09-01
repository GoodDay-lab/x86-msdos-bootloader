
#ifndef _DRIVE_H_
#define _DRIVE_H_  // I like that movie..

#include "stddef.h"

extern void read_sector(u8, u8, u8, u8, char*, u8, u8*, u8*);  // reads sector to head, cyllinder, sector  (last 2 ptrs are ah and al)
extern void write_sector(u8, u8, u8, u8, char*, u8, u8*, u8*);  // write sector to head, cyllinder, sector  (last 2 ptrs are ah and al)

#endif 
