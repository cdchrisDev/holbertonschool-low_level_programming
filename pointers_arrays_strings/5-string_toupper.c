#include "main.h"
/**
 * string_toupper - convert lower to uppercase
 * @char: a char
 * Return: uppercase letter
 */
char *string_toupper(char *c)
{
	while (*c++ != '\0')
	{
		if (*c == ' ')
			continue;
		else if (*c >= 97 && *c <= 122)
			*c -= 32;
	}
	return (c);
}
