#include "lists.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * print_list - write a func that prints all list_t elements
 * @h: elements
 * Return: list the elements
 */
size_t print_list(const list_t *h)
{
	size_t i;
	unsigned int n;
	char *s;

	i = 0;

	while (h != NULL)
	{
		i++;
		n = h->len;
		s = h->str;
	/* remember the member */
		if (h->str == NULL)
			printf("[%d] (nil)\n", n);
		else
			printf("[%d] %s\n", n, s);

		h = h->next;
	}
	return (i);
}
