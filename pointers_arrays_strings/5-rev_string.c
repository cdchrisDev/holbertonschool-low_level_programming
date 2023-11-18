#include "main.h"
/**
 * rev_string - reverse a string
 * a simple program return a reversed a string
 * @s: character
 * Return: a reversed string
 */
void rev_string(char *s)
{
	char cap = s[0];
	int i;
	int fc = 0;

	while (s[fc] != '\0')
		fc++;

	
	for (i = 0; i < fc; i++)
	{
		fc--;
		cap = s[i];
		s[i] = s[fc];
		s[fc] = cap;
	}
}
