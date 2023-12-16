#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * sum_dlistint - a func that returns the sum of all (n)data
 * @head: first node
 * Return: the sum or 0 if its empty
 */
int sum_dlistint(dlistint_t *head)
{
	int res = 0;

	while (head)
	{
		res += head->n;

		head = head->next;
	}
	return (res);
}
