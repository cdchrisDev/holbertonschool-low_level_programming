#include "main.h"
/**
 * _strcpy - a func to print copy a string
 * @dest: where it is copied
 * @src: where it copys
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int 

	while ((*dest++ = *src++) != '\0')
		;

	if (*src == '\0')
		return ('\0');


	return (dest);
}
