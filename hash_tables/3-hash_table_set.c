#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * hash_table_set - a func that adds an element to the hash table
 * @ht: hash table
 * @key: a key
 * @value: a value
 * Return: 1 for success, 0 if it fails
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	size_t i = 0;
	hash_node_t *new, *s;

	i = key_index((unsigned char *)key, ht->size);

	if (key == NULL || value == NULL)
		return (0);

	if (ht->array[i] != NULL)
		for (s = ht->array[i]; s; s = s->next)
			if (strcmp(key, s->key) == 0)
			{
				free(s->value);
				s->value = strdup(value);
				return (1);
			}

	new = calloc(sizeof(*new), 1);
	if (new == NULL)
		return (0);

	new->key = strdup(key);
	new->value = strdup(value);
	if (new->key == NULL || new->value == NULL)
	{
		free(new->key);
		free(new->value);
		free(new);
		return (0);
	}
	new->next = ht->array[i];
	ht->array[i] = new;
	return (1);
}
