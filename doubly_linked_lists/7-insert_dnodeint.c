#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * insert_dnodeint_at_index - a func that insert a new node in a position
 * @h: node
 * @idx: index
 * @n: integer
 * Return: addrs of new node or NULL if fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *p = *h; /* new node, pointer equal to h*/

	if (idx == 0)	/* if index 0, use function to add at beggining*/
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{	/* Looping until reach the expected list position*/
		p = p->next;
		if (p == NULL)
			return (NULL);
	}

	if (p->next == NULL)
		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = p; /* The previous of new is a pointer type dlistint_t*/
	new->next = p->next; /* the next of new and pointer are the same*/
	p->next->prev = new; /*The next and the previous to the next is equal to new*/
	p->next = new; /*however, the next of pointer is also the new node*/

	return (new);

}
