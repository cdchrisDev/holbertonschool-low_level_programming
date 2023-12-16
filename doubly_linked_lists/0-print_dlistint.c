#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_dlistint - a func that prints all elements
 * @h: a node
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t i;

	i = 0;

	while (h != NULL)
	{
		i++;
		printf("%d\n", h->n);
		h = h->next;
	}
	return (i);
}
