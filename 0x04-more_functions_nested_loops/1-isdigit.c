#include "holberton.h"
/**
 *_isdigit -entry point
 *@c: an integer from 0 to 9
 *Description: look for a digit form 0 to 9
 *Return: 1 if c is a digit, otherwise 0
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else if (c >= 'a' && c <= 'z')
	{
		return (0);
	}
	return (0);
}

