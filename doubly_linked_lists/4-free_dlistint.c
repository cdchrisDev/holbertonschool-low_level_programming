#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * free_dlistint - a function that frees a `dlistint_t`
 * @head: first node
 * Return: node freed
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *new;

	new = NULL;

	while (head != NULL)
	{
		new = head;
		head = head->next;
		free(new);
	}
}
