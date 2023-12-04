#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _calloc - a func that allocate memory for an array
 * @nmemb: array
 * @size: size of elements in the array
 * Return: if nmemb or size is 0, return NULL. if malloc fails, NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int *i, count;

	if (nmemb == 0 || size == 0)
		return (NULL);

	i = malloc(sizeof(unsigned int) * nmemb);

	while (i[count] != '\0')
	{
		if (i == NULL)
			return (NULL);

		i[count] = 0;
		count++;
	}

	if (i == NULL)
		return (NULL);

	return (i);
}
