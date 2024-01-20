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
## 1. Write a hash function implementing the djb2 algorithm.

* Prototype: `unsigned long int hash_djb2(const unsigned char *str);`
* You are allowed to copy and paste the function from [this page](https://gist.github.com/papamuziko/7bb52dfbb859fdffc4bd0f95b76f71e8)
```
julien@ubuntu:~/Hash tables$ cat 1-djb2.c 
unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash;
    int c;

    hash = 5381;
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return (hash);
}
julien@ubuntu:~/Hash tables$ 
julien@ubuntu:~/Hash tables$ cat 1-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    char *s;

    s = "cisfun";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    s = "Don't forget to tweet today";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    s = "98";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    return (EXIT_SUCCESS);
}
julien@ubuntu:~/Hash tables$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-djb2.c -o b
julien@ubuntu:~/Hash tables$ ./b 
6953392314605
3749890792216096085
5861846
julien@ubuntu:~/Hash tables$ 
```
**SOLVED**
```
/**
 * hash_djb2 - implementation of the djb2 algorithm
 * @str: string used to generate hash value
 *
 * Return: hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}
```
## 2. Write a function that gives you the index of a key.

* Prototype: `unsigned long int key_index(const unsigned char *key, unsigned long int size);`
	* where `key` is the key
	* and `size` is the size of the array of the hash table
* This function should use the `hash_djb2` function that you wrote earlier
* Returns the index at which the key/value pair should be stored in the array of the hash table
* You will have to use this hash function for all the next tasks
```
julien@ubuntu:~/Hash tables$ cat 2-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    char *s;
    unsigned long int hash_table_array_size;

    hash_table_array_size = 1024;
    s = "cisfun";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
    s = "Don't forget to tweet today";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
    s = "98";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));  
    return (EXIT_SUCCESS);
}
julien@ubuntu:~/Hash tables$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 1-djb2.c 2-key_index.c -o c
julien@ubuntu:~/Hash tables$ ./c 
6953392314605
237
3749890792216096085
341
5861846
470
julien@ubuntu:~/Hash tables$ 
```
**SOLVED**
```
#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * key_index - a func that gives you the index of a key
 * @key: the key
 * @size: the size of the array
 * Return: index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
```
## 3. Write a function that adds an element to the hash table.

* Prototype: `int hash_table_set(hash_table_t *ht, const char *key, const char *value);`
	* Where `ht` is the hash table you want to add or update the key/value to
	* `key` is the key. `key` can not be an empty string
	* and `value` is the value associated with the key. value must be duplicated. value can be an empty string
Returns: 1 if it succeeded, 0 otherwise
In case of collision, add the new node at the beginning of the list

```
julien@ubuntu:~/Hash tables$ cat 3-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    hash_table_set(ht, "betty", "cool");
    return (EXIT_SUCCESS);
}
julien@ubuntu:~/Hash tables$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c -o d
julien@ubuntu:~/Hash tables$
```
**SOLVED**
```
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
```
## 4. Write a function that retrieves a value associated with a key
Write a function that retrieves a value associated with a key.
* **Prototype**: `char *hash_table_get(const hash_table_t *ht, const char *key);`
	* where `ht` is the hash table you want to look into
	* and `key` is the key you are looking for
* Returns the value associated with the element, or `NULL` if `key` couldn’t be found
```
julien@ubuntu:~/Hash tables$ cat 4-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;
    char *value;

    ht = hash_table_create(1024);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Bob", "and Kris love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Cool");
    hash_table_set(ht, "98", "Battery Street");
    hash_table_set(ht, "c", "isfun");

    value = hash_table_get(ht, "python");
    printf("%s:%s\n", "python", value);
    value = hash_table_get(ht, "Bob");
    printf("%s:%s\n", "Bob", value);
    value = hash_table_get(ht, "N");
    printf("%s:%s\n", "N", value);
    value = hash_table_get(ht, "Asterix");
    printf("%s:%s\n", "Asterix", value);
    value = hash_table_get(ht, "Betty");
    printf("%s:%s\n", "Betty", value);
    value = hash_table_get(ht, "98");
    printf("%s:%s\n", "98", value);
    value = hash_table_get(ht, "c");
    printf("%s:%s\n", "c", value);
    value = hash_table_get(ht, "javascript");
    printf("%s:%s\n", "javascript", value);
    return (EXIT_SUCCESS);
}
julien@ubuntu:~/Hash tables$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c -o e
julien@ubuntu:~/Hash tables$ ./e 
python:awesome
Bob:and Kris love asm
N:queens
Asterix:Obelix
Betty:Cool
98:Battery Street
c:isfun
javascript:(null)
julien@ubuntu:~/Hash tables$
```
**SOLVED**
```
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
```
## 5. Write a function that prints a hash table.
* **Prototype**: `void hash_table_print(const hash_table_t *ht);`
	* where `ht` is the hash table
* You should print the key/value in the order that they appear in the array of hash table
	* Order: array, list
* Format: see example
* If `ht` is NULL, don’t print anything
```
julien@ubuntu:~/Hash tables$ cat 5-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    hash_table_print(ht);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Bob", "and Kris love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Cool");
    hash_table_set(ht, "98", "Battery Street");
    hash_table_print(ht);
    return (EXIT_SUCCESS);
}
julien@ubuntu:~/Hash tables$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 5-hash_table_print.c -o f
julien@ubuntu:~/Hash tables$ ./f 
{}
{'Betty': 'Cool', 'python': 'awesome', '98': 'Battery Street', 'N': 'queens', 'c': 'fun', 'Bob': 'and Kris love asm', 'Asterix': 'Obelix'}
julien@ubuntu:~/Hash tables$ 
```
**SOLVED**
```
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
```
## 6. Write a function that deletes a hash table.
* **Prototype**: `void hash_table_delete(hash_table_t *ht);`
	* where `ht` is the hash table
```
julien@ubuntu:~/Hash tables$ cat 6-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;
    char *key;
    char *value;

    ht = hash_table_create(1024);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Bob", "and Kris love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Cool");
    hash_table_set(ht, "98", "Battery Streetz");
    key = strdup("Tim");
    value = strdup("Britton");
    hash_table_set(ht, key, value);
    key[0] = '\0';
    value[0] = '\0';
    free(key);
    free(value);
    hash_table_set(ht, "98", "Battery Street"); 
    hash_table_set(ht, "hetairas", "Bob");
    hash_table_set(ht, "hetairas", "Bob Z");
    hash_table_set(ht, "mentioner", "Bob");
    hash_table_set(ht, "hetairas", "Bob Z Chu");
    hash_table_print(ht);
    hash_table_delete(ht);
    return (EXIT_SUCCESS);
}
julien@ubuntu:~/Hash tables$ gcc -Wall -pedantic -Werror -Wextra 6-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 5-hash_table_print.c 6-hash_table_delete.c -o g
julien@ubuntu:~/Hash tables$ valgrind ./g
==6621== Memcheck, a memory error detector
==6621== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==6621== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==6621== Command: ./g
==6621== 
{'Betty': 'Cool', 'mentioner': 'Bob', 'hetairas': 'Bob Z Chu', 'python': 'awesome', 'Bob': 'and Kris love asm', '98': 'Battery Street', 'N': 'queens', 'c': 'fun', 'Tim': 'Britton', 'Asterix': 'Obelix'}
==6621== 
==6621== HEAP SUMMARY:
==6621==     in use at exit: 0 bytes in 0 blocks
==6621==   total heap usage: 37 allocs, 37 frees, 8,646 bytes allocated
==6621== 
==6621== All heap blocks were freed -- no leaks are possible
==6621== 
==6621== For counts of detected and suppressed errors, rerun with: -v
==6621== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
julien@ubuntu:~/Hash tables$ 
```
**SOLVED**
```
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
```

