#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * add_dnodeint_end - write a func that adds at the end of `dlistint_t`
 * @head: pointer to pointer to first node
 * @n: a integer
 * Return: the addrs of new element or NULL if fails
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *old;

	new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		new->prev = NULL;
		return (new);
	}
	old = *head;

	while (old->next != NULL)
		old = old->next;

	old->next = new;
	new->prev = old;
	return (new);
}
