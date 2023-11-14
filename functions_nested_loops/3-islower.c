#include "main.h"
/**
 * _islower - 2th called func
 * A function to check for lowercase char
 * @c: a char
 * Return: 0
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);

	else
		return (0);
}
