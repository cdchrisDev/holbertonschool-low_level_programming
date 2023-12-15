#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * add_node - func to add new node at the head
 * @head: double pointer to head
 * @str: a string
 * Return: the addr of new element or null if fails
 */
list_t *add_node(list_t **head, const char *str)
{	/* since we need add, new space is alloc */
	list_t *new = malloc(sizeof(list_t));/*new node list_t*/

	if (new == NULL)
		return (NULL);

	new->str = strdup(str); /* new alloc for string */
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->len = strlen(str);
	new->next = *head; /* set next node to head */
	*head = new; /* head is a pointer to next node*/

	return (new);	/*return next node */
}
