#ifndef FIXED_HPP
# define FIDED_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>

class Fixed {
private:
  int              fpv;          // fixed-point number value
  static const int n;            // number of fractional bits will always be the integer literal 8


public:
                   Fixed();
                   Fixed(const Fixed &f);
                   ~Fixed();
                   Fixed & operator = (const Fixed &f);
  int              getRawBits(void) const;    //returns the raw value of the fixed-point value
  void             setRawBits(int const raw); // sets the raw value of the fixed-point number
};

#endif
