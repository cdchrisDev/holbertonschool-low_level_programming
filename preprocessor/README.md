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
# Object-like Macros
a simple identifier which will be replaced by code. They're used to create symbolic names to numeric constats<br />
Using `#define` keyword and then any name (ussually on UPPPERCASE) we create a macro<br />
`#define BUFFER_SIZE 1024` --> defines macro name as `BUFFER_SIZE` as an abbreviation for the token 1024<br />
<br />
`(foo = (char *)malloc(BUFFER_SIZE)) == (foo = (char *)malloc(1024));`<br />
<br />
The macro's body end at the end of the `#define` line. You may continue the definition onto multiple lines, if necessary, using backslash-newline<br />
```
#define NUMBERS 1, \
		2, \
		3
int x[] = { NUMBERS };
	=> int x[] = { 1, 2, 3};
```
When the preproessor expands a macro name, the macro's expansion the macro invocation, then the expansion is examinated for more macros to expand
```
#define TABLESIZE BUFSIZE
#define BUFSIZE 1024
```
## Macro arguments
To define a macro that uses arguments, insert them between the pair of paretheses in the macro definition\
As an example, here is a macro that computes the minimum of two numeric values, as it is defined in many C programs, and some uses.
```
#define min(x, y)	((x) < (y) ? (x) : (y))
x = min(a, b);  ==> x = ((a) < (b) ? (a) : (B));
y = min(1, 2);  ==> y = ((1) < (2) ? (1) : (2));
z = min(a + 28, *p); ==> z = ((a + 28) < (*p) ? (a + 28) : (*p));
```
there is no requirement for square brackets or braces to balance, and they do not prevent a comma from separating arguments\
`macro (array[x = y, x +  1])`<br />
<br />
For example, `min (min (a, b) c)` if first expanded to\
`min (((a) < (b) ? (a) : (b)), (c))`<br />
<br />
and then to
```
((((a) < (b) ? (a) : (b))) < (c))
? (((a) < (b) ? (a) : (b)))
: (c))
```
(Line breaks shown here for clarity would not actually be generated)<br />
You can leave macro arguments empty; this is not an error to the preprocessor
```
     min(, b)        ==> ((   ) < (b) ? (   ) : (b))
     min(a, )        ==> ((a  ) < ( ) ? (a  ) : ( ))
     min(,)          ==> ((   ) < ( ) ? (   ) : ( ))
     min((,),)       ==> (((,)) < ( ) ? ((,)) : ( ))
     
     min()      error--> macro "min" requires 2 arguments, but only 1 given
     min(,,)    error--> macro "min" passed 3 arguments, but takes just 2
```
Whitespace is not preprocessing token, so if a macro `foo` takes one argument `foo()` and `foo ( )` both supply and empty argument.\
## Conditional Compilation
* They include `#if, #elif, #ifdef, #else, #ifndef`
* `#if, #elif, #else, #ifdef, #ifndef` must be terminated with a closing `#endif`
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
