# C - More functions, more nested loops
### Resources
* [Nested while loops](https://www.youtube.com/watch?v=Z3iGeQ1gIss&ab_channel=ZackAnnaTutorials)
* [C - functions](https://www.tutorialspoint.com/cprogramming/c_functions.htm)
* [Learning to program in C](https://www.youtube.com/watch?v=qMlnFwYdqIw&ab_channel=JonathanEngelsma)
* [What is the purpose of a function prototype?](https://www.geeksforgeeks.org/what-is-the-purpose-of-a-function-prototype/)
* [C - Header Files](https://www.tutorialspoint.com/cprogramming/c_header_files.htm)
# Tasks
## 0. Write a function that checks for uppercase character.

* Prototype: `int _isupper(int c);`
* Returns `1` if `c` is uppercase
* Returns `0` otherwise
**FYI**: The standard library provides a similar function: `isupper`. Run `man isupper` to learn more.
```
julien@ubuntu:~/$ cat 0-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
    char c;

    c = 'A';
    printf("%c: %d\n", c, _isupper(c));
    c = 'a';
    printf("%c: %d\n", c, _isupper(c));
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-isupper.c -o 0-isuper
julien@ubuntu:~/$ ./0-isuper 
A: 1
a: 0
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * _isupper - 2th called to func
 * a program to check for uppercase letter
 * @c: a char int
 * Return: a char int
 */

int _isupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (0);
	}
	else if (c >= 65 && c <= 90)
	{
		return (1);
	}
	else
		return (0);

	return (c);
}
```
## 1. Write a function that checks for a digit (0 through 9).

* Prototype: `int _isdigit(int c);`
* Returns `1` if `c` is a digit
* Returns `0` otherwise
**FYI**: The standard library provides a similar function: `isdigit`. Run man `isdigit` to learn more.
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
    char c;

    c = '0';
    printf("%c: %d\n", c, _isdigit(c));
    c = 'a';
    printf("%c: %d\n", c, _isdigit(c));
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-isdigit.c -o 1-isdigit
julien@ubuntu:~/$ ./1-isdigit 
0: 1
a: 0
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * _isdigit - 2th func called
 * a program to check for ints
 * @c: a int
 * Return: 1 if digit, 0 if not
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);

	else
		return (0);

	return (c);
}
```
## 2. Write a function that multiplies two integers.

* Prototype: `int mul(int a, int b);`
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
    printf("%d\n", mul(98, 1024));
    printf("%d\n", mul(-402, 4096));
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-mul.c -o 2-mul
julien@ubuntu:~/$ ./2-mul 
100352
-1646592
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * mul - 2th called to func
 * a func to multiply two num
 * @a: den
 * @n: mul
 * Return: r = a * n;
 */
int mul(int a, int n)
{
	int r;

	r = a * n;

	return (r);
}
```
## 3. Write a function that prints the numbers, from 0 to 9, followed by a new line.

* Prototype: `void print_numbers(void);`
* You can only use `_putchar` twice in your code
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
    print_numbers();
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 3-main.c 3-print_numbers.c -o 3-print_numbers
julien@ubuntu:~/$ ./3-print_numbers | cat -e
0123456789$
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * print_numbers - print the numbers from 0 to 9
 * @void: no parameters
 * Return: 0
 */
void print_numbers(void)
{
	int n;

	for (n = 0; n <= 9; n++)
		_putchar(n + '0');

	_putchar('\n');
}
```
## 4. Write a function that prints the numbers, from 0 to 9, followed by a new line.

* Prototype: `void print_most_numbers(void);`
* Do not print `2` and `4`
* You can only use `_putchar` twice in your code
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
    print_most_numbers();
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 4-main.c 4-print_most_numbers.c -o 4-print_most_numbers
julien@ubuntu:~/$ ./4-print_most_numbers 
01356789
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * print_most_numbers - print most numbers except 2 and 4
 * Return: 0
 */
void print_most_numbers(void)
{
	int n;

	for (n = 0; n <= 9; n++)
	{
		if (n == 2 || n == 4)
			continue;

		_putchar(n + '0');

	}
	_putchar('\n');
}
```
## 5. Write a function that prints 10 times the numbers, from 0 to 14, followed by a new line.

* Prototype: `void more_numbers(void);`
* You can only use `_putchar` three times in your code
```
julien@ubuntu:~/$ cat 5-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    more_numbers();
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 5-main.c 5-more_numbers.c -o 5-more_numbers
julien@ubuntu:~/$ ./5-more_numbers 
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
julien@ubuntu:~/
```
**SOLVED**
```
#include "main.h"
/**
 * more_numbers - print the numbers from 0 to 14 x10.
 * Return: 0
 */
void more_numbers(void)
{
	int j, i;

	for (j = 0; j < 10; j++)
	{
		for (i = 0; i <= 14; i++)
		{
			if (i > 9)
			{
				_putchar(i / 10 + '0');
			}
			_putchar(i % 10 + '0');
		}
		_putchar('\n');
	}
}
```
## 6. Write a function that draws a straight line in the terminal.

* Prototype: `void print_line(int n);`
* You can only use `_putchar` function to print
* Where `n` is the number of times the character _ should be printed
* The line should end with a `\n`
* If `n` is `0` or less, the function should only print `\n`
