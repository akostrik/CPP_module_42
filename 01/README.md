# C vs C++ file manipulation functions (ex04)

## C (forbidden)

FILE *fp

fopen, fclose, fwrite, fread, ftell, fseek, fprintf, fscanf, feof, fileno, fgets, fputs, fgetc, fputc

Modes : r, w, a

Crashes: int my_int = 32; printf("%s", my_int)

Hard-coded maximum buffer sizes

## C++ 

fstream f

f.open, f.close, f>>, f<<, f.seekg, f.seekp, f.tellg, f.tellp, f.read, f.write, f.eof

Modes : ios::in, ios::out, ios::bin , ...

Fstreams close the files they manage when they leave scope

How input and output is performed is implicitly selected using the variable type

Extensibility for user-defined types (i.e. you can teach streams how to handle your own classes)

Dynamically sizing receiving strings based on the actual input

Exceptions

# Convert (ex04)
## std::string to char* 
```
std::string str;
const char * c = str.c_str();
char       * c = str.data();
```
## char* to string
- Using the “=” operator
- Using the string constructor
- Using the assign function

# Reference vs pointer (ex03)
Pointers and references present some small differences that make them less or more appropriate depending on the use and the lifecycle of the object
used.

HumanA can have a reference or a pointer to the Weapon. Ideally, it should be implemented as a reference, since the Weapon exists from creation until destruction, and never changes (here HumanA has `Weapon& weaponREF` attribut).

HumanB must have a pointer to a Weapon since the field is not set at creation time, and the weapon can be NULL (here HumanB has `Weapon* weaponPTR` attribut).

In the both cases we can change the type of the weapon. 

## Reference
If something should always exist and never change, use a references

A reference !=  new variable

A reference doesn't occupy memory

A reference = an aliase for an existing variable

A reference = a constant pointer, always points to the same variable, we can't change it 

Reference = a dereferenced pointer

A reference can't point to nothing

```
   std::string &sREF = s;
// std::string             тип, на который объявляется ссылка
//             &sREF       переменная типа ссылка на string
//                     s   переменная, на которую объявляется ссылка
```
## Pointer

If something should not always exist and can change, use a pointer

A pointer can be pointing to a non-existing address


# To do
ex 05 func Harl::

