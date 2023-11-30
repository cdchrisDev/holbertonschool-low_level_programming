#include "main.h"
#include <stdlib.h>
/**
 * create_array - a func that create an array of chars, and init
 * with specific chars
 * @size: the size of array
 * @c: char to specificated
 * Return: NULL if size is 0. A pointer to the array or NULL if fails.
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i = 0;
	char *ci;

	if (size == 0)
		return (NULL);
	else if (size > 0)
	{
		ci  = malloc(size * sizeof(char));
		while (i <= size)
		{
			if (ci == NULL)
				return (NULL);
			else
			{
				ci[i] = c;
				i++;
			}
		}
	}
	return (ci);
	free(ci);
}
