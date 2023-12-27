# C - Variadic functions
### Resources
* [stdarg.h](https://intranet.hbtn.io/rltoken/gyP9q81fzXR7FIeHScaKyw)
* [Variadic Functions](https://intranet.hbtn.io/rltoken/PY9dOZHn7a5M9suR-0j1yQ)
* [Const Keyword](https://intranet.hbtn.io/rltoken/8IGI7fBTuIOm1T-2BAUDIg)
## Learning Objectives
* What are variadic functions
	* ISO C defines a syntax for declaring a func to take a var num or type of arguments (Also known as varargs or variadic functions) However, the language itself provides no mechanism for such functions to access their non-required arguments; instead, you use the variable arggguments macros defined in `stdarg.h`
## Why they are used
Ordinary C functions take a fixed number of arguments. But, some func perform operatios that can meaningfully accept an unlimited number of arguments<br />
In some cases a function can handle any number of values by operating on all of them as a block. For example, consider a function that allocates a one-dimensional array with malloc to hold a specified set of values. This operation makes sense for any number of values, as long as the length of the array corresponds to that number. Without facilities for variable arguments, you'll have to define a separate func for each possible array size.<br />
The library fucn `printf` is an example of another class of function where variable arguments are usuful. This func prints its arguments **These are good reasons to define a variadic function which can handle as many arguments as the caller chooses to pass**
## How variadic functions are defined and used
**Defining and using a variadic function involves three steps:**
* Define the function as variadic, using an ellipsis `...` in the argument list, and using special macros to access the variable arguments. See [Receiving the Argument values](https://www.gnu.org/software/libc/manual/html_node/Receiving-Arguments.html). <br />
	* ordinary arguments have unique names, but optional arguments have nothing but `...` **How can you access them?** | The only way to access them is sequentially, in the order they were written, and you must use special macros from `stdarg.h` in the following three step process:
	1. Initialize an argument pointer variable of type `va_list` using `va_start`. The argument pointer when initialized points to the first optional argument.
	2. You access the opional arguments by successive calls to `va_arg` The first call to `va_arg` gives you the first optional argument, the next call gives you the second, and so on.
	3. You indicate that you are finished with the argument pointer variale by calling `va_end`
* Declare the function as variadic, using a prototype with allipsis `...` in all the files which call it. See [Syntax for Variable Arguments](https://www.gnu.org/software/libc/manual/html_node/Variadic-Prototypes.html).<br />
	* A func that accepts a variable number of arguments must be declared with a prototype that says so. You write the fixed arguments as usual, and then tack on `...` to indicate the possibility of additional arguments. The syxtax of ISO C requires at least one fixed argument before the `...`:
```
int func (const char *a, int b, ...)
{
	
}
```
defines a `func` which returns an int and takes two required arguments, a `const char *` and an `int`. These are followed by any number of anonymous arguments<br />
**Portability Note:** For some C compilers, the last required argument must not be declared `register` i the func definition. Furthermore, this argument’s type must be self-promoting: that is, the default promotions must not change its type. This rules out array and function types, as well as float, char (whether signed or not) and short int (whether signed or not). This is actually an ISO C requirement.
* Call the func by writing the fixed arguments followed by the additional variable arguments See [Calling variadic Func](https://www.gnu.org/software/libc/manual/html_node/Calling-Variadics.html).
	* In principle, functions that are defined to be variadic must also be declared to be variadic using a function prototype whenever you call them.<br />
## stdarg.h
`stdarg.h` is a header in the that allows functios to accept an **indefinite number of arguments**, it provides facilities for stteping through a list of function arguments of unknown number and type.<br />

### std::va_list
**typedef /* unspecified */ va_list;**
va_list is a complete object type (in practice, a unique built-in type or `char*`) suitable for holding the information needed by the macros `va_start`, `va_copy`, ``va_arg`, and `va_end`.<br />
If a `va_list` instance is created, passed to another function and used vi `va_arg` in that function, then any subsequent use in the calling function should be preceded by a call to `va_end`<br />
It is legal to pass a pointer to a `va_list` object to another function and then use that object after the function returns.<br />
* **va_start**: enables access to variadic function arguments
* **va_copy**: makes a copy of the variadic function arguments
* **va_arg**: accesses the next variadic function arguments
* **va_end**: ends traversal of the variadic function arguments
```
#include <stdio.h>
#include <stdarg.h>

/* print all args one at a time until a negative argument is seen;
   all args are assumed to be of int type */
void printargs(int arg1, ...)
{
  va_list ap;
  int i;

  va_start(ap, arg1); 
  for (i = arg1; i >= 0; i = va_arg(ap, int))
    printf("%d ", i);
  va_end(ap);
  putchar('\n');
}

int main(void)
{
   printargs(5, 2, 14, 84, 97, 15, -1, 48, -1);
   printargs(84, 51, -1, 3);
   printargs(-1);
   printargs(1, -1);
   return 0;
}
```
This program yields the output:
```
5 2 14 84 97 15
84 51

1
```
## 0. Write a function that returns the sum of all its parameters.

* Prototype: `int sum_them_all(const unsigned int n, ...);`
* If `n == 0`, return `0`
```
julien@ubuntu:~/0x0f. variadic functions$ cat 0-main.c
#include <stdio.h>
#include "variadic_functions.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int sum;

    sum = sum_them_all(2, 98, 1024);
    printf("%d\n", sum);
    sum = sum_them_all(4, 98, 1024, 402, -1024);
    printf("%d\n", sum);    
    return (0);
}
julien@ubuntu:~/0x0f. variadic functions$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-sum_them_all.c -o a
julien@ubuntu:~/0x0f. variadic functions$ ./a 
1122
500
julien@ubuntu:~/0x0f. variadic functions$ 
```
**SOLVED**
```
#include "variadic_functions.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * sum_them_all - sum all the args
 * @n: a num
 * Return: the sum of all
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list MoArg;
	unsigned int i, add = 0;
	/* set the start of infinite arg list */
	va_start(MoArg, n);
	for (i = 0; i < n; i++)
	{
		if (n == 0)
			return (0);

		add += va_arg(MoArg, int);
	}
	va_end(MoArg);
	return (add);
}
```
## 1. Write a function that prints numbers, followed by a new line.

* Prototype: `void print_numbers(const char *separator, const unsigned int n, ...);`
* where `separator` is the string to be printed between numbers
* and `n` is the number of integers passed to the function
* You are allowed to use `printf`
* If `separator` is `NULL`, don’t print it
* Print a new line at the end of your function
```
julien@ubuntu:~/0x0f. variadic functions$ cat 1-main.c
#include "variadic_functions.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_numbers(", ", 4, 0, 98, -1024, 402);
    return (0);
}
julien@ubuntu:~/0x0f. variadic functions$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-print_numbers.c -o b
julien@ubuntu:~/0x0f. variadic functions$ ./b
0, 98, -1024, 402
julien@ubuntu:~/0x0f. variadic functions$ 
```
**SOLVED**
```
#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_numbers - func to print nums
 * @separator: string
 * @n: num of arg
 * Return: printed nums
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list MoArg;
	unsigned int i;

	va_start(MoArg, n);

	for (i = 0; i < n; i++)
	{
		if (1 + i == n)
			printf("%d", va_arg(MoArg, int));
		else if (separator == NULL)
			printf("%d", va_arg(MoArg, int));
		else
			printf("%d%s", va_arg(MoArg, int), separator);
	}
	putchar('\n');
}
```
## 2. Write a function that prints strings, followed by a new line.

* Prototype: `void print_strings(const char *separator, const unsigned int n, ...);`
* where `separator` is the string to be printed between the strings
* and `n` is the number of strings passed to the function
* You are allowed to use `printf`
* If separator is NULL, don’t print it
* If one of the string is NULL, print `(nil)` instead
* Print a new line at the end of your function
```
julien@ubuntu:~/0x0f. Variadic functions$ cat 2-main.c
#include "variadic_functions.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_strings(", ", 2, "Jay", "Django");
    return (0);
}
julien@ubuntu:~/0x0f. Variadic functions$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-print_strings.c -o c
julien@ubuntu:~/0x0f. Variadic functions$ ./c 
Jay, Django
julien@ubuntu:~/0x0f. Variadic functions$ 
```
**SOLVED**
```
#include <stdarg.h>
#include "variadic_functions.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_strings - a func to print strings
 * @separator: a string
 * @n: num of args
 * Return: a string
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
		unsigned int i;
		va_list MoArg;

		va_start(MoArg, n);

		for (i = 0; i < n; i++)
		{	/* Convert to char from Int*/
			char *c = va_arg(MoArg, char *);

			if (c != NULL)
				printf("%s", c);
			else
				printf("(nil)");


			if (separator != NULL && i < n - 1)
				printf("%s", separator);
		}
		va_end(MoArg);
		putchar('\n');
}
```
## 3. Write a function that prints anything.

* Prototype: `void print_all(const char * const format, ...);`
* where `format` is a list of types of arguments passed to the function
	* c: char
	* i: integer
	* f: float
	* s: char * (if the string is NULL, print (nil) instead
	* any other char should be ignored
	* see example
* You are not allowed to use `for`, `goto`, ternary operator, `else`, `do ... while`
* You can use a maximum of
	* 2 `while` loops
	* 2 `if`
* You can declare a maximum of `9` variables
* You are allowed to use `printf`
* Print a new line at the end of your function
```
julien@ubuntu:~/0x0f. Variadic functions$ cat 3-main.c
#include "variadic_functions.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_all("ceis", 'B', 3, "stSchool");
    return (0);
}
julien@ubuntu:~/0x0f. Variadic functions$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-print_all.c -o d
julien@ubuntu:~/0x0f. Variadic functions$ ./d 
B, 3, stSchool
julien@ubuntu:~/0x0f. Variadic functions$ 
```
**SOLVED**
```
#include "variadic_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
/**
 * print_all - a func that prints anything
 * @format: struct of format
 * Return: anything
 */
void print_all(const char * const format, ...)
{
	int i, cnt = 0;
	char c;
	float f;
	char *s;
	va_list MoArg;

	va_start(MoArg, format);
	while (format && format[cnt] != '\0')
	{
		switch (format[cnt])
		{
			case 'c':
				c = va_arg(MoArg, int);
				printf("%c", c);
				break;
			case 'i':
				i = va_arg(MoArg, int);
				printf("%d", i);
				break;
			case 'f':
				f = va_arg(MoArg, double);
				printf("%f", f);
				break;
			case 's':
				s = va_arg(MoArg, char*);
				printf("%s", s ? s : "(nil)");
				break;
			default:
				cnt++;
				continue;
		}
		if (format[cnt + 1])
			printf(", ");
		cnt++;
	}
	va_end(MoArg);
	putchar('\n');
}
```
