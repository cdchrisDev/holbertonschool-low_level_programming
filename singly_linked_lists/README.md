# this is the singly linked list project

1. > write a function that prints all the elements of a `list_t` list.
	* Prototype: `size_t print_list(const list_t *h);`
	* Return: the number of nodes
	* Format: see example
	* if `str` is `NULL`, print `[0] (nil)`
	* You are allowed to use `printf`
```
julien@ubuntu:~/Singly linked lists$ cat 0-main.c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    list_t *head;
    list_t *new;
    list_t hello = {"World", 5, NULL};
    size_t n;

    head = &hello; //first node
    new = malloc(sizeof(list_t)); //new space alloc for next node "new"
    if (new == NULL)
    { //checking for errors 
        printf("Error\n");
        return (1);
    }
    new->str = strdup("Hello"); //alloc mem for str in next node "new"
    new->len = 5;
    new->next = head; //pointer next to next node in new = head, so new jump to INIT node
    head = new; // and head jump to the next node "new"
    n = print_list(head);
    printf("-> %lu elements\n", n);

    printf("\n");
    free(new->str); // free string of the next node 
    new->str = NULL; // set the string next node to NULL
    n = print_list(head);
    printf("-> %lu elements\n", n);

    free(new); //free the struct 
    return (0);
}
julien@ubuntu:~/Singly linked lists$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-print_list.c -o a
julien@ubuntu:~/Singly linked lists$ ./a 
[5] Hello
[5] World
-> 2 elements

[0] (nil)
[5] World
-> 2 elements
julien@ubuntu:~/Singly linked lists$ 
```
## SOLVED
```
#include "lists.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * print_list - write a func that prints all list_t elements
 * @h: elements
 * Return: list the elements
 */
size_t print_list(const list_t *h)
{
	size_t i; // node count
	unsigned int n;
	char *s;

	i = 0;

	while (h != NULL)
	{	// Looping the same node until is NULL
		i++;
		n = h->len;
		s = h->str;
	/* remember the member */
		if (h->str == NULL)
			printf("[%d] (nil)\n", n);
		else
			printf("[%d] %s\n", n, s);

		h = h->next;
	}
	return (i);
}
```
