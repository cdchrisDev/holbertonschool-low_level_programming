# C - File I/O
### Resources
* [File descriptors](https://en.wikipedia.org/wiki/File_descriptor)
* [C Programming in Linux - open(), read(), write() functions](https://intranet.hbtn.io/rltoken/2wyxBQICb3qsEh_UOxYgyw)
# Tasks
## 0. Write a function that reads a text file and prints it to the `POSIX` standard output
* Prototype: `ssize_t read_textfile(const char *filename, size_t letters);`
* where letters is the number of letters it should read and print`
* returns the actual number of letters it could read and print
* if the file can not be opened or read, return `0`
* if `filename` is `NULL` return `0` 
* if write fails or does not write the expected amount of bytes, return `0`
```
julien@ubuntu:~/File descriptors and permissions$ cat Requiescat 
Requiescat
by Oscar Wilde

Tread lightly, she is near
Under the snow,
Speak gently, she can hear
The daisies grow.

All her bright golden hair
Tarnished with rust,
She that was young and fair
Fallen to dust.

Lily-like, white as snow,
She hardly knew
She was a woman, so
Sweetly she grew.

Coffin-board, heavy stone,
Lie on her breast,
I vex my heart alone,
She is at rest.

Peace, Peace, she cannot hear
Lyre or sonnet,
All my life's buried here,
Heap earth upon it.
julien@ubuntu:~/File descriptors and permissions$ cat 0-main.c
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    ssize_t n;

    if (ac != 2)
    {
        dprintf(2, "Usage: %s filename\n", av[0]);
        exit(1);
    }
    n = read_textfile(av[1], 114);
    printf("\n(printed chars: %li)\n", n);
    n = read_textfile(av[1], 1024);
    printf("\n(printed chars: %li)\n", n);
    return (0);
}
julien@ubuntu:~/File descriptors and permissions$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-read_textfile.c -o a
julien@ubuntu:~/File descriptors and permissions$ ./a Requiescat 
Requiescat
by Oscar Wilde

Tread lightly, she is near
Under the snow,
Speak gently, she can hear
The daisies grow.
(printed chars: 114)
Requiescat
by Oscar Wilde

Tread lightly, she is near
Under the snow,
Speak gently, she can hear
The daisies grow.

All her bright golden hair
Tarnished with rust,
She that was young and fair
Fallen to dust.

Lily-like, white as snow,
She hardly knew
She was a woman, so
Sweetly she grew.

Coffin-board, heavy stone,
Lie on her breast,
I vex my heart alone,
She is at rest.

Peace, Peace, she cannot hear
Lyre or sonnet,
All my life's buried here,
Heap earth upon it.

(printed chars: 468)
julien@ubuntu:~/File descriptors and permissions$ 
```
**SOLVED**
```
/**
 * read_textfile - reads a text file and prints it to the POSIX
 * @filename: points to file that we will be receiving
 * @letters: size of letters to read in
 * Return: the readFile
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int f = 0, rf = 0, wf = 0, cf;
	char *buffer;
	/*
	 *f: file
	 *rf: read file
	 *wf: write file
	 *cf: close file
	 */
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	if (filename == NULL)
		return (0);
	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	rf = read(f, buffer, letters);
	if (rf == -1)
		return (0);
	wf = write(STDOUT_FILENO, buffer, rf);
	if (wf == -1)
		return (0);
	cf = close(f);
	if (cf == -1)
		return (0);
	free(buffer);
	return (rf);
}
```
## 1. Create a function that creates a file.
* **Prototype**: `int create_file(const char *filename, char *text_content);`
* where `filename` is the name of the file to create and `text_content` is a `NULL` terminated string to write to the file
* **Returns**: `1` on success, `-1` on failure (file can not be created, file can not be written, `write` “fails”, etc…)
* The created file must have those permissions: `rw-------`. If the file already exists, do not change the permissions.
* if the file already exists, truncate it
* if `filename` is `NULL` return `-1`
* if `text_content` is `NULL` create an empty file
```
julien@ubuntu:~/File descriptors and permissions$ cat 1-main.c
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    int res;

    if (ac != 3)
    {
        dprintf(2, "Usage: %s filename text\n", av[0]);
        exit(1);
    }
    res = create_file(av[1], av[2]);
    printf("-> %i)\n", res);
    return (0);
}
julien@ubuntu:~/File descriptors and permissions$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-create_file.c -o b
julien@ubuntu:~/File descriptors and permissions$ ./b hello world
-> 1)
julien@ubuntu:~/File descriptors and permissions$ ls -l hello
-rw------- 1 julien julien 5 Dec  3 14:28 hello
julien@ubuntu:~/File descriptors and permissions$ cat hello 
worldjulien@ubuntu:~/File descriptors and permis$ 
```
**SOLVED**
```
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 * create_file - a func that creates a file
 * @filename: the file
 * @text_content: NULL terminated to write to the file
 * Return: 1 or -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int f, wf, len, cf;
	mode_t mode = S_IRUSR | S_IWUSR;

	if (filename == NULL)
		return (-1);

	f = open(filename, O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (f == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len] != '\0'; len++)
			;
		wf = write(f, text_content, len);
	}
	if (wf == -1)
		return (-1);

	cf = close(f);
	if (cf == -1)
		return (-1);
	return (1);
}
```
## 2. Write a function that appends text at the end of a file.
* **Prototype**: `int append_text_to_file(const char *filename, char *text_content);`
* where `filename` is the name of the file and `text_content` is the `NULL` terminated string to add at the end of the file
* **Return**: `1` on success and `-1` on failure
* Do not create the file if it does not exist
* If `filename` is `NULL` return `-1`
* If `text_content` is `NULL`, do not add anything to the file. Return `1` if the file exists and `-1` if the file does not exist or if you do not have the required permissions to write the file
```
julien@ubuntu:~/File descriptors and permissions$ cat 2-main.c
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    int res;

    if (ac != 3)
    {
        dprintf(2, "Usage: %s filename text\n", av[0]);
        exit(1);
    }
    res = append_text_to_file(av[1], av[2]);
    printf("-> %i)\n", res);
    return (0);
}
julien@ubuntu:~/File descriptors and permissions$ echo -n Hello > hello
julien@ubuntu:~/File descriptors and permissions$ ls -l hello
-rw-rw-r-- 1 julien julien 5 Dec  3 14:48 hello
julien@ubuntu:~/File descriptors and permissions$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-append_text_to_file.c -o c
julien@ubuntu:~/File descriptors and permissions$ ./c hello " World!
> "
-> 1)
julien@ubuntu:~/File descriptors and permissions$ cat hello 
Hello World!
julien@ubuntu:~/File descriptors and permissions$
```
**SOLVED**
```
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 * append_text_to_file - appends text
 * @filename: pointer to file
 * @text_content: text to write
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int f, wf, cf, len;

	if (filename == NULL)
		return (-1);

	f = open(filename, O_APPEND | O_WRONLY);
	if (f == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len] != '\0'; len++)
			;
		wf = write(f, text_content, len);
	}
	if (wf == -1)
		return (-1);

	cf = close(f);
	if (cf == -1)
		return (-1);

	return (1);
}
```
## 3. Write a program that copies the content of a file to another file.
* **Usage**: `cp file_from file_to`
* if the number of argument is not the correct one, exit with code `97` and print `Usage: cp file_from file_to`, followed by a new line, on the `POSIX` standard error
* if `file_to` already exists, truncate it
* if `file_from` does not exist, or if you can not read it, exit with code `98` and print `Error: Can't read from file NAME_OF_THE_FILE`, followed by a new line, on the `POSIX` standard error
	* where `NAME_OF_THE_FILE` is the first argument passed to your program
