#include "main.h"
/**
 * _isalpha - 2th func called
 * a program to check for chars
 * @c: a char
 * Return: 1 or 0
 */
int _isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);

	else if (c >= 'A' && c <= 'Z')
		return (1);

	else
		return (0);
}
