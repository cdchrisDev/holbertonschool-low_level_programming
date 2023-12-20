#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * hash_table_create - a func that creates a hash table.
 * @size: is the size of the array
 * Return: pointer to created hash table, NULL if goes wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht = malloc(sizeof(hash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(hash_table_t) * ht->size);

	/* Calloc init in 0 */
	return (ht);
}
