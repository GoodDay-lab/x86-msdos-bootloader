#include "libc/draw.h"
#include "libc/math.h"

void inline draw_pixel(int page, int x, int y, int c)
{
    __asm__ __volatile__ ("int $0x10\n" : : "a"(0x0c00 | c), "b"(page), "c"(x), "d"(y));
}

void draw_rectangle(int x1, int y1, int x2, int y2, int c)
{
        int i;
        if (x2 < x1) { i = x2; x2 = x1; x1 = i; }
        if (y2 < y1) { i = y2; y2 = y1; y1 = i; }

        for (i = x1; i < x2; i++) { draw_pixel(0, i, y1, c); }
        for (i = y1; i < y2; i++) { draw_pixel(0, x2, i, c); }
        for (i = x2; i >= x1; i--) { draw_pixel(0, i, y2, c); }
        for (i = y2; i >= y1; i--) { draw_pixel(0, x1, i, c); }
}

