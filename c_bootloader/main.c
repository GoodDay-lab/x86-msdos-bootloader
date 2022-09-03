#include "include/def.h"
#include "include/io.h"
#include "include/drive.h"
#include "include/MBR.h"
#include "fat16/FAT_bpb.h"

// I don't know why, but I can't define global variables!
// Please write to 'issue' if you know cause, thanks!

void main()
{      
    // Makes 'mbr_table' to a pointer to 0x7dbe (where is MBR (Master Boot Record))
    //MBR_TABLE(mbr_table)
    // Makes 'bpb_part' to a pointer to 0x7c03 (where is FAT Boot Partition)
    BPB_PARTITION(bpb_part)
    
    char OEM[] = "OEM: ";
    char SERIAL[] = "VOL: ";
    char ENDL[] = "\n";
    
    printf(OEM);
    printf((*bpb_part).BPB_OemID);
    printf(ENDL);

    printf(SERIAL);
    printf((*bpb_part).EBR_VolLabel);
    printf(ENDL);
}
