#include "dog.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * print_dog - a func to print struct dog
 * @d: name of dog
 *
 * Return: formated text
 *
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		{};

	if (d->name == NULL)
		printf("Name: (nil)");

	printf("Name: %s\nAge: %.7f\nOwner: %s\n", d->name, d->age, d->owner);
}