* if you can not create or if `write` to `file_to fails`, exit with code `99` and print Error: `Can't write to NAME_OF_THE_FILE`, followed by a new line, on the `POSIX` standard error
	* where `NAME_OF_THE_FILE` is the second argument passed to your program
* if you can not close a file descriptor , exit with code `100` and print Error: `Can't close fd FD_VALUE`, followed by a new line, on the `POSIX` standard error
	* where `FD_VALUE` is the value of the file descriptor
* Permissions of the created file: `rw-rw-r--`. If the file already exists, do not change the permissions
* You must read `1,024` bytes at a time from the `file_from` to make less system calls. Use a buffer
* You are allowed to use `dprintf`
```
julien@ubuntu:~/File descriptors and permissions$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-cp.c -o cp
julien@ubuntu:~/File descriptors and permissions$ cat incitatous 
Why you should think twice before putting pictures on social media.
(What you always wanted to know about @Incitatous)
#PrivacyAware
http://imgur.com/a/Mq1tc
julien@ubuntu:~/File descriptors and permissions$ ./cp incitatous Incitatous
julien@ubuntu:~/File descriptors and permissions$ ls -l Incitatous 
-rw-rw-r-- 1 julien julien 158 Dec  3 15:39 Incitatous
julien@ubuntu:~/File descriptors and permissions$ cat Incitatous 
Why you should think twice before putting pictures on social media.
(What you always wanted to know about @Incitatous)
#PrivacyAware
http://imgur.com/a/Mq1tc
julien@ubuntu:~/File descriptors and permissions$ 
```
**SOLVED**
```
#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
/**
 * main - Copy the contents of a file to other file
 * @argc: num arg
 * @argv: vector arg
 * Return: 0 if successful, 97-100 otherwise
 */
int main(int argc, char *argv[])
{
	int ffrom, fto, c_status;
	char buffer[1024];
	ssize_t size;

	if (argc != 3)
		args_error();

	ffrom = open(argv[1], O_RDONLY);
	if (ffrom == -1)
		f_from_error(argv[1]);

	fto = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fto == -1)
		f_to_error(argv[2]);

	while ((size = read(ffrom, buffer, 1024)) > 0)
	{
		if (write(fto, buffer, size) != size)
			f_to_error(argv[2]);
	}

	if (size == -1)
		f_from_error(argv[1]);

	c_status = close(ffrom);
	if (c_status == -1)
		c_error(ffrom);

	c_status = close(fto);
	if (c_status == -1)
		c_error(fto);

	return (0);
}

/**
 * args_error - Print error and exit if wrong number of arguments
 */
void args_error(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
 * f_from_error - Print error and exit if file from error
 * @file: The name of the file
 */
void f_from_error(char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	exit(98);
}

/**
 * f_to_error - Print error and exit if file to error
 * @file: The name of the file
 */
void f_to_error(char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
}

/**
 * c_error - Print error and exit if close fails
 * @fd: The file descriptor
 */
void c_error(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}
```

