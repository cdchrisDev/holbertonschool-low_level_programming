#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * malloc_checked - func that allocates memory using malloc
 * @b: memory to alloc
 * Return: a pointer to the alloc mem
 */
void *malloc_checked(unsigned int b)
{
	unsigned int *B = malloc(b);

	if (B == NULL)
		return (NULL);
	else
		return (B);
}
