#include "main.h"
/**
 * _strlen - a func to print the length of a string
 * @s: a string
 * Return: the length of a string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	/* Increase by 1 each time func is called without assignment */
	return (1 + _strlen_recursion(s + 1));
}
