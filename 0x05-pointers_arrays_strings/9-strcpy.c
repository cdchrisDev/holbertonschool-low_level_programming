#include "holberton.h"
/**
 *_strcpy - entry point
 *@dest: string to be pasted
 *@src: string to be copied
 *Description: this funtion copy and paste a string
 *Return: return a string copied
 */
char *_strcpy(char *dest, char *src)
{
	int counter;

	counter = 0;

	for (counter = 0; src[counter] != '\0'; counter++)
	{
		dest[counter] = src[counter];
	}
	dest[counter] = '\0';

	return (dest);
}

