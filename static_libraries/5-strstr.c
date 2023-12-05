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

	while (haystack[i])
	{
		int j = 0;

		while (needle[j])
		{
			if (haystack[i + j] != needle[j])
				break;

			j++;
		}

		if (needle[j] == '\0')
			return (haystack + i);

		i++;
	}
	return (NULL);
}

