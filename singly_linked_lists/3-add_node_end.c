#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * add_node_end - a func to add new node end of lists_t
 * @head: pointer to beggining of list_t
 * @str: a string
 * Return: added nodes
 */
list_t *add_node_end(list_t **head, const char *str)
{	/* set the back and forward */
	list_t *new;
	list_t *old;
	size_t n;
	/* set new memspace for new list_t*/
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	/* set new memspace for new->str*/
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);	/* fail check */
		return (NULL);
	}
	/* next node init by setting NULL*/
	new->next = NULL;
	n = strlen(str);
	new->len = n;
	/* Connect first node, NULL as sign of INIT*/
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	/* connect old to head, so, new jump to old*/
	old = *head;
	/* itirating node sequence from old which is first than new*/
	while (old->next != NULL)
		old = old->next;
	/* after loop, old connect to last node which is new*/
	old->next = new;
	return (new);
}
