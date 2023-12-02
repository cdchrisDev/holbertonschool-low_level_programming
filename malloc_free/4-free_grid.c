#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * free_grid - write a func that frees a 2 dimenstional grid
 * @grid: 2D array
 * @height: array to free
 * Return: a freed array
 */
void free_grid(int **grid, int height)
{
	int j = 0;

	for (; j < height; j++)
		free(grid[j]);

	free(grid);
}
