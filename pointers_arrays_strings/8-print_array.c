#include <stdio.h>
#include "main.h"
/**
 * print_array - a simple program to print and array of ints
 * @a: int
 * @n: int
 * Return: void
 */
void print_array(int *a, int n)
{
	int i = 0;

	while (i < n - 1)
	{
		printf("%d, ", a[i]);
		i++;

		if (i == (n - 1))
			printf("%d", a[n - 1]);
	}
	printf("\n");

}
