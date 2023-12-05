#include "main.h"
/**
 * _strlen - length of a string
 * a program to return the length of a string
 * @s: a character of a string
 * Return: the length of a string
 */
int _strlen(char *s)
{
	int c;

	for (c = 0; *s != '\0' ; s++)
		c++;

	return (c);
}
