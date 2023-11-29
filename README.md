# This is the holberton low level programming  repository

## C Static Libraries
As our programs get larger and complex is necesary to delegate pieces of code to more smaller components to work with. It is better to manipulate tiny and lighter pieces than manipulate a big and havier

**What is a "C" Library? What is good for?**
Are just collections of objects files that are linked only during the linking phase of compilation, and are not relevant during runtime. (just the executable is needed)

In the compilation time both are either linked into the program or one of its share libraries. However, the object files from the dynamic library are not inserted into the executable file. Instead, when the program is started, a program in the system `dynamic loader` checks out which shared libraries were linked with the program, loads them to memory and attaches them to the copy of the program in memory
But, if we re-compile  the dynamic library and try to run a second copy of our program with the new library, we'll soon get stuck - `dynamic library` soon will find the copy of the library is already stored in memory, and thus will attach it to our program, and not load the new (modified) version from the disk

**Creating A Static "C" Library Using "are" and "ranlib"**
`ar` for `archiver` Create **Static Libraries** *which are actually archive files*
> `ar rc libutil.a util_file.o util_net.o util_math.o`
