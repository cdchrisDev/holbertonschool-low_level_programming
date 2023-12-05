#include "main.h"
/**
 * _strchr - a func to locate a char in a str
 * @s: a string
 * @c: char
 * Return: pointer to the occurrence of the character
 */
char *_strchr(char *s, char c)
{
	while (s++)
	{
		if (*s == c)
			return (s);
		if (!*s)
			return (0);
	}
	return (0);
}
