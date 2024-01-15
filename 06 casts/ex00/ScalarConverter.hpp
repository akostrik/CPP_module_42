#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <stdlib.h> // strtof atoi strtof strtod
# include <cfloat>   // FLT_MAX
# include <climits>  // CHAR_MAX INT_MAX
# include <iostream> // cout
# include <cerrno>
# include <iomanip>  // setprecision

class ScalarConverter {
  private:
                  ScalarConverter  ();
                  ScalarConverter  (const ScalarConverter &obj);
  ScalarConverter &operator =      (const ScalarConverter &obj);

  public:
                  ~ScalarConverter ();
  static void     convert(std::string str);
  static bool     fInTheEnd(std::string s);
  static bool     thereIsPoint(std::string s);
  static bool     isInteger(std::string s);
};

#endif
