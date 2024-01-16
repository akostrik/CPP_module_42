# C++ feautures (also C features)
http://www.cplusplus.com  

## Automatic initialisation (OOP feature)
Orthodox canonical class form in C++98: 
```
class A
{
   public:
      A ();                         // default constructor
      A (const A &obj);             // copy constructor
      ~A ();                        // destructor
      A &operator = (const A &obj); // copy assignment operator
};
```

## Inheritance (feature)
* super class = base class = parent class
* subclass = derived class = child class
* a constructor is not inherited
* a destructor is not inherited
* a destructor must be defined even if it is declared pure-virtual
* when a child class initilaies its instance, the constructors are called hierarchically, the destructors are called in the inverse order
* operator = is inherited, but hidden by the implicitely declared one

## Overloading (OOP feature)
* different functions can have the same name provided they are distinguished by their parameter types 
* a child can have a function with the same name, this function becomes an independant funciton of the child
* to use the operator = of the Parent in the Child:
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
    return *this;
  }
}
```

## Incapsulation (OOP feature)
* the data is **incapsulated** as mush as possible -> fewer parts of the program see them -> flexibility for changing

## Types
### `std::string` 
* = `'basic_string<char>`
* ≈ an array of char
* ≈ vector<char>
* initialized dinamically, not statically
* != text literal  

### `uintptr_t` data type (06/ex02)  
* `unsigned int`
* stores a data pointer
* `void*` can be converted to `uintptr_t`, then back to `void*`, the result will compare equal to the original pointer
* typically is the same size as a pointer (may be larger or smaller, for ex on a hypothetical platform where `void*` is 32 bits, but only 24 bits of virtual address space are used, you could have a 24-bit `uintptr_t`)
* utilility: integer-specific operations on a pointer, to do something unusual with a pointer, for ex to invert all bits, you cast a pointer to `uintptr_t`, manipulate it as an int, then cast back

### `intptr_t` data type
...

## Convertions, casts (01/ex04, 06) (only before C++11 information)
https://en.cppreference.com/w/cpp/language  

|                 | `char`               | `char*`                                                        | `std::string`                             | `int`                | `float`              | `double`
|-----------------|----------------------|----------------------------------------------------------------|-------------------------------------------|----------------------|----------------------|---------
| to `char*`      | ---                  | ---                                                            | c_str()  sscanf  stringstream             |                      |                      |
| to `std::string`| sprintf  stringstream| =  string_constructor  stringstream  _s.data()  std::to_string_| ---                                       | sprintf  stringstream| sprintf  stringstream| sprintf  stringstream
| to `int`        |                      |                                                                | atoi  stringstream  sscanf  _stoi_        | ---                  |                      |
| to `float`      |                      |                                                                | atof  strtof  stringstream  sscanf  _stof_| implicit             | ---                  | implicit
| to `double`     |                      |                                                                | strtod  stringstream  sscanf  _stod_      | implicit             | implicit             | ---
  
* С-style cast: `(int)x`, `int(x)` etc
    + casts off  `const` и `volatile`
    + int -> ptr
    + ptr -> int
    + Child* -> Parent*
    + Parent* -> Child*
    + casts pointers as reinterpret_cast
    + tries in turn:
        - const_cast
        - static_cast
        - static_cast, then const_cast
        - reinterpret_cast
        - reinterpret_cast, then const_cast
   + is not verified by the compiler => error possible, for ex, while convertign of const types or while changing the type of the data without checking the possible range of the types
   + should be avoided
* `const_cast<target-type ﻿>(expr) ﻿`
    + the simpliest cast
    + usage: to remove or add `const` or `volatile` (no other C++ cast is capable of removing it)
* `static_cast<target-type ﻿>(expr ﻿)` (06/ex00)		
    + usage: ordinary type conversions
    + ≈ implicit type conversions 
    + compile-time
    + explicitly performs involving lvalue-to-rvalue, array-to-pointer, function-to-pointer conversion 
    + can call explicit or implicit conversion functions
    + Parent      -> Child&
    + Parent*     -> Child*
    + Child*      -> Parent*
    + expr        -> void : discards the value of expression after evaluating it
    + ptr         -> void*
    + void*       -> ptr (any object type)
    + int         -> enumeration
    + enumeration -> enumeration
    + float       -> enumeration
    + void*       -> *T -> void\* -> the original value
