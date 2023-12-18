#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * delete_dnodeint_at_index - a func that deletes the node at index
 * @head: first node
 * @index: index
 * Return: 1 if succeeded and -1 if not
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *new, *p = *head;
	unsigned int i;

	if (index != 0)
		for (i = 0; i < index - 1 && p != NULL; i++)
			p = p->next;

	if (p == NULL || (p->next == NULL && index != 0))
		return (-1);

	new = p->next;

	if (index != 0)
	{
		p->next = new->next;
		free(new);
	}
	else
	{
		free(p);
		*head = new;
	}
	return (1);
}
