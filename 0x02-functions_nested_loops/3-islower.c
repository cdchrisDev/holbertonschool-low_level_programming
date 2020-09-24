#include "holberton.h"
/**
 *_islower - entry point
 *@c: lowercase or uppercase char
 *Description: look for lowercase chars
 *Return: 1 if c is lowercase, otherwise 0
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (0);
	}
	return (0);
}

