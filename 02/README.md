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

<span style="color:orange">s</span><span style="color:red">eeeeeeee</span><span style="color:blue">mmmmmmmmmmmmmmmmmmmmmmm</span> (s = bit n°31)

number = (<span style="color:orange">s</span> ? -1:1) * $2^<span style="color:red">e</span>$ * 1.<span style="color:blue">(mantissa bits)</span>

- <span style="color:orange">s sign bit</span>
- <span style="color:red">e exponent giving its order of magnitude (= порядок = показатель степени) </span>
- <span style="color:blue">m mantissa specifying the actual digits of the number ∊ [1;10) </span>

Example 3.14:

<span style="color:orangee">s sign bit = 0b</span>

3,14 ∊ [ $2^1$ ; $2^2$ ) => <span style="color:red">e = $2^7$ = 128 = 10000000b</span>

$\frac{3,14 -2 }{4 - 2} = 0,57$ => <span style="color:blue">m = $2^{23}*0,57$ = 4781507 = 10010001111010111000011b </span>

<span style="color:orange">0</span> <span style="color:red">10000000</span> <span style="color:blue">10010001111010111000011</span>

Property	                                 | float                    | double
------------------------------------------|--------------------------|--------------------------
.                                         | 8 e bits, 23 m bits	   | 11 e bits, 52 m bits
Largest representable number	            | 3.402823466e+38	         | 1.7976931348623157e+308
Smallest number without losing precision	| 1.175494351e-38	         | 2.2250738585072014e-308
Smallest representable number  	         | 1.401298464e-45	         | 5e-324
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
