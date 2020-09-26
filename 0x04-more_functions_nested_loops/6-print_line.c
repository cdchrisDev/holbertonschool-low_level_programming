#include "holberton.h"
/**
 *print_line - entry point
 *@n: number of times
 *Description: shaping lines
 *Return: no returned
 */
void print_line(int n)
{
	int i;

	for (i = n; i > 0; i--)
	{
		_putchar(95);
	}
	_putchar('\n');
}
