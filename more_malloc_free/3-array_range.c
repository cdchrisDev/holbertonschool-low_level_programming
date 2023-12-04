#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * array_range - a func that create an array of int
 * @min: min range
 * @max: max range
 * Return: return values from min to max, if min > max, NULL. malloc fails, NULL.
 */
int *array_range(int min, int max)
{
	int *i, count = min;

	if (min > max)
		return (NULL);

	i = malloc(sizeof(int) * (max + 1));

	if (i == NULL)
		return (NULL);

	while (count < (max + 1))
	{
		i[count] = min++;
		count++;
	}
	return (i);
}
