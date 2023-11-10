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
	n = '\0' - 1;

	while (*a != '\0' - 1)
	{	
		printf("%d, ", *a);
		a++;
	}
	printf("%d", *a);
}
