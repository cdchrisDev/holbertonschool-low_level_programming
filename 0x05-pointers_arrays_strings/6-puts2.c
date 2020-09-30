#include "holberton.h"
/**
 *puts2 - entry point
 *@str: string of numbers
 *Description: this function prints every other character
 *Return: void returned
 */
void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
	{
		if (i % 2 == 0)
		{
			_putchar(str[i]);
		}
	}
	_putchar('\n');
}
