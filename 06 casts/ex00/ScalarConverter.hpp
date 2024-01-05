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

/////////////////////////////////////////////////// OCCF
private:
                         ScalarConverter  ();
                         ScalarConverter  (const ScalarConverter &obj);
 ScalarConverter         &operator =      (const ScalarConverter &obj);

public:
                         ~ScalarConverter ();

/////////////////////////////////////////////////// MEMBER FUNCTIONS
public:
  static void            convert          (std::string s);

// private:
//   static bool            isSpecial        (std::string s);
//   static bool            isChar           (std::string s);
//   static bool            isInt            (std::string s);
//   static bool            isFloat          (std::string s);
//   static bool            isDouble         (std::string s);
};

#endif
