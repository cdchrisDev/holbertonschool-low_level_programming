#include "main.h"
/**
 * string_toupper - convert lower to uppercase
 * @char: a char
 * Return: uppercase letter
 */
char *string_toupper(char *c)
{
	int i = 0;

	while (c[i++] != '\0')
	{
		if (c[i] >= 'a' && c[i] <= 'z')
			c[i] -= 32;
	}
	return (c);
}
