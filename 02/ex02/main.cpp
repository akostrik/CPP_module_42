#include <iostream>
#include "Fixed.hpp"

int main( void ) {
  Fixed       a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max( a, b ) << std::endl << std::endl;

  // my testes
  a = Fixed(1.1f);
  Fixed       c(1.1f);
  Fixed       d(3.3f);
  Fixed const e(1.1f);
  Fixed const f(3.3f);

  std::cout << "a               : " << a                << std::endl;
  std::cout << "c               : " << c                << std::endl;
  std::cout << "d               : " << d                << std::endl;
  std::cout << "e               : " << e                << std::endl;
  std::cout << "f               : " << f                << std::endl;
  std::cout << "a == c          : " << (a == c)         << std::endl;
  std::cout << "a == d          : " << (a == d)         << std::endl;
  std::cout << "a != d          : " << (a != d)         << std::endl;
  std::cout << "a >  d          : " << (a >  d)         << std::endl;
  std::cout << "a <  d          : " << (a <  d)         << std::endl;
  std::cout << "a >  c          : " << (a >  c)         << std::endl;
  std::cout << "a >= c          : " << (a >= c)         << std::endl;
  std::cout << "a +  d          : " <<  a +  d          << std::endl;
  std::cout << "d -  a          : " <<  d -  a          << std::endl;
  std::cout << "a *  c          : " <<  a *  c          << std::endl;
  std::cout << "d /  a          : " <<  d /  a          << std::endl;
  std::cout << "a               : " <<  a               << std::endl;
  std::cout << "a++             : " <<  a++             << std::endl;
  std::cout << "a               : " <<  a               << std::endl;
  std::cout << "a.operator++()  : " <<  a.operator++()  << std::endl;
  std::cout << "a               : " <<  a               << std::endl;
  std::cout << "++a             : " <<  ++a             << std::endl;
  std::cout << "a               : " <<  a               << std::endl;
  std::cout << "a.operator++(5) : " <<  a.operator++(5) << std::endl;
  std::cout << "a               : " <<  a               << std::endl;
  std::cout << "a--             : " <<  a--             << std::endl;
  std::cout << "a               : " <<  a               << std::endl;
  std::cout << "Fixed::max(a,c) : " <<  Fixed::max(a,c) << std::endl;
  std::cout << "Fixed::max(a,d) : " <<  Fixed::max(a,d) << std::endl;
  std::cout << "Fixed::max(e,f) : " <<  Fixed::max(e,f) << std::endl;
  std::cout << "Fixed::min(a,d) : " <<  Fixed::min(a,d) << std::endl;
  std::cout << "Fixed::min(e,f) : " <<  Fixed::min(e,f) << std::endl;
  return 0;
}