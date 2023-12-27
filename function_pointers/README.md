# C - Function pointers
### Resources
* [Function Pointer in C](https://intranet.hbtn.io/rltoken/qJ_oIzVwaDaLHr2PaWdfgw)
* [Pointers to functions](https://intranet.hbtn.io/rltoken/zH2EY_rooZFB4zyN7gRFEQ)
* [Function Pointers in C / C++](https://intranet.hbtn.io/rltoken/ZMt6k0RrDVvF3WeLK2Wllw)
* [why pointers to functions?](https://intranet.hbtn.io/rltoken/61rj01NJ8P7cBMd8m6Sm7w)
* [Everything you need to know about pointers in C](https://intranet.hbtn.io/rltoken/Z0tUxkCEq-2HssDEnN0bsg)

## Learning Objectives
* What are function pointers and how to use them
	* Function pointers allow different code to be executed at runtime. They can also be passed to a function to enable callbacks. Function pointers are supported by third-generation programming languages (such as PL/I, COBOL, Fortran, dBASE dBL, and C) and object-oriented programming languages (such as C++, C#, and D).<br />

* What does a function pointer exactly hold
	* A function pointer is a pointer variable, but it holds the address of a function, not the address of a data item. The only things you can do with a function pointer are read its value, assign its value, or call the function that it points toward.<br />

* Where does a function pointer point to in the virtual memory
	* A function pointer in computer programming is a pointer variable that points to the address of a function, rather than pointing to data like integers or objects. In other words, it's a variable that can store the memory address of a function, allowing you to call that function indirectly through the pointer.<br />

# We can have pointers to FUNCTIONS!!!
```
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

### function pointers use cases
All of these cases are related to the concept that func pointers can be passed as arguments to other funcs, and then. A func that will recieve a func pointer as argument, can call back the func that this func will point to.<br />
**BUT**, What this mean?
```
#include <stdio.h>
void A()
{
	printf("hello");
}
void B(void (*ptr)()) //func pointer as argument
{
	ptr(); //call-back func that "ptr" points to
}
int main()
{
	B(A); //A is callback func.
}
```
When ref to a func is passed by another func, that particular func is called a `callback` func, in this case is `A()`<br />
## 0. Write a function that prints a name.

* Prototype: `void print_name(char *name, void (*f)(char *));`
```
julien@ubuntu:~/0x0e. Function pointers$ cat 0-main.c
#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name_as_is - prints a name as is
 * @name: name of the person
 *
 * Return: Nothing.
 */
void print_name_as_is(char *name)
{
    printf("Hello, my name is %s\n", name);
}

/**
 * print_name_uppercase - print a name in uppercase
 * @name: name of the person
 *
 * Return: Nothing.
 */
void print_name_uppercase(char *name)
{
    unsigned int i;

    printf("Hello, my uppercase name is ");
    i = 0;
    while (name[i])
    {
        if (name[i] >= 'a' && name[i] <= 'z')
        {
            putchar(name[i] + 'A' - 'a');
        }
        else
        {
            putchar(name[i]);
        }
        i++;
    }
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    print_name("Bob", print_name_as_is);
    print_name("Bob Dylan", print_name_uppercase);
    printf("\n");
    return (0);
}
julien@ubuntu:~/0x0e. Function pointers$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-print_name.c -o a
julien@ubuntu:~/0x0e. Function pointers$ ./a 
Hello, my name is Bob
Hello, my uppercase name is BOB DYLAN
julien@ubuntu:~/0x0e. Function pointers$ 
```
**SOLVED**
```
#include "function_pointers.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_name - a func that prints a name
 * @name: a name
 * @f: func pointer to a name
 * Return: a name
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || (*f) == NULL)
		return;

	(*f)(name);
}
```
## 1. Write a function that executes a function given as a parameter on each element of an array.

* Prototype: `void array_iterator(int *array, size_t size, void (*action)(int));`
* where `size` is the size of the array
* and `action` is a pointer to the function you need to use
```
julien@ubuntu:~/0x0e. Function pointers$ cat 1-main.c
#include <stdio.h>
#include "function_pointers.h"

/**
 * print_elem - prints an integer
 * @elem: the integer to print
 *
 * Return: Nothing.
 */
void print_elem(int elem)
{
    printf("%d\n", elem);
}

/**
 * print_elem_hex - prints an integer, in hexadecimal
 * @elem: the integer to print
 *
 * Return: Nothing.
 */
void print_elem_hex(int elem)
{
    printf("0x%x\n", elem);
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int array[5] = {0, 98, 402, 1024, 4096};

    array_iterator(array, 5, &print_elem);
    array_iterator(array, 5, &print_elem_hex);
    return (0);
}
julien@ubuntu:~/0x0e. Function pointers$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-array_iterator.c -o b
julien@ubuntu:~/0x0e. Function pointers$ ./b 
0
98
402
1024
4096
0x0
0x62
0x192
0x400
0x1000
julien@ubuntu:~//0x0e. Function pointers$ 
```
**SOLVED**
```
#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * array_iterator - a func that executes a function given
 * as a parameter on each element of an array.
 * @array: an array
 * @size: the size
 * @action: pointer to func its needed to use
 * Return: the formated text
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i = 0;

	if (array == NULL || (*action) == NULL)
		return;

	while (i < size)
	{
		(*action)(array[i]);
		i++;
		if ((*action) == NULL)
			return;
	}
}
```
## 2. Write a function that searches for an integer.

* Prototype: `int int_index(int *array, int size, int (*cmp)(int));`
* where `size` is the number of elements in the array `array`
* `cmp` is a pointer to the function to be used to compare values
* `int_index` returns the index of the first element for which the `cmp` function does not return `0`
* If no element matches, return `-1`
* If size <= `0`, return `-1`
```
julien@ubuntu:~/0x0e. Function pointers$ cat 2-main.c
#include <stdio.h>
#include "function_pointers.h"

/**
 * is_98 - check if a number is equal to 98
 * @elem: the integer to check
 *
 * Return: 0 if false, something else otherwise.
 */
int is_98(int elem)
{
    return (98 == elem);
}

/**
 * is_strictly_positive - check if a number is greater than 0
 * @elem: the integer to check
 *
 * Return: 0 if false, something else otherwise.
 */
int is_strictly_positive(int elem)
{
    return (elem > 0);
}


/**
 * abs_is_98 - check if the absolute value of a number is 98
 * @elem: the integer to check
 *
 * Return: 0 if false, something else otherwise.
 */
int abs_is_98(int elem)
{
    return (elem == 98 || -elem == 98);
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int array[20] = {0, -98, 98, 402, 1024, 4096, -1024, -98, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 98};
    int index;

    index = int_index(array, 20, is_98);
    printf("%d\n", index);
    index = int_index(array, 20, abs_is_98);
    printf("%d\n", index);
    index = int_index(array, 20, is_strictly_positive);
    printf("%d\n", index);
    return (0);
}
julien@ubuntu:~/0x0e. Function pointers$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-int_index.c -o c
julien@ubuntu:~/0x0e. Function pointers$ ./c 
2
1
2
julien@ubuntu:~/0x0e. Function pointers$ 
```
**SOLVED**
```
#include "function_pointers.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * int_index - a func that searches for a int
 * @array: an array of pointers to int
 * @size: the size of array
 * @cmp: pointer to a func used to compare values
 * Return: the found int
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL)
		return (-1);

	if (size <= 0)
		return (-1);

	while (i++ < size)
		if (cmp(array[i]))
			return (i);

	return (-1);
}
```
## 3. Write a program that performs simple operations.

* You are allowed to use the standard library
* Usage: `calc` `num1 operator num2`
* You can assume `num1` and `num2` are integers, so use the `atoi` function to convert them from the string input to `int`
* `operator` is one of the following:
	* `+`: addition
	* `-`: subtraction
	* `*`: multiplication
	* `/`: division
	* `%`: modulo
* The program prints the result of the operation, followed by a new line
* You can assume that the result of all operations can be stored in an `int`
* if the number of arguments is wrong, print `Error`, followed by a new line, and exit with the status `98`
* if the `operator` is none of the above, print `Error`, followed by a new line, and exit with the status `99`
* if the user tries to divide (`/` or `%`) by `0`, print `Error`, followed by a new line, and exit with the status `100`
*This task requires that you create four different files.*
<br />

**3-calc.h**
<br />

This file should contain all the function prototypes and data structures used by the program. You can use this structure:
```
/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
    char *op;
    int (*f)(int a, int b);
} op_t;
```
**3-op_functions.c**
This file should contain the 5 following functions (not more):

* `op_add`: returns the sum of `a` and `b`. Prototype: `int op_add(int a, int b);`
* `op_sub`: returns the difference of `a` and `b`. Prototype: `int op_sub(int a, int b);`
* `op_mul`: returns the product of `a` and `b`. Prototype: `int op_mul(int a, int b);`
* `op_div`: returns the result of the division of `a` by `b`. Prototype: `int op_div(int a, int b);`
* `op_mod`: returns the remainder of the division of `a` by `b`. Prototype: `int op_mod(int a, int b);`
**3-get_op_func.c**<br />

This file should contain the function that selects the correct function to perform the operation asked by the user. You’re not allowed to declare any other function.<br />

* Prototype: `int (*get_op_func(char *s))(int, int);`
* where `s` is the operator passed as argument to the program
* This function returns a pointer to the function that corresponds to the operator given as a parameter. Example: `get_op_func("+")` should return a pointer to the function `op_add`
* You are not allowed to use `switch` statements
* You are not allowed to use `for` or `do ... while` loops
* You are not allowed to use `goto`
* You are not allowed to use `else`
* You are not allowed to use more than one `if` statement in your code
* You are not allowed to use more than one `while` loop in your code
* If s does not match any of the 5 expected operators (`+`, `-`, `*`, `/`, `%`), return `NULL`
* You are only allowed to declare these two variables in this function:
```
    op_t ops[] = {
        {"+", op_add},
        {"-", op_sub},
        {"*", op_mul},
        {"/", op_div},
        {"%", op_mod},
        {NULL, NULL}
    };
    int i;
