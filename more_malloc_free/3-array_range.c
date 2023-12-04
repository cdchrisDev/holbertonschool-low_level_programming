#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * array_range - a func that create an array of int
 * @min: min range
 * @max: max range
 * Return: return values from min to max, if min > max, NULL. fails, NULL.
 */
int *array_range(int min, int max)
{
	int *i, count = min, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	i = malloc(sizeof(int) * size);

	if (i == NULL)
		return (NULL);

	while (count < size)
	{
		i[count] = min++;
		count++;
	}
	return (i);
}
