#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <exception>
# include <iostream>
# include <limits>
# include <stdlib.h>

void trim(std::string *s);
int  strcmp(std::string s1, std::string s2);
bool isDigits(std::string s);
bool isDigitsWithDecmalPoint(std::string s);
bool inLimits(std::string s, std::string min, std::string max);

#endif