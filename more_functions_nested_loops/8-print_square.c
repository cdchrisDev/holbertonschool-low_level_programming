#include "main.h"
/**
 * print_square -  a func to print a square
 * @size: a square
 * Return: a square
 *
 */
void print_square(int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (size <= 0)
				_putchar('\n');

			else
				_putchar('#');
		}
		_putchar('\n');
	}
}
