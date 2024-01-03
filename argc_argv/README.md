# C - argc, argv
### Resources:
* [Arguments to main](https://intranet.hbtn.io/rltoken/ro9HSskzyAhNpzdcVhdVWw)
* [argc and argv](https://intranet.hbtn.io/rltoken/zjdRHZTL-ImDCnGuMfHYfA)
* [What does argc and argv mean?](https://intranet.hbtn.io/rltoken/RT0y1HPM-AChT_JQedpdaA)
* [how to compile with unused variables](https://intranet.hbtn.io/rltoken/GvQNF9qKoUuY1t0U1AsetA)
## Learning Objevtives
# C - argc and argv (argument count and argument vector)
**Arguments to main**\
provides a usuful oportunity to give parameters to programs. Typically, this facility is used to direct the way the program goes about it's task. It's particularly common to provide file names to a program through is arguments.\

`int main(int arc, char *argv[]);`\
 <br />
In **UNIX**, the exit estatus is used to indicate that a program completed successfully **(a zero value)** or some error occurred **(a non-zero vale).** The Standard has adopted this convention; `exit(0)` is used to return `success` to its host environment, any other value is used to indicate failure. if the host environment itself uses a different numbering convention, `exit` will do the necessary translation. Since the translation is implementation-defined, it is now considered better practice to use the values defined in `<stdlib.h>`: `EXIT_SUCCESS` and `EXIT_FAILURE`.\
<br />
### Arguments
* **argc:** Count of the arguments supplied to the program.
* **argv:** An array of pointers to the strings, its type is (almost) *array of pointer to `char`* 
* **NOTE:** `char *argv[]` and `char **argv` are equavalent. Remember too that when it is passed to a function, the name of an array is converted to the address of its first element.
<br />

### When a program starts, the arguments to main will have been initialized to meet the following conditions:
* `argc` is greater than zero
* `argv[argc]` is a null pointer
* `argv[0]` through to `argv[argc-1]` are pointers to strings whose meaning will be determined by the program.
* `argv[0]` will be a string containing the program's name or a null string if that is not available. Remaining elements of `argv` represent the arguments supplied to the program. In cases where there is only support for single-case characters, the contents of these strings will be supplied to the program in lower-case.
<br />

```
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	while(argc--)
		printf("%s\n", *argv++);
	exit(EXIT_SUCCESS);
}
```

Passing the arguments `abcde, text, hello` and the program name `show_args`\
![illustration of the code](https://publications.gbdirect.co.uk//c_book/figures/10.1.png) <br />
<br />
Each time that `argv` is incremented, it is stepped one item further along the array of arguments. Thus after the first iteration of the loop, argv will point to the pointer which in turn points to the `abcde` argument\
![second example of code](https://publications.gbdirect.co.uk//c_book/figures/10.2.png) <br />
<br />

```
$ show_args abcde text hello
show_args
abcde
text
hello
$
```

**The following program accept any number of command-line arguments and prints them out:**

```
#include <stdio.h>

int main (int argc, char argv[])
{
	int count;

	printf("This program was called with \"%s\".\n", argv[0]);

	if (argc > 1)
	{
		for (count = 1; count < argc; count++);
		{
			printf("argv[%d] = %s\n", count, argv[count]);
		}
	}
	else
	{
		printf("The command had no other arguments.\n");
	}
	return 0;
}
```

If you name your executable `fubar`, and call it with the command `/fubar a b c`, it will print out the following text:

```

This program was called with "./fubar".
argv[1] = a
argv[2] = b
argv[3] = c

```

### Best way to suppress 'Unused variables' warning are:
`(void)argc;` and `__attribute__((unused))` -> on main first declaration.
# Tasks
### 0. Write a program that prints its name, followed by a new line.

* If you rename the program, it will print the new name, without having to compile it again
* You should not remove the path before the name of the program
```
julien@ubuntu:~/argc, argv$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-whatsmyname.c -o mynameis
julien@ubuntu:~/argc, argv$ ./mynameis 
./mynameis
julien@ubuntu:~/argc, argv$ mv mynameis mynewnameis
julien@ubuntu:~/argc, argv$ ./mynewnameis 
./mynewnameis
julien@ubuntu:~/argc, argv$ 
```
**SOLVED**
```
#include <stdlib.h>
#include <stdio.h>
/**
 * main - program that prints its name, followed by a new line.
 * @argc: counter of args
 * @argv: args array
 * Return: 1
 */
int main(int argc, char **argv)
{
	printf("%s\n", argv[0]);
	(void)argc;
	return (0);
}
```
## 1. Write a program that prints the number of arguments passed into it.

* Your program should print a number, followed by a new line
```
julien@ubuntu:~/argc, argv$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-args.c -o nargs
julien@ubuntu:~/argc, argv$ ./nargs 
0
julien@ubuntu:~/argc, argv$ ./nargs hello
1
julien@ubuntu:~/argc, argv$ ./nargs "hello, world"
1
julien@ubuntu:~/argc, argv$ ./nargs hello, world
2
julien@ubuntu:~/argc, argv$ 
```
**SOVED**
```
#include <stdlib.h>
#include <stdio.h>
/**
 * main - func to return int of argv
 * @argc: counter to int
 * @argv: array of arguments
 * Return: 1
 */
int main(int argc, char **argv)
{
	printf("%d\n", argc - 1);
	(void)**argv;
	return (EXIT_SUCCESS);
}
```
## 2. Write a program that prints all arguments it receives.

* All arguments should be printed, including the first one
* Only print one argument per line, ending with a new line
```
julien@ubuntu:~/argc, argv$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-args.c -o args
julien@ubuntu:~/argc, argv$ ./args 
./args
julien@ubuntu:~/argc, argv$ ./args You can do anything, but not everything.
./args
You
can
do
anything,
but
not
everything.
julien@ubuntu:~/argc, argv$ 
```
**SOLVED**
```
#include <stdio.h>
#include <stdlib.h>
/**
 * main - print arguments
 * @argc: int of argv
 * @argv: arguments
 * Return: 1
 */
int main(int argc, char **argv)
{
	int i = 0;

	while (i != argc)
	{
		printf("%s\n", *(argv + i));
		i++;
	}
	return (EXIT_SUCCESS);
}
```
## 3. Write a program that multiplies two numbers.

* Your program should print the result of the multiplication, followed by a new line
* You can assume that the two numbers and result of the multiplication can be stored in an integer
* If the program does not receive two arguments, your program should print `Error`, followed by a new line, and return `1`
```
julien@ubuntu:~/argc, argv$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-mul.c -o mul
julien@ubuntu:~/argc, argv$ ./mul 2 3
6
julien@ubuntu:~/argc, argv$ ./mul 2 -3
-6
julien@ubuntu:~/argc, argv$ ./mul 2 0
0
julien@ubuntu:~/argc, argv$ ./mul 245 3245342
795108790
julien@ubuntu:~/argc, argv$ ./mul
Error
julien@ubuntu:~/argc, argv$ 
```
**SOLVED**
```
#include <stdio.h>
#include <stdlib.h>
/**
 * main - a func to mul two numbers
 * @argc: counter of int on argv
 * @argv: arguments
 * Return: The result and \n, if is not 2 arg, print: error, return 1
 */
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int res, den, mul;

		den = atoi(argv[1]);
		mul = atoi(argv[2]);
		res = den * mul;
		printf("%d\n", res);
		return (0);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (EXIT_SUCCESS);
}
```
## 4. Write a program that adds positive numbers.

* Print the result, followed by a new line
* If no number is passed to the program, print `0`, followed by a new line
* If one of the number contains symbols that are not digits, print `Error`, followed by a new line, and return `1`
* You can assume that numbers and the addition of all the numbers can be stored in an `int`
```
julien@ubuntu:~/argc, argv$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-add.c -o add
julien@ubuntu:~/argc, argv$ ./add 1 1
2
julien@ubuntu:~/argc, argv$ ./add 1 10 100 1000
1111
julien@ubuntu:~/argc, argv$ ./add 1 2 3 e 4 5
Error
julien@ubuntu:~/argc, argv$ ./add
0
julien@ubuntu:~/argc, argv$ 
```
**SOLVED**
```
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the addition of positive numbers,
 *        followed by a new line.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: If one of the numbers contains symbols that are non-digits - 1.
 *         Otherwise - 0.
 */
int main(int argc, char *argv[])
{
	int num, digit, sum = 0;

	for (num = 1; num < argc; num++)
	{
		for (digit = 0; argv[num][digit]; digit++)
		{
			if (argv[num][digit] < '0' || argv[num][digit] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		sum += atoi(argv[num]);
	}

	printf("%d\n", sum);

	return (0);
}
```
