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

seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm (s = bit n°31)

number = ${(-1)}^{s}$ * 1.(mantissa bits) * $2^e$ 

- s sign bit
- e exponent giving its order of magnitude (= порядок = показатель степени)
- m mantissa specifying the actual digits of the number ∊ [1;10)

Property	                          | e     | m | float                                            
-----------------------------------|-------|---|--------------------------------------------------
bits                               | .     | . | seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm (1+8+23)        
Largest                    	     | .     |   | 340282346638528859811704183484516925440 $_{10}$  
Largest 	                          | .     |   |  -                                               
Smallest without losing precision  | .     |   |  1.175494351e-38	                                
Smallest                	        | .     |   |  1.401298464e-45     	                          
the smallest x such that 1+x > 1   |       |   |  1.1929093e-7	                                   
3.14                               | ∊ [ $2^1$ ; $2^2$ ) => e = $2^7$ | $\frac{3,14 -2 }{4 - 2} = 0,57$ => m = $0,57*2^{23}$ |  0 10000000 10010001111010111000011 = 0x4048F5C3
0                                  |       |   |  0 00000000 00000000000000000000000 = 0x00000000
1.0                                |       |   |  0 01111111 00000000000000000000000 = 0x3f800000
0.5                                |       |   |  0 01111110 00000000000000000000000 = 0x3f000000
3                                  |       |   |  0 10000000 10000000000000000000000 = 0x40400000
+inf                               |       |   |  0 11111111 00000000000000000000000 = 0x7f800000
-inf                               |       |   |  1 11111111 00000000000000000000000 = 0xff800000
+NaN                               |       |   |  0 11111111 10000000000000000000000 = 0x7fc00000
+NaN                               |       |   |  0 11111111 11100000000000000000000 = 0x7ff00000

## Fixed-point

Representing non-integer numbers by storing a fixed number of digits of their fractional part. 

For example : Dollar amounts are often stored with exactly two fractional digits, representing the cents.

A valuable balance between performance, accuracy, range, precision.


# Sources
https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html

https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html

https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html

https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html 

https://stackoverflow.com/questions/60224493/whats-the-largest-number-float-type-can-hold
