#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * free_dog - a func to frees dogs
 * @d: a struct dog
 *
 * Return: freed memory
 */
void free_dog(dog_t *d)
{
	free(d->name);
	free(d->owner);
	free(d);
}
