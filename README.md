# Data specifiers

## public data != private, != protected
* members are accessible from outside the class  
## private data != public, != protected
* members cannot be accessed or viewed from outside the class  
## protected datta != public, != private
* members cannot be accessed from outside the class, however, they can be accessed in inherited classes

## final class
* inheritance is prohibited

## static data
* is not associated with a particular object, belongs to the class rather than objects of the class  
* can be called using the class name or through an object

## const data != mutable
* we can't modify it directly (a compile-time error)  
* we can't modify it through a pointer/reference to non-const type (undefined behavior)  
* we can't modify it by a (const nor a non-const) member function, even if it is passed by reference  
* we can modity if by constructor/destructor   
* we can modity if by casting the const away (not advised)  
* we can't call a non-const method a const object   
* we can't call a non-const method through a pointer/reference to a const object if the referred-to object is const   
* we can't call a non-const method through a pointer/reference to a const object if the referred-to object is not const  
`const int C=3` parameters which will not be changed fter compiling  
`const int *C` a pointer to a constant int, we can change the pointer, we can not change the value of the variable 
`int const *C` the same  
`int * const C` a constant pointer to int, we can not change the pinter, we cn change the value of the variable   
`int const * const C` a constant pointer to a constant int
* a constant object can call directly only a contant methode of a class

## mutable data != const
* we can modify a mutable class member through member functions even if the containing object is const  

## virtual data

## abstract class
* contains (or inherits without redefinition) at least one pure virtual function (the virtual function should be defined in the child class) 
* cannot be directly instantiated  
* may specifies abstract methods via signatures that are to be implemented by its descendants
* all the abstract methods of the parent must be implemented in the child
* may provide implementations of some methods
* another way to prevent a class from being instantiated: make all constructors protected
* a child class calls the constructer of the base class, than its own comstructor
* C++ has no keyword `abstract`

## interface = pure abstract class 
* consists of only virtual member functions (only declarations)

## template class

# Function specifiers

## private / public / protected function
* see private / public / protected data modifiers

## static (not member) function 
* can't be called from other places

## static member function
* does not have a receiver object
* is basically a normal function that's nested inside of the scope of the class
* is not associated with a particular object, belongs to the class rather than objects of the class  
* can be called using the class name or through an object  
* can directly access only static variables and functions  
* doesn't have `*this` pointer  

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
## const funciton != mutable
* не изменяет объект и не вызывает неконстантные методы класса (поскольку они могут изменить объект)  
* компилятор знает, что возвращенное функцией значение поменять нельзя  
* можно иметь константную и неконстантную версии одной и той же функции  

```
const char *func() {
  return "текст";
}
```
## mutable funciton != const

