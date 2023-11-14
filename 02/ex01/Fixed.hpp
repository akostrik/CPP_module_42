#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>

class Fixed {
private:
  static int const n = 8;                      // number of fractional bits
  int              raw;                       // fixed-point number value

public:
                   Fixed();
                   Fixed(int const _fpv);   // NEW converts p to the corresponding fpv, n is initialized to 8
                   Fixed(float const _fpv);// NEW converts p to the corresponding fpv, n is initialized to 8
                   Fixed(const Fixed &obj);
  Fixed&           operator = (const Fixed &obj);
                   ~Fixed();
  void             setRawBits(int const raw); // sets the raw value of the fixed-point number
  int              getRawBits(void) const;    // returns the raw value of the fixed-point value
  float            toFloat(void) const;       // NEW converts the fixed-point value to a floating-point value
  int              toInt(void) const;         // NEW converts the fixed-point value to an integer value
};

std::ostream&      operator<<(std::ostream& os, Fixed const & f); // NEW overload of the insertion operator <<, inserts a floating-p representation of the fp number into the output stream object passed as param

#endif
