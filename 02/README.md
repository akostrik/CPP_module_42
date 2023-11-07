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


## Floating-point

The IEEE-754 standard: float (4 bytes) or double (8 bytes) has:
- sign bit
- exponent giving its order of magnitude (= порядок = показатель степени)
- mantissa specifying the actual digits of the number ∊ [1;10) 

 seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm    meaning
31                              0    bit #

number = (s ? -1:1) * 2^e * 1.(mantissa bits)

Property	                                 | Value for float	         | Value for double
------------------------------------------|--------------------------|------------------------
Largest representable number	            | 3.402823466e+38	         | 1.7976931348623157e+308
Smallest number without losing precision	| 1.175494351e-38	         | 2.2250738585072014e-308
Smallest representable number(*)	         | 1.401298464e-45	         | 5e-324
Mantissa bits	                           | 23	                     | 52
Exponent bits	                           | 8	                     | 11
the smallest x such that 1+x > 1          | 1.1929093e-7	            | 2.220446049250313e-16
0                                         | 0x00000000               |
1.0                                       | 0x3f800000               |
0.5                                       | 0x3f000000               |
3                                         | 0x40400000               |
+inf                                      | 0x7f800000               |
-inf                                      | 0xff800000               |
+NaN                                      | 0x7fc00000 or 0x7ff00000 |


## Fixed-point

Representing non-integer numbers by storing a fixed number of digits of their fractional part. 

For example : Dollar amounts are often stored with exactly two fractional digits, representing the cents.

A valuable balance between performance, accuracy, range, precision.


# Sources
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html

https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html

https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html

https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html 
