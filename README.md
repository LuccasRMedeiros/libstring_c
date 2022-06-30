# libstring_c
## Because strings are beautiful

Did you ever feelted that C lack a decent way to deal with strings?
You know, there is a header for it "string.h" that have functions to copy,
concat and deal with strings of data in general, but there isn't a string type
that is a collection of chars. Strings are largely used, specially in the front
end of applications, it is used even in applications that does not have a front
end at all. String is the first data type used by any programmer (unless you 
skiped your first program that prints "Hello World!" to the console). Strings 
are generally the form that users transmit data to other users, even if they 
don't mind it at all, every text message is a string or a collection of them.
This README file is a collection of strings.
It all create the need for any programmer to deal with strings, but the only way
we, C programmers, do have to work with them is declaring "char[]/char[n]" or
just "char\*". To have our entry in the world of defined strings here it is
**Libstring_c** which implements two types of strings, array of fixed number of
chars and a pointer to char that can have memory allocated to it to create
dynamic strings.

if you find this library useful to your work, you are free to use it.
Also feel free to open issues you find while using it.
