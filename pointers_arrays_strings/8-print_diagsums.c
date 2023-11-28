#include <stdlib.h>
#include <stdio.h>
#include "main.h"
/**
 * print_diagsums - a func that prints the sum of two diagonals of a
 * squeare matrix of integers
 * @a: a num
 * @size: the size
 * Return: 0
 */
void print_diagsums(int *a, int size)
{
	int i, sum = 0, sum1 = 0;

	for (i = 0; i < size; i++)
	{
		sum +=  a[i * (size + 1)];
	}

	for (i = 0; i < size; i++)
	{
		sum1 += a[(size - 1) * (i + 1)];
	}

	printf("%d, %d\n", sum, sum1);
}
