#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * _strdup - return a pointer to a newly allocated space in memory
 * which contains a copy of the string
 * @str: a string
 * Return: a pointer to new location
 */
char *_strdup(char *str)
{
	char *j;

	if (str == NULL)
		return (NULL);
	else
		j = malloc(strlen(str) + 1);
			if (j == NULL)
				return (NULL);
			else
				strcpy(j, str);

	return (j);
}
