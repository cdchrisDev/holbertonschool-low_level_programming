#include "main.h"
/**
 * *_memcpy - a func to copy memory area
 * @dest: where to copy to
 * @src: where to copy from
 * @n: num of n
 * Return: the copy of src on dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i != n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
