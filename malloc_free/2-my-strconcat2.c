#include <stdlib.h>
#include "main.h"
#include <stdio.h>
/**
 * str_concat - concatenate two strings
 * @s1: char
 * @s2: char
 * Return: the concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	char *strcctnd;
	int cnt1 = 0, cnt2 = 0, i, j;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[cnt1++] != '\0');

	while (s2[cnt2++] != '\0');

	cnt2++;
	strcctnd = malloc(sizeof(char) * (cnt1 + cnt2));

	if (strcctnd == NULL)
		return (NULL);

	for (i = 0; i < cnt1; i++)
		strcctnd[i] = s1[i];

	for (j = 0; j < cnt2; j++)
		strcctnd[i + j] = s2[j];

	return (strcctnd);
}
