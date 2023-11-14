# Orthodox canonical class form in C++98 (ex00)

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
# Floating-point numbers vs Fixed-point numbers
Accuracy = to how close a measurement is to the true value

Precision = how much information you have about a quantity, how uniquely you have it pinned down

Fixed point arithmetic is much faster than floating point arithmetic

## Floating-point

seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm 

bit n°31 ............... bit n°0

number = ${(-1)}^{s}$ * 1.(mantissa bits) * $2^e$ 

- s sign bit
- e exponent giving its order of magnitude (= порядок = показатель степени)
- m mantissa specifying the actual digits of the number ∊ [1;10)

[IEEE-754 Floating Point Converter](https://www.h-schmidt.net/FloatConverter/IEEE754.html)

Decimal	                          | e                            | m   | float                                            
-----------------------------------|------------------------------|-----|--------------------------------------------------
bits                               |                              |     | seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm (1+8+23)        
3.14                               | ∊ [ $2^1$ ; $2^2$ ) => $2^7$ | $\frac{3,14 -2 }{4 - 2} *2^{23}$ |  0 10000000 10010001111010111000011 = 0x4048F5C3
0                                  |                              |     |  0 00000000 00000000000000000000000 = 0x00000000
1.0                                |                              |     |  0 01111111 00000000000000000000000 = 0x3f800000
0.5                                |                              |     |  0 01111110 00000000000000000000000 = 0x3f000000
3                                  |                              |     |  0 10000000 10000000000000000000000 = 0x40400000
$2^{e−127}$*(1+m/ $2^{23}$ )       | ~11111111~ ~00000000~        |     |
$2^{1−127}$*(0+m/ $2^{23}$ )       | 00000000                     |     |
Largest $2^{254−127}$ *(1+ ($2^{23}$−1)/ $2^{23}$) = 340282346638528859811704183484516925440 | 11111110       |     |   
Smallest without losing precision  |                              |     |  1.175494351e-38	                                
Smallest                	        |                              |     |  1.401298464e-45     	                          
the smallest x : 1+x > 1           |                              |     |  1.1929093e-7	                                   
+inf                               | 11111111                     |     |  0 11111111 00000000000000000000000 = 0x7f800000
-inf                               | 11111111                     |     |  1 11111111 00000000000000000000000 = 0xff800000
+NaN                               | 11111111                     | ~0~ |  0 11111111 10000000000000000000000 = 0x7fc00000

## Fixed-point

Representing non-integer numbers by storing a fixed number of digits of their fractional part

For example : Dollar amounts are often stored with exactly two fractional digits, representing the cents

fixed<8,3> = a 8-bit fixed point number, of which 3 right most bits are fractional

# Const

Const object = whose type is const-qualified, or a non-mutable subobject of a const object. 

Such object cannot be modified: attempt to do so directly is a compile-time error, and attempt to do so indirectly (e.g., by modifying the const object through a reference or pointer to non-const type) results in undefined behavior.

You need to explicitly tell the compiler that your function will not modify any members

You cannot call a non-const method a const object

You cannot call a non-const method through a pointer or reference to a const object (regardless of whether the referred-to object is const or not)

An object declared as const can neither be changed by a const nor a non-const member function (except for constructor and destructor). Even if it is passed by reference. There are two exceptions to this rule:
- The constness can be casted away (casting the const away) but is generally not advised;
- Class members can be declared using the mutable keyword; these members can be changed through member functions even if the containing object is declared const.


# Sources
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html

https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html

https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html

https://stackoverflow.com/questions/60224493/whats-the-largest-number-float-type-can-hold

https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html 

https://github.com/achrafelkhnissi/CPP_Modules/tree/master

https://github.com/Saxsori/CPP_Modules/tree/main

https://github.com/42YerevanProjects/cpp_modules/tree/master
