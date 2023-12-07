#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * array_iterator - a func that executes a function given
 * as a parameter on each element of an array.
 * @array: an array
 * @size: the size
 * @action: pointer to func its needed to use
 * Return: the formated text
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i = 0;

	if (array == NULL || (*action) == NULL)
		return;

	while (i < size)
	{
		(*action)(array[i]);
		i++;
		if ((*action) == NULL)
			return;
	}
}
