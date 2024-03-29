#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * str_concat - concatenates two strings.
 * @s1: char pointer
 * @s2: char pointe
 *  Return: strTemp
 */
char *str_concat(char *s1, char *s2)
{
	char *temp;
	int i;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	i = strlen(s1);
	temp = malloc(strlen(s1) + strlen(s2) + 1);

	if (temp == NULL)
		return (NULL);

	strcpy(temp, s1);
	strcpy(temp + i, s2);

	return (temp);
}
