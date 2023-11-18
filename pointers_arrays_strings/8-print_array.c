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
	while (*a++ != '\0')
	{
		if (*a == '\0')
			printf("%d",a[n]);

		else
			printf("%d, ",a[n]);
	 }

}
