#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * **alloc_grid - a function that draws 2 dimensional array
 * @width: self
 * @height: self
 * Return: 0 if its 0 or non-positive or draws a grid
 */
int **alloc_grid(int width, int height)
{
	int j = 0, i = 0;
	int **gridint;

	if (height <= 0 || width <= 0)
		return (NULL);

	gridint = malloc(sizeof(int *) * height); /* Array to pointers to int */

	if (gridint == 0)
		return (NULL);

	for (; j < height; j++)
	{
		gridint[j] = malloc(sizeof(int) * width);

		if (gridint[j] == NULL)
		{
			for (; i < j; i++)
				free(gridint[i]);

			free(gridint);
			return (NULL);
		}

	}
	for (j = 0; j < height; j++)
		for (i = 0; i < width; i++)
			gridint[j][i] = 0;

	return (gridint);
}