* `dynamic_cast<target-type ﻿>(expr) ﻿` (06/ex02)
    + usage: cast within an inheritance hierarchy, cast sideways or even up another chain, seeks out the desired object and returns it if possible
    + usage: to handle polymorphism
    + usage: to find the type of object
    + Parent should have a virtual function (Parent always has a virtual destructor)
    + ptr / ref                       -> ptr / ref within an inheritance hierarchy
    + ptr / ref to a polymorphic type -> ptr / ref to any type
    + Parent                          -> Child*
    + Parent&                         -> Child& `Parent &p; try { Child &m = dynamic_cast<Child&>(p); } catch (bad_cast) { }` (safe downcast)
* `reinterpret_cast<target-type ﻿>(expr ﻿)` (06/ex01)
    + usage: weird conversions, bit manipulations (like turning a raw data stream into actual data, or storing data in the low bits of a pointer to aligned data)
    + prt / ref                       -> prt / ref
    + prt / ref                       -> int
    + int                             -> prt / ref 
    + can't cas a value to a value
    + turns one type directly into another
    + cast the result back -> the original value
* `std::bit_cast` (c++20)
* `literal_cast`
* stringstream
```
template <typename T> T fromStr(const std::string& s) {
  std::istringstream iss(s);
  T v;
  iss >> v;
  return v;
}
template <typename T> std::string toStr(T v) {
  std::ostringstream oss;
  oss << v;
  return oss.str();
}
int i = fromStr<int>(toStr(5));
```
* stoi (c++11)  
* s.data() (c++11)  
* std::to_string (c++11)  
* stod (c++11) 

## Implicit conversion sequence 
* to convert an argument in a function call to the type of the corresponding parameter in a function declaration

### Standard conversion sequences
1) Exact match includes the conversions:
    + identity conversions
    + lvalue-to-rvalue conversions
    + array-to-pointer conversions
    + qualification conversions
2) Promotion
    + integral and floating point promotions
3) Conversion includes the conversions:
    + int and float conversions
    + float-int conversions
    + pointer conversions
    + pointer-to-member conversions
    + boolean conversions

### User-defined conversion sequences
Consists of :
* a standard conversion sequence
* a user-defined conversion
* a second standard conversion sequence

### Ellipsis conversion sequences
Occurs when the compiler matches an argument in a function call with a corresponding ellipsis parameter

## Templates
Allows functions and classes to operate with generic types.  
A templated class or function is the equivalent of (before compiling) copying and pasting the templated block of code, and then replacing the template parameter with the actual one.  
Class templates / variable templates  
```
template<typename T> T max(T &a, T &b) {
  return a > b ? a : b;
}
```

##  Value 
* is the representation of some entity that can be manipulated by a program  
* this terminology is used to categorize expressions (and not values)  

**R-value**: 
* r = right side of the assignment operator
* content
* refers to an object that persists beyond a single expression
* can be l-values or non-l-values
* Ex: the programm is executing, it sees the expression 4 + 9 and generates 13 value, but there is no indications there to strore 13 => 13 is not l-value
  
**L-value**:
* l = left side of the assignment operator
* something that could be assigned to
* a variable or a de-referenced reference
* location
* a temporary value that does not persist beyond the expression that uses it    
* has storage addresses that are programmatically accessible to the running program (for ex, using &)
* Ex: the cariable x is declared and attributed the value 13
   
## Reference vs pointer (01/ex03)
* `HumanA`: a reference or a pointer to the Weapon, and a reference is better since the Weapon exists from creation and never changes
* `HumanB`: a pointer to a Weapon, since the field is not set at creation time and the weapon can be NULL
* in the both cases, we can change the type of the weapon  

Reference:  
* is a dereferenced pointer  
* is an aliase for an existing variable !=  new variable  
* is a constant pointer, always points to the same variable, we can't change it (?)  
* doesn't occupy memory  
* can't point to nothing  
* if something should always exist and never change, use a references  
```
   std::string &sREF = s;
//             &sREF       the variable of the type 'reference to string'
//                     s   the variable the reference is declared to
```
  
Pointer:  
* can point to a non-existing address  
* if something should not always exist and can change, use a pointer  

## File manipulations (01/ex04)

C file manipulations:  
* FILE *fp  
* fopen, fclose, fwrite, fread, ftell, fseek, fprintf, fscanf, feof, fileno, fgets, fputs, fgetc, fputc  
* modes : r, w, a  
* `int my_int = 32; printf("%s", my_int)` fails  
* hard-coded maximum buffer sizes  

