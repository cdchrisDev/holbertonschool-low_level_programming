# C - Structure, typedef
## Learning Objectives
* What are structures, when, why and how to use them
	* A structure is a user defined data type available in C that allows to combine data items of different kinds.<br /> It is used when we want to structure data or just don't know how mucho we're gonna add to our functions.<br /> As standar data types, after a struct has been define we can create an instance of the sabe struct<br /> `struct NAME`
* How to use typedef
	* `typedef` followed by our struct that we want to generate an instances of.
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
## Array of structs
We can also declare a struct which is an array of struct like following:
```
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
	{"+", op_add},
	{"-", op_sub},
	{"*", op_mul},
	{"/", op_div},
	{"%", op_mod},
	{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op != NULL)
	{
		if (*ops[i].op == *s && s[1] == '\0')
			return (ops[i].f);

		i++;
	}
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
# Tasks
## 0. Define a new type `struct dog` with the following elements:

* `name`, type = `char *`
* `age`, type = `float`
* `owner`, type = `char *`
```
julien@ubuntu:~/0x0d. structures, typedef$ cat 0-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    my_dog.name = "Poppy";
    my_dog.age = 3.5;
    my_dog.owner = "Bob";
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return (0);
}
julien@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c -o a
julien@ubuntu:~/0x0d. structures, typedef$ ./a 
My name is Poppy, and I am 3.5 :) - Woof!
julien@ubuntu:~/0x0d. structures, typedef$ 
```
**SOLVED**: *main.h*
```
#ifndef DOG_H
#define DOG_H
/**
 * struct dog - print a text
 * @name: dog's name
 * @age: Dog's age
 * @owner: Dog's owner
 * Return: text
 *
 * Descriptoion: this structure hold puppy info
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog;

typedef dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
```
## 1. Write a function that initialize a variable of type struct dog

* Prototype: `void init_dog(struct dog *d, char *name, float age, char *owner);`
```
julien@ubuntu:~/0x0d. structures, typedef$ cat 1-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    init_dog(&my_dog, "Poppy", 3.5, "Bob");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return (0);
}
julien@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-init_dog.c -o b
julien@ubuntu:~/0x0d. structures, typedef$ ./b 
My name is Poppy, and I am 3.5 :) - Woof!
julien@ubuntu:~/0x0d. structures, typedef$ 
```
**SOLVED**
```
#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * init_dog - a func that initialize a var type struct dog
 * @d: name of struct
 * @name: dogs name
 * @age: dogs age
 * @owner: dogs owner
 * Return: a text
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		;

	else
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
```
## 2. Write a function that prints a struct dog

* Prototype: `void print_dog(struct dog *d);`
* Format: see example bellow
* You are allowed to use the standard library
* If an element of `d` is `NULL`, print `(nil)` instead of this element. (if `name` is `NULL`, print `Name: (nil)`)
* if `d` is `NULL` print nothing.
```
julien@ubuntu:~/0x0d. structures, typedef$ cat 2-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    my_dog.name = "Poppy";
    my_dog.age = 3.5;
    my_dog.owner = "Bob";
    print_dog(&my_dog);
    return (0);
}
julien@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-print_dog.c -o c
julien@ubuntu:~/0x0d. structures, typedef$ ./c 
Name: Poppy
Age: 3.500000
Owner: Bob
julien@ubuntu:~/0x0d. structures, typedef$ 
```
**SOLVED**
```
#include "dog.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * print_dog - a func to print struct dog
 * @d: name of dog
 *
 * Return: formated text
 *
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	if (d->name == NULL)
	{
		d->name = "(nil)";
		d->owner = "(nil)";
	}
	printf("Name: %s\nAge: %.6f\nOwner: %s\n", d->name, d->age, d->owner);
```
## 3. Define a new type `dog_t` as a new name for the type `struct dog`.
```
julien@ubuntu:~/0x0d. structures, typedef$ cat 3-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    dog_t my_dog;

    my_dog.name = "Poppy";
    my_dog.age = 3.5;
    my_dog.owner = "Bob";
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return (0);
}
julien@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c -o d
julien@ubuntu:~/0x0d. structures, typedef$ ./d 
My name is Poppy, and I am 3.5 :) - Woof!
julien@ubuntu:~/0x0d. structures, typedef$ 
```
**SOLVED**
`main.h`
## 4. Write a function that creates a new dog.

* Prototype: `dog_t *new_dog(char *name, float age, char *owner);`
* You have to store a copy of `name` and `owner`
* Return `NULL` if the function fails
```
julien@ubuntu:~/0x0d. structures, typedef$ cat 4-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    dog_t *my_dog;

    my_dog = new_dog("Poppy", 3.5, "Bob");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog->name, my_dog->age);
    return (0);
}
julien@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 4-new_dog.c -o e
julien@ubuntu:~/0x0d. structures, typedef$ ./e
My name is Poppy, and I am 3.5 :) - Woof!
julien@ubuntu:~/0x0d. structures, typedef$ 
```
**SOLVED**
```
#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * new_dog - func to create and init a new struct for dog
 * @name: name
 * @age: age
 * @owner: owner name
 * Return: pointer to string
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	int k, i = 0, j = 0;
	/*new struct of type dog_t*/
	dog_t *new__dog;
	new__dog = (dog_t *)malloc(sizeof(dog_t));
	/* check for malloc with errors */
	if (new__dog == NULL)
		return (NULL);
	/* strlen() */
	while (name[i] != '\0')
		i++;

	while (owner[j] != '\0')
		j++;
	/* assigning char mem slots */
	new__dog->name = malloc(i + 1);
	new__dog->owner = malloc(j + 1);
	/* checking errors for those slots */
	if (new__dog->name == NULL || new__dog->owner == NULL)
	{	
		free(new__dog->name);
		free(new__dog->owner);

		free(new__dog);
		return (NULL);
	}	
	/* strcpy() */
	for (k = 0; k <= i; k++)
		new__dog->name[k] = name[k];
	for (k = 0; k <= j; k++)
		new__dog->owner[k] = owner[k];
	/* last char '\0' */
	new__dog->name[i] = '\0';
	new__dog->owner[j] = '\0';
	new__dog->age = age;

	return (new__dog);
}
```
## 5. Write a function that frees dogs.

* Prototype: `void free_dog(dog_t *d);`
```
julien@ubuntu:~/0x0d. structures, typedef$ cat 5-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    dog_t *my_dog;

    my_dog = new_dog("Poppy", 3.5, "Bob");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog->name, my_dog->age);
    free_dog(my_dog);
    return (0);
}
julien@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 5-free_dog.c 4-new_dog.c -o f
julien@ubuntu:~/0x0d. structures, typedef$ valgrind ./f
==22840== Memcheck, a memory error detector
==22840== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==22840== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==22840== Command: ./f
==22840== 
My name is Poppy, and I am 3.5 :) - Woof!
==22840== 
==22840== HEAP SUMMARY:
==22840==     in use at exit: 0 bytes in 0 blocks
==22840==   total heap usage: 4 allocs, 4 frees, 1,059 bytes allocated
==22840== 
==22840== All heap blocks were freed -- no leaks are possible
==22840== 
==22840== For counts of detected and suppressed errors, rerun with: -v
==22840== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
julien@ubuntu:~/0x0d. structures, typedef$
```
**SOLVED**
```
#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * free_dog - a func to frees dogs
 * @d: a struct dog
 *
 * Return: freed memory
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}
```
