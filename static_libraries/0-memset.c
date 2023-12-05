#include "main.h"
/**
 * _memset - fills memory with constant byte
 * @s: buffer
 * @b: constant bytes
 * @n: num of bytes
 * Return: pointer to memory area s;
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i != n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
