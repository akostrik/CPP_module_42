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
  // Constructors
                   Fixed();
                   Fixed(int const raw_);
                   Fixed(float const raw_);
                   Fixed(const Fixed &obj);
                   ~Fixed();

  // member functions
  void             setRawBits  (int const raw);
  int              getRawBits  (void)                  const;
  float            toFloat     (void)                  const;
  int              toInt       (void)                  const;
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
  Fixed            operator ++ (int);  // a++
  Fixed&           operator ++ (void); // ++a
  Fixed            operator -- (int);
  Fixed&           operator -- (void);

  // overloaded member functions
  static Fixed&    max (Fixed &ref1, Fixed &ref2);             // returns a ref 
  static Fixed&    max (const Fixed &ref1, const Fixed &ref2); // returns a ref
  // static Fixed&    min (Fixed &ref1, Fixed &ref2)
  // static Fixed&    min (const Fixed &ref1, const Fixed &ref2)
};

  std::ostream&      operator<<(std::ostream& os, Fixed const &f); // overload of the insertion operator <<, inserts a floating-p representation of the fp number into the output stream object passed as param

#endif
