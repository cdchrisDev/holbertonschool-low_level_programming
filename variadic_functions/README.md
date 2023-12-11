# This is the Variadic Functios Project
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
* Declare the function as variadic, using a prototype with allipsis `...` in all the files which call it. See [Syntxt for Variable Arguments](https://www.gnu.org/software/libc/manual/html_node/Variadic-Prototypes.html).
* Call the func by writing the fixed arguments followed by the additional variable arguments See [Calling variadic Func](https://www.gnu.org/software/libc/manual/html_node/Calling-Variadics.html).

