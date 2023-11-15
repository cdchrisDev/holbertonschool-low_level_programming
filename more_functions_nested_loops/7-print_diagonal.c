#include "main.h"
/**
 * print_diagonal - print a diagonal line on the terminal
 * @n: a int
 * Return: void
 */
void print_diagonal(int n)
{
	int j;

	j = n;
	while (n > 0)
	{
		_putchar('\\');
		n--;
		_putchar('\n');
		j--;
		while (j > 0)
		{
			_putchar(' ');
			j--;
		}
	}	
}
