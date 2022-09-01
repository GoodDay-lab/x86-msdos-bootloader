#include "include/stddef.h"
#include "include/stdio.h"
#include "include/drive.h"
#include "include/parttable.h"

// Your code should be in main 'function'
// Because it's entry point

void main()
{      
    // Makes 'partition_table' a pointer to 0x7dbe (where is MBR (Master Boot Record))
    PART_TABLE(partition_table);
    
    char ACTIVE[] = " * ";
    char DEACTIVE[] = " - ";
    char PARTITION[] = "Partition  ";
    char ENDL[] = "\n";

    int t;
    for (t = 0; t < 4; t++) {
        printf(PARTITION);
        printf((*partition_table)[t].status  == 0x80 ? ACTIVE : DEACTIVE);
        printf(ENDL);
    }
}
