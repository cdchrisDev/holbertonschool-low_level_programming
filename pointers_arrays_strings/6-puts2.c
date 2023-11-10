#include "main.h"
/**
 * puts2 - func half char
 * a program to print every other character of a string.
 * @str: a character sequence
 * Return: half'ed string
 */

void puts2(char *str)
{
	int i;

	i = 0;

	while (*str != '\0')
	{
		if (i % 2 == 0)
		{
			_putchar(*str);
		}
		str++;
		i++;
	}
	_putchar('\n');
}
