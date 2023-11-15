#include <iostream>
#include "Fixed.hpp"

int main( void ) {
  Fixed a(1.1f);
  Fixed b(1.1f);
  Fixed c(3.3f);
  // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

  std::cout << "a      : "      << a        << std::endl;
  std::cout << "b      : "      << b        << std::endl;
  std::cout << "c      : "      << c        << std::endl;
  std::cout << "a == b : " << (a == b) << std::endl;
  std::cout << "a == c : " << (a == c) << std::endl;
  std::cout << "a != c : " << (a != c) << std::endl;
  std::cout << "a >  c : " << (a >  c) << std::endl;
  std::cout << "a <  c : " << (a <  c) << std::endl;
  std::cout << "a >  b : " << (a >  b) << std::endl;
  std::cout << "a >= b : " << (a >= b) << std::endl;
  std::cout << "a +  c : " <<  a +  c  << std::endl;
  std::cout << "c -  a : " <<  c -  a  << std::endl;
  std::cout << "a *  b : " <<  a *  b  << std::endl;
  std::cout << "c /  a : " <<  c /  a  << std::endl;
  std::cout << "a      : " << a        << std::endl;
  std::cout << "a++    : " <<  a++     << std::endl;
  std::cout << "a      : " << a        << std::endl;
  std::cout << "a++    : " <<  a++     << std::endl;
  std::cout << "a      : " << a        << std::endl;
  // std::cout << ++a << std::endl;
  // std::cout << a << std::endl;
  // std::cout << a++ << std::endl;
  // std::cout << a << std::endl;
  // std::cout << b << std::endl;
  // std::cout << Fixed::max( a, b ) << std::endl;
  return 0;
}