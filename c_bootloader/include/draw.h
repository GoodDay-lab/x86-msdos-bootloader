
#ifndef _DRAW_H_
#define _DRAW_H_

#include "def.h"

#define LIGHT 0b1000
#define RED 0b0100
#define GREEN 0b0010
#define BLUE 0b0001
#define LRED (LIGHT | RED)
#define LGREEN (LIGHT | GREEN)
#define LBLUE (LIGHT | BLUE)

extern void draw_pixel(u16, u16, u16, u8);
extern void draw_rectangle(u16, u16, u16, u16, u8);

#endif
