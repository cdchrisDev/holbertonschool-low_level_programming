#include "main.h"
/**
 * rev_string - reverse a string
 * a simple program return a reversed a string
 * @s: character
 * Return: a reversed string
 */
void rev_string(char *s)
{
	char rev, cap;
	int i;

	rev = rev + cap;

	for (i = 0; *s != '\0'; s++)
		i++;

	s--;

	while (i != 0)
	{
		cap = *s;
		i--;
		s--;
	}
	*s = rev;
}
