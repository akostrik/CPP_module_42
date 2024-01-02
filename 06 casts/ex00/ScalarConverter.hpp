#ifndef SCLARCONVERTER_HPP
# define SCLARCONVERTER_HPP

# include <string>
# include <exception>
# include <iostream>
# include <limits>
# include "utils.hpp"

class ScalarConverter {

private:
  char            charV;
  int             intV;
  float           floatV;
  double          doubleV;

public:
/////////////////////////////////////////////////// OCCF
                  ScalarConverter  ();
                  ScalarConverter  (const ScalarConverter &obj);
                  ~ScalarConverter ();
  ScalarConverter &operator =      (const ScalarConverter &obj);

/////////////////////////////////////////////////// MEMBER FUNCTIONS
  std::string     detectType(std::string str);
  void            convert          (std::string str);

  class ConvertionImpossible : public std::exception {
    public:
      const char *what() const throw();
  };
};

/////////////////////////////////////////////////// EXCEPTIONS
std::ostream &operator <<(std::ostream &out, const ScalarConverter &obj);

#endif
