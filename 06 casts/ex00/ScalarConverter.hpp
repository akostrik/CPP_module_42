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

/////////////////////////////////////////////////// GETTERS
  char            getCharV         () const;
  int             getIntV          () const;
  float           getFloatV        () const;
  double          getDoubleV       () const;

/////////////////////////////////////////////////// MEMBER FUNCTIONS
  void            convert          (std::string str);

/////////////////////////////////////////////////// EXCEPTIONS
  class ConvertionFailed : public std::exception {
    public:
      const char *what() const throw();
  };
};

std::ostream &operator <<(std::ostream &out, const ScalarConverter &obj);

#endif
