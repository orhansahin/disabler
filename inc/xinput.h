#ifndef __XINPUT_H__
#define __XINPUT_H__


#include <stdlib.h>
#include <stdio.h>

void device_get();
char device_find_id(FILE*);
int  device_disable(char id);
int  charTo_int(char);


#endif // __XINPUT_H__