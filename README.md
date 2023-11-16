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

# Const object = non-mutable

Attempt to modify it directly -> a compile-time error.

Attempt to modify it indirectly (e.g., by modifying the const object through a reference or pointer to non-const type) -> undefined behavior.

You cannot call a non-const method a const object.

You cannot call a non-const method through a pointer or reference to a const object (regardless of whether the referred-to object is const or not).

Can neither be changed by a const nor a non-const member function (except for constructor and destructor), even if it is passed by reference. There are two exceptions to this rule:
- Ccasting the const away (not advised);
- Class members can be declared using the mutable keyword; these members can be changed through member functions even if the containing object is declared const.

# A static member data member of a class

Is not associated with a particular object.

Belongs to the class rather than objects of the class. 

If it is public, it can be accessed directly using the class name.

Can also be called through objects of the class type, though this is not rechttps://companies.intra.42.fr/en/offersommended.

## A static data member

## A static member function

Has no *this pointer.

Can directly access other static members (variables or functions), but not non-static members, because non-static members must belong to a class object.

In the context of function declarations, static = "this function is scoped only to this file and can't be called from other places".

In the context of member functions, static = "this member function does not have a receiver object. It's basically a normal function that's nested inside of the scope of the class".

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
