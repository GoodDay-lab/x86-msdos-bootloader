
#ifndef _DRAW_H_
#define _DRAW_H_

#define LIGHT 0b1000
#define RED 0b0100
#define GREEN 0b0010
#define BLUE 0b0001
#define LRED (LIGHT | RED)
#define LGREEN (LIGHT | GREEN)
#define LBLUE (LIGHT | BLUE)

void draw_pixel(int, int, int, int);
void draw_rectangle(int, int, int, int, int);

#endif
