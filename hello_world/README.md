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
