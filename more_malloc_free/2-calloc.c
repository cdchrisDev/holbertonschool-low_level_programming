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
	unsigned int count = 0;
	char *i;
	
	if (nmemb == 0 || size == 0)
		return (NULL);

	i = malloc(size * nmemb);

	if (i == NULL)
		return (NULL);

	while (count < (size * nmemb))
	{
		i[count] = 0;
		count++;
	}
	return (i);
}
