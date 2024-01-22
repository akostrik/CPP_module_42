#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>  // std
# include <cstdlib>   // rand
# include <exception>

class Base {
  public:
    virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif