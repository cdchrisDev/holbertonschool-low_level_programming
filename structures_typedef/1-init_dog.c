#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * init_dog - a func that initialize a var type struct dog
 * @d: name of struct
 * @name: dogs name
 * @age: dogs age
 * @owner: dogs owner
 * Return: a text
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		;

	else
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
