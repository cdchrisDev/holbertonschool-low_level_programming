#include "search_algos.h"
/**
 * linear_search - search in array
 * @array: an array of ints
 * @size: the size of the array
 * @value: the value to search
 * Return: the index
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (!array)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array [%ld] = [%d]\n", i, array[i]);

		if (array[i] == value)
			break;

		if (i == size)
			return (-1);
	}
	return (i);
}
