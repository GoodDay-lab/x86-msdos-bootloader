
#ifndef _DRIVE_H_
#define _DRIVE_H_  // I like that movie..

extern void init_drive(char *);  // ptr will point on extension segment
extern void read_sector(int, int, int, char *, int);  // reads sector

#endif 
