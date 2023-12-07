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

### Best way to suppress 'Unused variables' warning are:
`(void)argc;` and `__attribute__((unused))` -> on main first declaration.

## Automatic and Dynamic Allocation, Malloc and free
The `malloc` function is used to allocate a certain amount of memory during the execution of a program. It will request a block of memory from the heap. If the request is granted, the system will reserve the requested amount of memory and malloc will return a pointer to the reserved space.\
when the amount of memory is not needed anymore, you must return it to the operating system by calling the function `free`.\
<br />
### Automatic allocation
Variable and strings memory have their location memory automatically assigned.

```
/**
 * cisfun - function used for concept introduction
 * @n1: number of projects
 * @n2: number of tasks
 *
 * Return: nothing.
 */
void cisfun(unsigned int n1, unsigned int n2)
{	/* arg and local var are stored auto in mem */
    int n;  /* when the func is called program reserve space and uses */
    char c;	/* so you don't have to worry about */
    int *ptr;
    char array[3];
}
```
<br />
![memory address](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/misc/2020/9/8ef868cec3c5d5ab7a025a3b964471f2e266a89c.PNG?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20231130%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20231130T171046Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=e678926c02aa130c9e406f88702017681fc04c65784bfce55a9493045bd30f8d)<br />

**Special case: String Literals**

```
char *str;
	
str = "School";
```

The string `"School"` that was just declared is stored automatically in memory when the program is launched. But, the memory that stores the string is only readable. In fact, if you try to change a character using str, you will have a little surprise :)\
<br />

```
void segf(void)
{
	char *str;
		Segmentation fault (core dumped)
	str = "School";
	str[0] = 's';
}
```
In the above example, the var `str` is a pointer to a char, that is initialized to the address of the first character of the string "School". But the memory storing the string "School2 is **READ-ONLY** and will also not be released when the function returns. This is the state of the memory after the line `str = "School"` is executed.
<br />
![Adress memory22](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2022/8/29dd5c267b1c6e4bdd13c2efa9df71e1f2a2f7e0.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20231130%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20231130T183606Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=f54fe05702f50c35cf81485992cc863e82ef2a6c3484045accdde1a3fb96ad53)<br />
And this is the state of the memory after the function returns:
<br />
![memory address2](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2022/8/683d365753bb64d96f9e8c8deee6d0523db179f1.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20231130%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20231130T183606Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=85d1888eff65989a08d66861e1d8c15fdbd040ab3ddb0d0370a7163930b44131)<br />

Note that when using the notation: `char s[] = "School"`, the array `s` holds a copy of the string "School".\
So it is possible to modify this copy.

```
#include <stdio.h>

void print_school(void)
{
    char str[] = "School";

    str[0] = 's';
    printf("%s\n", str);
}


int main(void)
{
    print_school();
    return (0);
}
```

This is the memory before the call to `print_school`:\
![memory address3](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2022/8/40996bf95c7a495a9f26e23dc2b17c0c43e56d2e.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20231130%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20231130T183606Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=2718ca93f98bf6e5a071157f80fe5f1a1b0d1ff9eba5b25fb8c9e142f757112f)<br />
Note that the string "School" is always represent in the memory.\
This is the memory right before the line str[0] = s is executed:\

Note the differences:\

The var str is not a pointer, it's an array. str does not hold the memory address of the string "School", but a copy of it.
The string "School" is copied into this array.\

