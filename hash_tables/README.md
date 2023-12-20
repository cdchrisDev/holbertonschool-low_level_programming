# This is the hash tables project

### Resources
* [What is a HashTable Data Structure - Introduction to Hash Tables , Part 0](https://www.youtube.com/watch?v=MfhjkfocRR0&ab_channel=PaulProgramming)

* [Hash function](https://en.wikipedia.org/wiki/Hash_function)

* [Hash table](https://en.wikipedia.org/wiki/Hash_table)

## What is a Hash Function?<br />
a **hash function** is any function that can be used to map data of arbitrary size to fixed-size values, though there are some hash functions that support variable length output. The values returned by a hash function are called *Hash Values*, *Hash Codes*, *digest* or simply *hashes* the values are usually used to index a fixed-storage addressing.

## What is a Hash table?<br />
Is a data structure that implements an associative array, also called a dictionary which is an abstract data type that maps keys to values. A Hash table uses a hash function to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found. During lookup, the key is hashed and the resulting hash indicates where the corresponding value is stored.
<br/>

## What makes a good hash function?<br />
* The complexity of the hash tables depends on the different mathematical outputs that a function can return, so. The harder the equation, the better the hash table

* when hashing strings it's important to consider all characters – except when it's known in advance that the first three characters of all strings will be the same; considering these then is a waste.

* it is also important to generate a good spread over the problem space, i.e. all possible objects. *This means that when hashing numbers between 100 and 1050 it's no good to let the most significant digit play a big part in the hash because for ~ 90% of the objects, this digit will be 0. It's far more important to let the last three digits determine the hash.*
<br />

## What is a hast table, how do they work and how to use them?<br />
A hash table is a *data structure* that is used to store keys/value pairs. It uses a hash function to compute an index into an array in which an element will be inserted or searched. By using a good hash function, hashing can work well.<br/>


## What is a collision and what are the main ways of dealing with collisions in the context of a hash table<br />
When one or more hash values compete with a single hash table slot, collisions occur. To resolve this, the next available empty slot is assigned to the current hash value. The most common methods are open addressing, chaining, probabilistic hashing, perfect hashing and coalesced hashing technique.<br />

## What are the advantages and drawbacks of using hash tables<br />
Hash tables offer efficient data storage and retrieval, but they come with some drawbacks. These include collision resolution, variable performance, space overhead, lack of ordered data, and dependency on a quality hash function. They are not ideal for range queries, and resizing can introduce overhead.<br />

## What are the advantages and drawbacks of using hash tables 
Hash tables offer efficient data storage and retrieval, but they come with some drawbacks. These include collision resolution, variable performance, space overhead, lack of ordered data, and dependency on a quality hash function. They are not ideal for range queries, and resizing can introduce overhead.<br />

## What are the most use cases?|<br />
Probably the most common use for hash tables is databases. To retrieve and increment through data in a database in a performant way, we need some way to identify it uniquely, and we need some way to index it<br />

# Task
## Data structures
**Please, use these data structures for this project:**
```
/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
     char *key;
     char *value;
     struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
     unsigned long int size;
     hash_node_t **array;
} hash_table_t;
```
## 0. Write a function that creates a hash table.

* Prototype: `hash_table_t *hash_table_create(unsigned long int size);`
	* where size is the size of the array
* Returns a pointer to the newly created hash table
* If something went wrong, your function should return `NULL`
```
julien@ubuntu:~/Hash tables$ cat 0-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    printf("%p\n", (void *)ht);
    return (EXIT_SUCCESS);
}
julien@ubuntu:~/Hash tables$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-hash_table_create.c -o a
julien@ubuntu:~/Hash tables$ ./a 
0x238a010
julien@ubuntu:~/Hash tables$ valgrind ./a
==7602== Memcheck, a memory error detector
==7602== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==7602== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==7602== Command: ./a
==7602== 
0x51fc040
==7602== 
==7602== HEAP SUMMARY:
==7602==     in use at exit: 8,208 bytes in 2 blocks
==7602==   total heap usage: 2 allocs, 0 frees, 8,208 bytes allocated
==7602== 
==7602== LEAK SUMMARY:
==7602==    definitely lost: 16 bytes in 1 blocks
==7602==    indirectly lost: 8,192 bytes in 1 blocks
==7602==      possibly lost: 0 bytes in 0 blocks
==7602==    still reachable: 0 bytes in 0 blocks
==7602==         suppressed: 0 bytes in 0 blocks
==7602== Rerun with --leak-check=full to see details of leaked memory
==7602== 
==7602== For counts of detected and suppressed errors, rerun with: -v
==7602== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
julien@ubuntu:~/Hash tables$
```
**SOLVED**
```
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
	ht->array = malloc(sizeof(unsigned long int) * size);
	/* Calloc init in 0 */
	return (ht);
}
```
