# Object Oriented Programming (OOP) 

## Automatic initialisation, constructors, destructors
Orthodox canonical class form in C++98: default constructor, copy constructor, destructor, copy assignment operator
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

## Overloading (different functions can have the same name provided they are distinguished by their parameter types. 

## Inheritance
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

## Incapsulation
* данные **инкапсулированы**, насколько возможно -> они скрываются -> меньше частей программы могут их видеть -> больше гибкости для внесения изменений

# C++ feautures
http://www.cplusplus.com/reference

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

## Templates
Allows functions and classes to operate with generic types.  
A templated class or function is the equivalent of (before compiling) copying and pasting the templated block of code, and then replacing the template parameter with the actual one.  
Class templates / variable templates  
```
template<typename T> T max(T &a, T &b) {
  return a > b ? a : b;
}
```

## Types
`std::string` инициализирован динамически, не статически   
`std::string` = `'basic_string<char>` ≈ динамический массив char'ов ≈ vector<char>  
`std::string` != строковый литерал  

### Limits
`std::numeric_limits<T>::infinity()` the largest representable value (if T supports infinity, std::numeric_limits<T>::has_infinity = true)  
`std::numeric_limits<T>::max()` the largest finite value  
`std::numeric_limits<T>::min()` the smallest positive normal value. Floating-point formats have an interval where the exponent cannot get any smaller, but the significand is allowed to get smaller until it reaches zero, this comes at the expense of precision, min() is the point where this precision loss starts  
`std::numeric_limits<T>::denorm_min()` the smallest positive value = std::numeric_limits<T>::min() if the type doesn't have subnormal values  
`-std::numeric_limits<T>::infinity()` is the least value, negative infinity (if std::numeric_limits<T>::has_infinity == true and std::numeric_limits<T>::is_signed == true)  
`std::numeric_limits<T>::lowest()` the least finite value  (c++11)

## Convertions, casts (01/ex04, 06/ex00) (only before C++11 information)

|                 | `char`         | `char*`                                                 | `std::string`                 | `int`          | `float`        | `double`
|-----------------|----------------|---------------------------------------------------------|-------------------------------|----------------|----------------|---------
| to `char*`      | ---            | ---                                                     | c_str() sscanf myFromStr      |                |                |
| to `std::string`| sprintf myToStr| = string_constructor _s.data()_ _std::to_string_ myToStr| ---                           | sprintf myToStr| sprintf myToStr| sprintf myToStr
| to `int`        | sscanf         | sscanf                                                  | atoi sscanf _stoi_ myFromStr  | ---            |                |
| to `float`      | sscanf         | sscanf                                                  | strtof sscanf atof myFromStr  | implicit       | ---            | implicit
| to `double`     | sscanf         | sscanf                                                  | strtod sscanf _stod_ myFromStr| implicit       | implicit       | ---
  
* atoi при переполнении возвращает INT_MIN/INT_MAX  
* atof при переполнении неопределенное поведение   
    + double x = atof("2147483647"): 2147483647.0   
    + float x = atof("2147483647"): 2147483648.0   
* sscanf при переполнении неопределенное поведение  
    + float f; sscanf ("2147483647","%f",&f); : 2147483648.0
* strtof сообщает о переполнении, о потери значимости, о неправильном формате входных данных
    + strtof("2147483647") = 2147483648.0   
* strtod сообщает о переполнении, о потери значимости, о неправильном формате входных данных
    + strtof("2147483647") = 2147483647.0   
* istringstream (?)
* С-style `(int)` `(float)` etc
    + `(int)double_value` вычисляет целую часть
    + `(char)long_value` отбрасывает значащие разряды
    + отбрасывает `const` и `volatile`
    + преобразовывает `int` в указатель и обратно
    + преобразовывает указатели вверх и вниз по иерархии наследования
    + преобразовывает указатели как reinterpret_cast, ориентируясь на битовое представление
    + по очереди пробует :
        - const_cast
        - static_cast
        - static_cast и затем const_cast
        - reinterpret_cast
        - reinterpret_cast и затем const_cast
* myToStr
```
template <typename T> std::string myToStr(T val) {
  std::ostringstream oss;
  oss<< val;
  return oss.str();
}
```
* myFromStr
```
template<typename T> T myFromStr(const std::string& s) {
  std::istringstream iss(s);
  T res;
  iss >> res;
  return res;
}

int i = myFromStr<int>(myToStr(5));
```
* float->double: such that back from double to float results in exactly the same value  
* int -> float:
    + `int` bigger than 16777216 may lose precision
