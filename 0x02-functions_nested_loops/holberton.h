#ifndef _PUTCHAR
#define _PUTCHAR
#include <unistd.h>

int _putchar(char c)
{
	return (write(1, &c, 1));
}

#endif
