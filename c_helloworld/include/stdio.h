#ifndef _STDIO_H_
#define _STDIO_H_

#include "stddef.h"

extern void printf(const char *);

#ifndef _NO_HEX_STDIO_H_
extern void to_hex_digit(u8, char *);
extern void to_hex_str(u16);
#endif

extern void set_video_mode(u8);

#endif
