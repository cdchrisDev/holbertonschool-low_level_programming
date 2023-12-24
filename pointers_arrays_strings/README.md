# C - Pointers Arrays and strings
### Resources
* [C - Arrays](https://www.tutorialspoint.com/cprogramming/c_arrays.htm)
* [C - pointers](https://www.tutorialspoint.com/cprogramming/c_pointers.htm)
* [C - Strings](https://www.tutorialspoint.com/cprogramming/c_strings.htm)
* [Memory Layout](https://aticleworld.com/memory-layout-of-c-program/)
## Learning Objectives
* What are pointers and how to use them
	* A pointer is a piece of data that stores the address of the value on another piece of data<br />

* What are arrays and how to use them
	* And array is a sequence of values assigned to a specific data type, in other words. Is a data collection of the same type<br />

* What are the differences between pointers and arrays
	* An array is a set of objects of the same type. Whereas a pointer is a variable that contains the address of another variable.<br />

* How to use strings and how to manipulate them
	* Strings are located character separated in an array terminating by null byte `\0`, so we have to move to the entire array in one direction to manipulate the arra `char str = "Hola, como estas` `while(str++);`
* Scope of variables
	* Global: `int var; Foo(){}`
	* Local:  `Foo(){ int var; }`
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

Prototype: char *_strncat(char *dest, char *src, int n);
The _strncat function is similar to the _strcat function, except that
it will use at most n bytes from src; and
src does not need to be null-terminated if it contains n or more bytes
Return a pointer to the resulting string dest
FYI: The standard library provides a similar function: strncat. Run man strncat to learn more.
