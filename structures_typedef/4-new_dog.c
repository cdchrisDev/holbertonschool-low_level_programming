#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * new_dog - func to create and init a new struct for dog
 * @name: name
 * @age: age
 * @owner: owner name
 * Return: pointer to string
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	int k, i = 0, j = 0;
	/*new struct of type dog_t*/
	dog_t *new__dog;
	new__dog = (dog_t *)malloc(sizeof(dog_t));

	if (new__dog == NULL)
		return (NULL);

	while (name[i] != '\0')
		i++;

	while (owner[j] != '\0')
		j++;

	new__dog->name = malloc(i + 1);
	new__dog->owner = malloc(j + 1);

	if (new__dog->name == NULL || new__dog->owner == NULL)
	{
		free(new__dog->name);
		free(new__dog->owner);

		free(new__dog);
		return (NULL);
	}	

	for (k = 0; k <= i; k++)
		new__dog->name[k] = name[k];
	for (k = 0; k <= j; k++)
		new__dog->owner[k] = owner[k];

	new__dog->name[i] = '\0';
	new__dog->owner[j] = '\0';
	new__dog->age = age;

	return (new__dog);
}
