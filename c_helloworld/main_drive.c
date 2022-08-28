#include "include/stddef.h"
#include "include/stdio.h"
#include "include/drive.h"
#include "include/parttable.h"

PART_TABLE partition_table = {
	.part0 = {'H', 'e'}
};  // Now you can work with your partition table

void main()
{
	char HELLO_MSG[] = "Hello, world\n";
	printf(HELLO_MSG);
}
