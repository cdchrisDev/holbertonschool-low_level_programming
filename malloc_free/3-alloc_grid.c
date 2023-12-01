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
	int j, i;
	int **gridint;

	gridint[j][] = malloc(sizeof(int *) * height);
	gridint[][i] = malloc(sizeof(int *) * width);

	if (gridint == NULL)
		return (NULL);

	if (height <= 0 || width <= 0)
		return (NULL);

	for (j = 0; j <= height; j++)
	{
		if (gridint[j] == NULL)
		{
			for (; j >= 0; j--)
				free(gridint[j]);

			free(gridint);
			return (NULL);
		}
	}
	for (j = 0; j < height; j++)
		for (i = 0; i < width; i++)
			gridint[j][i] = 0;

	return (gridint);
}
