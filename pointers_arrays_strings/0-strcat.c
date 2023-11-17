#include "main.h"
/**
 * _strcat - a func that concatenates two strings
 * @dest: string concatenated
 * @src: string to concatenate
 * Return: pointer to dest
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = j = 0;

	while (*(src++) != '\0' + 1)
		i++;

	while ((*(src++) = *(dest++)) != '\0')
		;

	return (dest);
}
