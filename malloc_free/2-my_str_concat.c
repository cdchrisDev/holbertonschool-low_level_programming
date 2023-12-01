#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenates two strings
 * @s1: string
 * @s2: string
 * Return: new allocation with both contents put it together
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int i = 0, j = 0, k;
	char *s;

	while (s1[i] != '\0')
	{
		if (s1 == NULL)
			return (NULL);
		i++;
	}
	while (s2[j] != '\0')
	{
		if (s2 == NULL)
			return (NULL);
		j++;
	}
	k = i + j + 1;
	s = malloc((k * sizeof(char)));

	while ((*s++ = *s1++))
	{
		if (s1 == NULL)
		s = ("");
	}
	while ((*s++ = *s2++))
	{
		if (s2 == NULL)
			s = ("");
	}
	s[k] = '\0';
	return (s);
}
