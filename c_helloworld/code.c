#include "libc/stdio.h"
#include "libc/draw.h"

void main()
{
	set_video_mode(0x13);
	printf("\n\n\n\n     Hello, world\n\r");
	printf("  That is a simplest bootloader\n\r");
	draw_rectangle(10, 20, 254, 50, RED);
}

