#include "holberton.h"
/**
 *print_line - entry point
 *@void: no takes arguments
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