```
**3-main.c**<br />

This file should contain your `main` function only.<br />

* You are not allowed to code any other function than `main` in this file
* You are not allowed to directly call `op_add`, `op_sub`, `op_mul`, `op_div` or `op_mod` from the main function
* You have to use `atoi` to convert arguments to `int`
* You are not allowed to use any kind of loop
* You are allowed to use a maximum of 3 `if` statements
**Compilation and examples**
```
julien@ubuntu:~/0x0e. Function pointers$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 3-op_functions.c 3-get_op_func.c -o calc
julien@ubuntu:~/0x0e. Function pointers$ ./calc 1 + 1
2
julien@ubuntu:~/0x0e. Function pointers$ ./calc 97 + 1
98
julien@ubuntu:~/0x0e. Function pointers$ ./calc 1024 / 10
102
julien@ubuntu:~/0x0e. Function pointers$ ./calc 1024 '*' 98
100352
julien@ubuntu:~/0x0e. Function pointers$ ./calc 1024 '\*' 98
Error
julien@ubuntu:~/0x0e. Function pointers$ ./calc 1024 - 98
926
julien@ubuntu:~/0x0e. Function pointers$ ./calc 1024 '%' 98
44
julien@ubuntu:~/0x0e. Function pointers$ 
```
**SOLVED**
*calc.h*
```
#ifndef _CALC_H
#define _CALC_H

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

int op_mod(int a, int b);
int op_div(int a, int b);
int op_mul(int a, int b);
int op_sub(int a, int b);
int op_add(int a, int b);
int (*get_op_func(char *s))(int, int);

#endif
```
*3-get_op_func.c*
```
#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * get_op_func - a func to select the correct OP
 * @s: string
 * Return: OP
 */


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
	printf("Error\n");
	exit(99);
}
```
*3-op_functions.c*
```
#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * op_add - a addtion OP
 * @a: int
 * @b: int
 * Return: op
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - a substraction OP
 * @a: int
 * @b: int
 * Return: OP
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - a multiply op
 * @a: int
 * @b: int
 * Return: OP
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - a divition OP
 * @a: int
 * @b: int
 * Return: OP
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}
/**
 * op_mod - a modulus OP
 * @a: int
 * @b: int
 * Return: OP
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
```

