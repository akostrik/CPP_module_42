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
* belongs to the class, is not associated with a particular object  
* is called using the class name or through an object
* static class = a private and unimplemented default constructor (formally C++ does not have static classes)

## abstract class
* contains (or inherits without redefinition) at least one pure virtual (abstract) function
* all the abstract methods of the parent must be implemented in the child
* may provide implementations of some methods
* cannot be instantiated  
* another way to prevent a class from being instantiated: make all the constructors `protected`
* C++ has no keyword `abstract`

## interface = pure abstract class 
* consists of only virtual member functions (only declarations)
* non-instancable

## const data != mutable
`any              function` can't           modify `                    const data`  
`any              function` can &nbsp;&nbsp;modity `casted const away   const data` (not advised)   
`    const member function` can't           modify `passed by value     const data`  
`    const member function` can't           modify `passed by reference const data`  
`non-const member function` can't           modify `passed by value     const data`   
`non-const member function` can't           modify `passed by reference const data`   
`constructor              ` can &nbsp;&nbsp;modify `                    const data`  
`destructor               ` can &nbsp;&nbsp;modify `                    const data`  
`                           const object`.`non-const member function` NON    
`pointer/reference to a     const object`.`non-const member function` NON  
`pointer/reference to a non const object`.`non-const member function` NON  
`                           const object`.`    const member function` OK  
`                           const object`.`non const member function` NON  

After compiling:  
const variable cannot be left un-initialized at the time  
`const int                с = 3` &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;can't change the value  
`const int               *с    `  can&nbsp;&nbsp;&nbsp;change the pointer, can't change the value  
`       int         const *с     ` can&nbsp;&nbsp;&nbsp;change the pointer, can't change the value  
`       int       * const  с     ` can't change the pointer, can&nbsp;&nbsp;&nbsp;change the value    
`       int const * const  с     ` can't change the pointer, can't change the value  
  
`const std::string& s = "AB";` OK, const запрещает умирать временному объекту, который присваивается этой ссылке, он жив пока жива константная ссылка  
`      std::string& s = "AB";` NON, ссылка на адрес памяти указывает на тот же, на который и объект ей присвоенный, если объект временный, то он сразу умирает

## mutable data != const
* we can modify a mutable class member through member functions even if the containing object is const  

## virtual data

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
  static void f();
};

void MyClass::f() {} // do not write 'static'

