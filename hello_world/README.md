# C - Hello, World
## Resources
* [Everything you need to know to start with C.pdf](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/misc/2021/1/d801279f75de6a982a55d752dfd3632909f720f0.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20231220%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20231220T011715Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=c617397e09716d91e6215b9b681eda3560ba1fdf2939e389ec7f06bbab16229d)
* [Dennis Ritchie](https://en.wikipedia.org/wiki/Dennis_Ritchie)
* ["C" Programming Language: Brian Kernighan](https://www.youtube.com/watch?v=de2Hsvxaf8M&ab_channel=Computerphile)
* [Why C programming is Awesome](https://www.youtube.com/watch?v=smGalmxPVYc&ab_channel=ChrisHawkes)
* [Learning to program in C part 1](https://www.youtube.com/watch?v=rk2fK2IIiiQ&ab_channel=JonathanEngelsma)
* [Learning to program in C part 2](https://www.youtube.com/watch?v=FwpP_MsZWnU&ab_channel=JonathanEngelsma)
* [Understanding C program Compilation Process](https://www.youtube.com/watch?v=VDslRumKvRA&ab_channel=HowTo)
* [Betty Coding Style](https://github.com/hs-hq/Betty/wiki)
* [Hash-bang under the hood](https://twitter.com/unix_byte/status/1024147947393495040?s=21)
* [Linus Torvalds on C vs C++](https://harmful.cat-v.org/software/c++/linus)
## Learning Objectives
### General
* Why C programming is awesome
	* Because almost every electronic device in the world was coded using C programming language
<br />

* Who invented C
	* Dennis MacAlistair Ritchie (September 9, 1941 – c. October 12, 2011)
<br />

* Who are Dennis Ritchie, Brian Kernighan and Linus Torvalds
	* The people behind the bases of the Unix Fundation 
<br />

* What happens when you type `gcc main.c`
	* It compiles the file `main.c`
<br />

* What is `main`
	* The entry point of our program, it looks for it when it starts
<br />

* How to print text using `printf`, `puts` and `putchar`
	* `printf("%[format]", Var)`, `puts(Var)` and `putchar('a')`
<br />

* How to get the size of a specific type using the unary operator `sizeof`
	* `sizeof(type)` where `type`is a var or int, float, char, etc...
<br />

* How to compile using `gcc`
	* `gcc FILE [option] OUT_FILE_NAME`
<br />

* What is the default program name when compiling with `gcc`
	* a.out
<br />

* What is the official C coding style and how to check your code with `betty-style`
	* `betty FILE.c`
<br />

* How to find the right header to include in your source code when using a stadard library function
	* READ THE FRIENDLY MANUAL (RTFM) `man $nameOfFunction`
<br />

* How does the `main` function influence the return value of the program
	* shows how the program exited.
<br />

# Task
## 0. Write a script that runs a C file through the preprocessor and save the result into another file.
* The C file name will be saved in the variable `$CFILE`
* The output should be saved in the file `c`
```
julien@ubuntu:~/c/$ cat main.c 
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    return (0);
}
julien@ubuntu:~/c/$ export CFILE=main.c
julien@ubuntu:~/c/$ ./0-preprocessor 
julien@ubuntu:~/c/$ tail c
# 942 "/usr/include/stdio.h" 3 4

# 2 "main.c" 2


# 3 "main.c"
int main(void)
{
 return (0);
}
julien@ubuntu:~/c/$ 
```
**SOLVED**
```
#!/bin/bash
gcc -E $CFILE -o c
```
## 1. Write a script that compiles a C file but does not link.
<br />

* The C file name will be saved in the variable `$CFILE`
* The output file should be named the same as the C file, but with the extension `.o` instead of `.c`.
	* Example: if the C file is `main.c`, the output file should be `main.o`
```
julien@ubuntu:~/c/$ export CFILE=main.c
julien@ubuntu:~/c/$ cat main.c
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    return (0);
}
julien@ubuntu:~/c/$ ./1-compiler 
julien@ubuntu:~/c/$ ls
0-preprocessor  1-compiler   c            main.o
Makefile               100-intel      main.c  main.s
julien@ubuntu:~/c/$ cat -v main.o | head
^?ELF^B^A^A^@^@^@^@^@^@^@^@^@^A^@>^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^P^B^@^@^@^@^@^@^@^@^@^@@^@^@^@^@^@@^@^K^@^H^@UHM-^IM-eM-8^@^@^@^@]M-C^@GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609^@^T^@^@^@^@^@^@^@^AzR^@^Ax^P^A^[^L^G^HM-^P^A^@^@^\^@^@^@^\^@^@^@^@^@^@^@^K^@^@^@^@A^N^PM-^F^BC^M^FF^L^G^H^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^D^@M-qM-^?^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^C^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^C^@^B^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^C^@^C^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^C^@^E^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^C^@^F^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^C^@^D^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^H^@^@^@^R^@^A^@^@^@^@^@^@^@^@^@^K^@^@^@^@^@^@^@^@main.c^@main^@^@^@^@ ^@^@^@^@^@^@^@^B^@^@^@^B^@^@^@^@^@^@^@^@^@^@^@^@.symtab^@.strtab^@.shstrtab^@.text^@.data^@.bss^@.comment^@.note.GNU-stack^@.rela.eh_frame^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^[^@^@^@^A^@^@^@^F^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@@^@^@^@^@^@^@^@^K^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@!^@^@^@^A^@^@^@^C^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@K^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@'^@^@^@^H^@^@^@^C^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@K^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@,^@^@^@^A^@^@^@0^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@K^@^@^@^@^@^@^@5^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@5^@^@^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@M-^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@J^@^@^@^A^@^@^@^B^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@M-^@^@^@^@^@^@^@^@8^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^H^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@E^@^@^@^D^@^@^@@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@M- ^A^@^@^@^@^@^@^X^@^@^@^@^@^@^@    ^@^@^@^F^@^@^@^H^@^@^@^@^@^@^@^X^@^@^@^@^@^@^@^Q^@^@^@^C^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@M-8^A^@^@^@^@^@^@T^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^B^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@M-8^@^@^@^@^@^@^@M-X^@^@^@^@^@^@^@
^@^@^@^H^@^@^@^H^@^@^@^@^@^@^@^X^@^@^@^@^@^@^@  ^@^@^@^C^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@M-^P^A^@^@^@^@^@^@^M^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@julien@ubuntu:~/c/$ 
```
**SOLVE**
```
#!/bin/bash
gcc -c $CFILE 
```
## 2. Write a script that generates the assembly code of a C code and save it in an output file.
<br />

* The C file name will be saved in the variable `$CFILE`
The output file should be named the same as the C file, but with the extension `.s` instead of `.c`.
Example: if the C file is `main.c`, the output file should be `main.s`
```
julien@ubuntu:~/c/$ export CFILE=main.c
julien@ubuntu:~/c/$ cat main.c
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    return (0);
}
julien@ubuntu:~/c/$ ./2-assembler
julien@ubuntu:~/c/$ ls
0-preprocessor  1-compiler  2-assembler c  main.c  main.s  Makefile
julien@ubuntu:~/c/$ cat main.s
    .file   "main.c"
    .text
    .globl  main
    .type   main, @function
main:
.LFB0:
    .cfi_startproc
    pushq   %rbp
    .cfi_def_cfa_offset 16
    .cfi_offset 6, -16
    movq    %rsp, %rbp
    .cfi_def_cfa_register 6
    movl    $0, %eax
    popq    %rbp
    .cfi_def_cfa 7, 8
    ret
    .cfi_endproc
.LFE0:
    .size   main, .-main
    .ident  "GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
    .section    .note.GNU-stack,"",@progbits
julien@ubuntu:~/c/$ 
```
**SOLVED**
```
#!/bin/bash
gcc -S $CFILE 
```
## 3. Write a script that compiles a C file and creates an executable named cisfun.
<br />

* The C file name will be saved in the variable `$CFILE`
```
julien@ubuntu:~/c/$ export CFILE=main.c
julien@ubuntu:~/c/$ cat main.c
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    return (0);
}
julien@ubuntu:~/c/$ ./3-name 
julien@ubuntu:~/c/$ ls
0-preprocessor  1-compiler   3-name  cisfun  main.o  Makefile
100-intel       2-assembler  c       main.c  main.s
julien@ubuntu:~/c/$ 
```
**SOLVED**
```
#!/bin/bash
gcc $CFILE -o cisfun
```
## 4. Write a C program that prints exactly "Programming is like building a multilingual puzzle, followed by a new line.
<br />

* Use the function `puts`
* You are not allowed to use `printf`
* Your program should end with the value `0`
```
julien@ubuntu:~/c/$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 4-puts.c && ./a.out
"Programming is like building a multilingual puzzle
julien@ubuntu:~/c/$ echo $?
0
julien@ubuntu:~/c/$ 
```
**SOLVED**
```
#include <stdio.h>
/**
 * main - entry point
 * @void: no parameter
 * Description: this program prints something
 * Return: always 0
 */
int main(void)
{
	puts("\"Programming is like building a multilingual puzzle");
	return (0);
}
```
## 5. Write a C program that prints exactly with proper grammar, but the outcome is a piece of art,, followed by a new line.
<br />

* Use the function `printf`
* You are not allowed to use the function `puts`
* Your program should return `0`
* Your program should compile without warning when using the `-Wall` `gcc` option
```
julien@ubuntu:~/c/$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 5-printf.c
julien@ubuntu:~/c/$ ./a.out 
with proper grammar, but the outcome is a piece of art,
julien@ubuntu:~/c/$ echo $?
0
julien@ubuntu:~/c/$ 
```
**SOLVED**
```
#include <stdio.h>
/**
 * main - Entry point
 * @void: no parameter
 * Return: Always 0 (success)
 */
int main(void)
{
	char *grammar = "with proper grammar, but the outcome is a piece of art,";

	printf("%s\n", grammar);
	return (0);
}
```
## 6. Write a C program that prints the size of various types on the computer it is compiled and run on.
<br />

* You should produce the exact same output as in the example
* Warnings are allowed
* Your program should return `0`
* If you are using a linux on Vagrant you might have to install the package `libc6-dev-i386` to test the `-m32 gcc` option (normally you dont need to do anything on your sandbox).
```
julien@ubuntu:~/c/$ gcc 6-size.c -m32 -o size32 2> /tmp/32
julien@ubuntu:~/c/$ gcc 6-size.c -m64 -o size64 2> /tmp/64
julien@ubuntu:~/c/$ ./size32
Size of a char: 1 byte(s)
Size of an int: 4 byte(s)
Size of a long int: 4 byte(s)
Size of a long long int: 8 byte(s)
Size of a float: 4 byte(s)
julien@ubuntu:~/c/$ ./size64
Size of a char: 1 byte(s)
Size of an int: 4 byte(s)
Size of a long int: 8 byte(s)
Size of a long long int: 8 byte(s)
Size of a float: 4 byte(s)
julien@ubuntu:~/c/$ echo $?
0
julien@ubuntu:~/c/$ 
```
**SOLVED**
```
#include <stdio.h>
/**
  * main - Entry point
  * Description: prints sizes of different types in c
  * Return: always 0 (success)
  */
int main(void)
{
	printf("Size of a char: %lu byte(s)\n", sizeof(char));
	printf("Size of an int: %lu byte(s)\n", sizeof(int));
	printf("Size of a long int: %lu byte(s)\n", sizeof(long));
	printf("Size of a long long int: %lu byte(s)\n", sizeof(double));
	printf("Size of a float: %lu byte(s)\n", sizeof(float));
	return (0);
}
```
## 8. Write a script that generates the assembly code (Intel syntax) of a C code and save it in an output file.
<br />

* The C file name will be saved in the variable `$CFILE`.
* The output file should be named the same as the C file, but with the extension `.s` instead of `.c`.
	* **Example**: if the C file is `main.c`, the output file should be `main.s`
```
julien@ubuntu:~/c/$ export CFILE=main.c
julien@ubuntu:~/c/$ cat main.c
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    return (0);
}
julien@ubuntu:~/c/$ ./100-intel 
julien@ubuntu:~/c/$ cat main.s
    .file   "main.c"
    .intel_syntax noprefix
    .text
    .globl  main
    .type   main, @function
main:
.LFB0:
    .cfi_startproc
    push    rbp
    .cfi_def_cfa_offset 16
    .cfi_offset 6, -16
    mov rbp, rsp
    .cfi_def_cfa_register 6
    mov eax, 0
    pop rbp
    .cfi_def_cfa 7, 8
    ret
    .cfi_endproc
.LFE0:
    .size   main, .-main
    .ident  "GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
    .section    .note.GNU-stack,"",@progbits
julien@ubuntu:~/c/$ 
```
**SOLVED**
```
#!/bin/bash
gcc -S -masm=intel $CFILE
```
## 9. Write a C program that prints exactly `and that piece of art is useful"- Dora Korpar, 2015-10-19`, followed by a new line, to the standard error.
* You are not allowed to use any functions listed in the NAME Section of the man(3) `printf` or man(3) `puts`
* Your program should return 1
* Your program should compile without any warnings when using the `Wall gcc` option
```
julien@ubuntu:~/c/$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -o quote 101-quote.c
julien@ubuntu:~/c/$ ./quote
and that piece of art is useful" - Dora Korpar, 2015-10-19
julien@ubuntu:~/c/$ echo $?
1
julien@ubuntu:~/c/$ ./quote 2> q
julien@ubuntu:~/c/$ cat q
and that piece of art is useful" - Dora Korpar, 2015-10-19
julien@ubuntu:~/c/$ grep printf < 101-quote.c
julien@ubuntu:~/c/$ grep put < 101-quote.c
julien@ubuntu:~/c/$ 
```
**SOLVED**
```
#include <stdio.h>
/**
 * main - entry point
 * Return: 1
 */
int main(void)
{
	char *c = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	while (*c)
		putchar(*c++);

	return (1);
}
```
