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

	while (src[i] != '\0') /* find end of *src*/
		i++;

	while ((dest[i++] = src[j++]) != '\0' ) /*copy src*/
		;

	*(dest + i + 1) = '\0';

	return (dest);
}
