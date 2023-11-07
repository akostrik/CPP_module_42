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
                   Fixed(int const v);        // converts p to the corresponding fpv, n is initialized to 8 NEW
                   Fixed(float const v);      // converts p to the corresponding fpv, n is initialized to 8 NEW
                   Fixed(const Fixed &obj);
                   Fixed & operator = (const Fixed &obj);
                   ~Fixed();
  void             setRawBits(int const raw); // sets the raw value of the fixed-point number
  int              getRawBits(void) const;    // returns the raw value of the fixed-point value
  float            toFloat(void) const;       // converts the fixed-point value to a floating-point value   NEW
  int              toInt(void) const;         // converts the fixed-point value to an integer value         NEW
  void             f()	// an overload of the insertion (<<) operator, inserts a floating-p representation of the fixed-p number into the output stream object passed as param
};

#endif
