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
- a sign bit
- an exponent giving its order of magnitude
- a mantissa specifying the actual digits of the number

Экспоненциальная форма представления вещественных чисел, число хранится в виде мантиссы и порядка (показателя степени). 

Фиксированная относительная точность и изменяющаяся абсолютная.

## Fixed-point

Representing non-integer numbers by storing a fixed number of digits of their fractional part. 

For example : Dollar amounts are often stored with exactly two fractional digits, representing the cents.

A valuable balance between performance, accuracy, range, precision.


# Sources
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html

https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html

https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html

https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html 
