#include "include/stddef.h"
#include "include/stdio.h"
//#include "include/draw.h"

void main()
{
	set_video_mode(0x13);
	printf("\n\n\n\n    Hello, world\n");
	printf("  That is a simplest bootloader\n");
	//draw_rectangle(10, 20, 254, 60, RED);
}