## virtual (member) function
* a member function of a Parent, redefined by a Child 
* must be defined in Parent, even though it is not used
* cannot be static
* when you refer to a Child object by a pointer to the Parent, you call a virtual function and execute its Child’s version 
* is accessed through object pointers
* a constructor and a destructor can not be virtual
* a non-final class with virtual functions should have virtual destructor
* реализуют polymorphisme: в иерархии классов есть функции, имеющие одинаковое имя и параметры и отмеченные `virtual` -> объект и вызов функции из набора виртуальных будут сформированы при выполнении (**позднее связывание**) (один интерфейс, несколько реализаций)
* three scenario:
    - Interface/ abstract class. Pure virtual function, (abstract class and non-instancable (interface).
```
class Interface {
    virtual void f() = 0;
};
class Concrete: public Interface {
    void f() override {} // override f()
};
```
    - Polymorphism/ concrete class. Virtual function was declared as normal function except it can be override by derived class. You must implement it.
```
class Parent {
    virtual void g();
}
class Child: public Parent {
    void g() override{}
}
```
    - **Hide**: a function with the same name of parent, not declared `virtual`

### polymorphysme
* вызов виртуальной функции через имя объекта разрешается статически, динамическое связывание возможно только через указатель или ссылку
* **polymorphic class** определяет или наследует виртуальную функцию
* полиморфными могут быть функции-члены класса (но не класс)

### vtable = virtual function table
* ≈ hidden static data member of the class  
* every object of a polymorphic class is associated with (possibly multiple) vtable for its most-derived class  
* stores pointers to virtual functions 
* when a virtual function is called, the program calls the functions associated ... by vtable   
* if an object of type A does not point to the vtable of A, then that object is actually a sub-object of something derived from A

## abstract function = pure virtual
* declared with `=0`  
* defines a functionality without realisation (the realisation is defined in the inherited classes)  
* a destructor must have a definition (?)
* C++ has no keyword `abstract`  

## override function
* explicit indication that the function is redefined
* `override` keyword is a C++11 extension

## final function
* proihibite `virtual` functions in the inherited classes 

## template function
* allows functions and classes to operate with generic types. This allows a function or class declaration to reference via a generic variable another different class (built-in or newly declared data type) without creating full declaration for each of these different classes.

# Inheritance specifiers

## public inheritance
* public data are inherited as public
* protected data are inherited as protected 

## protected inheritance
* all inherited data become protected

## private inheritance
* all inherited data become private

## virtual inheritance
* предотвращает появление множественных объектов базового класса в иерархии наследования 

# Inheritance
* subclass = derived class = child class
* super class = base class = parent class
* a constructor is not inherited
* a destructor is not inherited
* a destructor must be defined even if it is declared pure-virtual
* a virtual method that is not pure should be defined
* когда дочерний класс инициализирует свой объект, конструкторы вызываются один за другим иерархически, начиная с базового класса и заканчивая последним производным классом, destructors are called in the inverse order
* operator = is inherited, but hidden by the implicitely declared one (явно или неявно определенный оператор закрывает одноименный из базового класса)
* how to use the opetaor = of the parent class in the child class:
```
class Parent {
public:
  Parent& operator = (const Parent &obj) {
    return *this;
  }
};

class Child : public Parent {
public:
  Child& operator=(const Child &obj) {
    Parent::operator=(obj);
    // если тут копирование всех нестатических членов-данных, добавленных в Child, то оператор присваивания можно не определять компилятор сам его добавит неявно
    return *this;
  }
}
```
* a child can have a function with the same name, this function becomes an independant funciton of the child

# Some C++ particularities

## Orthodox canonical class form in C++98 
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

## Reference vs pointer (01 / ex03)
`HumanA` can have a reference or a pointer to the Weapon. Ideally, it should be implemented as a reference, since the Weapon exists from creation until destruction, and never changes (here `HumanA` has `Weapon& weaponREF` attribut).  
`HumanB` must have a pointer to a Weapon since the field is not set at creation time, and the weapon can be NULL (here `HumanB` has `Weapon* weaponPTR` attribut).  
In the both cases we can change the type of the weapon.   

### Reference
* is a dereferenced pointer  
* is an aliase for an existing variable !=  new variable  
* is a constant pointer, always points to the same variable, we can't change it (?)  
* doesn't occupy memory  
* can't point to nothing  
* if something should always exist and never change, use a references  
```
   std::string &sREF = s;
// std::string             тип, на который объявляется ссылка
//             &sREF       переменная типа ссылка на string
//                     s   переменная, на которую объявляется ссылка
```
### Pointer
* can point to a non-existing address  
* if something should not always exist and can change, use a pointer  

## File manipulation (01 / ex04)

### C (forbidden by the subject)
* FILE *fp  
* fopen, fclose, fwrite, fread, ftell, fseek, fprintf, fscanf, feof, fileno, fgets, fputs, fgetc, fputc  
* modes : r, w, a  
* `int my_int = 32; printf("%s", my_int)` fails  
* hard-coded maximum buffer sizes  

### C++ 
* fstream f  
* f.open, f.close, f>>, f<<, f.seekg, f.seekp, f.tellg, f.tellp, f.read, f.write, f.eof  
* modes : ios::in, ios::out, ios::bin , ...  
* Fstream closes the files when they leave scope  
* how input and output type is defined by the variable type  
* dynamically sizing receiving strings based on the actual input  
* extensibility for user-defined types (i.e. you can teach streams how to handle your own classes)  
* exceptions  

## Convertion (01 / ex04)
### std::string to char* 
```
std::string str;
const char * c = str.c_str();
char       * c = str.data();
```
### char* to string
- Using the “=” operator
- Using the string constructor
- Using the assign function

# Floating-point numbers vs Fixed-point numbers (02)
* **Accuracy** to how close a measurement is to the true value  
* **Precision** how much information you have about a quantity, how uniquely you have it pinned down

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
Representing non-integer numbers by storing a fixed number of digits of their fractional part.  
Fixed point arithmetic is much faster.  
Example : Dollar amounts are often stored with exactly two fractional digits, representing the cents.  
Example : $1234.4321_{float}$ = (316014.6176, 8) = (316015, 8) = ($00000000.00000100.11010010.01101111_{2}$, 8) 

# School Requirements
* a header should include all the dependencies it needs

## Are forbidden:
- external libraries or features from versions other than C++98
- boost libraries
- *printf(), *alloc(), free()
- namespace
- `friend` keywords
- reading the string character by character (we should use functions std::string) 
- C file manipulation functions
- containers (vector/list/map/and so forth)
- algorithms (anything that requires to include the <algorithm> header)
- a function implementation put in a header file (except for function templates)
- memory leaks
- double inclusion (avoid it by adding include guards)  
- `public` without any reason
  
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

## ***
07/ex01: тестируют const (!)
