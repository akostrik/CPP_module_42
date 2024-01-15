#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <cfloat>
# include <string>
# include <exception>
# include <iostream>
# include <limits>
# include <stdlib.h>
# include <iostream>
# include <iomanip>
# include <math.h>
# include <bitset>
# include <stdio.h>

// too mach headers ?

class ScalarConverter {
  private:
                  ScalarConverter  ();
                  ScalarConverter  (const ScalarConverter &obj);
  ScalarConverter &operator =      (const ScalarConverter &obj);

  public:
                  ~ScalarConverter ();
  static void     convert(std::string str);
  static bool     fInTheEnd(std::string s);
  static int      strlen(std::string s);
  static bool     thereIsPoint(std::string s);
  static bool     isSingleDigitNumber(std::string s);
  static bool     isChar(std::string s);
  static bool     isDisplayableChar(std::string s);
  static bool     isNonDisplayableChar(std::string s);
  static bool     isDisplayableChar(double d);
  static bool     isNonDisplayableChar(double d);
  static bool     isDisplayableChar(char c);
};

#endif
