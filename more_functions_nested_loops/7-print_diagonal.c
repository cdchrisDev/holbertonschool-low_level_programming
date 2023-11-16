#include "main.h"
/**
 * print_diagonal - print a diagonal line on the terminal
 * @n: a int
 * Return: void
 */
void print_diagonal(int n)
{
	int j, i;


	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				_putchar('\\');
				_putchar('\n');
				break;
			}
			else
			{
				_putchar(' ');
			}
		}
	}
}