* stoi c++11  
* s.data() c++11  
* std::to_string c++11  
* stod c++11 
* `const_cast<target-type ﻿>(expr) ﻿`
    + самое простое приведение типов
    + убирает `const` и `volatile`
    + если не удалось, ошибка компиляции
* `static_cast<target-type ﻿>(expr ﻿)` 		
    + https://en.cppreference.com/w/cpp/language/static_cast  
    + для приведения одного типа к другому
    + static_cast<встроенные типы>: встроенные в C++ правила приведения
    + static_cast<типы определенны программистом>: правила приведения, определенные программистом
    + static_cast<pointer> корректно если один из указателей - это void*
    + static_cast<pointer> корректно если это приведение между объектами классов, где один класс является наследником другого
    + нет проверки по диапазону
    + a compile-time cast, если не удалось, ошибка компиляции
    + кроме если это приведение между указателями на объекты классов вниз по иерархии и оно не удалось, результат операции undefined
    + снимается ограничение на видимость базового класса при преобразованиях между указателями/ссылками на классы потомки и базовые классы
    + снимается ограничение на видимость базового класса при преобразованиях между указателями на члены классов
    + static_cast<reference to complete class D>(lvalue of its non-virtual base B) or static_cast<pointer to complete class D>(prvalue pointer to its non-virtual base B) -> downcast
        - if B is ambiguous / inaccessible / virtual base / a base of a virtual base of D -> this downcast is ill-formed
        - no runtime checks to ensure that the object's runtime type is actually D, what should be guaranteed by other means the result refers to the enclosing object of type D
    + if there is an implicit conversion sequence from expression to target-type
    + if overload resolution for a direct initialization of an object or reference of type target-type from expression would find at least one viable function -> static_cast<target-type ﻿>(expression ﻿) returns the imaginary variable Temp initialized as if by target-type Temp(expression ﻿);, which may involve implicit conversions, a call to the constructor of target-type or a call to a user-defined conversion operator.
    + static_cast<void (possibly cv-qualified)>() discards the value of expression after evaluating it
    + if a standard conversion sequence from target-type to the type of expression exists, that does not include lvalue-to-rvalue, array-to-pointer, function-to-pointer, null pointer, null member pointer, or boolean conversion, then static_cast can perform the inverse of that implicit conversion
    + if conversion of expression to target-type involves lvalue-to-rvalue, array-to-pointer, or function-to-pointer conversion, it can be performed explicitly by static_cast
    + a value of integer or enumeration type can be converted to any complete enumeration type.
        - if the underlying type is not fixed, the behavior is undefined if the value of expression is out of range (the range is all values possible for the smallest bit-field large enough to hold all enumerators of the target enumeration).
        - If the underlying type is fixed, the result is the same as converting the original value first to the underlying type of the enumeration and then to the enumeration type.
    + a value of a floating-point type can also be converted to any complete enumeration type.
        - the result is the same as converting the original value first to the underlying type of the enumeration, and then to the enumeration type.
    + a pointer to member of some complete class D can be upcast to a pointer to member of its unambiguous, accessible base class B. This static_cast makes no checks to ensure the member actually exists in the runtime type of the pointed-to object: if B does not contain the original member and is not a base class of the class containing the original member, the behavior is undefined.
    + a prvalue of type pointer to void (possibly cv-qualified) can be converted to pointer to any object type T. Conversion of any pointer to pointer to void and back to pointer to the original (or more cv-qualified) type preserves its original value.
        - if the original pointer value represents an address of a byte in memory that does not satisfy the alignment requirement of T, then the resulting pointer value is unspecified.
        - if the original pointer value points to an object a, and there is an object b of type similar to T that is pointer-interconvertible with a, the result is a pointer to b.
        - otherwise the pointer value is unchanged.
    + as with all cast expressions, the result is a prvalue
```
float a = 5.2;
int b = static_cast<int>(a);
```
* `dynamic_cast<target-type ﻿>(expr) ﻿` 
    + 1) TYPE& dynamic_cast<TYPE&> (object); to cast from references to base class objects to references to derived class objects
    + 2) TYPE* dynamic_cast<TYPE*> (object);
    + casts a datum from one pointer or reference type to another
    + casting to pointer to a type that is not a type of actual object -> result = NULL 
    + casting to reference to a type that is not a type of actual object -> bad_cast exception
    + we cannot verify the success by `if(reference types == 0)` (because there is no such thing as a 0-reference)
    + may be used to find the type of object (!)
    + there should be at least one virtual function in the Base class (in practice, this is not a limitation because base classes have a virtual destructor)
    + a runtime check to ensure the validity of the cast
    + безопасное приведение по иерархии наследования, в том числе и для виртуального наследования
    + dynamic_cast<derv_class *>(base_class_ptr_expr): используется RTTI (Runtime Type Information), чтобы привести один указатель на объект класса к другому указателю на объект класса. Классы должны быть полиморфными, то есть в базовом классе должна быть хотя бы одна виртуальная функция. Если эти условие не соблюдено, ошибка возникнет на этапе компиляции. Если приведение невозможно, то об этом станет ясно только на этапе выполнения программы и будет возвращен NULL.
    + dynamic_cast<derv_class &>(base_class_ref_expr) почти как с указателями, но в случае ошибки во время исполнения исключение bad_cast
    + safe downcast possible
