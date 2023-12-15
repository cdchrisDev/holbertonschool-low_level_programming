#include "lists.h"
/**
 * free_list - func that frees a list_t
 * @head: node to first node
 * Return: freed
 */
void free_list(list_t *head)
{
	list_t *newnew;

	while (head != NULL)
	{
		newnew = head;
		head = head->next;
		free(newnew->str);
		free(newnew);
	}
}
