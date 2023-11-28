#include <stdlib.h>
#include "main.h"
/**
 * _strpbrk - a func to look for bytes *accept on string *s
 * @s: a string
 * @accept: bytes to look for
 * Return: the occurrencenses
 */
char *_strpbrk(char *s, char *accept)
{

	int i = 0;
	while (s[i++] != '\0')
	{
		int j = 0;

		while(accept[j++] != '\0')
		{
			if (s[i] == accept[j])
			{
				return (&s[i]);
			}
		}
	}
	return (NULL);
}