```
employee &e;
try { manager &m = dynamic_cast<manager&>(e); }
catch (bad_cast) { ... }
```
* `reinterpret_cast<target-type ﻿>(expr ﻿)`
    + нужны веские причины
    + результат может быть некорректным
    + никаких проверок не делается
    + `data_type *var_name = reinterpret_cast <data_type *>(pointer_variable)`
    + converts a pointer into a pointer of another type
    + does not check if the pointer type = type of the pointed data 
    + doesn’t have any return type
    + не может быть приведено одно значение к другому значению
    + привести указатель к указателю, указатель к целому, целое к указателю
    + умеет работать со ссылками
    + при приведении указателей на функции
    + reinterpret_cast<whatever *>(some *)
    + reinterpret_cast<integer_expression>(some *)
    + reinterpret_cast<whatever *>(integer_expression)
* lexical_cast
```
#include <boost/lexical_cast.hpp>
boost::lexical_cast<int>(str)
```

### `uintptr_t` data type (06/ex02)
* an unsigned int type: any pointer to void can be converted to `uintptr_t`, then converted back to pointer to void, the result will compare equal to the original pointer
* an optional type since C99 (?)
* might be the same size as a `void*`, or larger, or smaller: for example on a hypothetical platform where void* is 32 bits, but only 24 bits of virtual address space are used, you could have a 24-bit `uintptr_t`

## Data specifiers

### public, private, protected
* public members are accessible from outside the class  
* privat: members cannot be accessed or viewed from outside the class  
* protected: members cannot be accessed from outside the class, however, they can be accessed in inherited classes

### final class
* inheritance is prohibited

### static data
* belongs to the class, is not associated with a particular object  
* is called using the class name or through an object
* static class = a private and unimplemented default constructor (formally C++ does not have static classes)
* выделение памяти происходит только один раз и существуют эти элементы до завершения программы
* хранятся в сегментах памяти .data и .bss (в heap и не на stack), что позволяет хранить значение переменной на протяжении всей жизни программы
* медленнее, чем нестатические переменные (т.к. переход в другой сегмент памяти и проверка инициализации переменной)
* если используете многопоточность, то должны быть осторожными
  
#### static data (variable or object) in a function 
* инициализируется один раз, затем сохраняют значение
* хранит значение между вызовами функции 

#### static variable member of a class
* не инициализируются с помощью конструктора
* определение вне класса с помощью оператора разрешения области видимости (::)
* `static A a;` объявляем объект, а не определяем его
* член класса будет один для всех экземпляров класса
* если создали три объекта класса, то конструктор статического члена класса будет вызван один раз

### static class
* не может создан в виде объекта
* для группирования связанных по смыслу методов, свойств и полей
* содержит только статические методы, свойства, и поля
* не может быть наследован

### abstract class
* contains (or inherits without redefinition) at least one pure virtual (abstract) function
* all the abstract methods of the parent must be implemented in the child
* may provide implementations of some methods
* cannot be instantiated  
* another way to prevent a class from being instantiated: make all the constructors `protected`
* C++ has no keyword `abstract`

### interface = pure abstract class 
* consists of only virtual member functions (only declarations)
* non-instancable

### const data != mutable
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

### volatile data

### virtual data

### template class

### extern
сделать глобальную переменную внешней (которую можно использовать в любом файле программы)

### auto (c++20)
in any of the parameters of a function declaration: that declaration becomes an abbreviated function template declaration

## Function specifiers

### private public protected function
* see private / public / protected data modifiers

### static not member function 
* can't be called from other places

### static member function
* is not associated with a particular object, belongs to the class rather than objects of the class  
* basically a normal function that's nested inside of the scope of the class
* can be called using the class name or through an object  
* can access only static variables and functions  
* doesn't have `*this`
* можное использовать без создания объекта класса
* доступ с использованием имени класса и оператора разрешения области видимости (::)
* внутри функции обращаться можно только к статическим членам данных, другим статическим функциям-членам и любым другим функциям извне класса
* имеет область видимости класса, в котором находится

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
### const not member function
* doesn't exist

