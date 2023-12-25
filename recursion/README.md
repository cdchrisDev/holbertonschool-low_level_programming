# C - Recursion
### Resources
* [Recursion, introduction](https://intranet.hbtn.io/rltoken/RZZmKmQJAnyqS_Ci1fFy2A)
* [What on Earth is Recursion?](https://intranet.hbtn.io/rltoken/2W6GbB5XNktHDrjqoRPy2g)
* [C - Recursion](https://intranet.hbtn.io/rltoken/DC8k2o4fIaE379ozY_Gl1A)
* [C Programming Tutorial 85, Recursion pt.1](https://intranet.hbtn.io/rltoken/z4N9mWZKHoonkjFmeA2moA)
* [C Programming Tutorial 86, Recursion pt.2](https://intranet.hbtn.io/projects/2158#:~:text=C%20Programming%20Tutorial%2086%2C%20Recursion%20pt.2)
## Learning Objectives
* What is recursion
	* def: the repeated application of a recursive procedure or definition.
	* wiki: In computer science, recursion is a method of solving a computational problem where the solution depends on solutions to smaller instances of the same problem.<br />

* How to implement recursion
	* Recursion solves such recursive problems by using functions that call themselves from within their own code<br />

* In what situations you should implement recursion
	* Recursive functions are appropriate for use cases where a problem can be broken down into smaller, similar sub-problems that can be solved in a similar manner<br />

* In what situations you should not implement recursion
	* Iterative algorithms: These algorithms use loops to iterate through a problem and solve it without recursion. ...
	* Dynamic programming: This technique involves breaking a problem down into smaller subproblems and solving them in a bottom-up manner, without recursion.
<br />
## 0. Write a function that prints a string, followed by a new line.

* Prototype: `void _puts_recursion(char *s);`
**FYI**: The standard library provides a similar function: `puts`. Run `man puts` to learn more.
```
julien@ubuntu:~/Recursion$ cat 0-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    _puts_recursion("Puts with recursion");
    return (0);
}
julien@ubuntu:~/Recursion$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 0-main.c 0-puts_recursion.c -o 0-puts_recursion
julien@ubuntu:~/Recursion$ ./0-puts_recursion 
Puts with recursion
julien@ubuntu:~/Recursion$ 
```
**SOLVED**
```
#include <stdlib.h>
#include "main.h"
/**
 * _puts_recursion - a func to print a string, followed newline
 * @s: a char
 * Return: 0
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}
	_putchar(*s);
	_puts_recursion(s + 1);
}
```
## 1. Write a function that prints a string in reverse.

* Prototype: `void _print_rev_recursion(char *s);`
```
julien@ubuntu:~/Recursion$ cat 1-main.c
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    _print_rev_recursion("\nColton Walker");
    return (0);
}
julien@ubuntu:~/Recursion$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 1-main.c 1-print_rev_recursion.c -o 1-print_rev_recursion
julien@ubuntu:~/Recursion$ ./1-print_rev_recursion 
reklaW notloC
julien@ubuntu:~/Recursion$ 
```
**SOLVED**
```
#include <stdio.h>
#include "main.h"
/**
 * _print_rev_recursion - print a string in reverse
 * @s: a string
 * Return: the reversed string
 */
void _print_rev_recursion(char *s)
{
	if (*s)
  	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
```
## 2. Write a function that returns the length of a string.

* Prototype: `int _strlen_recursion(char *s);`
**FYI**: The standard library provides a similar function: `strlen`. Run `man strlen` to learn more.
```
Write a function that returns the length of a string.

Prototype: int _strlen_recursion(char *s);
FYI: The standard library provides a similar function: strlen. Run man strlen to learn more.

julien@ubuntu:~/Recursion$ cat 2-main.c 
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

    n = _strlen_recursion("Corbin Coleman");
    printf("%d\n", n);
    return (0);
}
julien@ubuntu:~/Recursion$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89  2-main.c 2-strlen_recursion.c -o 2-strlen_recursion
julien@ubuntu:~/Recursion$ ./2-strlen_recursion 
14
julien@ubuntu:~/Recursion$ 
```
**SOLVED**
```
#include "main.h"
/**
 * _strlen_recursion - a func to print the length of a string
 * @s: a string
 * Return: the length of a string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	/* Increase by 1 each time func is called without assignment */
	return (1 + _strlen_recursion(s + 1));
}
```
## 3.  Write a function that returns the factorial of a given number.

* Prototype: `int factorial(int n);`
* If `n` is lower than `0`, the function should return `-1` to indicate an error
* Factorial of `0` is `1`
```
julien@ubuntu:~/Recursion$ cat 3-main.c
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

    r = factorial(1);
    printf("%d\n", r);
    r = factorial(5);
    printf("%d\n", r);
    r = factorial(10);
    printf("%d\n", r);
    r = factorial(-1024);
    printf("%d\n", r);
    return (0);
}
julien@ubuntu:~/Recursion$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-factorial.c -o 3-factorial
julien@ubuntu:~/Recursion$ ./3-factorial 
1
120
3628800
-1
julien@ubuntu:~/Recursion$
```
**SOLVED**
```
#include "main.h"
/**
 * factorial - a func that return factorial of a num
 * @n: a num
 * Return: -1 if is lower (error) - fact' of 0 is 1
 */
int factorial(int n)
{
	if (n == 0)
		return (1);
	else if (n < 0)
		return (-1);
	else
		return (n * factorial(n - 1));
}
```
## 4. Write a function that returns the value of x raised to the power of y.

* Prototype: `int _pow_recursion(int x, int y);`
* If y is lower than `0`, the function should return `-1`
**FYI**: The standard library provides a different function: `pow`. Run `man pow` to learn more.
```
julien@ubuntu:~/Recursion$ cat 4-main.c
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

    r = _pow_recursion(1, 10);
    printf("%d\n", r);
    r = _pow_recursion(1024, 0);
    printf("%d\n", r);
    r = _pow_recursion(2, 16);
    printf("%d\n", r);
    r = _pow_recursion(5, 2);
    printf("%d\n", r);
    r = _pow_recursion(5, -2);
    printf("%d\n", r);
    r = _pow_recursion(-5, 3);
    printf("%d\n", r);
    return (0);
}
julien@ubuntu:~/Recursion$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 4-pow_recursion.c -o 4-pow
julien@ubuntu:~/Recursion$ ./4-pow 
1
1
65536
25
-1
-125
julien@ubuntu:~/Recursion$ 
```
**SOLVED**
```
#include "main.h"
/**
 * _pow_recursion - a func to return x raised to the power of y
 * @x: base
 * @y: exponent
 * Return: the result
 */
int _pow_recursion(int x, int y)
{
	int res = x;

	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);

	res *= _pow_recursion(x, y - 1);
	return (res);
}
```
## 5. Write a function that returns the natural square root of a number.

* Prototype: `int _sqrt_recursion(int n);`
* If `n` does not have a natural square root, the function should return `-1`
**FYI**: The standard library provides a different function: `sqrt`. Run `man sqrt` to learn more.
```
julien@ubuntu:~/Recursion$ cat 5-main.c 
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

    r = _sqrt_recursion(1);
    printf("%d\n", r);
    r = _sqrt_recursion(1024);
    printf("%d\n", r);
    r = _sqrt_recursion(16);
    printf("%d\n", r);
    r = _sqrt_recursion(17);
    printf("%d\n", r);
    r = _sqrt_recursion(25);
    printf("%d\n", r);
    r = _sqrt_recursion(-1);
    printf("%d\n", r);
    return (0);
}
julien@ubuntu:~/gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 5-sqrt_recursion.c -o 5-sqrt
julien@ubuntu:~/Recursion$ ./5-sqrt 
1
32
4
-1
5
-1
julien@ubuntu:~/Recursion$ 
```
**SOLVED**
```
#include "main.h"

int _sqrt(int n, int i);

/**
 * _sqrt_recursion - return the natural square root of a num
 * @n: a num
 * Return: result
 */
int _sqrt_recursion(int n)
{
	return (_sqrt(n, 1));
}
/**
 * _sqrt - Calculate natural square root
 * @n: num
 * @i: iterator
 * Return: 0;
 */
int _sqrt(int n, int i)
{
	int sqrt = i * i;

	if (sqrt > n)
		return (-1);

	if (sqrt == n)
		return (i);

	return (_sqrt(n, i + 1));
}
```
## 6. Write a function that returns 1 if the input integer is a [prime number](https://en.wikipedia.org/wiki/Prime_number), otherwise return 0.

* Prototype: `int is_prime_number(int n);`
```
julien@ubuntu:~/Recursion$ cat 6-main.c
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

    r = is_prime_number(1);
    printf("%d\n", r);
    r = is_prime_number(1024);
    printf("%d\n", r);
    r = is_prime_number(16);
    printf("%d\n", r);
    r = is_prime_number(17);
    printf("%d\n", r);
    r = is_prime_number(25);
    printf("%d\n", r);
    r = is_prime_number(-1);
    printf("%d\n", r);
    r = is_prime_number(113);
    printf("%d\n", r);
    r = is_prime_number(7919);
    printf("%d\n", r);
    return (0);
}
julien@ubuntu:~/Recursion$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 6-main.c 6-is_prime_number.c -o 6-prime
julien@ubuntu:~/Recursion$ ./6-prime 
0
0
0
1
0
0
1
1
julien@ubuntu:~/Recursion$ 
```
**SOLVED**
```
#include "main.h"
/**
 * _div - check if n is divisible by 2
 * @n: a num
 * @div: divided by
 * Return: 1 if its prime, 0 if its not
 */
int _div(int n, int div)
{
	if (n % div == 0)
		return (0);

	if (div == n / 2)
		return (1);

	return (_div(n, div + 1));
}
/**
 * is_prime_number - check if its prime
 * @n: a num
 * Return: 1 if its prime and 0 if not
 */
int is_prime_number(int n)
{
	int div = 2;

	if (n <= 1)
		return (0);
	if (n >= 2 && n <= 3)
		return (1);

	return (_div(n, div));
}
```
