#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <exception>
# include <iostream>
# include <sstream>
# include <limits>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <float.h>

void trim(std::string *s);
int  strcmp(std::string s1, std::string s2);
int  strlen(std::string s);
bool digits(std::string s);
bool digitsAndMayBePoint(std::string s);
bool inLimits(std::string s, std::string min, std::string max);
bool isSpecialDouble(std::string s);
bool isSpecialFloat(std::string s);
bool isChar(std::string s);
bool isInt(std::string s);
bool isFloat(std::string s);
bool isDouble(std::string s);
template <typename T> std::string toString(T val);

#endif