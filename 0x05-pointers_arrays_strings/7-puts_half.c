#include "holberton.h"
/**
 *puts_half - entry point
 *@str: string passed
 *Description: this function print half of string
 *Return: void returned
 */
void puts_half(char *str)
{
	int len;
	int i;

	for (len = 0; str[len] != 0; len++)
	{
		if (len % 2 == 0)
		{
			i = len / 2;
		}
		else
		{
			i = len - ((len - 1) / 2);
		}
	}
	for (; i < len; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
