#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <exception>
# include <iostream>
# include <sstream>
# include <limits>
# include <stdlib.h>
# include <stdio.h>
# include <float.h>

void trim(std::string *s);
int  strcmp(std::string s1, std::string s2);
int  strlen(std::string s);
bool isDigits(std::string s);
bool isDigitsWithDecmalPoint(std::string s);
bool inLimits(std::string s, std::string min, std::string max);
bool isSpecialDouble(std::string s);
bool isSpecialFloat(std::string s);
bool isChar(std::string s);
bool isInt(std::string s);
bool isFloat(std::string s);
bool isDouble(std::string s);

#endif