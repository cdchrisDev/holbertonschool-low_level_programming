#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * dlistint_len - a func that returns the number of elements
 * @h: a node
 * Return: num of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	int n = 0;

	while (h != NULL)
	{
		n++;
		h = h->next;
	}
	return (n);
}