And this is the memory state when the program leaves the func `print_school`:\
![memory address4](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2022/8/f9d8928eedb59bc51a2706113cd850f99c79f958.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20231130%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20231130T183606Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=c6b42ff0b8165ade197da306739a4619ffcb0b1def793f47f697e4607cdd66d7)<br />
Note, again, that the string `"School"` is still present in the memory
**Why would I need dynamic allocation?**\
We use dynamic allocation for inputs that are no fixed to a certain spaces. Insted, since we sometimes don't actually know how big is going to be a var. That's when dynamic memory comes into play.
### Dynamic Allocation
The `malloc` func allocates a num of bytes in memory and returs a pointer to the allocated memory. Will have read and write permissions.
* Prototype: `void *malloc(size_t size);`
* Where `void *` means it is a pointer to type of your choice
* and `size` is the number of bytes you need to allocate
```
#include <stdio.h>
#include <stdlib.h>

nt main(void)
{
    char *str;

    str = malloc(sizeof(char) * 3);
    str[0] = 'O';
    str[1] = 'K';
    str[2] = '\0';
    printf("%s\n", str);
    return (0);
}
julien@ubuntu:~/c/malloc$ gcc malloc_example.c -o m
julien@ubuntu:~/c/malloc$ ./m
OK
julien@ubuntu:~/c/malloc$ 
```
we use `malloc` to create a 3 byte allocated space in memory. Operator `sizeof`. It's very important because data types can be different size depending on what machine is run on. Here we're saying we want 3 times the size of char. **Always use `sizeof` for a better portability**\
<br />
Let's see another example, with integers
<br />
```
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *tab;

    tab = malloc(sizeof(*tab) * 3);
    tab[0] = 98;
    tab[1] = -1024;
    tab[2] = 402;
    printf("%d, %d, %d\n", tab[0], tab[1], tab[2]);
    return (0);
}
```
We use `malloc` to create a space in memory where can store three integers.
<br />
<br />
### Memory
Contrary to local var and func parameters, the memory that is allocated with `malloc` is not automatically released when the func returns.
```
#include <stdio.h>
#include <stdlib.h>

void m(int n0, int n1, int n2)
{
    int *t;
    int sum;

    t = malloc(sizeof(*t) * 3);
    t[0] = n0;
    t[1] = n1;
    t[2] = n2;
    sum = t[0] + t[1] + t[2];
    printf("%d + %d + %d = %d\n", t[0], t[1], t[2], sum);
}

int main(void)
{
    m(98, 402, -1024);
    return (0);
}
```
This is what the memory would look like before the func `m` returns:\
![Addr Mem.](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/misc/2020/9/b85d599111ab5ddf834ca90e7f0b589b0f7a3de7.PNG?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20231130%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20231130T183606Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=f963e06b2fd9c3b110abddf67dc3c81f83f0823b3719aa01a843b33853c22c19)<br />
And this will be the state of the memory after the function m returns:\
![Mem addr.2](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/misc/2020/9/4956b6e9fce3999ce47a1a39766c7c6f742c09a6.PNG?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20231130%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20231130T183606Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=d68485ce96fc5ac3b402e55d3b4916c5440a4fb662552c345b1fca83b4a3f335)<br />
**The memory is not initialized**\
Both Auto alloc and `malloc` does not initiate mem spaces
<br />
<br />
### Free
when you are using `malloc`, you have to handle the memory yourself. This means that:
* You need to keep track of all the addresses of the allocated memory (In a var of type pointer)
* You have to deallocate every memory space you previously allocaed yourself. if you do not do this, then your program can run out of memory and your program might kill it self.
```
int main(void)
{
    while (1)
    {
        malloc(sizeof(char) * 1024);
    }
    return (0);
}
julien@ubuntu:~/c/malloc$ gcc while_malloc.c -o killme
julien@ubuntu:~/c/malloc$ ./killme 
Killed
julien@ubuntu:~/c/malloc$ 
```
The `free` functions frees the memory space which have been allocated by a previous call to `malloc` (pr `calloc`, or `realloc).\
* Prototype: `void free(void *ptr);`
* where `ptr` is the address of the memory space previously allocated by and returned by a call to `malloc`.
<br />
<br />

**Example:**

```
void m(int n0, int n1, int n2)
{
    int *t;
    int sum;

    t = malloc(sizeof(*t) * 3);
    t[0] = n0;
    t[1] = n1;
    t[2] = n2;
    sum = t[0] + t[1] + t[2];
    printf("%d + %d + %d = %d\n", t[0], t[1], t[2], sum);
    free(t);
}
int main(void)
{
    m(98, 402, -1024);
    return (0);
}
``` 
The memory allocated by `malloc` is `freed`'d with a call to the function `free`.\
You should always `free` all `malloc`ed memory spaces.
<br />

### Valgrind
We use [valgrind](https://valgrind.org/) for building dynamic memory analysis tools. There are Valgrind tools that can automatically detect many memory management and threading bugs, and profile programs in detail.\
```
#include <stdio.h>
#include <stdlib.h>

/**
 * m - stores 3 int in a new allocated space in memory and prints the sum
 * @n0: integer to store and print
 * @n1: integer to store and print
 * @n2: integer to store and print
 *
 * Return: nothing
 */
void m(int n0, int n1, int n2)
{
    int *t;
    int sum;

    t = malloc(sizeof(*t) * 3);
    t[0] = n0;
    t[1] = n1;
    t[2] = n2;
    sum = t[0] + t[1] + t[2];
    printf("%d + %d + %d = %d\n", t[0], t[1], t[2], sum);
}

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    m(98, 402, -1024);
    return (0);
}
julien@ubuntu:~/c/malloc$ gcc malloc_mem.c -o m
julien@ubuntu:~/c/malloc$ valgrind ./m
==3749== Memcheck, a memory error detector
==3749== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==3749== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==3749== Command: ./m
==3749== 
98 + 402 + -1024 = -524
==3749== 
==3749== HEAP SUMMARY:
==3749==     in use at exit: 12 bytes in 1 blocks
==3749==   total heap usage: 2 allocs, 1 frees, 1,036 bytes allocated
==3749== 
==3749== LEAK SUMMARY:
==3749==    definitely lost: 12 bytes in 1 blocks
==3749==    indirectly lost: 0 bytes in 0 blocks
==3749==      possibly lost: 0 bytes in 0 blocks
==3749==    still reachable: 0 bytes in 0 blocks
==3749==         suppressed: 0 bytes in 0 blocks
==3749== Rerun with --leak-check=full to see details of leaked memory
==3749== 
==3749== For counts of detected and suppressed errors, rerun with: -v
==3749== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
julien@ubuntu:~/c/malloc$ 
```
**WE DEFINITELY LOST: 12 bytes in 1 block**
```
julien@ubuntu:~/c/malloc$ cat free_mem.c
#include <stdio.h>
#include <stdlib.h>

/**
 * m - stores 3 int in a new allocated space in memory and prints the sum
 * @n0: integer to store and print
 * @n1: integer to store and print
 * @n2: integer to store and print
 *
 * Return: nothing
 */
void m(int n0, int n1, int n2)
{
    int *t;
    int sum;

    t = malloc(sizeof(*t) * 3);
    t[0] = n0;
    t[1] = n1;
    t[2] = n2;
    sum = t[0] + t[1] + t[2];
    printf("%d + %d + %d = %d\n", t[0], t[1], t[2], sum);
    free(t);
}

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    m(98, 402, -1024);
    return (0);
}
julien@ubuntu:~/c/malloc$ gcc free_mem.c -o f
julien@ubuntu:~/c/malloc$ valgrind ./f
==3763== Memcheck, a memory error detector
==3763== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==3763== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==3763== Command: ./f
==3763== 
98 + 402 + -1024 = -524
==3763== 
==3763== HEAP SUMMARY:
==3763==     in use at exit: 0 bytes in 0 blocks
==3763==   total heap usage: 2 allocs, 2 frees, 1,036 bytes allocated
==3763== 
==3763== All heap blocks were freed -- no leaks are possible
==3763== 
==3763== For counts of detected and suppressed errors, rerun with: -v
==3763== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
julien@ubuntu:~/c/malloc$ 
```
**all heap blocks were freed - no leaks are possible.** This is what you should always aim for.
### Don't trust anyone
On error, `malloc` return `NULL`. As for any other C library function, you should always check `malloc` return
value before using it. If you don't will run into segfaults.
```
julien@ubuntu:~/c/malloc$ cat malloc_segf.c
#include <stdlib.h>
#include <limits.h>

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    char *s;

    while (1)
    {
        s = malloc(INT_MAX);
        s[0] = 'H';
    }
    return (0);
}
julien@ubuntu:~/c/malloc$ gcc malloc_segf.c -o s
julien@ubuntu:~/c/malloc$ ./s
Segmentation fault (core dumped)
julien@ubuntu:~/c/malloc$ 
```
This is how to check the return value of `malloc`:
```
julien@ubuntu:~/c/malloc$ cat malloc_segf.c
#include <stdlib.h>
#include <limits.h>

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    char *s;

    while (1)
    {
        s = malloc(INT_MAX);
        s[0] = 'H';
    }
    return (0);
}
julien@ubuntu:~/c/malloc$ gcc malloc_segf.c -o s
julien@ubuntu:~/c/malloc$ ./s
Segmentation fault (core dumped)
julien@ubuntu:~/c/malloc$ 
This is an example on how to check the return value of malloc:

julien@ubuntu:~/c/malloc$ cat malloc_check.c
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

/**
 * main - introduction to malloc and free
 *
 * Return: 0.
 */
int main(void)
{
    char *s;
    int i;

    i = 0;
    while (1)
    {
        s = malloc(INT_MAX);
        if (s == NULL)
        {
            printf("Can't allocate %d bytes (after %d calls)\n", INT_MAX, i);
            return (1);
        }
        s[0] = 'H';
        i++;
    }
    return (0);
}
julien@ubuntu:~/c/malloc$ gcc malloc_check.c -o c
julien@ubuntu:~/c/malloc$ ./c
Can't allocate 2147483647 bytes (after 0 calls)
julien@ubuntu:~/c/malloc$ 
```
## Should I cast the result of malloc
**No**; you shouldn't cast the result, since:\
* It is unnecessary, as `void *` is automatically and safely promoted to any other pointer type in this case.
* It adds clutter to the code, cast are not very easy to read (especially if the pointer type is long).
* It makes you repeat yourself, which is generally bad.
* It can hide an error if you forgot to include `<stdlib.h>`. This can cause crashes (or worse, not cause a crash until
way later in some totally different part of the code). Consider what happens if pointers and integers are differently sized; then you're
hiding a warning by casting and might lose bits of your returned address. Note: as of C99 implicit functions are gone from C, and this
point is no longer relevant since there's no automatic assumption that undeclared functions return `int`

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
They include `#if, #elif, #ifdef, #else, #ifndef`\
* `#if, #elif, #else, #ifdef, #ifndef` must be terminated with a closing `#endif`\


# C - Structure, typedef
A structure is a user defined data type available in C that allows to combine data items of different kinds
## Structure declaration
* You can define a structure in the global scope of your program (outside of all your functions, just like the functions prototypes)
* you can declare elements of your structure in its scope.
```
struct User
{
	char *name;
	char *email;
	int age;
};

int main(void)
{
	struct User user;

	return (0);
}
```
**You can access the elements of your structure by using the `'.'` symbol.
```
struct User
{
	char *name;
	char *email
	int age;
};

int main(void)
{
	struct User user;
	user.name = "Foo bar";
	user.email = "foo@hbtn.io";
	user.age = 98;
	return (0);
}
```
## Pointers to structures
To access elements of a pointer to a structure, you have to derefence the pointer and then access to the data using the `'.'` symbol<br />
**BUT**<br />
There is a simple way to do that, just by using '->' symbol. This symbol is equivalent to dereferencing + using `'.'`
```
struct User
{
	char *name;
	char *email;
	int age;
};

int main(void)
{
	struct User user;
	struct User *ptr;

	ptr = &user; //DEREF before access data with '.'
	(*ptr).name = "Foor Bar";
	ptr->email = "foo@hbtn.com"
	return (0);
}
```
## INIT
There are three ways to initialize a structure. For the `struct` type
```
struct point {
	int x;
	int y;
};
```
C89-style initializer are used when contiguous members may be given
```
//define a variable p of type point, and init its first two members in place
struct point p = { 1, 2 };
```
for non contiguous or out of order member list, designated initializer style may be used
```
// define a var p of type point, and set members using designated init
struct point p = { .y = 2, .x = 1 };
```
A thrid way of init a structure is to copy the value of an existing object of the same type
```
struct point q = p;
```
## Pointers to struct
pointer can be used to refer to a struct by its address. This is usuful for passing structs to a func. The pointer can be dereferenced using the `*` operator. The `->` operator dereferences the pointer to struct (left operand) and then accesses the value of a member of the struct (right operand)
```
struct point 
{
	int x;
	int y;
};
struct point my_point = { 3, 7 }
struct point *p = &my_point; // p is a pointer to my_point
(*p).x = 8; // set the first member of the struct
p -> x = 8; // equivalent method to set the first member of the struct
```
## typedef
The C programming language provides a keyword called typedef, which you can use to give a type, a new name.
```
typedef unsigned char byte;

int main(void)
{
	byte c; //after this type definition, the identifier 'byte'
		//can be used as an abbreviation for the type
	c = 200; //unsigned char, like in the example
	return (0);
}
```
**you can do it with structures to define a new data type**
```
struct Computer 
{
	char *name;
	char *brand;
}

typedef struct Computer Computer

typedef struct Computer
{
	char *name;
	char *brand;
} Computer;
```
**Then use that data type to define a structure variables directly like in the example**
```
typedef struct User
{
	char *name;
	char *email;
	int age;
} user;

int main(void)
{
	struct User user;
	user user2;

	return (0);
}
```
# C - Function pointers
## We can have pointers to FUNCTIONS!!!

void fun(int a)
{
	printf("Value of a is %d\n", a);
}

int main(void)
{	// Equal to: void (*fun_ptr)(int);
	void (*fun_ptr)(int) = &fun; 
	// and to: fun_ptr = &fun;
	//invoking fun() using fun_ptr
	(*fun_ptr)(10)

	return (0);
}
```
**Why do we need an extra bracket around function pointer like fun_ptr in above example**<br />
If we remove bracket, then the expression `void (*fun_ptr)(int)` becomes `void *fun_ptr(int)` which its declaration for
a func that returs void pointer
### Few key points about func pointers
1. Unlike normal pointer, a func pointer points to code, **NOT DATA**. Typically a func pointer stores the start of exec code
2. Unlike normal pointers, we do not allocate de-allocate memory using func pointers
3. A func name can also be used to get func addrs. example<br />
	* in the below program, we have removed the addrs operator `&` in assigment. We have also changed func call by removing `*`. The program works
```
#include <stdio.h> 
// A normal function with an int parameter 
// and void return type 
void fun(int a) 
{ 
    printf("Value of a is %d\n", a); 
} 
  
int main() 
{  
    void (*fun_ptr)(int) = fun;  // & removed 
  
    fun_ptr(10);  // * removed 
  
    return 0; 
}
```
4. like normal pointers, we can have an array of func pointers
5. Func pointer can be used in place of switch case. For example, in below program, user is asked for a choice between 0 and 2 to do different task
```
#include <stdio.h> 
void add(int a, int b) 
{ 
    printf("Addition is %d\n", a+b); 
} 
void subtract(int a, int b) 
{ 
    printf("Subtraction is %d\n", a-b); 
} 
void multiply(int a, int b) 
{ 
    printf("Multiplication is %d\n", a*b); 
} 
  
int main() 
{ 
    // fun_ptr_arr is an array of function pointers 
    void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply}; 
    unsigned int ch, a = 15, b = 10; 
  
    printf("Enter Choice: 0 for add, 1 for subtract and 2 "
            "for multiply\n"); 
    scanf("%d", &ch); 
  
    if (ch > 2) return 0; 
  
    (*fun_ptr_arr[ch])(a, b); 
  
    return 0; 
}
```
6. Like normal data pointers, a func pointer can be passed as an argument and can also be returned from a func.
	* This point in particular is very useful in C. In C, we can use function pointers to avoid code redundancy. For example a simple qsort() function can be used to sort arrays in ascending order or descending or by any other order in case of array of structures. Not only this, with function pointers and void pointers, it is possible to use qsort for any data type.
```
// A simple C program to show function pointers as parameter 
#include <stdio.h> 
  
// Two simple functions 
void fun1() { printf("Fun1\n"); } 
void fun2() { printf("Fun2\n"); } 
  
// A function that receives a simple function 
// as parameter and calls the function 
void wrapper(void (*fun)()) 
{ 
    fun(); 
} 
  
int main() 
{ 
    wrapper(fun1); 
    wrapper(fun2); 
    return 0; 
}
```
**and example for qsort comparator**
```
#include <stdio.h> 
#include <stdlib.h> 
  
// A sample comparator function that is used 
// for sorting an integer array in ascending order. 
// To sort any array for any other data type and/or 
// criteria, all we need to do is write more compare 
// functions.  And we can use the same qsort() 
int compare (const void * a, const void * b) 
{ 
  return ( *(int*)a - *(int*)b ); 
} 
  
int main () 
{ 
  int arr[] = {10, 5, 15, 12, 90, 80}; 
  int n = sizeof(arr)/sizeof(arr[0]), i; 
  
  qsort (arr, n, sizeof(int), compare); 
  
  for (i=0; i<n; i++) 
     printf ("%d ", arr[i]); 
  return 0; 
}
```
Similar to qsort(), we can write our own functions that can be used for any data type and can do different tasks without code redundancy. Below is an example search function that can be used for any data type. In fact we can use this search function to find close elements (below a threshold) by writing a customized compare function.

```
#include <stdio.h> 
#include <stdbool.h> 
  
// A compare function that is used for searching an integer 
// array 
bool compare (const void * a, const void * b) 
{ 
  return ( *(int*)a == *(int*)b ); 
} 
  
// General purpose search() function that can be used 
// for searching an element *x in an array arr[] of 
// arr_size. Note that void pointers are used so that 
// the function can be called by passing a pointer of 
// any type.  ele_size is size of an array element 
int search(void *arr, int arr_size, int ele_size, void *x, 
           bool compare (const void * , const void *)) 
{ 
    // Since char takes one byte, we can use char pointer 
    // for any type/ To get pointer arithmetic correct, 
    // we need to multiply index with size of an array 
    // element ele_size 
    char *ptr = (char *)arr; 
  
    int i; 
    for (i=0; i<arr_size; i++) 
        if (compare(ptr + i*ele_size, x)) 
           return i; 
  
    // If element not found 
    return -1; 
}  
int main() 
{ 
    int arr[] = {2, 5, 7, 90, 70}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int x = 7; 
    printf ("Returned index is %d ", search(arr, n, 
                               sizeof(int), &x, compare)); 
    return 0; 
}
```
7. Many object oriented features in C++ are implemented using function pointers in C.
