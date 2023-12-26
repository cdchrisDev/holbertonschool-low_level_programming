## C - argc, argv
### Resources:
* [Arguments to main](https://intranet.hbtn.io/rltoken/ro9HSskzyAhNpzdcVhdVWw)
* [argc and argv](https://intranet.hbtn.io/rltoken/zjdRHZTL-ImDCnGuMfHYfA)
* [What does argc and argv mean?](https://intranet.hbtn.io/rltoken/RT0y1HPM-AChT_JQedpdaA)
* [how to compile with unused variables](https://intranet.hbtn.io/rltoken/GvQNF9qKoUuY1t0U1AsetA)
## Learning Objevtives
## C - argc and argv (argument count and argument vector)
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
### 0. 
