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

	i = 0;
	j = 0;

	while (dest[i] != '\0')
		i++;


	while (src[j] != '\0')
	{
		dest[i] = src[j];

		i++, j++;
	}

	dest = '\0';

	return (dest);

}
