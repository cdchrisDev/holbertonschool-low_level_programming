#include "hash_tables.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * hash_table_get - get the value link to the key
 * @ht: hash table
 * @key: key to look for
 * Return: the value associated
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *S = NULL;
	unsigned long int i;

	if (!ht || !key || !*key)
		return (NULL);

	i = key_index((unsigned char *)key, ht->size);
	S = ht->array[i];

	while (S)
	{
		if (!strcmp(key, S->key))
			return (S->value);

		S = S->next;
	}
	return (NULL);
}
