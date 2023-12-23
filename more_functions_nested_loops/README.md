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
    print_line(0);
    print_line(2);
    print_line(10);
    print_line(-4);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 6-main.c 6-print_line.c -o 6-lines
julien@ubuntu:~/$ ./6-lines | cat -e
$
__$
__________$
$
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * print_line - write a straight line
 * @n: a int
 * Return: a drew line
 */
void print_line(int n)
{
	while (n > 0)
	{
		_putchar('_');
		n--;
	}

	_putchar('\n');
}
```
## 7. Write a function that draws a diagonal line on the terminal.

* Prototype: `void print_diagonal(int n);`
* You can only use `_putchar` function to print
* Where `n` is the number of times the character `\` should be printed
* The diagonal should end with a `\n`
* If `n` is `0` or less, the function should only print a `\n`
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
    print_diagonal(0);
    print_diagonal(2);
    print_diagonal(10);
    print_diagonal(-4);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 7-main.c 7-print_diagonal.c -o 7-diagonals
julien@ubuntu:~/$ ./7-diagonals | cat -e
$
\$
 \$
\$
 \$
  \$
   \$
    \$
     \$
      \$
       \$
        \$
         \$
$
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * print_diagonal - print a diagonal line on the terminal
 * @n: a int
 * Return: void
 */
void print_diagonal(int n)
{
	int j, i;

	if (n <= 0)
		_putchar('\n');


	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				_putchar('\\');
				_putchar('\n');
				break;
			}
			else
			{
				_putchar(' ');
			}
		}
	}
}
```
## 8. Write a function that prints a square, followed by a new line.

* Prototype: `void print_square(int size);`
+ You can only use `_putchar` function to print
* Where `size` is the size of the square
* If `size` is `0` or less, the function should print only a new line
+ Use the character `#` to print the square
```
julien@ubuntu:~/$ cat 8-main.c 
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_square(2);
    print_square(10);
    print_square(0);
    return (0);
}

julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 8-main.c 8-print_square.c -o 8-squares
julien@ubuntu:~/$ ./8-squares 
##
##
##########
##########
##########
##########
##########
##########
##########
##########
##########
##########
```
**SOLVED**
```
#include "main.h"
/**
 * print_square -  a func to print a square
 * @size: a square
 * Return: a square
 *
 */
void print_square(int size)
{
	int i, j;

	if (size <= 0)
		_putchar('\n');

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (size > 0)
				_putchar('#');
		}
		_putchar('\n');
	}
}
```
## 9. The “Fizz-Buzz test” is an interview question designed to help filter out the 99.5% of programming job candidates who can’t seem to program their way out of a wet paper bag.

Write a program that prints the numbers from `1` to `100`, followed by a new line. But for multiples of three print `Fizz` instead of the number and for the multiples of five print `Buzz`. For numbers which are multiples of both three and five print `FizzBuzz`.

* Each number or word should be separated by a space
* You are allowed to use the standard library
```
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 9-fizz_buzz.c -o 9-fizz_buzz
julien@ubuntu:~/$ ./9-fizz_buzz 
1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz Fizz 22 23 Fizz Buzz 26 Fizz 28 29 FizzBuzz 31 32 Fizz 34 Buzz Fizz 37 38 Fizz Buzz 41 Fizz 43 44 FizzBuzz 46 47 Fizz 49 Buzz Fizz 52 53 Fizz Buzz 56 Fizz 58 59 FizzBuzz 61 62 Fizz 64 Buzz Fizz 67 68 Fizz Buzz 71 Fizz 73 74 FizzBuzz 76 77 Fizz 79 Buzz Fizz 82 83 Fizz Buzz 86 Fizz 88 89 FizzBuzz 91 92 Fizz 94 Buzz Fizz 97 98 Fizz Buzz
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include <stdio.h>
/**
 * main - entry point
 * a program to print FizzBuzz depending its multiply
 * Return: 0
 */

int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			if (i % 15 == 0)
				printf("FizzBuzz ");
			else
				printf("Fizz ");
		}

		else if (i % 5 == 0)
		{
			if (i == 100)
			{
				printf("Buzz");
				putchar('\n');
			}
			else
				printf("Buzz ");
		}
		else
			printf("%d ", i);

	}

	return (0);
}
```
## 10. Write a function that prints a triangle, followed by a new line.

* Prototype: `void print_triangle(int size);`
* You can only use `_putchar` function to print
* Where `size` is the size of the triangle
* If `size` is `0` or less, the function should print only a new line
* Use the character `#` to print the triangle
```
julien@ubuntu:~/$ cat 10-main.c 
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_triangle(2);
    print_triangle(10);
    print_triangle(1);
    print_triangle(0);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 10-main.c 10-print_triangle.c -o 10-triangles
julien@ubuntu:~/$ ./10-triangles 
 #
##
         #
        ##
       ###
      ####
     #####
    ######
   #######
  ########
 #########
##########
#

julien@ubuntu:~/$ ./10-triangles | tr ' ' . | cat -e
.#$
##$
.........#$
........##$
.......###$
......####$
.....#####$
....######$
...#######$
..########$
.#########$
##########$
#$
$
julien@ubuntu:~/$
```
**SOLVED**
```
#include "main.h"
/**
 * print_triangle - a func to print triangles by giving a num
 * @size: where is the num of triangle size
 * Return: tri
 */
void print_triangle(int size)
{
	int j, i, jj;

	if (size <= 0)
		_putchar('\n');

	for (j = 1; j <= size; j++)
	{
		for (jj = size - j; jj > 0; jj--)
			_putchar(' ');
		for (i = 1; i <= j; i++)
			_putchar('#');

		_putchar('\n');
	}
}
```
