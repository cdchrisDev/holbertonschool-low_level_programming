#include "main.h"
/**
 * _strcat - a func that concatenates two strings
 * @dest: string concatenated
 * @src: string to concatenate
 * Return: pointer to dest
 */

char *_strcat(char *dest, char *src)
{
	int j, i;

	j = i = 0;

	while (*dest++ != '\0')
		;


	while (*src++ != '\0')
	{
		i++, j++;

		dest[i] = src[j];
	}

	dest = '\0';

	return (dest);

}
