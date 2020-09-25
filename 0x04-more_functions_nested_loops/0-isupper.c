#include "holberton.h"
/**
 *_isupper - entry point
 *@c: lowecase or uppercase char
 *Description: look for uppercase chars
 *Return: 1 if c is uppercase, otherwise 0
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else if (c >= 'a' && c <= 'z')
	{
		return (0);
	}
	return (0);
}

