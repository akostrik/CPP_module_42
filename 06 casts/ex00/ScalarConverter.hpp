#ifndef SCLARCONVERTER_HPP
# define SCLARCONVERTER_HPP

# include <string>
# include <exception>
# include <iostream>
# include <limits>
# include <stdlib.h>
# include <iostream>
# include <iomanip>
# include <math.h>
# include <bitset>
# include "utils.hpp"

class ScalarConverter {

private:
  char            charV;
  int             intV;
  float           floatV;
  double          doubleV;
  bool            charOk;
  bool            intOk;
  bool            floatOk;
  bool            doubleOk;

// static methods
public:
/////////////////////////////////////////////////// OCCF
                  ScalarConverter  ();
                  ScalarConverter  (const ScalarConverter &obj);
                  ~ScalarConverter ();
  ScalarConverter &operator =      (const ScalarConverter &obj);

/////////////////////////////////////////////////// GETTERS
  char            getCharV         () const;
  int             getIntV          () const;
  float           getFloatV        () const;
  double          getDoubleV       () const;
  bool            charIsOk         () const;
  bool            intIsOk          () const;
  bool            floatIsOk        () const;
  bool            doubleIsOk       () const;

/////////////////////////////////////////////////// MEMBER FUNCTIONS
  void            convert          (std::string s);
  bool            isSpecial        (std::string s);
  bool            isChar           (std::string s);
  bool            isInt            (std::string s);
  bool            isFloat          (std::string s);
  bool            isDouble         (std::string s);
};

std::ostream &operator <<(std::ostream &out, const ScalarConverter &obj);

#endif
