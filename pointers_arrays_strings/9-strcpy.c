#include "main.h"
/**
 * _strcpy - a func to print copy a string
 * @dest: where it is copied
 * @src: where it copys
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;

	while ((dest[i] = src[i]) != '\0')
		i++;

	return (dest + '\0');
}
