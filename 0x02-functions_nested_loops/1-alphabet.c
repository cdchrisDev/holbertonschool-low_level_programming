#include "holberton.h"

/**
 *main - entry point
 *@void: takes no parameters
 *Return: print 0 but the alphabet
 */

int main(void)
{
	int _putchar(char c);
	int Alph;

	for (Alph = 'a'; Alph <= 'z'; Alph++)
	{
		_putchar(Alph);
	}
	_putchar('\n');

	return (0);
}

