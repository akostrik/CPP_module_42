#ifndef SCLARCONVERTER_HPP
# define SCLARCONVERTER_HPP

# include <string>
# include <exception>
# include <iostream>
# include <limits>
# include "utils.hpp"

class ScalarConverter {

private:
  char            charVal;
  int             intVal;
  float           floatVal;
  double          doubleVal;

public:
                  ScalarConverter  ();
                  ScalarConverter  (const ScalarConverter &obj);
                  ~ScalarConverter ();
  ScalarConverter &operator =      (const ScalarConverter &obj);

  std::string     detectType(std::string str);
  void            convert          (std::string str); // char int float double 
  // ’c’ 0 -42 0.0 -4.2 -inf +inf nan 0.0f -4.2f -inff +inff nanf

  class ConvertionImpossible : public std::exception {
    public:
      const char *what() const throw();
  };
};

std::ostream &operator <<(std::ostream &out, const ScalarConverter &obj);

#endif
