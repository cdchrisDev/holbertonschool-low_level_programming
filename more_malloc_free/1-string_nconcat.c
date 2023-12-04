#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * string_nconcat - concatenate two strings
 * @s1: first string
 * @s2: second string 
 * @n: num of byts to concatenate
 * Return: the string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0, j = 0, k;
	char *concat;

	while (s1[i++] != '\0');
	while (s2[j++] != '\0');

	k = i + n;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	concat = malloc(sizeof(char) * k);

	i = 0;
	j = 0;

	while (s1[i] != '\0')
	{
		concat[i] = s1[i];
		i++;
	}
	while (j < n)
	{
		concat[i + j] = s2[j];
		j++;
	}
	concat[i + j] = '\0';
	
	return (concat);
}
