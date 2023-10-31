# Orthodox canonical class form

In C++98 the OCCF had four different methods that the C++ compiler is willing to generate:

Default constructor
Copy constructor
Destructor
Copy assignment operator

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
