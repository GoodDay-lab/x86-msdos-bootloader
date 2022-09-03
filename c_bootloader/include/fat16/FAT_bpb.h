
#ifndef _FAT_BPB_H_
#define _FAT_BPB_H_

/* Provides structs and methods to work with FAT */
#include "FAT_def.h"

typedef struct {
        char       BPB_OemID[8];
        uint16     BPB_BytsPerSctr;
        uint8      BPB_SctrPerClust;
        uint16     BPB_ResvSctrs;
        uint8      BPB_FatNum;
        uint16     BPB_RootEntCnt;
        uint16     BPB_TotlSctrs;
        uint8      BPB_MediaType;
        uint16     BPB_SctrPerFat;
        uint16     BPB_SctrPerTrack;
        uint16     BPB_NumHeads;
        uint32     BPB_HiddenSctrs;
        uint32     BPB_LrgSctrCnt;
        uint8      EBR_DrvNum;
        uint8      EBR_NTFlag;
        uint8      EBR_Sign;
        char       EBR_VolNum[4];
        char       EBR_VolLabel[8];
        char       EBR_SysID[8];
} FAT_BPB;

#define BPB_PARTITION(NAME) \
        static FAT_BPB* NAME = (FAT_BPB*)0x7c03;


#endif
