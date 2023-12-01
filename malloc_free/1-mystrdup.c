#include "main.h"
#include <stdlib.h>
/**
 * _strdup - return a pointer to a newly allocated space in memory
 * which contains a copy of the string
 * @str: a string
 * Return: a pointer to new location
 */
char *_strdup(char *str)
{
	char *j;
	unsigned int i = 0;

	if (str == NULL)
		return (NULL);

	while (str[i])
		i++;

	j = malloc((1 + i) * sizeof(char));
	if (j == NULL)
		return (NULL);

	while ((*j++ = *str++) != '\0')
		;

	return (j);
}
