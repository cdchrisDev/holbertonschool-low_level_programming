#include "hash_tables.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_delete - deletes ht
 * @ht: hash_table
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *S, *tmp;
	unsigned long int i;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		S = ht->array[i];
		while (S)
		{
			tmp = S;
			S = S->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
	}
	free(ht->array);
	free(ht);
}
