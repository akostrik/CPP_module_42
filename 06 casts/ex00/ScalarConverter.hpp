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
                         ScalarConverter  ();
                         ScalarConverter  (const ScalarConverter &obj);
 ScalarConverter         &operator =      (const ScalarConverter &obj);

public:
                         ~ScalarConverter ();
  static void            convert          (std::string s);

};

#endif
