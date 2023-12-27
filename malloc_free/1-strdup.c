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

	char *j = malloc(strlen(str) + 1);

	if (j == NULL || str == NULL)
		return (NULL);

	strcpy(j, str);

	return (j);
}
