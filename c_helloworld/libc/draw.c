#include "../include/draw.h"
#include "../include/math.h"

/*
 * In draw.h header you can find macros of RED, BLUE, GREEN, LIGHT RED, LIGHT GREEN, LIGHT BLUE colors
 */

/*
 * Draw pixel on coords (x, y), (c - color), (page uses in bios interrupt)
 */
void inline draw_pixel(u16 page, u16 x, u16 y, u8 c)
{
    __asm__ __volatile__ ("int $0x10\n" : : "a"(0x0c00 | c), "b"(page), "c"(x), "d"(y));
}

/*
 * Draws rectangle with 
 * 		high left corner on (x1, y1)
 * 		bottom right corner on (x2, y2)
 * 		c - color
 */
void draw_rectangle(u16 x1, u16 y1, u16 x2, u16 y2, u8 c)
{
    int i;
	for (i = x1; i < x2; i++) { draw_pixel(0, i, y1, c); draw_pixel(0, i, y2, c); }
	for (i = y1; i < y2; i++) { draw_pixel(0, x1, i, c); draw_pixel(0, x2, i, c); }
}

