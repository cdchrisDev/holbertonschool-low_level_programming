# C - Malloc, free
### Resources
* [0x0a - malloc & free - quick overview.pdf](https://intranet.hbtn.io/rltoken/jLHiF8lDWmdjL7HMjrsyKQ)
* [Dynamic memory allocation in C - malloc calloc realloc free](https://intranet.hbtn.io/rltoken/q_SFo9w6mIBGMJk_1nzbVQ) *stop at 6:50*
## Learning Objectives
* What is the difference between automatic and dynamic allocation
	* Automatic memory allocation is used in languages such as C and C++, where variables are declared with a fixed size at compile time. Dynamic memory allocation, on the other hand, refers to the allocation of memory at runtime, as opposed to compile time<br />

* What is `malloc` and `free` and how to use them
	* The malloc function will request a block of memory from the heap. If the request is granted, the operating system will reserve the requested amount of memory. When the amount of memory is not needed anymore, you must return it to the operating system by calling the function free.<br/>

* Why and when use `malloc`
	* Malloc is used for dynamic memory allocation and is useful when you don't know the amount of memory needed during compile time. Allocating memory allows objects to exist beyond the scope of the current block.<br />

* How to use `valgrind`
	* `valgrind ./EXEC_NAME`
# Tasks
## 0. Write a function that creates an array of chars, and initializes it with a specific char.

* Prototype: `char *create_array(unsigned int size, char c);`
* Returns `NULL` if size = `0`
* Returns a pointer to the array, or `NULL` if it fails
```
#include "main.h"
#include <stdlib.h>
/**
 * create_array - a func that create an array of chars, and init
 * with specific chars
 * @size: the size of array
 * @c: char to specificated
 * Return: NULL if size is 0. A pointer to the array or NULL if fails.
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i = 0;
	char *ci;

	if (size == 0)
		return (NULL);
	else if (size > 0)
	{
		ci  = malloc(size * sizeof(char));
		while (i <= size)
		{
			if (ci == NULL)
				return (NULL);

			ci[i] = c;
			i++;
		}
	}
	return (ci);
	free(ci);
}
```
## 1. Write a function that returns a pointer to a newly allocated space in memory, which contains a copy of the string given as a parameter.

* Prototype: `char *_strdup(char *str);`
* The `_strdup()` function returns a pointer to a new string which is a duplicate of the string `str`. Memory for the new string is obtained with malloc, and can be freed with `free`.
* Returns `NULL` if str = NULL
* On success, the `_strdup` function returns a pointer to the duplicated string. It returns `NULL` if insufficient memory was available
**FYI**: The standard library provides a similar function: `strdup`. Run `man strdup` to learn more.
```
julien@ubuntu:~/0x0a. malloc, free$ cat 1-main.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s;

    s = _strdup("Duplicated");
    if (s == NULL)
    {
        printf("failed to allocate memory\n");
        return (1);
    }
    printf("%s\n", s);
    free(s);
    return (0);
}
julien@ubuntu:~/0x0a. malloc, free$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-strdup.c -o s
julien@ubuntu:~/0x0a. malloc, free$ ./s 
Duplicated
julien@ubuntu:~/0x0a. malloc, free$ 
```
**SOLVED**
```
#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * _strdup - return a pointer to a newly allocated space in memory
 * which contains a copy of the string
 * @str: a string
 * Return: a pointer to new location
 */
char *_strdup(char *str)
{
	char *j;

	if (str == NULL)
		return (NULL);

	j = malloc(strlen(str) + 1);
		if (j == NULL)
			return (NULL);

	strcpy(j, str);

	return (j);
}
```
## 2. Write a function that concatenates two strings.

* Prototype: `char *str_concat(char *s1, char *s2);`
* The returned pointer should point to a newly allocated space in memory which contains the contents of `s1`, followed by the contents of `s2`, and null terminated
* if `NULL` is passed, treat it as an empty string
* The function should return `NULL` on failure
```
julien@ubuntu:~/0x0a. malloc, free$ cat 2-main.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s;

    s = str_concat("Best ", "School");
    if (s == NULL)
    {
        printf("failed\n");
        return (1);
    }
    printf("%s\n", s);
    free(s);
    return (0);
}
julien@ubuntu:~/0x0a. malloc, free$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-str_concat.c -o 2-str_concat
julien@ubuntu:~/0x0a. malloc, free$ ./2-str_concat | cat -e
Best School$
julien@ubuntu:~/0x0a. malloc, free$
```
**SOLVED**
```
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * str_concat - concatenates two strings.
 * @s1: char pointer
 * @s2: char pointe
 *  Return: strTemp
 */
char *str_concat(char *s1, char *s2)
{
	char *temp;
	int i;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	i = strlen(s1);
	temp = malloc(strlen(s1) + strlen(s2) + 1);

	if (temp == NULL)
		return (NULL);

	strcpy(temp, s1);
	strcpy(temp + i, s2);

	return (temp);
}
```
## 3. Write a function that returns a pointer to a 2 dimensional array of integers.

* Prototype: `int **alloc_grid(int width, int height);`
* Each element of the grid should be initialized to `0`
* The function should return `NULL` on failure
* If `width` or `height` is `0` or negative, return `NULL`
```
julien@ubuntu:~/0x0a. malloc, free$ cat 3-main.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_grid - prints a grid of integers
 * @grid: the address of the two dimensional grid
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: Nothing.
 */
void print_grid(int **grid, int width, int height)
{
    int w;
    int h;

    h = 0;
    while (h < height)
    {
        w = 0;
        while (w < width)
        {
            printf("%d ", grid[h][w]);
            w++;
        }
        printf("\n");
        h++;
    }   
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int **grid;

    grid = alloc_grid(6, 4);
    if (grid == NULL)
    {
        return (1);
    }
    print_grid(grid, 6, 4);
    printf("\n");
    grid[0][3] = 98;
    grid[3][4] = 402;
    print_grid(grid, 6, 4);
    return (0);
}
julien@ubuntu:~/0x0a. malloc, free$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-alloc_grid.c -o 3-alloc_grid
julien@ubuntu:~/0x0a. malloc, free$ ./3-alloc_grid
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 

0 0 0 98 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 402 0 
julien@ubuntu:~/0x0a. malloc, free$
```
**SOLVED**
```
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * **alloc_grid - a function that draws 2 dimensional array
 * @width: self
 * @height: self
 * Return: 0 if its 0 or non-positive or draws a grid
 */
int **alloc_grid(int width, int height)
{
	int j = 0, i = 0;
	int **gridint;

	if (height <= 0 || width <= 0)
		return (NULL);

	gridint = malloc(sizeof(int *) * height); /* Array to pointers to int */

	if (gridint == 0)
		return (NULL);

	for (; j < height; j++)
	{
		gridint[j] = malloc(sizeof(int) * width);

		if (gridint[j] == NULL)
		{
			for (; i < j; i++)
				free(gridint[i]);

			free(gridint);
			return (NULL);
		}

	}
	for (j = 0; j < height; j++)
		for (i = 0; i < width; i++)
			gridint[j][i] = 0;

	return (gridint);
}
```
## 4. Write a function that frees a 2 dimensional grid previously created by your alloc_grid function.

* Prototype: `void free_grid(int **grid, int height);`
* Note that we will compile with your `alloc_grid.c` file. Make sure it compiles.
```
julien@ubuntu:~/0x0a. malloc, free$ cat 4-main.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_grid - prints a grid of integers
 * @grid: the address of the two dimensional grid
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: Nothing.
 */
void print_grid(int **grid, int width, int height)
{
    int w;
    int h;

    h = 0;
    while (h < height)
    {
        w = 0;
        while (w < width)
        {
            printf("%d ", grid[h][w]);
            w++;
        }
        printf("\n");
        h++;
    }   
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int **grid;

    grid = alloc_grid(6, 4);
    if (grid == NULL)
    {
        return (1);
    }
    print_grid(grid, 6, 4);
    printf("\n");
    grid[0][3] = 98;
    grid[3][4] = 402;
    print_grid(grid, 6, 4);
    free_grid(grid, 4);
    return (0);
}
julien@ubuntu:~/0x0a. malloc, free$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 3-alloc_grid.c 4-free_grid.c -o 4-free_grid
julien@ubuntu:~/0x0a. malloc, free$ valgrind ./4-free_grid
==5013== Memcheck, a memory error detector
==5013== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==5013== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==5013== Command: ./f
==5013== 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 

0 0 0 98 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 402 0 
==5013== 
==5013== HEAP SUMMARY:
==5013==     in use at exit: 0 bytes in 0 blocks
==5013==   total heap usage: 6 allocs, 6 frees, 1,248 bytes allocated
==5013== 
==5013== All heap blocks were freed -- no leaks are possible
==5013== 
==5013== For counts of detected and suppressed errors, rerun with: -v
==5013== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
julien@ubuntu:~/0x0a. malloc, free$ 
```
**SOLVED**
```
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * free_grid - write a func that frees a 2 dimenstional grid
 * @grid: 2D array
 * @height: array to free
 * Return: a freed array
 */
void free_grid(int **grid, int height)
{
	int j = 0;

	for (; j < height; j++)
		free(grid[j]);

	free(grid);
}
```
