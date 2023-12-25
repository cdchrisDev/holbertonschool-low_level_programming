# C - Pointers Arrays and strings
### Resources
* [C - Arrays](https://www.tutorialspoint.com/cprogramming/c_arrays.htm)
* [C - pointers](https://www.tutorialspoint.com/cprogramming/c_pointers.htm)
* [C - Strings](https://www.tutorialspoint.com/cprogramming/c_strings.htm)
* [Memory Layout](https://aticleworld.com/memory-layout-of-c-program/)
* [C - Pointer to  Pointer](https://intranet.hbtn.io/rltoken/YoasQWf5LbinwueEzXlghw)
* [C - Pointer to Pointer with example](https://intranet.hbtn.io/rltoken/mLxqSzYyRIO3jGMy_MwxDA)
* [Multi-dimensional Arrays in C](https://intranet.hbtn.io/rltoken/DCKFJFt4UwqEWwktR4T4Ug)
* [Two dimensional (2D) arrays in C programming with example](https://intranet.hbtn.io/rltoken/jY3lkOKQk81XgkkOe1qp2Q)
## Learning Objectives
* What are pointers and how to use them
	* A pointer is a piece of data that stores the address of the value on another piece of data<br />

* What are arrays and how to use them
	* And array is a sequence of values assigned to a specific data type, in other words. Is a data collection of the same type<br />

* What are the differences between pointers and arrays
	* An array is a set of objects of the same type. Whereas a pointer is a variable that contains the address of another variable.<br />

* How to use strings and how to manipulate them
	* Strings are located character separated in an array terminating by null byte `\0`, so we have to move to the entire array in one direction to manipulate the arra `char str = "Hola, como estas` `while(str++);`<br />

* Scope of variables
	* Global: `int var; Foo(){}`
	* Local:  `Foo(){ int var; }`<br />

* What are pointers to pointers and how to use them
	* Pointer to a pointer is a form of multiple indirection or a chain of pointers. Normally, a pointer contains the address of a variable. When we define a pointer to a pointer, the first pointer contains the address of the second pointer, which points to the location that contains the actual value as shown below.<br />

* What are multidimensional arrays and how to use them
	* A multi-dimensional array is an array with more than one level or dimension. For example, a 2D array, or two-dimensional array, is an array of arrays, meaning it is a matrix of rows and columns (think of a table). A 3D array adds another dimension, turning it into an array of arrays of arrays.<br />

* What are the most common C standard library functions to manipulate strings
	* strcat - concatenate two strings.
	* strchr - string scanning operation.
	* strcmp - compare two strings.
	* strcpy - copy a string.
	* strlen - get string length.
	* strncat - concatenate one string with part of another.
	* strncmp - compare parts of two strings.<br />

## 0. Write a function that takes a pointer to an int as parameter and updates the value it points to to 98.

* Prototype: `void reset_to_98(int *n);`
```
julien@ubuntu:~/$ cat 0-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code 
 *
 * Return: Always 0.
 */
int main(void)
{
    int n;

    n = 402;
    printf("n=%d\n", n);
    reset_to_98(&n);
    printf("n=%d\n", n);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-reset_to_98.c -o 0-98
julien@ubuntu:~/$ ./0-98 
n=402
n=98
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * reset_to_98 - prototype func
 * a function to reset a 'n' to 98
 * @n: number to update
 * Return: updated number
 */
void reset_to_98(int *n)
{
	*n = 98;
}
```
## 1. Write a function that swaps the values of two integers.

* Prototype: `void swap_int(int *a, int *b);`
```
julien@ubuntu:~/$ cat 1-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int a;
    int b;

    a = 98;
    b = 42;
    printf("a=%d, b=%d\n", a, b);
    swap_int(&a, &b);
    printf("a=%d, b=%d\n", a, b);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-swap.c -o 1-swap
julien@ubuntu:~/$ ./1-swap 
a=98, b=42
a=42, b=98
julien@ubuntu:~/$
```
**SOLVED**
```
#include "main.h"
/**
 * swap_int - swaper for 2 ints
 * this program swap the position of 2 var
 * @a: num to swap
 * @b: num to swap
 * Return: the swapped nums
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
```
## 2. Write a function that returns the length of a string.

* Prototype: `int _strlen(char *s);`
**FYI:** The standard library provides a similar function: `strlen`. Run `man strlen` to learn more.
```
julien@ubuntu:~/$ cat 2-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *str;
    int len;

    str = "My first strlen!";
    len = _strlen(str);
    printf("%d\n", len);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-strlen.c -o 2-strlen
julien@ubuntu:~/$ ./2-strlen 
16
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * _strlen - length of a string
 * a program to return the length of a string
 * @s: a character of a string
 * Return: the length of a string
 */
int _strlen(char *s)
{
	int c;

	for (c = 0; *s != '\0' ; s++)
		c++;

	return (c);
}
```
## 3. Write a function that prints a string, followed by a new line, to stdout.

* Prototype: `void _puts(char *str);`
* **FYI**: The standard library provides a similar function: `puts`. `Run man` puts to learn more.
```
julien@ubuntu:~/$ cat 3-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *str;

    str = "I do not fear computers. I fear the lack of them - Isaac Asimov";
    _puts(str);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 3-main.c 3-puts.c -o 3-puts
julien@ubuntu:~/$ ./3-puts 
I do not fear computers. I fear the lack of them - Isaac Asimov
julien@ubuntu:~/$ 

```
**SOLVED**
```
#include <stdio.h>

void _puts(char *str)
{
	while (*str++)
		_putchar(str);

	_putchar('\n');

}
```
## 4. Write a function that prints a string, in reverse, followed by a new line.

* Prototype: `void print_rev(char *s);`
```
julien@ubuntu:~/$ cat 4-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *str;

    str = "I do not fear computers. I fear the lack of them - Isaac Asimov";
    print_rev(str);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 4-main.c 4-print_rev.c -o 4-print_rev
julien@ubuntu:~/$ ./4-print_rev 
vomisA caasI - meht fo kcal eht raef I .sretupmoc raef ton od I
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * print_rev - print in reverse
 * A simple program to print in reverse
 * @s: character
 * Return: a reversed string
 */
void print_rev(char *s)
{
	int i;

	for (i = 0; *s != '\0'; s++)
		i++;

	s--;

	while (i != 0)
	{
		_putchar(*s);
		i--;
		s--;
	}
	_putchar('\n');
}
```
## 5. Write a function that reverses a string.

* Prototype: `void rev_string(char *s);`
```
julien@ubuntu:~/$ cat 5-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char s[10] = "My School";

    printf("%s\n", s);
    rev_string(s);
    printf("%s\n", s);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 5-rev_string.c -o 5-rev_string
julien@ubuntu:~/$ ./5-rev_string 
My School
loohcS yM
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * rev_string - reverse a string
 * a simple program return a reversed a string
 * @s: character
 * Return: a reversed string
 */
void rev_string(char *s)
{
	char cap = s[0];
	int i;
	int fc = 0;

	while (*s++)
		fc++;

	for (i = 0; i < fc; i++)
	{
		fc--;
		cap = s[i];
		s[i] = s[fc];
		s[fc] = cap;
	}
}
```
## 6. Write a function that prints every other character of a string, starting with the first character, followed by a new line.

* Prototype: `void puts2(char *str);`
```
julien@ubuntu:~/$ cat 6-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *str;

    str = "0123456789";
    puts2(str);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 6-main.c 6-puts2.c -o 6-puts2
julien@ubuntu:~/$ ./6-puts2 
02468
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * puts2 - func half char
 * a program to print every other character of a string.
 * @str: a character sequence
 * Return: half'ed string
 */

void puts2(char *str)
{
	int i;

	i = 0;

	while (*str != '\0')
	{
		if (i % 2 == 0)
		{
			_putchar(*str);
		}
		str++;
		i++;
	}
	_putchar('\n');
}
```
## 7. Write a function that prints half of a string, followed by a new line.

* Prototype: `void puts_half(char *str);`
* The function should print the second half of the string
* If the number of characters is odd, the function should print the last n characters of the string, where `n = (length_of_the_string - 1) / 2`
```
julien@ubuntu:~/$ cat 7-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *str;

    str = "0123456789";
    puts_half(str);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 7-main.c 7-puts_half.c -o 7-puts_half
julien@ubuntu:~/$ ./7-puts_half 
56789
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * puts_half - a program to cut a string in half
 * a simple program to print a string in half
 * @str: a string
 * Return a halfed string
 */
void puts_half(char *str)
{
	int n, c, len;

	len = 0;

	for (n = 0; *(str + n) != '\0'; n++)
		len++;


	c = len / 2;

	if ((len % 2) == 1)
		c = ((len + 1) / 2);

	for (n = c; str[n] != '\0'; n++)
		_putchar(str[n]);

	_putchar('\n');
}
```
## 8. Write a function that prints n elements of an array of integers, followed by a new line.

* Prototype: `void print_array(int *a, int n);`
* where `n` is the number of elements of the array to be printed
* Numbers must be separated by comma, followed by a space
* The numbers should be displayed in the same order as they are stored in the array
* You are allowed to use `printf`
```
julien@ubuntu:~/$ cat 8-main.c
#include "main.h"

/**
 * main - check the code for
 *
 * Return: Always 0.
 */
int main(void)
{
    int array[5];

    array[0] = 98;
    array[1] = 402;
    array[2] = -198;
    array[3] = 298;
    array[4] = -1024;
    print_array(array, 5);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 8-main.c 8-print_array.c -o 8-print_array
julien@ubuntu:~/$ ./8-print_array 
98, 402, -198, 298, -1024
julien@ubuntu:~/$
```
**SOLVED**
```
#include <stdio.h>
#include "main.h"
/**
 * print_array - a simple program to print and array of ints
 * @a: int
 * @n: int
 * Return: void
 */
void print_array(int *a, int n)
{
	int i = 0;

	while (i < n - 1)
	{
		printf("%d, ", a[i]);
		i++;

		if (i == (n - 1))
			printf("%d", a[n - 1]);
	}
	printf("\n");

}
```
## 9. strcpy

* Prototype: `char *_strcpy(char *dest, char *src);`
Write a function that copies the string pointed to by `src`, including the terminating null byte (`\0`), to the buffer pointed to by `dest`.

* Return value: the pointer to `dest`
**FYI**: The standard library provides a similar function: `strcpy`. Run `man strcpy` to learn more.
```
julien@ubuntu:~/$ cat 9-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char s1[98];
    char *ptr;

    ptr = _strcpy(s1, "First, solve the problem. Then, write the code\n");
    printf("%s", s1);
    printf("%s", ptr);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 9-main.c 9-strcpy.c -o 9-strcpy
julien@ubuntu:~/$ ./9-strcpy 
First, solve the problem. Then, write the code
First, solve the problem. Then, write the code
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * _strcpy - a func to print copy a string
 * @dest: where it is copied
 * @src: where it copys
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;

	while ((dest[i] = src[i]) != '\0')
		i++;

	return (dest + '\0');
}
```
## 10. Write a function that convert a string to an integer.

* Prototype: `int _atoi(char *s);`
* The number in the string can be preceded by an infinite number of characters
* You need to take into account all the `-` and `+` signs before the number
* If there are no numbers in the string, the function must return `0`
* You are not allowed to use `long`
* You are not allowed to declare new variables of “type” array
* You are not allowed to hard-code special values
* We will use the `-fsanitize=signed-integer-overflow` gcc flag to compile your code.
**FYI**: The standard library provides a similar function: `atoi`. Run `man atoi` to learn more.
```
julien@ubuntu:~/$ cat 100-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int nb;

    nb = _atoi("98");
    printf("%d\n", nb);
    nb = _atoi("-402");
    printf("%d\n", nb);
    nb = _atoi("          ------++++++-----+++++--98");
    printf("%d\n", nb);
    nb = _atoi("214748364");
    printf("%d\n", nb);
    nb = _atoi("0");
    printf("%d\n", nb);
    nb = _atoi("Suite 402");
    printf("%d\n", nb);
    nb = _atoi("         +      +    -    -98 Battery Street; San Francisco, CA 94111 - USA             ");
    printf("%d\n", nb);
    nb = _atoi("---++++ -++ Sui - te -   402 #cisfun :)");
    printf("%d\n", nb);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -fsanitize=signed-integer-overflow 100-main.c 100-atoi.c -o 100-atoi
julien@ubuntu:~/$ ./100-atoi 
98
-402
-98
214748364
0
402
98
402
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * _atoi -a func to convert a string to int
 * @s: a char
 * Return: 0
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	do {
		if (*s == '-')
			sign *= -1;

		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');

		else if (num > 0)
			break;

	} while (*s++);

	return (num * sign);
}
```
## 0. strcat
* Prototype: char *_strcat(char *dest, char *src);
* This function appends the `src` string to the `dest` string, overwriting the terminating null byte (`\0`) at the end of `dest`, and then adds a terminating null byte
* Returns a pointer to the resulting string `dest`
**FYI**: The standard library provides a similar function: `strcat`. Run `man strcat` to learn more.
```
julien@ubuntu:~/$ cat 0-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char s1[98] = "Hello ";
    char s2[] = "World!\n";
    char *ptr;

    printf("%s\n", s1);
    printf("%s", s2);
    ptr = _strcat(s1, s2);
    printf("%s", s1);
    printf("%s", s2);
    printf("%s", ptr);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-strcat.c -o 0-strcat
julien@ubuntu:~/$ ./0-strcat 
Hello 
World!
Hello World!
World!
Hello World!
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * _strcat - a func that concatenates two strings
 * @dest: string concatenated
 * @src: string to concatenate
 * Return: pointer to dest
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
		i++;


	for (; src[j] != '\0'; j++, i++)
	{
		dest[i] = src[j];
	}
	dest[i] = '\0';

	return (dest);

}
```
## 1. Write a function that concatenates two strings.

* Prototype: char *_strncat(char *dest, char *src, int n);
* The `_strncat` function is similar to the `_strcat` function, except that
	* it will use at most `n` bytes from `src`; and
	* `src` does not need to be null-terminated if it contains `n` or more bytes
	* Return a pointer to the resulting string `dest`
**FYI**: The standard library provides a similar function: `strncat`. Run `man strncat` to learn more.
```
julien@ubuntu:~/$ cat 1-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char s1[98] = "Hello ";
    char s2[] = "World!\n";
    char *ptr;

    printf("%s\n", s1);
    printf("%s", s2);
    ptr = _strncat(s1, s2, 1);
    printf("%s\n", s1);
    printf("%s", s2);
    printf("%s\n", ptr);
    ptr = _strncat(s1, s2, 1024);
    printf("%s", s1);
    printf("%s", s2);
    printf("%s", ptr);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-strncat.c -o 1-strncat
julien@ubuntu:~/$ ./1-strncat 
Hello 
World!
Hello W
World!
Hello W
Hello WWorld!
World!
Hello WWorld!
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * char *_strncat - a func at least n bytes
 * @dest: the string where will concatenate
 * @src: where it concatenate
 * @n: num of bytes to concatenate
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0, k;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
		j++;

	if (n < j)
		j = n - 1;

	k = 0;

	while (k <= j)
	{
		dest[i] = src[k];
		k++, i++;
	}

	dest[i + 1] = '\0';

	return (dest);
}
```
## 2. strncpy: Write a function that copies a string.

* Prototype: `char *_strncpy(char *dest, char *src, int n);`
* Your function should work exactly like `strncpy
**FYI**: The standard library provides a similar function: `strncpy`. Run `man strncpy` to learn more.
```
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char s1[98];
    char *ptr;
    int i;

    for (i = 0; i < 98 - 1; i++)
    {
        s1[i] = '*';
    }
    s1[i] = '\0';
    printf("%s\n", s1);
    ptr = _strncpy(s1, "First, solve the problem. Then, write the code\n", 5);
    printf("%s\n", s1);
    printf("%s\n", ptr);
    ptr = _strncpy(s1, "First, solve the problem. Then, write the code\n", 90);
    printf("%s", s1);
    printf("%s", ptr);
    for (i = 0; i < 98; i++)
    {
        if (i % 10)
        {
            printf(" ");
        }
        if (!(i % 10) && i)
        {
            printf("\n");
        }
        printf("0x%02x", s1[i]);
    }
    printf("\n");
    return (0);
}
```
**SOLVED**
```
#include "main.h"
/**
 * _strncpy - strncpy replicated
 * @dest: string 1
 * @src: string 2
 * @n: num of bytes
 * Return: 0
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
```
##  3. strcmp: Write a function that compares two strings.

* Prototype: `int _strcmp(char *s1, char *s2);`
* Your function should work exactly like `strcmp`
**FYI**: The standard library provides a similar function: `strcmp`. Run `man strcmp` to learn more.
```
julien@ubuntu:~/$ cat 3-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char s1[] = "Hello";
    char s2[] = "World!";

    printf("%d\n", _strcmp(s1, s2));
    printf("%d\n", _strcmp(s2, s1));
    printf("%d\n", _strcmp(s1, s1));
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-strcmp.c -o 3-strcmp
julien@ubuntu:~/$ ./3-strcmp 
-15
15
0
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: less, equal to or greater than 0
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
		if (s1[i] == '\0')
			return (0);

	return (s1[i] - s2[i]);
}
```
## 4. Write a function that reverses the content of an array of integers.

* Prototype: `void reverse_array(int *a, int n);`
* Where `n` is the number of elements of the array
```
julien@ubuntu:~/$ cat 4-main.c
#include "main.h"
#include <stdio.h>

/**
 * print_array - print an array of integers
 * @a: an array of integers
 * @n: the number of elements to swap
 *
 * Return: nothing.
 */
void print_array(int *a, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (i != 0)
        {
            printf(", ");
        }
        printf("%d", a[i]);
        i++;
    }
    printf("\n");
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 98, 1024, 1337};

    print_array(a, sizeof(a) / sizeof(int));
    reverse_array(a, sizeof(a) / sizeof(int));
    print_array(a, sizeof(a) / sizeof(int));
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 4-rev_array.c -o 4-rev_array
julien@ubuntu:~/$ ./4-rev_array 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 98, 1024, 1337
1337, 1024, 98, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * reverse_array - a func to reverse the content of an array
 * @a: an int
 * @n: a num of elements in the array
 * Return: a reversed array
 */
void reverse_array(int *a, int n)
{
	int i, cap = a[0];

	for (i = 0; i < n; i++)
	{
		n--;
		cap = a[i];
		a[i] = a[n];
		a[n] = cap;
	}
}
```
## 5. Write a function that changes all lowercase letters of a string to uppercase.

* Prototype: `char *string_toupper(char *);`
```
julien@ubuntu:~/$ cat 5-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char str[] = "Look up!\n";
    char *ptr;

    ptr = string_toupper(str);
    printf("%s", ptr);
    printf("%s", str);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 5-string_toupper.c -o 5-string_toupper
julien@ubuntu:~/$ ./5-string_toupper 
LOOK UP!
LOOK UP!
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * string_toupper - convert lower to uppercase
 * @c: a char
 * Return: uppercase letter
 */
char *string_toupper(char *c)
{
	int i = 0;

	while (c[i++] != '\0')
	{
		if (c[i] >= 'a' && c[i] <= 'z')
			c[i] -= 32;
	}
	return (c);
}
```
## 6. Write a function that capitalizes all words of a string.

* Prototype: `char *cap_string(char *);`
* Separators of words: space, tabulation, new line, `,`, `;`, `.`, `!`, `?`, `"`, `(`, `)`, `{`, and `}`
```
julien@ubuntu:~/$ cat 6-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char str[] = "Expect the best. Prepare for the worst. Capitalize on what comes.\nhello world! hello-world 0123456hello world\thello world.hello world\n";
    char *ptr;

    ptr = cap_string(str);
    printf("%s", ptr);
    printf("%s", str);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 6-main.c 6-cap_string.c -o 6-cap
julien@ubuntu:~/$ ./6-cap 
Expect The Best. Prepare For The Worst. Capitalize On What Comes.
Hello World! Hello-world 0123456hello World Hello World.Hello World
Expect The Best. Prepare For The Worst. Capitalize On What Comes.
Hello World! Hello-world 0123456hello World Hello World.Hello World
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
  * cap_string - ...
  * @s: ...
  *
  * Return: char value
  */
char *cap_string(char *s)
{
	int a = 0, i;
	int cspc = 13;
	char spc[] = {32, '\t', '\n', 44, ';', 46, '!', '?', '"', '(', ')', '{', '}'};

	while (s[a])
	{
		i = 0;

		while (i < cspc)
		{
			if ((a == 0 || s[a - 1] == spc[i]) && (s[a] >= 97 && s[a] <= 122))
				s[a] -= 32;

			i++;
		}

		a++;
	}

	return (s);
}
```
## 7. Write a function that encodes a string into 1337.

* Letters `a` and `A` should be replaced by `4`
* Letters `e` and `E` should be replaced by `3`
* Letters `o` and `O` should be replaced by `0`
* Letters `t` and `T` should be replaced by `7`
* Letters `l` and `L` should be replaced by `1` 
* Prototype: `char *leet(char *);`
* You can only use one `if` in your code
* You can only use two loops in your code
* You are not allowed to use `switch`
* You are not allowed to use any ternary operation
```
julien@ubuntu:~/$ cat 7-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code for
 *
 * Return: Always 0.
 */
int main(void)
{
    char s[] = "Expect the best. Prepare for the worst. Capitalize on what comes.\n";
    char *p;

    p = leet(s);
    printf("%s", p);
    printf("%s", s);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 7-main.c 7-leet.c -o 7-1337
julien@ubuntu:~/$ ./7-1337 
3xp3c7 7h3 b3s7. Pr3p4r3 f0r 7h3 w0rs7. C4pi741iz3 0n wh47 c0m3s.
3xp3c7 7h3 b3s7. Pr3p4r3 f0r 7h3 w0rs7. C4pi741iz3 0n wh47 c0m3s.
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"

/**
  * leet - Encodes a string into 1337
  * @s: The string to encode
  *
  * Return: The encoded string
  */
char *leet(char *s)
{
	int a = 0, b = 0, l = 5;
	char r[5] = {'A', 'E', 'O', 'T', 'L'};
	char n[5] = {'4', '3', '0', '7', '1'};

	while (s[a])
	{
		b = 0;

		while (b < l)
		{
			if (s[a] == r[b] || s[a] - 32 == r[b])
			{
				s[a] = n[b];
			}

			b++;
		}

		a++;
	}

	return (s);
}
```
## 0. memset: Write a function that fills memory with a constant byte.

* Prototype: `char *_memset(char *s, char b, unsigned int n);`
* The `_memset()` function fills the first `n` bytes of the memory area pointed to by `s` with the constant byte `b`
* Returns a pointer to the memory area `s`
**FYI**: The standard library provides a similar function: `memset`. Run `man memset` to learn more.
```
julien@ubuntu:~/$ cat 0-main.c
#include "main.h"
#include <stdio.h>

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
void simple_print_buffer(char *buffer, unsigned int size)
{
        unsigned int i;

        i = 0;
        while (i < size)
        {
                if (i % 10)
                {
                        printf(" ");
                }
                if (!(i % 10) && i)
                {
                        printf("\n");
                }
                printf("0x%02x", buffer[i]);
                i++;
        }
        printf("\n");
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char buffer[98] = {0x00};

    simple_print_buffer(buffer, 98);
    _memset(buffer, 0x01, 95);
    printf("-------------------------------------------------\n");
    simple_print_buffer(buffer, 98);    
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-memset.c -o 0-memset
julien@ubuntu:~/$ ./0-memset 
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
-------------------------------------------------
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x00 0x00 0x00
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * _memset - fills memory with constant byte
 * @s: buffer
 * @b: constant bytes
 * @n: num of bytes
 * Return: pointer to memory area s;
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i != n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
```
## 1. memcpy: Write a function that copies memory area.

* Prototype: `char *_memcpy(char *dest, char *src, unsigned int n);`
* The `_memcpy()` function copies `n` bytes from memory area `src` to memory area `dest`
* Returns a pointer to `dest`
* **FYI**: The standard library provides a similar function: `memcpy`. Run `man memcpy` to learn more.
```
julien@ubuntu:~/$ cat 1-main.c
#include "main.h"
#include <stdio.h>

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
void simple_print_buffer(char *buffer, unsigned int size)
{
    unsigned int i;

    i = 0;
    while (i < size)
    {
        if (i % 10)
        {
            printf(" ");
        }
        if (!(i % 10) && i)
        {
            printf("\n");
        }
        printf("0x%02x", buffer[i]);
        i++;
    }
    printf("\n");
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char buffer[98] = {0};
    char buffer2[98] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    simple_print_buffer(buffer, 98);
    _memcpy(buffer + 50, buffer2, 10);
    printf("-------------------------------------------------\n");
    simple_print_buffer(buffer, 98);    
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-memcpy.c -o 1-memcpy
julien@ubuntu:~/$ ./1-memcpy 
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
-------------------------------------------------
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x01 0x02 0x03 0x04 0x05 0x06 0x07 0x08 0x09 0x0a
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * *_memcpy - a func to copy memory area
 * @dest: where to copy to
 * @src: where to copy from
 * @n: num of n
 * Return: the copy of src on dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i != n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
```
## 2. strchr: Write a function that locates a character in a string.

* Prototype: `char *_strchr(char *s, char c);`
* Returns a pointer to the first occurrence of the character `c` in the string `s`, or `NULL` if the character is not found
**FYI**: The standard library provides a similar function: `strchr`. Run `man strchr` to learn more
```
julien@ubuntu:~/$ cat 2-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s = "hello";
    char *f;

    f = _strchr(s, 'l');

    if (f != NULL)
    {
        printf("%s\n", f);
    }
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-strchr.c -o 2-strchr
julien@ubuntu:~/$ ./2-strchr 
llo
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * _strchr - a func to locate a char in a str
 * @s: a string
 * @c: char
 * Return: pointer to the occurrence of the character
 */
char *_strchr(char *s, char c)
{
	while (s++)
	{
		if (*s == c)
			return (s);
		if (!*s)
			return (0);
	}
	return (0);
}
```
## 3. strspn: Write a function that gets the length of a prefix substring.

* Prototype: `unsigned int _strspn(char *s, char *accept);`
* Returns the number of bytes in the initial segment of `s` which consist only of bytes from `accept`
**FYI**: The standard library provides a similar function: `strspn`. Run `man strspn` to learn more.
```
julien@ubuntu:~/$ cat 3-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s = "hello, world";
    char *f = "oleh";
    unsigned int n;

    n = _strspn(s, f);
    printf("%u\n", n);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-strspn.c -o 3-strspn
julien@ubuntu:~/$ ./3-strspn 
5
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"

/**
 * _strspn -  gets the length of a prefix substring
 *
 * @s: char pointer
 * @accept: char pointer
 *
 *
 * Return: s
 */

unsigned int _strspn(char *s, char *accept)
{

	unsigned int count1, count2;

	for (count1 = 0; s[count1] != '\0'; count1++)
	{
		for (count2 = 0; accept[count2] != '\0'; count2++)
		{
			if (s[count1] == accept[count2])
			{
				break;
			}
		}
			if (!(accept[count2]))
			{
				break;
			}
	}
	return (count1);
}
```
## 4. strbrk: Write a function that searches a string for any of a set of bytes.

* Prototype: `char *_strpbrk(char *s, char *accept);`
* The `_strpbrk()` function locates the first occurrence in the string s of any of the bytes in the string `accept`
* Returns a pointer to the byte in `s` that matches one of the bytes in `accept`, or `NULL` if no such byte is found
**FYI**: The standard library provides a similar function: `strpbrk`. Run `man strpbrk` to learn more.
```
julien@ubuntu:~/$ cat 4-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s = "hello, world";
    char *f = "world";
    char *t;

    t = _strpbrk(s, f);
    printf("%s\n", t);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 4-strpbrk.c -o 4-strpbrk
julien@ubuntu:~/$ ./4-strpbrk 
llo, world
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include <stdlib.h>
#include "main.h"
/**
 * _strpbrk - a func to look for bytes *accept on string *s
 * @s: a string
 * @accept: bytes to look for
 * Return: the occurrencenses
 */
char *_strpbrk(char *s, char *accept)
{

	int i = 0;

	while (s[i] != '\0')
	{
		int j = 0;

		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				return (&s[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
```
## 5. strstr: Write a function that locates a substring.

* Prototype: `char *_strstr(char *haystack, char *needle);`
* The `_strstr()` function finds the first occurrence of the substring `needle` in the string `haystack`. The terminating null bytes (`\0`) are not compared
* Returns a pointer to the beginning of the located substring, or `NULL` if the substring is not found.
**FYI**: The standard library provides a similar function: `strstr`. Run `man `strstr` to learn more.
```
julien@ubuntu:~/$ cat 5-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s = "hello, world";
    char *f = "world";
    char *t;

    t = _strstr(s, f);
    printf("%s\n", t);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 5-strstr.c -o 5-strstr
julien@ubuntu:~/$ ./5-strstr 
world
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include <stdlib.h>
#include "main.h"
/**
 * _strstr - a func that locates a substring
 * @haystack: a string to look for
 * @needle: what to look for
 * Return: located substring
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0;

	while (haystack[i])
	{
		int j = 0;

		while (needle[j])
		{
			if (haystack[i + j] != needle[j])
				break;

			j++;
		}

		if (needle[j] == '\0')
			return (haystack + i);

		i++;
	}
	return (NULL);
}
```
## 6. Write a function that prints the chessboard
* Prototype: `void print_chessboard(char (*a)[8];`
```
julien@ubuntu:~/$ cat 7-main.c 
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char board[8][8] = {
        {'r', 'k', 'b', 'q', 'k', 'b', 'k', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'K', 'B', 'Q', 'K', 'B', 'K', 'R'},
    };
    print_chessboard(board);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 7-main.c 7-print_chessboard.c -o 7-print_chessboard
julien@ubuntu:~/$ ./7-print_chessboard 
rkbqkbkr
pppppppp




PPPPPPPP
RKBQKBKR
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * print_chessboard - a func to print the chessboard
 * @a: a chess piece
 * Return: the cheesboard
 */
void print_chessboard(char (*a)[8])
{
	int i = 0;

	for (; i < 8; i++)
	{
		int j = 0;

		for (; j < 8; j++)
		{
			_putchar(a[i][j]);
		}
		_putchar('\n');
	}
}
```
## 7. Write a function that prints the sum of the two diagonals of a square matrix of integers.

* Prototype: `void print_diagsums(int *a, int size);` 
* Format: see example
* You are allowed to use the standard library
**Note** that in the following example we are casting an `int[][]` into an `int*`. This is not something you should do. The goal here is to make sure you understand how an array of array is stored in memory.
```
julien@ubuntu:~/$ cat 8-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int c3[3][3] = {
        {0, 1, 5},
        {10, 11, 12},
        {1000, 101, 102},
    };
    int c5[5][5] = {
        {0, 1, 5, 12124, 1234},
        {10, 11, 12, 123521, 12512},
        {1000, 101, 102, 12545, 214543435},
        {100, 1012451, 11102, 12545, 214543435},
        {10, 12401, 10452, 11542545, 1214543435},
    };
    print_diagsums((int *)c3, 3);
    print_diagsums((int *)c5, 5);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 8-main.c 8-print_diagsums.c -o 8-print_diagsums
julien@ubuntu:~/$ ./8-print_diagsums 
113, 1016
1214556093, 1137318
julien@ubuntu:~/$
```
**SOLVED**
```
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
/**
 * print_diagsums - a func that prints the sum of two diagonals of a
 * squeare matrix of integers
 * @a: a num
 * @size: the size
 * Return: 0
 */
void print_diagsums(int *a, int size)
{
	int i, sum = 0, sum1 = 0;

	for (i = 0; i < size; i++)
	{
		sum +=  a[i * (size + 1)];
	}

	for (i = 0; i < size; i++)
	{
		sum1 += a[(size - 1) * (i + 1)];
	}

	printf("%d, %d\n", sum, sum1);
}
```
