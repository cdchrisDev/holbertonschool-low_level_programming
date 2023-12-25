#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * hash_table_set - a func that adds an element to the hash table
 * @ht: hash table
 * @key: a key
 * @value: a value
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int cnt, i = 0;
	hash_node_t *new;
	char *val;

	/* error checking */
	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	val = strdup(value);
	if (val == NULL)
		return (0);

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
		return (0);

	i = key_index((const unsigned char *)key, ht->size);
	for (cnt = i; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = val;
			return (1);
		}
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = val;
	new->next = ht->array[cnt] = ht->array[i];
	ht->array[i] = new;

	return (1); 
}
