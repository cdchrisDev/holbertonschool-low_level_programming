#include <stdio.h>
#include "main.h"
/**
 * print_to_98 - 2th func called
 * a func to print natural numbers
 * @n: a int
 * Return: void
 */

void print_to_98(int n)
{
	while (n != 99)
	{
		if (n == 98)
		{
			printf("%d", n);
			n++;
		}
		else if (n > 98)
		{
			printf("%d, ", n);
			n--;
		}
		else
		{
			printf("%d, ", n);
			n++;
		}

	}
	putchar('\n');
}
