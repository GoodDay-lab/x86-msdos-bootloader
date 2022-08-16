#include "libc/stdio.h"
#include "libc/drive.h"

void main()
{
	printf("Works..\n\r");
	printf("[S] extseg inited\n\r");
	printf("Reading sector... \n\r");
	read_sector(0, 0, 0, 0, 0);
}
