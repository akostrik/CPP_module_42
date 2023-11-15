#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>

class Fixed {
private:
  int              raw;
  static int const n = 8;

public:
                   Fixed();
                   Fixed(int const fpv_);
                   Fixed(float const fpv_);
                   Fixed(const Fixed &obj);
  Fixed&           operator = (const Fixed &obj);
                   ~Fixed();
  void             setRawBits(int const raw);      // member function
  int              getRawBits(void) const;         // member function
  float            toFloat(void) const;            // member function
  int              toInt(void) const;              // member function
  bool             operator==(const Fixed &rhOther ) const;
};

  // member functions:
  // >
  // <
  // >=
  // <=
  // !=
  // +
  // -
  // *
  // /
  // ++a  increase or decrease the fixed-point value from the smallest representable ϵ such as 1 + ϵ > 1
  // --a
  // a++
  // a--
  // overloaded member functions
  // static min (two references on fp numbers)           returns a reference to the smallest one.
  // static min (two references to constant fixed-point) returns a reference to the smallest one.
  // static max (two references on fp numbers)           returns a reference to the greatest one.
  // static max (two references to constant fp numbers)  returns a reference to the greatest one.


  std::ostream&      operator<<(std::ostream& os, Fixed const &f); // overload of the insertion operator <<, inserts a floating-p representation of the fp number into the output stream object passed as param

#endif
