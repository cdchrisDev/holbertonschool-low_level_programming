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
	while (n < 99 || n > 97)
	{
		if (n == 98)
		{
			printf("%d", n);
			break;
		}
		else if (n > 97 || n < 99)
		{
			printf("%d, ", n);
		}

		if (n > 97)
			n--;
		else if (n < 99)
			n++;
	}
	putchar('\n');
}
