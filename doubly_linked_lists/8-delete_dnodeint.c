#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * delete_dnodeint_at_index - a func to delete node
 * @head: struct
 * @index: the index
 * Return: updated list
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	int n = 0;
	dlistint_t *new = *head;
	unsigned int i = 0;

	*head = (*head)->next;

	if (*head == NULL || index == 0)
		return (-1);

	while (1)
	{
		if (i == index)
		{
			*head = new->next;
			break;
		}
		i++;
	}

	if (new->next != NULL)
		new->next->prev = new->prev;

	if (new->prev != NULL)
		new->prev->next = new->next;

	(*head)->n = n;

	free(new);
	return (1);
}