### const / mutable member funciton != mutable
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

### virtual member function
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

### abstract function = pure virtual
* cf. virtual function   
* C++ has no keyword `abstract`  

### override function
* explicit indication that the function is redefined
* `override` keyword is a C++11 extension

### final function
* prohibites `virtual` functions in the inherited classes 

### template function
* allows functions and classes to operate with generic types. This allows a function or class declaration to reference via a generic variable another different class (built-in or newly declared data type) without creating full declaration for each of these different classes.

### friend functon
* не являются членами класса
* имеют доступ к его private переменным и функциям

### inline (c++ 17)

## Inheritance specifiers

### public / private / ptotected inheritance
* public: public data are inherited as public, protected data are inherited as protected 
* private: all inherited data become private
* protected: all inherited data become protected

### virtual inheritance
* предотвращает появление множественных объектов базового класса в иерархии наследования 

## Other specifiers

### explicit

# Floating-point approximation to real numbers
* **Accuracy** how close a measurement is to the true value  
* **Precision** how much information you have about a quantity
Represents subsets of real numbers using an integer with a fixed precision (significand), scaled by an integer exponent of a fixed base. Similar in concept to scientific notation.   
  
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html  
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html  
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html  
https://stackoverflow.com/questions/60224493/whats-the-largest-number-float-type-can-hold  
  