C++ file manipulations:  
* fstream f  
* f.open, f.close, f>>, f<<, f.seekg, f.seekp, f.tellg, f.tellp, f.read, f.write, f.eof  
* modes : ios::in, ios::out, ios::bin , ...  
* Fstream closes the files when they leave scope  
* how input and output type is defined by the variable type  
* dynamically sizing receiving strings based on the actual input  
* extensibility for user-defined types (you can teach streams how to handle your own classes)  
* exceptions  

## Standard Template Library (STL)
Provides four components called algorithms, containers, functions, and iterators.  

## Namespace
Anonymous namespaces make private things really private.  

## Resolution
**lexical resolution** = **early binding** can be determined at compile time
**dynamic resolution** = **late binding** can be determined at run time

## System call
* call to the kernel
* != call to a systle library
* processus management: load, execute, exit, abort, fork, processus terminating, get/set process attributes, wait, signal, allocate, free
* file management: create, delete, open, close, read, write, reposition, get/set file attributes
* devicaes management: request device, release device, read, write, reposition, get/set device attributes, logically attach or detach devices
* information management: get/set time or date, get/set system data, get/set process, file, device attributes
* communications: create, delete communication connection, send, receive messages, transfer status information, attach or detach remote devices

## malloc
* free of the memory should be procedded in the inverse order to malloc
* malloc allocates more memory that the programmes asked, because it puts the size of the block in the beginning on the bloc  
+-----+--------------------------     ----+  
| 100 |                           ...     |  
+-----+--------------------------     ----+  
^  ^  ^  
|  |  the address retured by `malloc`  
|  the size   
the real beginning of the bloc  
* free() reads the size of the bloc and so knows how much memory it should free

## Specifiers

### public / private / protected data
* public members are accessible from outside the class  
* private: members cannot be accessed or viewed from outside the class  
* protected: members cannot be accessed from outside the class, however, they can be accessed in inherited classes

### public / private / protected function
* see private / public / protected data modifiers

### public / private / ptotected inheritance
* public: public data are inherited as public, protected data are inherited as protected 
* private: all inherited data become private
* protected: all inherited data become protected

### final class
* inheritance is prohibited

### final function
* prohibites `virtual` functions in the inherited classes 

### static variable in a function
* is initialized one time, the memory is allocated one time, the variable stores its value between the function calls during all the time of the executoin of the programm
* is stored in the memory segments .data и .bss (not heap, not stack)
* is slower than a non-static variable (the programm goes to another memory segment, vérifies if the variable is initialized)
* to be careful while multithreading

## static member of a class  
* belongs to the class, is not associated with a particular object, is the same for all the class instances
* if we crate three instances of the class, the constructor is called only one time
* can not be nitialized by a constructor
* definition of an object: out of the class, by `::`-operator
* declaration of an object: `static A a;`
* is called using the class name or through an object

