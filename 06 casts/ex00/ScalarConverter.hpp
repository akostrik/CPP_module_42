#ifndef SCLARCONVERTER_HPP
# define SCLARCONVERTER_HPP

# include <string>
# include <exception>
# include <iostream>
# include <limits>
# include <stdlib.h>
#include <iostream>
# include <iomanip>
# include "utils.hpp"

class ScalarConverter {

private:
  char            charV;
  int             intV;
  float           floatV;
  double          doubleV;
  std::string     specialFloatV;
  std::string     specialDoubleV;

// a private constructor and static methods
public:
/////////////////////////////////////////////////// OCCF
                  ScalarConverter     ();
                  ScalarConverter     (const ScalarConverter &obj);
                  ~ScalarConverter    ();
  ScalarConverter &operator =         (const ScalarConverter &obj);

/////////////////////////////////////////////////// GETTERS
  char            getCharV            () const;
  int             getIntV             () const;
  float           getFloatV           () const;
  double          getDoubleV          () const;
  std::string     getSpecialFloatV    () const;
  std::string     getSpecialDoubleV   () const;

/////////////////////////////////////////////////// MEMBER FUNCTIONS
  void            convert             (std::string str);
  bool            isSpace(std::string s);
  bool            isSpecialV (std::string s);
  bool            isChar     (std::string s);
  bool            isInt      (std::string s);
  bool            isFloat    (std::string s);
  bool            isDouble   (std::string s);
};

std::ostream &operator <<(std::ostream &out, const ScalarConverter &obj);

#endif
