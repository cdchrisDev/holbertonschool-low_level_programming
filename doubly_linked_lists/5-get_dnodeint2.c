/*
 *Author: Brayan Steven Salazar
 */

#include "lists.h"

/**
 * get_dnodeint_at_index - Retrieves the node at a specified index in a doubly
 *                         linked list.
 * @head: Pointer to the head of the doubly linked list.
 * @index: Index of the node to retrieve (starting from 0).
 *
 * Description:
 * This function traverses the doubly linked list starting from the head and
 * returns a pointer to the node at the specified index. If the index is out
 * of range or the list is empty, it returns NULL.
 *
 * Return: Pointer to the node at the specified index, or NULL if not found.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *ptr;
	unsigned int count;

	ptr = head;
	count = 0;

	while (ptr != NULL)
	{
		if (count == index)
			return (ptr);

		count++;
		ptr = ptr->next;
	}
	return (NULL);
}
