#include "main.h"
/**
 * _strspn - a func to get the length of a prefix substring
 * @s: a string
 * @accept: bytes to get
 * Return: num of bytes on s by accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0, j = 0;

	while (s[i++] != '\0')
		while (accept[j++] != '\0')
		{
			if (s[i] == accept[j])
				break;

			if (!(accept[j]))
				break;
		}
	return (i);
}
