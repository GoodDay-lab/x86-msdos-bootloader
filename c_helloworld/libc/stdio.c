#include "../include/stdio.h"

/*
 * To converts 16-bit number to hex I use
 * 	buffer, I use him as stack.
 * +-----------------------------------+
 * | c*N^k + c*N^(k-1) + ... + c*N^(0) | // Where's (c - random number), (N - your system (hex, bin, dec))
 * +-----------------------------------+ 
 */
char *BUFFER = "0000\n";

/*
 * Writes a string.
 *  print(f) - there's no formatting.
 */
void printf(const char *string)
{
	while (*string) {
		__asm__ __volatile__ ("int $0x10\n" : : "a"(0x0e00 | *string), "b"(0x0007));
		string++;
	}
	if ((*(string - 1)) == '\n') __asm__ __volatile__ ("int $0x10\n" :: "a"(0x0e00 | '\r'), "b"(0x0007));
}

#ifndef _LOGO_H_
/* 
 * Converts 4-bit number into hex:
 * 	[0-15] -> [0-9|A-F]
 */
void to_hex_digit(u8 digit, char* buf)
{
	digit += '0';
	if (digit > '9') 
		digit+= 7;
	*buf = digit;
}

/*
 * Converts word-length number into hex
 *  [0-2^16] -> [0-F][0-F][0-F][0-F]
 */
void to_hex_str(u16 number)
{
	u8 i;
	char *b = BUFFER;
	for (i = 0; i < 4; i++) {
		to_hex_digit(number % 16, (b+3-i));
		number /= 16;
	}
	printf(b);
}
#endif

/*
 * Change video mode and resolution
 * (Clean screen)
 *  BIOS int 10 (ah 2)
 * */
void set_video_mode(u8 mode)
{
	__asm__ __volatile__ ("int $0x10\n" : : "a"(0x0000 | mode));
}
