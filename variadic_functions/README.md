# This is the Variadic Functions Project
ISO C defines a syntax for declaring a func to take a var num or type of arguments (Also known as varargs or variadic functions) However, the language itself provides no mechanism for such functions to access their non-required arguments; instead, you use the variable arggguments macros defined in `stdarg.h`
## Why they are used
Ordinary C functions take a fixed number of arguments. But, some func perform operatios that can meaningfully accept an unlimited number of arguments<br />
In some cases a function can handle any number of values by operating on all of them as a block. For example, consider a function that allocates a one-dimensional array with malloc to hold a specified set of values. This operation makes sense for any number of values, as long as the length of the array corresponds to that number. Without facilities for variable arguments, you'll have to define a separate func for each possible array size.<br />
The library fucn `printf` is an example of another class of function where variable arguments are usuful. This func prints its arguments **These are good reasons to define a variadic function which can handle as many arguments as the caller chooses to pass**
## How variadic functions are defined and used
**Defining and using a variadic function involves three steps:**
* Define the function as variadic, using an ellipsis `...` in the argument list, and using special macros to access the variable arguments. See [Receiving the Argument values](https://www.gnu.org/software/libc/manual/html_node/Receiving-Arguments.html). <br />
	* ordinary arguments have unique names, but optional arguments have nothing but `...` **How can you access them?** | The only way to access them is sequentially, in the order they were written, and you must use special macros from `stdarg.h` in the following three step process:
	1. Initialize an argument pointer variable of type `va_list` using `va_start`. The argument pointer when initialized points to the first optional argument.
	2. You access the opional arguments by successive calls to `va_arg` The first call to `va_arg` gives you the first optional argument, the next call gives you the second, and so on.
	3. You indicate that you are finished with the argument pointer variale by calling `va_end`
* Declare the function as variadic, using a prototype with allipsis `...` in all the files which call it. See [Syntax for Variable Arguments](https://www.gnu.org/software/libc/manual/html_node/Variadic-Prototypes.html).<br />
	* A func that accepts a variable number of arguments must be declared with a prototype that says so. You write the fixed arguments as usual, and then tack on `...` to indicate the possibility of additional arguments. The syxtax of ISO C requires at least one fixed argument before the `...`:
```
int func (const char *a, int b, ...)
{
	
}
```
defines a `func` which returns an int and takes two required arguments, a `const char *` and an `int`. These are followed by any number of anonymous arguments<br />
**Portability Note:** For some C compilers, the last required argument must not be declared `register` i the func definition. Furthermore, this argument’s type must be self-promoting: that is, the default promotions must not change its type. This rules out array and function types, as well as float, char (whether signed or not) and short int (whether signed or not). This is actually an ISO C requirement.
* Call the func by writing the fixed arguments followed by the additional variable arguments See [Calling variadic Func](https://www.gnu.org/software/libc/manual/html_node/Calling-Variadics.html).
	* In principle, functions that are defined to be variadic must also be declared to be variadic using a function prototype whenever you call them.<br />
## stdarg.h
`stdarg.h` is a header in the that allows functios to accept an **indefinite number of arguments**, it provides facilities for stteping through a list of function arguments of unknown number and type.<br />

### std::va_list
**typedef /* unspecified */ va_list;**
va_list is a complete object type (in practice, a unique built-in type or `char*`) suitable for holding the information needed by the macros `va_start`, `va_copy`, ``va_arg`, and `va_end`.<br />
If a `va_list` instance is created, passed to another function and used vi `va_arg` in that function, then any subsequent use in the calling function should be preceded by a call to `va_end`<br />
It is legal to pass a pointer to a `va_list` object to another function and then use that object after the function returns.<br />
* **va_start**: enables access to variadic function arguments
* **va_copy**: makes a copy of the variadic function arguments
* **va_arg**: accesses the next variadic function arguments
* **va_end**: ends traversal of the variadic function arguments
```
#include <stdio.h>
#include <stdarg.h>

/* print all args one at a time until a negative argument is seen;
   all args are assumed to be of int type */
void printargs(int arg1, ...)
{
  va_list ap;
  int i;

  va_start(ap, arg1); 
  for (i = arg1; i >= 0; i = va_arg(ap, int))
    printf("%d ", i);
  va_end(ap);
  putchar('\n');
}

int main(void)
{
   printargs(5, 2, 14, 84, 97, 15, -1, 48, -1);
   printargs(84, 51, -1, 3);
   printargs(-1);
   printargs(1, -1);
   return 0;
}
```
This program yields the output:
```
5 2 14 84 97 15
84 51

1
```

