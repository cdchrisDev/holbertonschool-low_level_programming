# C - Functions, nested loops
### Resources 
* [Nested while loops](https://www.youtube.com/watch?v=Z3iGeQ1gIss&ab_channel=ZackAnnaTutorials)
* [C - Functions](https://www.tutorialspoint.com/cprogramming/c_functions.htm)
* [Learning how to program](https://www.youtube.com/watch?v=qMlnFwYdqIw&ab_channel=JonathanEngelsma) *(stop at 14:00)*
* [What is a function prototype](https://www.programiz.com/c-programming/c-user-defined-functions#:~:text=A%20function%20prototype%20is%20simply,be%20used%20in%20the%20program.)
* [What is the purpose of a function prototype?](https://www.geeksforgeeks.org/what-is-the-purpose-of-a-function-prototype/)
* [C - Header Files](https://www.tutorialspoint.com/cprogramming/c_header_files.htm)
# Tasks
## 0. Write a program that prints `_putchar`, followed by a new line.

The program should return `0`
```
julien@ubuntu:~/$  gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 0-putchar.c -o 0-putchar
julien@ubuntu:~/$ ./0-putchar 
_putchar
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * main - entry point
 * print putchar
 * Return: 0
 */

int main(void)
{
	_putchar(95);
	_putchar(112);
	_putchar(117);
	_putchar(116);
	_putchar(99);
	_putchar(104);
	_putchar(97);
	_putchar(114);
	_putchar(10);

	return (0);
}
```
## 1. Write a function that prints the alphabet, in lowercase, followed by a new line.

* Prototype: `void print_alphabet(void);`
* You can only use `_putchar` twice in your code
```
julien@ubuntu:~/$ cat 1-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_alphabet();
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 1-main.c 1-alphabet.c -o 1-alphabet
julien@ubuntu:~/$ ./1-alphabet 
abcdefghijklmnopqrstuvwxyz
julien@ubuntu:~/$
```
**SOLVED**
```
#include "main.h"
/**
 * print_alphabet - second called
 * a program to print alphabet
 * Return: 0
 */

void print_alphabet(void)
{
	int c;

	for (c = 'a'; c <= 'z'; c++)
		_putchar(c);

	_putchar('\n');
}
```
## 2. Write a function that prints 10 times the alphabet, in lowercase, followed by a new line.

* Prototype: `void print_alphabet_x10(void);`
* You can only use `_putchar` twice in your code
```
julien@ubuntu:~/$ cat 2-main.c
#include "main.h"

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
    print_alphabet_x10();
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 2-main.c 2-print_alphabet_x10.c -o 2-alphabet_x10
julien@ubuntu:~/$ ./2-alphabet_x10 
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * print_alphabet_x10 - 2th func
 * print all the letters of the alphabet 10 times
 * Return: 0
 */

void print_alphabet_x10(void)
{
	int i, c;

	i = 0;

	while (i < 10)
	{
		for (c = 'a'; c <= 'z'; c++)
			_putchar(c);

		i++;
		_putchar('\n');
	}
}
```
## 3. Write a function that checks for lowercase character.

* Prototype: `int _islower(int c);`
* Returns `1` if `c` is lowercase
* Returns `0` otherwise
**FYI:** The standard library provides a similar function: `islower`. Run `man islower` to learn more.
```
julien@ubuntu:~/$ cat 3-main.c 
#include "main.h"

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = _islower('H');
    _putchar(r + '0');
    r = _islower('o');
    _putchar(r + '0');
    r = _islower(108);
    _putchar(r + '0');
    _putchar('\n');
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 3-main.c 3-islower.c -o 3-islower
julien@ubuntu:~/$ ./3-islower 
011
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * _islower - 2th called func
 * A function to check for lowercase char
 * @c: a char
 * Return: 0
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);

	else
		return (0);
}
```
## 4. Write a function that checks for alphabetic character.

* Prototype: `int _isalpha(int c);`
* Returns `1` if `c` is a letter, lowercase or uppercase
* Returns `0` otherwise
**FYI:** The standard library provides a similar function: `isalpha`. Run `man isalpha` to learn more.
```
julien@ubuntu:~/$ cat 4-main.c 
#include "main.h"

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = _isalpha('H');
    _putchar(r + '0');
    r = _isalpha('o');
    _putchar(r + '0');
    r = _isalpha(108);
    _putchar(r + '0');
    r = _isalpha(';');
    _putchar(r + '0');
    _putchar('\n');
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 4-main.c 4-isalpha.c -o 4-isalpha
julien@ubuntu:~/$ ./4-isalpha 
1110
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * _isalpha - 2th func called
 * a program to check for chars
 * @c: a char
 * Return: 1 or 0
 */
int _isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);

	else if (c >= 'A' && c <= 'Z')
		return (1);

	else
		return (0);
}
```
## 5. Write a function that prints the sign of a number.

* Prototype: `int print_sign(int n);`
* Returns `1` and prints `+` if `n` is greater than zero
* Returns `0` and prints `0` if `n` is zero
* Returns `-1` and prints `-` if `n` is less than zero
```
julien@ubuntu:~/$ cat 5-main.c
#include "main.h"

/**
 * main - check the code.
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = print_sign(98);
    _putchar(',');
    _putchar(' ');
    _putchar(r + '0');
    _putchar('\n');
    r = print_sign(0);
    _putchar(',');
    _putchar(' ');
    _putchar(r + '0');
    _putchar('\n');
    r = print_sign(0xff);
    _putchar(',');
    _putchar(' ');
    _putchar(r + '0');
    _putchar('\n');
    r = print_sign(-1);
    _putchar(',');
    _putchar(' ');
    _putchar(r + '0');
    _putchar('\n');
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 5-main.c 5-sign.c -o 5-sign
julien@ubuntu:~/$ ./5-sign 
+, 1
0, 0
+, 1
-, /
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * print_sign - 2th func called
 * a func to check if its positive and negative and just print the sign
 * @n: a number
 * Return: a sign
 */
int print_sign(int n)
{
	int pos, neg;

	pos = 43;
	neg = 45;

	if (n > 0)
	{
		_putchar(pos);
		return (1);
	}
	else if (n < 0)
	{
		_putchar(neg);
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}
```
## 6. Write a function that computes the absolute value of an integer.

* Prototype: `int _abs(int);`
**FYI:** The standard library provides a similar function: `abs`. Run `man abs` to learn more.
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
    int r;

    r = _abs(-1);
    printf("%d\n", r);
    r = _abs(0);
    printf("%d\n", r);
    r = _abs(1);
    printf("%d\n", r);
    r = _abs(-98);
    printf("%d\n", r);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 6-main.c 6-abs.c -o 6-abs
julien@ubuntu:~/$ ./6-abs 
1
0
1
98
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * _abs - 2th func called
 * print the absolute value of a int
 * @n: a int
 * Return: 0 or -1
 */
int _abs(int n)
{
	if (n < 0)
	{
		return (n * -1);
	}
	else
	{
		return (n);
	}
}
```
## 7. Write a function that prints the last digit of a number.

* Prototype: `int print_last_digit(int);`
* Returns the value of the last digit
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
    int r;

    print_last_digit(98);
    print_last_digit(0);
    r = print_last_digit(-1024);
    _putchar('0' + r);
    _putchar('\n');
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 7-main.c 7-print_last_digit.c -o 7-last_digit
julien@ubuntu:~/$ ./7-last_digit 
8044
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * print_last_digit - 2th func called
 * a func to print the last digit of a number
 * @n: a int
 * Return: the value of the last digit
 */

int print_last_digit(int n)
{
	int j;

	if (n < 0)
	{
		j = (n % 10) * -1;

		_putchar(j + '0');
		return (j);
	}
	else
	{
		j = n % 10;

		_putchar(j + '0');
		return (j);
	}
}
```
## 8. Write a function that prints every minute of the day of Jack Bauer, starting from 00:00 to 23:59.

* Prototype: `void jack_bauer(void);`
* You can listen to this [soundtrack](https://www.youtube.com/watch?v=btAfXqgMkPs&ab_channel=Beko2095) while coding :)
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
    jack_bauer();
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 8-main.c 8-24_hours.c -o 8-24
julien@ubuntu:~/$ ./8-24 | head
00:00
00:01
00:02
00:03
00:04
00:05
00:06
00:07
00:08
00:09
julien@ubuntu:~/$ ./8-24 | tail
23:50
23:51
23:52
23:53
23:54
23:55
23:56
23:57
23:58
23:59
julien@ubuntu:~/$ ./8-24 | wc -l
1440
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * jack_bauer - second func called
 * print the jack bauer day
 * Return: 0
 */
void jack_bauer(void)
{
	int i;



	for (i = 0; i < 1440; i++)
	{
		_putchar(i / 60 / 10 + '0');
		_putchar(i / 60 % 10 + '0');
		_putchar(':');
		_putchar(i % 60 / 10 + '0');
		_putchar(i % 60 % 10 + '0');
	_putchar('\n');
	}
}
```
## 9. Write a function that prints the 9 times table, starting with 0.

* Prototype: `void times_table(void);`
* **Format:** see example
```
julien@ubuntu:~/$ cat 9-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    times_table();
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 9-main.c 9-times_table.c -o 9-times_table
ulien@ubuntu:~/$ ./9-times_table | cat -e
0,  0,  0,  0,  0,  0,  0,  0,  0,  0$
0,  1,  2,  3,  4,  5,  6,  7,  8,  9$
0,  2,  4,  6,  8, 10, 12, 14, 16, 18$
0,  3,  6,  9, 12, 15, 18, 21, 24, 27$
0,  4,  8, 12, 16, 20, 24, 28, 32, 36$
0,  5, 10, 15, 20, 25, 30, 35, 40, 45$
0,  6, 12, 18, 24, 30, 36, 42, 48, 54$
0,  7, 14, 21, 28, 35, 42, 49, 56, 63$
0,  8, 16, 24, 32, 40, 48, 56, 64, 72$
0,  9, 18, 27, 36, 45, 54, 63, 72, 81$
julien@ubuntu:~/$ ./9-times_table | tr ' ' . | cat -e
0,..0,..0,..0,..0,..0,..0,..0,..0,..0$
0,..1,..2,..3,..4,..5,..6,..7,..8,..9$
0,..2,..4,..6,..8,.10,.12,.14,.16,.18$
0,..3,..6,..9,.12,.15,.18,.21,.24,.27$
0,..4,..8,.12,.16,.20,.24,.28,.32,.36$
0,..5,.10,.15,.20,.25,.30,.35,.40,.45$
0,..6,.12,.18,.24,.30,.36,.42,.48,.54$
0,..7,.14,.21,.28,.35,.42,.49,.56,.63$
0,..8,.16,.24,.32,.40,.48,.56,.64,.72$
0,..9,.18,.27,.36,.45,.54,.63,.72,.81$
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * times_table - a function to print 9th table
 * @void: no parameters
 * Return: no return
 */

void times_table(void)
{
	int den, mul, result;

	for (den = 0; den < 10; den++)
	{

		for (mul = 0; mul < 10; mul++)
		{
			result = den * mul;
			/* result */
			if (result >= 0 && result <= 9)
				_putchar(result + '0');
			else
			{
				_putchar(result / 10 + '0');
				_putchar(result % 10 + '0');
			}
			/* identation */
			if (result + den >= 10 && mul != 9)
			{
				_putchar(',');
				_putchar(' ');
			}
			else if (result + den <= 10 && mul != 9)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
```
## 10. Write a function that adds two integers and returns the result.

* Prototype: `int add(int, int);`
```
julien@ubuntu:~/$ cat 10-main.c
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

    n = add(89, 9);
    printf("%d\n", n);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 10-main.c 10-add.c -o 10-add
julien@ubuntu:~/$ ./10-add 
98
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include "main.h"
/**
 * add - 2th called of func
 * add two numbers
 * @a: den
 * @b: mul
 * Return: int
 */

int add(int a, int b)
{
	int r = a + b;

	return (r);
}
```
## 11. Write a function that prints all natural numbers from n to 98, followed by a new line.

* Prototype: `void print_to_98(int n);`
* Numbers must be separated by a comma, followed by a space
* Numbers should be printed in order
* The first printed number should be the number passed to your function
* The last printed number should be `98`
* You are allowed to use the standard library
```
julien@ubuntu:~/$ cat 11-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_to_98(0);
    print_to_98(98);
    print_to_98(111);
    print_to_98(81);
    print_to_98(-10);
    return (0);
}
julien@ubuntu:~/$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 11-main.c 11-print_to_98.c -o 11-98
julien@ubuntu:~/$ ./11-98 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98
98
111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98
81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98
-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98
julien@ubuntu:~/$ 
```
**SOLVED**
```
#include <stdio.h>
#include "main.h"
/**
 * print_to_98 - 2th func called
 * a func to print natural numbers
 * @n: a int
 * Return: void
 */

void print_to_98(int n)
{
	while (n < 99 || n > 97)
	{
		if (n == 98)
		{
			printf("%d", n);
			break;
		}
		else if (n > 97 || n < 99)
		{
			printf("%d, ", n);
		}

		if (n > 97)
			n--;
		else if (n < 99)
			n++;
	}
	putchar('\n');
}
```
