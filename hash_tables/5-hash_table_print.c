#include "hash_tables.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * hash_table_print - prints ht
 * @ht: hash table to print
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *S;
	int init = 1;
	unsigned long i;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		S = ht->array[i];
		while (S)
		{
			if (!init)
				printf(", ");
			printf("'%s': '%s'", S->key, S->value);
			init = 0;
			S = S->next;
		}
	}
	printf("}\n");
}
