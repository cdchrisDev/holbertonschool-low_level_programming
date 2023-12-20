#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * hash_table_t - a func that creates a hash table. 
 * @size: is the size of the array
 * Return: pointer to created hash table, NULL if goes wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;

	ht = malloc(sizeof(*ht));

	ht->size = size;

	if (ht == NULL)
		return (NULL);

	ht->array = calloc(sizeof(hash_table_t*), ht->size);
	/* Calloc init in 0 */
	return ht; 
}
