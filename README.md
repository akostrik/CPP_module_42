# Orthodox canonical class form in C++98 

- Default constructor
- Copy constructor
- Destructor
- Copy assignment operator

```
class A final
{
   public:
      A ();
      A (const A &a);
      ~A ();
      A & operator = (const A &a);
};
```

# Data specifiers

## private / public / protected data

public    - members are accessible from outside the class

private   - members cannot be accessed or viewed from outside the class

protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes

## final class

запрет наследования

## static data

Is not associated with a particular object, belongs to the class rather than objects of the class

Can be called using the class name (if it is public) or through an object (not recommended)

## const / mutable data 

Non-mutable

Can't modify it directly -> a compile-time error

Can't modify it through a pointer/reference to non-const type -> undefined behavior

Can't modify it by a (const nor a non-const) member function, even if it is passed by reference

Can modity if by constructor/destructor 

Can modity if by casting the const away (not advised)

Can modify a class member declared `mutable` through member functions even if the containing object is const

Can't call a non-const method a const object

Can't call a non-const method through a pointer/reference to a const object if the referred-to object is const 

Can't call a non-const method through a pointer/reference to a const object if the referred-to object is not const 

`const int C=3` для параметров, которые не надо изменять после компиляции

`const int *C` указатель на постоянное int, указатель изменять можно, значение нельзя

`int const *C` указатель на постоянное int, указатель изменять можно, значение нельзя

`int * const C` постоянный указатель на int, значение указателя нельзя менять, а значение переменной можно 

`int const * const C` постоянный указатель на постоянный int 

константные объекты класса могут явно вызывать только константные методы класса

## virtual data

## template class

## abstract class

Абстрактные классы = содержат или наследуют без переопределения хотя бы одну чистую виртуальную функцию

Cannot be directly instantiated

- may be labeled as abstract 

- may specifies abstract methods via signatures that are to be implemented by its descendants (before a class derived from an abstract class can be instantiated, all abstract methods of its parent classes must be implemented)

- may provide implementations of some methods

_Abstract method_ = virtual function = объявлена с помощью синтаксиса чистого описателя (= 0))

Нельзя использовать для:
- переменных и данных членов
- типов аргументов
- типов возвращаемых функциями значений
- типов явных преобразований

C++ has no keyword abstract

## Pure abstract class = interface

Consists of only virtual methods 

# Function specifiers

## private / public / protected function

see data

## static function

Is not associated with a particular object, belongs to the class rather than objects of the class

Can be called using the class name (if it is public) or through an object (not recommended)

No `*this` pointer

Can directly access other static members (variables or functions), but not non-static members (non-static members belong to an object)

In the context of function declarations, static = "this function is scoped only to this file and can't be called from other places"

In the context of member functions, static = "this member function does not have a receiver object. It's basically a normal function that's nested inside of the scope of the class"

Example:
```
class MyClass {
 public:
  static void myfunc();
};

void MyClass::myfunc() {} // do not write 'static'

int main() {
  MyClass::myfunc();
}
```
## const / mutable funciton

Не изменяет объект и не вызывает неконстантные методы класса (поскольку они могут изменить объект)

Компилятор знает, что возвращенное функцией значение поменять нельзя
```
const char *func() {
  return "текст";
}
```

Можно иметь константную и неконстантную версии одной и той же функции.

## virtual function

Must be members of some class

Must be defined in the base class, even though it is not used

A member function declared within a parent class and re-defined by a child class

Производный класс может переопределить ее поведение

When you refer to a child class object by a pointer / reference to the parent class, you call a virtual function and execute its child class’s version 

Is accessed through object pointers

Вызов виртуальной функции через имя объекта разрешается статически, динамическое связывание возможно только через указатель или ссылку

We cannot have a virtual constructor or destructor

Cannot be a static member

Non-final class with virtual functions should have virtual destructor

Polymorphic class := определяет или наследует виртуальную функцию

## pure virtual funcitons

In the case of destructors, they must be implemented even when they are pure virtual

## override function

Явным образом указать, что мы хотим переопредлить функцию, а не скрыть ее

`override` keyword is a C++11 extension

## final function

Запретить определение virtual функции в производных классах 

## template function
Allows functions and classes to operate with generic types. This allows a function or class declaration to reference via a generic variable another different class (built-in or newly declared data type) without creating full declaration for each of these different classes.

## abstract function

= pure virtual

Не имеет определения

Цель - просто определить функционал без реализации, реализацию определят производные классы

C++ has no keyword abstract

# Reference vs pointer (01 / ex03)
Pointers and references present some small differences that make them less or more appropriate depending on the use and the lifecycle of the object
used.

HumanA can have a reference or a pointer to the Weapon. Ideally, it should be implemented as a reference, since the Weapon exists from creation until destruction, and never changes (here HumanA has `Weapon& weaponREF` attribut).