### static class
* ≈ a class with only static methods and members
* formally C++ does not have static classes (Java-like languages like C# have no non-member functions, so they have static classes)
* In C++, the namespace is more powerful thamn static class, because:
    + static methods have access to the classes private symbols
    + private static methods are still visible (if inaccessible) to everyone, which breaches somewhat the encapsulation
    + static methods cannot be forward-declared
    + static methods cannot be overloaded by the class user without modifying the library header
    + there is nothing that can be done by a static method that can't be done better than a (possibly friend) non-member function in the same namespace
    + namespaces have their own semantics (can be combined, can be anonymous, ...)
* can't be instanciated
* can't be inherited
* should have constructors / destructors au a usual class ?
* usage: to group ressembling methods, proprieties and fields
* usage: prevent writing instance members/methods

### static not member function 
* can't be called from other places

### static member function
* is not associated with a particular object, belongs to the class rather than objects of the class  
* basically a normal function that's nested inside of the scope of the class
* can be called using the class name or through an object  
* can access only static variables and functions  
* doesn't have `*this`
* can beused without instantiating if the class
* ia accessed by the class nale ou by the :: operator
* can call ony static functions, members, extern functions
* has the same scope as its class 

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
### abstract class
* contains (or inherits without redefinition) at least one pure virtual (abstract) function
* all the abstract methods of the parent must be implemented in the child
* may provide implementations of some methods
* cannot be instantiated  
* another way to prevent a class from being instantiated: make all the constructors `protected`
* C++ has no keyword `abstract`

### abstract function = pure virtual
* C++ has no keyword `abstract`  

### interface = pure abstract class 
* consists of only virtual member functions (only declarations)
* non-instancable

### override function
* explicit indication that the function is redefined
* `override` keyword is a C++11 extension

### const / mutable data
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
  
`const std::string& s = "AB";` OK, the temporary object is alive as long as the const ref is alive  
`      std::string& s = "AB";` NON, the temporary object disappeares

* mutable: * we can modify a mutable class member through member functions even if the containing object is const

### const not member function
* doesn't exist

### const / mutable member funciton
* doest't change the object
* doesn't call non-constant member functions  
* we can't change the return value
* we can have a constant version and a non-constant version of the same function
* mutable = const
```
const char *func() {
  return "text";
}
```

### volatile data

### virtual data

### virtual member function
* a member function of a Parent, redefined by a Child (the same name and parametres) (one interface, several realisations) (**polymorphic functions**)
* must be defined in Parent
* cannot be static
* a pointer to the Parent's function calls the Parent's virtual function and executes its Child’s version 
* a constructor and a destructor can not be virtual, a destructor must have a definition
* a destructor of a non-final class with virtual functions is virtual (?)
* run-timed the object vreation and function call (late binding) 
* stqtic resolution of a call of a virtual funciton via the object name

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

### virtual inheritance
* prevents a lot of Children of a Parent (?) 

### template class

### template function
* allows functions and classes to operate with generic types. This allows a function or class declaration to reference via a generic variable another different class (built-in or newly declared data type) without creating full declaration for each of these different classes.

### extern data
a global variable becomes accessible in any file of the programm

### auto (c++20)
In any of the parameters of a function declaration: that declaration becomes an abbreviated function template declaration

### friend functon
* are not member functions
* have acces to its private variables and functions

### inline (c++ 17)

### explicit

### terminlogy in the same style
**Incomplete class** : a class until the end of its definition
**Polymorphic class**: defines or inherits a virtual function 

# Approximation to real numbers
**Accuracy** how close a measurement is to the true value  
**Precision** how much information you have about a quantity  

## Single-precision floating-point approximation (FP32, float32)
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html  
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html  
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html  
  
* Represents subsets of real numbers using an int with a fixed precision (significand), scaled by an integer exponent of 2
* Similar to concept to scientific notation   
* Represent extremely small values as well as extremely large
* Using 32 bits, it's not possible to store every digit in such numbers
* Every time a floating point operation is done, some precision is lost. You can reduce the error by replacing floating point arithmetic with int as much as possible.  

### IEEE 754 formats (1985)  
[IEEE-754 Floating Point Converter](https://www.h-schmidt.net/FloatConverter/IEEE754.html)  
* `std::numeric_limits<T>::infinity()` the largest representable value  
* `std::numeric_limits<T>::max()` the largest finite value  
* `std::numeric_limits<T>::min()` the smallest positive normal value (there precision loss starts)  
* `std::numeric_limits<T>::denorm_min()` the smallest positive value, if the type has subnormal values  
* `std::numeric_limits<T>::lowest()` the least finite value (c++11)
    
**Normal = normilized floating point numbers**:    
* a real number may be approximated by multiple floating point representations, one of the representations is defined as _normal_
* e != 11111111, e != 00000000  
* m [0,1), no leading zeros in the mantissa, for example, 0.0123 would be written as $1.23 × 10^{−2}$
* an invisible 1 (not stored) is placed in front  
* the exponent is stored without sign => it is deplaced by 127, there is -127 in the table
* n ∈ [0 ; $2^{24}$] точно (полностью влезают в мантиссу)
* n ∈ [ $2^{24}$ + 1 ; $2^{25}$] rounded to a multiple of 2
* n ∈ [ $2^{25}$ + 1 ; $2^{26}$] rounded to a multiple of4
* ...
* n ∈ [ $2^{126}$ + 1 ; $2^{127}$] rounded to a multiple of $2^{103}$
* n ∈ [ $2^{127}$ + 1 ; $2^{128}$] rounded to a multiple of $2^{104}$
* n ∈ [ $2^{128}$ + 1 ; ...] turn into infinity
  
binary    	                                 | formula                                         | decimal 
---------------------------------------------|-------------------------------------------------|----------------------
s&nbsp;eeeeeeee&nbsp;mmmmmmmmmmmm...m        | $1.(m)                 * 2^{e  −127} * (-1)^{s}$|  
s&nbsp;eeeeeeee&nbsp;mmmmmmmmmmmm...m        | $(1+m/ 2^{23})         * 2^{e  −127} * (-1)^{s}$| 
0&nbsp;00000001&nbsp;00000000000000000000000 | $1.0                   * 2^{1  -127}           $| 1.17549435e-38 FLT_MIN min without losing precision
1&nbsp;01111111&nbsp;00000000000000000000000 | $1.0                   * 2^{127-127} * (-1)^{1}$| -1
0&nbsp;01111100&nbsp;01000000000000000000000 | $1.25                  * 2^{1  -127}           $| 0.15625
0&nbsp;01111101&nbsp;00000000000000000000000 | $1.0                   * 2^{125-127}           $| 0.25 
0&nbsp;01111110&nbsp;00000000000000000000000 | $1.0                   * 2^{126-127}           $| 0.5
0&nbsp;01111111&nbsp;00000000000000000000000 | $1.0                   * 2^{127-127}           $| 1.0
0&nbsp;10000000&nbsp;00000000000000000000000 | $1.0                   * 2^{128-127}           $| 2.0 
0&nbsp;10000000&nbsp;10000000000000000000000 | $1.5                   * 2^{128-127}           $| 3.0
0&nbsp;10000000&nbsp;10010001111010111000011 | $1.5700000524520874    * 2^{128-127}           $| 3.14  
0&nbsp;00000000&nbsp;00000000000000000000000 | $(-1)^0   * \frac{3,14-2}{4-2}    * 2^{150-127}$ | 3.14, 3.14 ∊ [ $2^1$ ; $2^2$ ), $2^7$ 
0&nbsp;10000001&nbsp;00000000000000000000000 | $1.0                   * 2^{129-127}           $| 4.0
0&nbsp;10000001&nbsp;01000000000000000000000 | $1.25                  * 2^{129-127}           $| 5.0 
0&nbsp;10000001&nbsp;10000000000000000000000 | $1.5                   * 2^{129-127}           $| 6.0 
0&nbsp;10000001&nbsp;11000000000000000000000 | $1.75                  * 2^{129-127}           $| 7.0 
0&nbsp;10000010&nbsp;00000000000000000000000 | $1.0                   * 2^{130-127}           $| 8.0
0&nbsp;10010110&nbsp;11111111111111111111111 | $1.9999998807907104    * 2^{150-127}           $| 16777215   
0&nbsp;10010111&nbsp;00000000000000000000000 | $1.9999998807907104    * 2^{150-127}           $| 16777216 = $2^{24}$ max неокругляющийся   
0&nbsp;10010111&nbsp;00000000000000000000000 | $1.9999998807907104    * 2^{150-127}           $| 16777217 -> 16777216 
0&nbsp;10010111&nbsp;00000000000000000000001 | $1.9999998807907104    * 2^{150-127}           $| 16777218
0&nbsp;10010111&nbsp;00000000000000000000010 | $1.9999998807907104    * 2^{150-127}           $| 16777219 -> 16777220
0&nbsp;10011010&nbsp;10011001100110011001100 | $1.5999999046325684    * 2^{154-127}           $| 2147483581->2147483520
0&nbsp;10011010&nbsp;10011001100110011001100 | $1.5999999046325684    * 2^{154-127}           $| 2147483582->2147483520
0&nbsp;10011010&nbsp;10011001100110011001100 | $1.5999999046325684    * 2^{154-127}           $| 2147483583->2147483520
0&nbsp;10011110&nbsp;00000000000000000000000 | $1.0                   * 2^{158-127}           $| 2147483584->2147483648
0&nbsp;10011110&nbsp;00000000000000000000000 | $1.0                   * 2^{158-127}           $| 2147483585->2147483648
0&nbsp;10011110&nbsp;00000000000000000000000 | $1.0                   * 2^{158-127}           $| ...
0&nbsp;10011110&nbsp;00000000000000000000000 | $1.0                   * 2^{158-127}           $| 2147483646->2147483648
0&nbsp;10011110&nbsp;00000000000000000000000 | $1.0                   * 2^{158-127}           $| 2147483647->2147483648
0&nbsp;10011110&nbsp;00000000000000000000000 | $1.0                   * 2^{158-127}           $| 2147483648
0&nbsp;11111110&nbsp;11111111111111111111111 | $(-1)^0   * 1+ (2^{23}−1)/ 2^{23} * 2^{254−127}$| 340282346638528859811704183484516925440 FLT_MAX

**Denormalized = denormal floating point numbers**:     
* expands the floating point range at the expense of precision
* e = 00000000  
* m starts with 0        
* m != 00000000000000000000000  
* m [0,1) ?  
* Some old documents: _denormal_ = _subnormal_.  
* Casual discussions often: _denormal_ = _subnormal_.  
* IEEE: ${denormals} = {subnormals}$ (there are no denormalized binary numbers outside the subnormal range)  

**Subnormal floating point numbers**:    
* A subset of demormilised numbers
* Any non-zero number with magnitude smaller than the smallest positive normal number
* Fill the underflow gap around zero
* If normalized, would have exponents below the smallest representable exponent
* e minimal  
  
binary    	                                 | formula                                         | decimal 
---------------------------------------------|-------------------------------------------------|---------
s&nbsp;00000000&nbsp;0mmmmmmmmmmm...m        | $(0+m/ 2^{23})         * 2^{1  -127} * (-1)^{s}$|         
s&nbsp;00000000&nbsp;0mmmmmmmmmmm...m        | $0.(m)                 * 2^{1  -127} * (-1)^{s}$|         
0&nbsp;00000000&nbsp;00000000000000000000001 | $(2^{-23})             * 2^{1  -127}           $| 1.40129846432481707092372958328991613128026194187651577175706828388979108268586060148663818836212158203125E&#8209 min&nbsp;representable
0&nbsp;00000000&nbsp;11111111111111111111111 | $0.9999998807907104    * 2^{1  -127}           $| 1.17549421069e-38 min
  
**Specail values (reserved in IEEE 754)**  
e = 11111111  
Получающихся в результате деления на ноль или при превышении числового диапазона.  
  
binary    	                                 | formula                                         | decimal 
---------------------------------------------|-------------------------------------------------|------------------
0&nbsp;00000000&nbsp;00000000000000000000000 | $0.0                   * 2^{1  -127}           $| 0.0     
0&nbsp;11111111&nbsp;00000000000000000000000 |                                                 | +inf 
1&nbsp;11111111&nbsp;00000000000000000000000 |                                                 | -inf
0&nbsp;11111111&nbsp;1********************** |                                                 | +NaN Not a Number

### The Microsoft Binary Format (MBF) 
...

### Minifloat
...  

### bfloat16
...  

### TensorFloat-32
...  

### IBM floating-point architecture
...  

### PMBus Linear-11
...  

### G.711 8-bit floats
...  

### Arbitrary precision
...  

## Double-precision floating-point approximation (FP64, float64)
### IEEE 754 double-precision binary floating-point format (binary64)
binary    	                                                                          | formula                     | decimal 
--------------------------------------------------------------------------------------|------------------------------------|-----
0&nbsp;00000000001&nbsp;00000000000000000000000000000000000000000000000000000000000000| $1.0                         * 2^{1   -511}$| 2.2250738585072014E-308 DBL_MIN min without losing precision
0&nbsp;01111111111&nbsp;00000000000000000000000000000000000000000000000000000000000000| $1.0                         * 2^{511 -511}$| 1.0
0&nbsp;10000110011&nbsp;00000000000000000000000000000000000000000000000000000000000000| $ ...                        * 2^{... -511}$| 9007199254740990 = $2^{53}$ max int in 53 bits   
0&nbsp;11111111110&nbsp;11111111111111111111111111111111111111111111111111111111111111| $(-1)^0* 1+(2^{32}−1)/2^{32} * 2^{1022−511}$| 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000 DBL_MAX 

## Fixed-point 
https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html  
  
Representing non-integer numbers by storing a fixed number of digits of their fractional part.  
Fixed point arithmetic is much faster than the floating-point one.  
Example: Dollar amounts are often stored with exactly two fractional digits, representing the cents  
Example: $1234.4321_{float}$ = (316014.6176, 8) = (316015, 8) = ($00000000.00000100.11010010.01101111_{2}$, 8)  

## Logarithmic 
Represent a real number by the logarithm of its absolute value and a sign bit. 

## Tapered floating-point
Does not appear to be used in practice.

## Interval 
Allows one to represent numbers as intervals and obtain guaranteed bounds on results. It is generally based on other arithmetics, in particular floating point.

## Rational representation to real numbers
Represent numbers as fractions with integral numerator and denominator, and can therefore represent any rational number exactly. 

## Without encoding representation of real numbers
Handles irrational numbers like pi or sqrt{3} in a formal way, without dealing with an encoding. Process the underlying mathematics directly, instead of using approximate values for each intermediate calculation.  
Computer algebra systems such as Mathematica, Maxima, Maple.
