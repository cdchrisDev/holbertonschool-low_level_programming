#include "function_pointers.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * int_index - a func that searches for a int
 * @array: an array of pointers to int
 * @size: the size of array
 * @cmp: pointer to a func used to compare values
 * Return: the found int
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL)
		return (-1);

	if (size <= 0)
		return (-1);

	while (i++ < size)
		if (cmp(array[i]))
			return (i);

	return (-1);
}

