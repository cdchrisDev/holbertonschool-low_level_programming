#include <stdio.h>
#include "holberton.h"
/**
 *print_array - entry point
 *@a: Array
 *@n: numbers to be printed
 *Description: this function print an array in order
 *Return: Void returned
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);

		if (i < n - 1)
		{
			printf(", ");
		}
		else
		{
			continue;
		}
	}
	printf("\n");
}
