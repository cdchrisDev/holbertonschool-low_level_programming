#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * list_len - a func that returns the number of elements in a list
 * @h: a struct
 * Return: num of elem in a list
 */
size_t list_len(const list_t *h)
{
	size_t n;

	n = 0;
	while (h != NULL)
	{
		n++;

		h = h->next;
	}
	return (n);
}
