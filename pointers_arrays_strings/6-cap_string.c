#include "main.h"
/**
 * cap_string - a func to capitalizes all words of a string
 * @c: a char
 * Return: a string cap
 */
char *cap_string(char *c)
{
	int i = 0;

	while (c[i++] != '\0')
	{
		if (c[i] == ' ' || c[i] == '\n' || c[i] == '\t' || c[i] == '.')
		{
			i++;

			if (c[i] >= 'A' && c[i] <= 'Z')
				continue;
			else if (c[i] == '0')
				continue;
			else
				c[i] -= 32;
		}
	}
	return (c);
}
