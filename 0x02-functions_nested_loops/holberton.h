#include <unistd.h>
#ifndef _PUTCHAR
#define _PUTCHAR

int _putchar(char c)
{
	return (write(1, &c, 1));
}

#endif
/* start of 1-alphabet.c */
int print_alphabet(void)
{
	int Alph;

	for (Alph = 'a'; Alph <= 'z'; Alph++)
	{
		_putchar(Alph);
	}
	_putchar('\n');

	return (0);
}
/* end of 1-alphabet.c */
