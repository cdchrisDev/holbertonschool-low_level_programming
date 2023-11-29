# This is the holberton low level programming  repository

## C Static Libraries
As our programs get larger and complex is necesary to delegate pieces of code to more smaller components to work with. It is better to manipulate tiny and lighter pieces than manipulate a big and havier

**What is a "C" Library? What is good for?**\
Are just collections of objects files that are linked only during the linking phase of compilation, and are not relevant during runtime. (just the executable is needed)

In the compilation time both are either linked into the program or one of its share libraries. However, the object files from the dynamic library are not inserted into the executable file. Instead, when the program is started, a program in the system `dynamic loader` checks out which shared libraries were linked with the program, loads them to memory and attaches them to the copy of the program in memory\
But, if we re-compile  the dynamic library and try to run a second copy of our program with the new library, we'll soon get stuck - `dynamic library` soon will find the copy of the library is already stored in memory, and thus will attach it to our program, and not load the new (modified) version from the disk\

**Creating A Static "C" Library Using "ar" and "ranlib"**\
`ar` for `archiver` Create **Static Libraries** *which are actually archive files*\
\
-> `ar rc libutil.a util_file.o util_net.o util_math.o`\
\
This command creates a static library named `libutil.a` and puts copies of the object files `util_file.o`, `util_net.o` and `util_math.o` in it. If the library file already exists, it has the object files added to it, or replaced, if they are newer than those inside the library. The `c` flag tells ar to create the library if it doesn't already exist. The `r` flag tells it to replace older object files in the library, with the new object files.\
\
\
**After a archive is created or modified.** There is a need to *index* it. This *index* is latter used by the compiler to speed up symbol-lookup inside the library, and make sure that the order of the symbols in the library won't matter during compilation\
\
-> `ranlib lilbutil.a`\
\
**Note:** when an archive file's index generation date (stored inside the archive file) is older than the file's last modification date (stored in the file system), a compiler trying to use this library will complain its index is out of date, and abort. There are two ways to overcome the problem:\

* -> Use `ranlib` to re-generate the index.\

* When copying the archive file to another location, use `cp -p`, instead of only `cp`. The `-p` flag tells `cp` to keep all attributes of the file, including its access permissions, owner *(if `cp` is invoked by a superuser)* and its last modification date. This will cause the compiler to think the index inside the file is still updated. This method is useful for makefiles that need to copy the library to another directory for some reason.


**Using a "C" Library In A Program**\
\
-> `cc main.o -L. -lutil -o prog`\
\
This will create a program using object file `main.o`, and any symbols it requires from the `util` static library. Note that we omitted the `lib` prefix and the `.a` suffix when mentioning the library on the link command. The linker attaches these parts back to the name of the library to create a name of a file to look for. Note also the usage of the `-L` flag - this flag tells the linker that libraries might be found in the given directory (`'.'`, refering to the current directory), in addition to the standard locations where the compiler looks for system libraries.\

**Creating A Share "C" Library Using "ld"**\
Is similar to static. Compile a list of objects files, then insert them all into a shared library file. However, there are two major differences:\

1. > __Compile for "Position Independent Code__ **(CID)** - When the object files are generated, we have no idea where in memory they will be inserted in a program that will use them. Many different programs may use the same library, ans each load it into a different memory in address. Thus, we need that all jump calls (`goto`, in assembly speak) and subroutines calls will use relative in most compilers, this is done by specifying `-fPIC` or `-fpic` on the compilation command.
2. > __Library File Creation__ - unlike a static library, a shared library is not an archive file. It has a format that is specific to the architecture for which it is being created. Thus, we need to use the compiler (either the compiler's dirver, or its linker) to generate the library and tell it that it should create a shared library, not a final program file.

```
cc -fPIC -c util_file.c
cc -fPIC -c util_net.c
cc -fPIC -c util_math.c
cc -shared libutil.so util_file.o util_net.o util_math.o
```


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

### Best way to suppress 'Unused variables' warning

```
#ifdef UNUSED
#elif defined(__GNUC__)
# define UNUSED(x) UNUSED_ ## x __attribute__((unused))
#elif defined(__LCLINT__)
# define UNUSED(x) /*@unused@*/ x
#else
# define UNUSED(x) x
#endif

void dcc_mon_siginfo_handler(int UNUSED(whatsig))
```
