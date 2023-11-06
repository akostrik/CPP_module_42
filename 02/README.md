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
# Fixed-point 
A method of representing non-integer numbers by storing a fixed number of digits of their fractional part. Dollar amounts, for example, are often stored with exactly two fractional digits, representing the cents.

A valuable balance between performance, accuracy, range, precision.

