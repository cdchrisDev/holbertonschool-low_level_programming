#ifndef DOG_H
#define DOG_H
/**
 * struct dog - print a text
 * @name: dog's name
 * @age: Dog's age
 * @owner: Dog's owner
 * Return: text
 *
 * Descriptoion: this structure hold puppy info
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog;
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif
