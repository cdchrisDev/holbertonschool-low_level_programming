# C - Static Library
### Resources
* [What Is A “C” Library? What Is It Good For?](https://intranet.hbtn.io/rltoken/ybnw3yGP38RCfO4a2u8AoQ)
* [Creating A Static “C” Library Using “ar” and “ranlib”](https://docencia.ac.upc.edu/FIB/USO/Bibliografia/unix-c-libraries.html)
* [Using A “C” Library In A Program](https://docencia.ac.upc.edu/FIB/USO/Bibliografia/unix-c-libraries.html)
* [What is difference between Dynamic and Static library(Static and Dynamic linking)](https://intranet.hbtn.io/rltoken/ybnw3yGP38RCfO4a2u8AoQ) *stop at 4:44*
## Learning Objectives
* **What is a "C" Library? What is good for?**\
Are just collections of objects files that are linked only during the linking phase of compilation, and are not relevant during runtime. (just the executable is needed)

In the compilation time both are either linked into the program or one of its share libraries. However, the object files from the dynamic library are not inserted into the executable file. Instead, when the program is started, a program in the system `dynamic loader` checks out which shared libraries were linked with the program, loads them to memory and attaches them to the copy of the program in memory\
But, if we re-compile  the dynamic library and try to run a second copy of our program with the new library, we'll soon get stuck - `dynamic library` soon will find the copy of the library is already stored in memory, and thus will attach it to our program, and not load the new (modified) version from the disk<br />



* **Creating A Static "C" Library Using "ar" and "ranlib"**\
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

# C - Static Library
### Resources
* [What Is A “C” Library? What Is It Good For?](https://intranet.hbtn.io/rltoken/ybnw3yGP38RCfO4a2u8AoQ)
* [Creating A Static “C” Library Using “ar” and “ranlib”](https://docencia.ac.upc.edu/FIB/USO/Bibliografia/unix-c-libraries.html)
* [Using A “C” Library In A Program](https://docencia.ac.upc.edu/FIB/USO/Bibliografia/unix-c-libraries.html)
* [What is difference between Dynamic and Static library(Static and Dynamic linking)](https://intranet.hbtn.io/rltoken/ybnw3yGP38RCfO4a2u8AoQ) *stop at 4:44*
# Learning Objectives
* What is a static library, how does it work, how to create one, and how to use it
	* A static library is a file containing a collection of object files (*.o) that are linked into the program during the linking phase of compilation and are not relevant during runtime. As shown in the diagram above, when a program is compiled, the compiler generates an object file from a source file.
* Basic usage of `ar`, `ranlib`, `nm`
	* **Syntax**: `ranlib [--plugin name] [-DhHvVt] archive`
	* **-Options**: `ranlib --help`
	* **-Version**: `ranlib --version`
	* **-D**: This option wil operate in deterministic mode. `ranlib -D fruits.a`
	* **-t**: This option will update the timestamp of the symbol map of an archive `ranlib -t fruits.a`
	* **-U**: This option do not operate in deterministic mode. `ranlib -U fruits.a`
# Tasks

## 0. Create the static library libmy.a containing all the functions listed below:
```
int _putchar(char c);
int _islower(int c);
int _isalpha(int c);
int _abs(int n);
int _isupper(int c);
int _isdigit(int c);
int _strlen(char *s);
void _puts(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
```
If you haven’t coded all of the above functions create empty ones with the right prototype.
Don’t forget to push your `main.h` file to your repository. It should at least contain all the prototypes of the above functions.
```
julien@ubuntu:~/Static Librairies$ ar -t libmy.a 
0-isupper.o
0-memset.o
0-strcat.o
1-isdigit.o
1-memcpy.o
1-strncat.o
100-atoi.o
2-strchr.o
2-strlen.o
2-strncpy.o
3-islower.o
3-puts.o
3-strcmp.o
3-strspn.o
4-isalpha.o
4-strpbrk.o
5-strstr.o
6-abs.o
9-strcpy.o
_putchar.o
julien@ubuntu:~/Static Librairies$ nm libmy.a 

0-isupper.o:
0000000000000000 T _isupper

0-memset.o:
0000000000000000 T _memset

0-strcat.o:
0000000000000000 T _strcat

1-isdigit.o:
0000000000000000 T _isdigit

1-memcpy.o:
0000000000000000 T _memcpy

1-strncat.o:
0000000000000000 T _strncat

100-atoi.o:
0000000000000000 T _atoi

2-strchr.o:
0000000000000000 T _strchr

2-strlen.o:
0000000000000000 T _strlen

2-strncpy.o:
0000000000000000 T _strncpy

3-islower.o:
0000000000000000 T _islower

3-puts.o:
                 U _putchar
0000000000000000 T _puts

3-strcmp.o:
0000000000000000 T _strcmp

3-strspn.o:
0000000000000000 T _strspn

4-isalpha.o:
0000000000000000 T _isalpha

4-strpbrk.o:
0000000000000000 T _strpbrk

5-strstr.o:
0000000000000000 T _strstr

6-abs.o:
0000000000000000 T _abs

9-strcpy.o:
0000000000000000 T _strcpy

_putchar.o:
0000000000000000 T _putchar
                 U write
julien@ubuntu:~/Static Librairies$ cat main.c 
#include "main.h"

int main(void)
{
    _puts("\"At the end of the day, my goal was to be the best hacker\"\n\t- Kevin Mitnick");
    return (0);
}
julien@ubuntu:~/Static Librairies$ gcc -std=gnu89 main.c -L. -lmy -o quote
julien@ubuntu:~/Static Librairies$ ./quote 
"At the end of the day, my goal was to be the best hacker"
    - Kevin Mitnick
julien@ubuntu:~/Static Librairies$ 
```
**SOLVED**<br />

`ar -t libmy.a`
## 1. Create a script called create_static_lib.sh that creates a static library called liball.a from all the .c files that are in the current directory.
```
julien@ubuntu:~/Static Librairies$ ls *.c
0-isupper.c  0-strcat.c  1-isdigit.c  1-strncat.c  2-strlen.c   3-islower.c  3-strcmp.c  4-isalpha.c  5-strstr.c  9-strcpy.c  _putchar.c
0-memset.c   100-atoi.c  1-memcpy.c   2-strchr.c   2-strncpy.c  3-puts.c     3-strspn.c  4-strpbrk.c  6-abs.c
julien@ubuntu:~/Static Librairies$ ./create_static_lib.sh 
julien@ubuntu:~/Static Librairies$ ls *.a
liball.a
julien@ubuntu:~/Static Librairies$ ar -t liball.a
0-isupper.o
0-memset.o
0-strcat.o
100-atoi.o
1-isdigit.o
1-memcpy.o
1-strncat.o
2-strchr.o
2-strlen.o
2-strncpy.o
3-islower.o
3-puts.o
3-strcmp.o
3-strspn.o
4-isalpha.o
4-strpbrk.o
5-strstr.o
6-abs.o
9-strcpy.o
_putchar.o
julien@ubuntu:~/Static Librairies$ 
```
**SOLVED**
```
#!/bin/bash
gcc -c *.c && ar rc liball.a *.o && ranlib liball.a
```