## IEEE 754 formats (1985)  
[IEEE-754 Floating Point Converter](https://www.h-schmidt.net/FloatConverter/IEEE754.html)  
  
Every time a floating point operation is done, some precision is lost. You can reduce the error by replacing floating point arithmetic with int as much as possible.  
  
### Normal = normilized floating point numbers  
e != 11111111  
e != 00000000  
m [0,1)   
A real numbers may be approximated by multiple floating point representations. One representation is defined as normal.  
No leading zeros in the mantissa. Rather, leading zeros are removed by adjusting the exponent. For example, 0.0123 would be written as $1.23 × 10^{−2}$.  
An invisible 1 (not stored) is placed in front  
If the exponent reaches -127 (00000000), the leading 1 is no longer used to enable gradual underflow  
невозможно записать ноль  
doesn't store big numbers precisely  
doesn't store `int` bigger than 16777216 precisely  
6 digits: a float with 6 decimal digits can be rounded into a floating-point representation and back without loss of precision  

binary    	                                 | formula                                         | decimal 
---------------------------------------------|-------------------------------------------------|----------------------
s&nbsp;eeeeeeee&nbsp;mmmmmmmmmmmm...m        | $1.(m)                 * 2^{e  −127} * (-1)^{s}$|  
s&nbsp;eeeeeeee&nbsp;mmmmmmmmmmmm...m        | $(1+m/ 2^{23})         * 2^{e  −127} * (-1)^{s}$| 
0&nbsp;00000001&nbsp;00000000000000000000000 | $1.0                   * 2^{1  -127}           $| 1.17549435e-38 FLT_MIN 
1&nbsp;01111111&nbsp;00000000000000000000000 | $1.0                   * 2^{127-127} * (-1)^{1}$| -1
0&nbsp;01111101&nbsp;00000000000000000000000 | $1.0                   * 2^{125-127}           $| 0.25 
0&nbsp;01111110&nbsp;00000000000000000000000 | $1.0                   * 2^{126-127}           $| 0.5
0&nbsp;01111111&nbsp;00000000000000000000000 | $1.0                   * 2^{127-127}           $| 1.0
0&nbsp;10000000&nbsp;00000000000000000000000 | $1.0                   * 2^{128-127}           $| 2.0 
0&nbsp;10000001&nbsp;00000000000000000000000 | $1.0                   * 2^{129-127}           $| 4.0
0&nbsp;10000010&nbsp;00000000000000000000000 | $1.0                   * 2^{130-127}           $| 8.0
0&nbsp;01111100&nbsp;01000000000000000000000 | $1.25                  * 2^{1  -127}           $| 0.15625
0&nbsp;10000001&nbsp;01000000000000000000000 | $1.25                  * 2^{129-127}           $| 5.0 
0&nbsp;10000000&nbsp;10000000000000000000000 | $1.5                   * 2^{128-127}           $| 3.0
0&nbsp;10000001&nbsp;10000000000000000000000 | $1.5                   * 2^{129-127}           $| 6.0 
0&nbsp;10000001&nbsp;11000000000000000000000 | $1.75                  * 2^{129-127}           $| 7.0 
0&nbsp;10000000&nbsp;10010001111010111000011 | $1.5700000524520874    * 2^{128-127}           $| 3.14  
0&nbsp;10010110&nbsp;11111111111111111111111 | $1.9999998807907104    * 2^{150-127}           $| 16777215 max int represented in 24 bits   
0&nbsp;00000000&nbsp;00000000000000000000000 | $(-1)^0   * \frac{3,14-2}{4-2}    * 2^{150-127}$ | 3.14, 3.14 ∊ [ $2^1$ ; $2^2$ ), $2^7$ 
0&nbsp;11111110&nbsp;11111111111111111111111 | $(-1)^0   * 1+ (2^{23}−1)/ 2^{23} * 2^{254−127}$ | 340282346638528859811704183484516925440 FLT_MAX max

### Denormalized = denormal floating point numbers   
e = 00000000  
m начинается с 0, a leading 0        
m != 00000000000000000000000  
m [0,1) ?  
Some old documents: _denormal_ = _subnormal_.  
Casual discussions often: _denormal_ = _subnormal_.  
IEEE: _denormal_ = _subnormal_ (there are no denormalized binary numbers outside the subnormal range)  

#### Subnormal floating point numbers  
Any non-zero number with magnitude smaller than the smallest positive normal number.  
If normalized, would have exponents below the smallest representable exponent.+  
Fill the underflow gap around zero.  
e минимальное  
  
binary    	                                 | formula                                         | decimal |
---------------------------------------------|-------------------------------------------------|---------|
s&nbsp;00000000&nbsp;0mmmmmmmmmmm...m        | $(0+m/ 2^{23})         * 2^{1  -127} * (-1)^{s}$|         |
s&nbsp;00000000&nbsp;0mmmmmmmmmmm...m        | $0.(m)                 * 2^{1  -127} * (-1)^{s}$|         |
0&nbsp;00000000&nbsp;00000000000000000000000 | $0.0                   * 2^{1  -127}           $| 0.0     |
0&nbsp;00000000&nbsp;00000000000000000000001 | $(2^{-23})             * 2^{1  -127}           $| 1.40129846432481707092372958328991613128026194187651577175706828388979108268586060148663818836212158203125E&#8209;45&nbsp;min |
0&nbsp;00000000&nbsp;11111111111111111111111 | $0.9999998807907104    * 2^{1  -127}           $| min |
0&nbsp;00000000&nbsp;11111111111111111111111 | $0.9999998807907104    * 2^{1  -127}           $| 1.17549421069e-38 |
  
**Reserved in IEEE 754**  
e = 11111111  
Получающихся в результате деления на ноль или при превышении числового диапазона.  
  
binary    	                                 | formula                                          | decimal 
---------------------------------------------|--------------------------------------------------|----------------------
0&nbsp;11111111&nbsp;00000000000000000000000 |                                                  | +inf 
1&nbsp;11111111&nbsp;00000000000000000000000 |                                                  | -inf
0&nbsp;11111111&nbsp;10000000000000000000000 |                                                  | +NaN Not a Number

## The Microsoft Binary Format (MBF) 

## Minifloat
...  

## bfloat16
...  

## TensorFloat-32
...  

## IBM floating-point architecture
...  

## PMBus Linear-11
...  

## G.711 8-bit floats
...  

## Arbitrary precision
...  

# Fixed-point approximation to real numbers
Representing non-integer numbers by storing a fixed number of digits of their fractional part.  
Fixed point arithmetic is much faster than the floating-point one.  
Example : Dollar amounts are often stored with exactly two fractional digits, representing the cents  
Example : $1234.4321_{float}$ = (316014.6176, 8) = (316015, 8) = ($00000000.00000100.11010010.01101111_{2}$, 8)  
  
https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html  

# Logarithmic approximation to real numbers
Represent a real number by the logarithm of its absolute value and a sign bit. 

# Tapered floating-point approximation to real numbers
Does not appear to be used in practice.

# Rational representation to real numbers
Represent numbers as fractions with integral numerator and denominator, and can therefore represent any rational number exactly. 

# Interval approximation to real numbers
Allows one to represent numbers as intervals and obtain guaranteed bounds on results. It is generally based on other arithmetics, in particular floating point.

# Without encoding representation of real numbers
Handles irrational numbers like pi or sqrt{3} in a formal way, without dealing with an encoding. Process the underlying mathematics directly, instead of using approximate values for each intermediate calculation.  
Computer algebra systems such as Mathematica, Maxima, Maple.

# Double
-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000 min  
  
179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000 max  

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
