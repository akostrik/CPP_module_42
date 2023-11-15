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
                   Fixed(int const raw_);
                   Fixed(float const raw_);
                   Fixed(const Fixed &obj);
                   ~Fixed();

  // member functions:
  void             setRawBits(int const raw);
  int              getRawBits(void) const;
  float            toFloat(void) const;
  int              toInt(void) const;
  Fixed&           operator =  (const Fixed &obj);
  bool             operator >  (const Fixed &refOther) const;
  bool             operator >= (const Fixed &refOther) const;
  bool             operator <  (const Fixed &refOther) const;
  bool             operator <= (const Fixed &refOther) const;
  bool             operator == (const Fixed &refOther) const;
  bool             operator != (const Fixed &refOther) const;
  Fixed            operator +  (const Fixed &refOther) const;
  Fixed            operator -  (const Fixed &refOther) const;
  Fixed            operator *  (const Fixed &refOther) const;
  Fixed            operator /  (const Fixed &refOther) const;
  Fixed&           operator ++ (void);
  Fixed            operator ++ (int);
};

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
