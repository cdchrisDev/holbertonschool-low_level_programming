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
	dog_t *new__dog;
	int j = 0, i = 0, J = 0, I = 0;
	/* get the length of strings*/
	while (name[i] != '\0')
		i++;

	while (owner[j] != '\0')
		j++;
	/* new location for struct*/
	new__dog = malloc(sizeof(dog_t));
	/*new location for strings*/
	new__dog->name = malloc(i + 1);
	new__dog->owner = malloc(j + 1);

	if (new__dog == NULL)
                return (NULL);
        
	if (new__dog->name == NULL || new__dog->owner == NULL)
        {
                free(new__dog->name);
                free(new__dog->owner);
                free(new__dog);
        }
	
	/* count in reverse and asign strings */
	while (i > I)
	{
		new__dog->name[I] = name[I];
		I++;
	}
	new__dog->age = age;
	while (j > J)
	{
		new__dog->owner[J] = owner[J];
		J++;
	}
	free(new__dog->name);
	free(new__dog->owner);
	free(new__dog);
	return (new__dog);
}
