#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <exception>
# include <iostream>
# include <limits>
# include <stdlib.h>
# include "ScalarConverter.hpp"

char  convertToChar(std::string s);
int   convertToInt(std::string s);
float convertToFloat(std::string s);
bool  isDouble(std::string s);
bool  isOnlySpaces(std::string s);
void  trim(std::string *s);
void  removePlusOrMinus(std::string *s);
int   strlen(std::string s);

#endif