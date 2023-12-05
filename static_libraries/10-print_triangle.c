#include "main.h"
/**
 * print_triangle - a func to print triangles by giving a num
 * @size: where is the num of triangle size
 * Return: tri
 */
void print_triangle(int size)
{
	int j, i, jj;

	if (size <= 0)
		_putchar('\n');

	for (j = 1; j <= size; j++)
	{
		for (jj = size - j; jj > 0; jj--)
			_putchar(' ');
		for (i = 1; i <= j; i++)
			_putchar('#');

		_putchar('\n');
	}
}
