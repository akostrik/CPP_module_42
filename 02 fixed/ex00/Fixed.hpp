#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>

class Fixed {
private:
  int              fpv;                       // fixed-point number value
  static int const n = 8;                     // number of fractional bits will always be the integer literal 8

public:
                   Fixed();
                   Fixed(const Fixed &obj);
                   Fixed & operator = (const Fixed &obj);
                   ~Fixed();
  void             setRawBits(int const raw); // sets the raw value of the fixed-point number
	int              getRawBits(void) const;    // returns the raw value of the fixed-point value
};

#endif
