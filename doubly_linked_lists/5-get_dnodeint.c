#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * get_dnodeint_at_index - a func return the nth node of `dlistint_t`
 * @head: pointer to 1rt
 * @index: node index
 * Return: the index
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *o;
	unsigned int i = 0;

	o = head;

	while (o != NULL)
	{
		if (i == index)
			return (o);

		i++;
		o = o->next;
	}
	return (NULL);
}