HumanB must have a pointer to a Weapon since the field is not set at creation time, and the weapon can be NULL (here HumanB has `Weapon* weaponPTR` attribut).

In the both cases we can change the type of the weapon. 

## Reference
If something should always exist and never change, use a references

A reference = a dereferenced pointer

A reference = an aliase for an existing variable !=  new variable

A reference = a constant pointer, always points to the same variable, we can't change it (?)

A reference doesn't occupy memory

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

# C vs C++ file manipulation functions (01 / ex04)

## C (forbidden by subject)

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

# Convert (01 / ex04)
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

# Floating-point numbers vs Fixed-point numbers (02)
Accuracy = to how close a measurement is to the true value

Precision = how much information you have about a quantity, how uniquely you have it pinned down

Fixed point arithmetic is much faster than floating point arithmetic

## Floating-point

[IEEE-754 Floating Point Converter](https://www.h-schmidt.net/FloatConverter/IEEE754.html)

- s sign bit
- e exponent giving its order of magnitude (= порядок = показатель степени)
- m mantissa specifying the actual digits of the number ∊ [1;10)

Decimal	                        | e                            | m   | float                                            
---------------------------------|------------------------------|-----|--------------------------------------------------
${(-1)}^{s}$ * 1.(mantissa bits) * $2^e$ |                      |     | s eeeeeeee mmmmmmmmmmmmmmmmmmmmmmm 
(1+m/ $2^{23}$ )* $2^{e−127}$    | ~11111111~ ~00000000~        |     |
(0+m/ $2^{23}$ )* $2^{1−127}$    | 00000000                     |     |
Largest $2^{254−127}$ *(1+ ($2^{23}$−1)/ $2^{23}$) = 340282346638528859811704183484516925440 |  |  | 0 11111110 11111111111111111111111   
1234.4321                        |                              |     | 0 10001001 00110100100110111010100
1234.43212890625                 |                              |     | 0 10001001 00110100100110111010100
316014.6250                      |                              |     | 0 10010001 00110100100110111010100
3.14                             | ∊ [ $2^1$ ; $2^2$ ) => $2^7$ | $\frac{3,14 -2 }{4 - 2} *2^{23}$ | 0 10000000 10010001111010111000011
0                                |                              |     | 0 00000000 00000000000000000000000
1.0                              |                              |     | 0 01111111 00000000000000000000000
0.5                              |                              |     | 0 01111110 00000000000000000000000
3                                |                              |     | 0 10000000 10000000000000000000000
1.175494351e-38 smallest without losing precision |             |     | 0 00000001 00000000000000000000000
1.401298464e-45 smallest  	      |                              |     | 0 00000000 00000000000000000000001
1.1929093e-7 the smallest x : 1+x > 1 |                         |     | 0 01101000 00000000001011001110001
+inf                             |                              |     | 0 11111111 00000000000000000000000
-inf                             |                              |     | 1 11111111 00000000000000000000000
+NaN                             |                              | ~0~ | 0 11111111 10000000000000000000000

## Fixed-point

Representing non-integer numbers by storing a fixed number of digits of their fractional part

Example : Dollar amounts are often stored with exactly two fractional digits, representing the cents

$1234.4321_{float}$ = (316014.6176, 8) = (316015, 8) = ($00000000.00000100.11010010.01101111_{2}$, 8) 

## Inheritance

конструкторы не наследуются

Внутри потомка можно создать одноимённую функцию с функцией родителя => отказ от этой части наследства, функция становится самостоятельной функцией своего класса

Наследованные деструкторы вызываются наоборот по сравнению с вызыванием конструктора

# Requirements
You should be able to use each of your headers independently from others. Thus, they must include all the dependencies they need. However, you must avoid the problem of double inclusion by adding include guards.

Nothing should be public for no reason.

For every exercise, you have to provide the most complete tests you can.

07/ex01: тестируют const (!).

## Forbidden:
- C++11 (and derived forms) and Boost libraries
- *printf(), *alloc() and free()
- the using namespace <ns_name> and friend keywords
- The implementation of the function should be done using functions from std::string, no by reading the string character by character
- C file manipulation functions
- External libraries or features from versions other than C++98
- Containers (vector/list/map/and so forth)
- Algorithms (anything that requires to include the <algorithm> header)
- Any function implementation put in a header file (except for function templates)
- Memory leaks
  
# Sources
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html

https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html

https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html

https://stackoverflow.com/questions/60224493/whats-the-largest-number-float-type-can-hold

https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html 

https://github.com/achrafelkhnissi/CPP_Modules/tree/master

https://github.com/Saxsori/CPP_Modules/tree/main

https://github.com/42YerevanProjects/cpp_modules/tree/master

https://rphlr.github.io/42-Evals/

http://www.cplusplus.com/reference/iomanip/

http://www.cplusplus.com/reference/string/string

https://github.com/achrafelkhnissi/CPP_Modules
