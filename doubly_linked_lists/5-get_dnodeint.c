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
	unsigned int i;

	while (head != NULL)
	{
		if (i == index)
			return (head);

		i++;
		head = head->next;
	}
	return (NULL);
}
