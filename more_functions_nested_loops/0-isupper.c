#include "main.h"
/**
 * _isupper - 2th called to func
 * a program to check for uppercase letter
 * @c: a char int
 * Return: a char int
 */

int _isupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (0);
	}
	else if (c >= 65 && c <= 90)
	{
		return (1);
	}
	return (c);
}
