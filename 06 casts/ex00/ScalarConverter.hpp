#ifndef SCLARCONVERTER_HPP
# define SCLARCONVERTER_HPP

# include <string>
# include <exception>
# include <iostream>
# include <limits>
# include <stdlib.h>
# include "utils.hpp"

class ScalarConverter {

private:
  std::string     charV;
  int             intV;
  float           floatV;
  double          doubleV;

public:
/////////////////////////////////////////////////// OCCF
                  ScalarConverter  ();
                  ScalarConverter  (const ScalarConverter &obj);
                  ~ScalarConverter ();
  ScalarConverter &operator =      (const ScalarConverter &obj);

/////////////////////////////////////////////////// GETTERS
  std::string     getCharV() const;
  int             getIntV() const;
  float           getFloatV() const;
  double          getDoubleV() const;

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
