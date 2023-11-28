#include <stdlib.h>
#include "main.h"
/**
 * _strstr - a func that locates a substring
 * @haystack: a string to look for
 * @needle: what to look for
 * Return: located substring
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0;

	while (haystack[i] != '\0')
	{
		int j = 0;

		while (needle[j] != '\0')
		{
			if ((haystack[i] == needle[j]) &&
			(haystack[i + 1] == needle[j + 1] || haystack[i - 1] == needle[j - 1]))
				return (&haystack[i]);

			j++;
		}
		i++;
	}
	return (NULL);
}