int main() {
  MyClass::f();
}
```
## const non-member function
* doesn't exist

## const member funciton != mutable
* doest't change the object
* doesn't call non-constant member functions  
* we can't change the return value
* we can have a constant version and a non-constant version of the same function

```
const char *func() {
  return "text";
}
```
## mutable member funciton != const

## virtual (member) function
* a member function of a Parent, redefined by a Child (the same name and parametres) (one interface, several realisations) (**polymorphic functions**)
* must be defined in Parent
* cannot be static
* a pointer to the Parent's function calls the Parent's virtual function and executes its Child’s version 
* a constructor and a destructor can not be virtual, a destructor must have a definition
* a destructor of a non-final class with virtual functions is virtual (?)
* **polymorphic class**: defines or inherits a virtual function 
* объект и вызов функции будут сформированы при выполнении (**позднее связывание**) 
* вызов виртуальной функции через имя объекта разрешается статически

3 scenarios:  
`class IPar { virtual void f() = 0 } class Chld: public IPar { void f() {} }`  **Interface** defines a functionality, Child defines the realisation  
`class Par  { virtual void f()     } class Chld: public Par  { void f() {} }`  Child **override** a virtual function   
`class Par  {         void f()     } class Chld: public Par  { void f() {} }`  Child **hide** a non-virtual function   

Virtual function table :  
* ≈ hidden static data member of the class  
* every object of a polymorphic class is associated with (possibly multiple) vtable for its most-derived class  
* stores pointers to virtual functions 
* when a virtual function is called, the program finds the associated function by vtable   
* if an object of type A does not point to the vtable of A, then that object is actually a sub-object of something derived from A

## abstract function = pure virtual
* cf. virtual function   
* C++ has no keyword `abstract`  

## override function
* explicit indication that the function is redefined
* `override` keyword is a C++11 extension

## final function
* proihibite `virtual` functions in the inherited classes 

## template function
* allows functions and classes to operate with generic types. This allows a function or class declaration to reference via a generic variable another different class (built-in or newly declared data type) without creating full declaration for each of these different classes.

## friend functon
* не являются членами класса
* имеют доступ к его private переменным и функциям

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

# Object-oriented programmine

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

## incapsulation
* данные **инкапсулированы**, насколько возможно -> они скрываются -> меньше частей программы могут их видеть -> больше гибкости для внесения изменений

# C++ feautures
http://www.cplusplus.com/reference

## Orthodox canonical class form in C++98 
- Default constructor
- Copy constructor
- Destructor
- Copy assignment operator

```
class A
{
   public:
      A ();
      A (const A &a);
      ~A ();
      A &operator = (const A &a);
};
```

## Reference vs pointer (01/ex03)
* `HumanA`: a reference or a pointer to the Weapon, and a reference is better since the Weapon exists from creation and never changes
* `HumanB`: a pointer to a Weapon, since the field is not set at creation time and the weapon can be NULL
* in the both cases, we can change the type of the weapon

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

## File manipulation (01/ex04)

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

## Convertion and cast (01/ex04, 06/ex00)
`std::string` инициализирован динамически, не статически   
`std::string` подобие динамического массива char'ов, подобие vector<char>  
string != строковый литерал  

|                      | `char`         | `char*`                                 | `std::string`     | `int`      | `float` | `double`
|----------------------|----------------|-----------------------------------------|-------------------|------------|---------|---------
| to `char*`           | x              |                                         | c_str()           |            |         |
| to `std::string`     |                | = / string constructor / s.data() c++11 | x                 | atoi       |         |
| to int               |                |                                         | atoi / stoi c++11 | x          |         |
| to float             |                |                                         | strtof            | implicit   | x       |
| to double            |                |                                         | strtod            | implicit   |         | x
 
### Static Cast
* для приведения одного типа к другому
* static_cast<встроенные типы>: встроенные в C++ правила приведения  
* static_cast<типы определенны программистом>: правила приведения, определенные программистом  
* static_cast<pointer> корректно если один из указателей - это void*
* static_cast<pointer> корректно если это приведение между объектами классов, где один класс является наследником другого  
* a compile-time cast

```
float a = 5.2;
int b = static_cast<int>(a);
```

### Dynamic cast 
1) TYPE& dynamic_cast<TYPE&> (object); to cast from references to base class objects to references to derived class objects
2) TYPE* dynamic_cast<TYPE*> (object);

* casts a datum from one pointer or reference type to another
* casting to pointer to a type that is not a type of actual object -> result = NULL 
* casting to reference to a type that is not a type of actual object -> bad_cast exception
* we cannot verify the success by `if(reference types == 0)` (because there is no such thing as a 0-reference)
* may be used to find the type of object (!)
* there should be at least one virtual function in the Base class (in practice, this is not a limitation because base classes have a virtual destructor)
* a runtime check to ensure the validity of the cast

```
employee &e;
try { manager &m = dynamic_cast<manager&>(e); }
catch (bad_cast) { ... }
```

### Const Cast

### Reinterpret Cast
* `data_type *var_name = reinterpret_cast <data_type *>(pointer_variable)`
* converts a pointer into a pointer of another type
* does not check if the pointer type = type of the pointed data 
* doesn’t have any return type

### `uintptr_t` data type (06/ex02)
* an unsigned int type: any pointer to void can be converted to `uintptr_t`, then converted back to pointer to void, the result will compare equal to the original pointer
* an optional type since C99 (?)
* might be the same size as a `void*`, or larger, or smaller: for example on a hypothetical platform where void* is 32 bits, but only 24 bits of virtual address space are used, you could have a 24-bit `uintptr_t`

# Floating-point numbers vs Fixed-point numbers (02)
* **Accuracy** to how close a measurement is to the true value  
* **Precision** how much information you have about a quantity, how uniquely you have it pinned down

## Floating-point
[IEEE-754 Floating Point Converter](https://www.h-schmidt.net/FloatConverter/IEEE754.html)
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html  
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html  
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html  
https://stackoverflow.com/questions/60224493/whats-the-largest-number-float-type-can-hold  
https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html  
  
- s sign bit
- e exponent giving its order of magnitude (= порядок = показатель степени)
- m mantissa specifying the actual digits of the number ∊ [1;10)

Decimal	                         | e                            | m   | float                                            
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
Example : Dollar amounts are often stored with exactly two fractional digits, representing the cents  
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
