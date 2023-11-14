#include "main.h"
/**
 * print_alphabet_x10 - 2th func
 * print all the letters of the alphabet 10 times
 * Return: 0
 */

void print_alphabet_x10(void)
{
	int i, c;

	i = 0;

	while (i < 10)
	{
		for (c = 'a'; c <= 'z'; c++)
			_putchar(c);

		i++;
		_putchar('\n');
	}
}
