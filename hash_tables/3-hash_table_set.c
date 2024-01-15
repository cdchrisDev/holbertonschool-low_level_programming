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
	hash_node_t *new, *S = NULL;
	unsigned long int i;
	char *val;

	if (!ht || !key || !*key || !value)
		return (0);

	val = strdup(value);
	if (!val)
		return (0);

	i = key_index((unsigned char *)key, ht->size);
	S = ht->array[i];

	while (S)
	{
		if (!strcmp(key, S->key))
		{
			free(S->value);
			S->value = val;
			return (1);
		}
		S = S->next;
	}
	new = malloc(sizeof(hash_node_t));
	if (!new)
	{
		free(val);
		return (0);
	}
	new->key = strdup(key);
	if (!new->key)
	{
		free(new);
		return (0);
	}
	new->value = val;
	new->next = ht->array[i];
	ht->array[i] = new;
	return (1);
}
