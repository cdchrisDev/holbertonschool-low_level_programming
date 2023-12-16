#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * add_dnodeint - write a func that adds a new node at start of `dlistint_t`
 * @head: pointer to pointer to first node
 * @n: nodes
 * Return: addrs of the new element or NULL if failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new;

	*head = new;
	return (new);
}
