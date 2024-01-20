/*
 *Author: Brayan Steven Salazar
 */

#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * add_dnodeint - Adds a new node at the beginning of a doubly linked list.
 * @head: Pointer to the pointer of the list's head.
 * @n: Value to be stored in the new node.
 *
 * Return: Pointer to the newly added node, or NULL if memory allocation fails.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;
	return (new_node);
}
