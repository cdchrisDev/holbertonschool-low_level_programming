# C - preprocessor
### Resources
* [Understanding C program Compilation process](https://intranet.hbtn.io/rltoken/YExZqwaYLppKtBK4Hr8Iyw)
* [Object-like Macros](https://intranet.hbtn.io/rltoken/YNfygjrLQsvIHp6fKY1CjA)
* [Pre processor directives in C](https://intranet.hbtn.io/rltoken/UwGCIuJ59QfBvL1qceYLwQ)
* [The C preprocessor](https://intranet.hbtn.io/rltoken/AshKZEhWCXUi7gHtOweOwQ)
* [Standard predefined Macros](https://intranet.hbtn.io/rltoken/efZkS0ixSSw5sKvEoBPlFA)
* [include guard](https://intranet.hbtn.io/rltoken/X5wONSZbaYNg_7KTIRarFA)
* [Common predefined Macros](https://intranet.hbtn.io/rltoken/RTJL9iYjkXCAX1czVTthKw)
## Learning Objectives
* What are macros and how to use them
	* A macro is an action or a set of actions that you can run as many times as you want. When you create a macro, you are recording your mouse clicks and keystrokes. After you create a macro, you can edit it to make minor changes to the way it works.<br />

* What are the most common predefined macros
	* [These](https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html)<br />

* How to include guard your header files
	* `#ifndef HEADER_FILE`<br /> `define HEADER_FILE`<br /> `#endif`
## 0. Create a header file that defines a macro named `SIZE` as an abbreviation for the token `1024`.
```
julien@ubuntu:~/0x0c. macro, structures$ cat 0-main.c
#include "0-object_like_macro.h"
#include "0-object_like_macro.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int s;

    s = 98 + SIZE;
    printf("%d\n", s);
    return (0);
}
julien@ubuntu:~/0x0c. macro, structures$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c -o a
julien@ubuntu:~/0x0c. macro, structures$ ./a 
1122
julien@ubuntu:~/0x0c. macro, structures$ 
```
**SOLVED**
```
#ifndef SIZE
#define SIZE 1024

#endif
```
## 1. Create a header file that defines a macro named `PI` as an abbreviation for the token `3.14159265359`.
```
julien@ubuntu:~/0x0c. macro, structures$ cat 1-main.c
#include "1-pi.h"
#include "1-pi.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    float a;
    float r;

    r = 98;
    a = PI * r * r;
    printf("%.3f\n", a);
    return (0);
}
julien@ubuntu:~/0x0c. macro, structures$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c -o b
julien@ubuntu:~/0x0c. macro, structures$ ./b
30171.855
julien@ubuntu:~/0x0c. macro, structures$ 
```
**SOLVED**
```
#ifndef PI
#define PI 3.14159265359

#endif
```
## 2. Write a program that prints the name of the file it was compiled from, followed by a new line.

* You are allowed to use the standard library
```
julien@ubuntu:~/0x0c. macro, structures$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c -o c
julien@ubuntu:~/0x0c. macro, structures$ ./c 
2-main.c
julien@ubuntu:~/0x0c. macro, structures$ cp 2-main.c 02-main.c
julien@ubuntu:~/0x0c. macro, structures$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 02-main.c -o cc
julien@ubuntu:~/0x0c. macro, structures$ ./cc
02-main.c
julien@ubuntu:~/0x0c. macro, structures$ 
```
**SOLVED**
```
#include <stdio.h>
/**
 * main - entry point
 *
 *
 * Return: the name of the compiled file
 */
int main(void)
{
	printf(__BASE_FILE__);
	putchar('\n');

	return (0);
}
```
## 3. Write a function-like macro `ABS(x)` that computes the absolute value of a number `x`.
```
#include <stdio.h>
#include "3-function_like_macro.h"
#include "3-function_like_macro.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int i;
    int j;

    i = ABS(-98) * 10;
    j = ABS(98) * 10;
    printf("%d, %d\n", i, j);
    return (0);
}
julien@ubuntu:~/0x0c. macro, structures$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c -o d
julien@ubuntu:~/0x0c. macro, structures$ ./d 
980, 980
julien@ubuntu:~/0x0c. macro, structures$ 
```
**SOLVED**
```
#ifndef _HEADER_
#define _HEADER_
#define ABS(x) ((x) < 0 ? ((x) * -1) : (x)) \

#endif
```
## 4. Write a function-like macro `SUM(x, y)` that computes the sum of the numbers `x` and `y`.
```
julien@ubuntu:~/0x0c. macro, structures$ cat 4-main.c
#include <stdio.h>
#include "4-sum.h"
#include "4-sum.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int s;

    s = SUM(98, 1024);
    printf("%d\n", s);
    return (0);
}
julien@ubuntu:~/0x0c. macro, structures$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c -o e
julien@ubuntu:~/0x0c. macro, structures$ ./e 
1122
julien@ubuntu:~/0x0c. macro, structures$ 
```
**SOLVED**
```
#ifndef _HEADER_
#define _HEADER_
#define SUM(x, y) (x + y)

#endif
```
