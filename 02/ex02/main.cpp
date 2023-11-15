#include <iostream>
#include "Fixed.hpp"

int main( void ) {
  Fixed a(1.1f);
  // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
  Fixed c(1.1f);
  Fixed d(3.3f);

  std::cout << "a               : " << a                << std::endl;
  std::cout << "c               : " << c                << std::endl;
  std::cout << "d               : " << d                << std::endl;
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
  // std::cout << Fixed::max( a, b ) << std::endl;
  return 0;
}