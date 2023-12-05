#include "main.h"
/**
 * print_line - write a straight line
 * @n: a int
 * Return: a drew line
 */
void print_line(int n)
{
	while (n > 0)
	{
		_putchar('_');
		n--;
	}

	_putchar('\n');
}
