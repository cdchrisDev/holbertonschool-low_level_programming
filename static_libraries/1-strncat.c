#include "main.h"
/**
 * char *_strncat - a func at least n bytes
 * @dest: the string where will concatenate
 * @src: where it concatenate
 * @n: num of bytes to concatenate
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0, k;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
		j++;

	if (n < j)
		j = n - 1;

	k = 0;

	while (k <= j)
	{
		dest[i] = src[k];
		k++, i++;
	}

	dest[i + 1] = '\0';

	return (dest);
}
