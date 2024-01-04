#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <exception>
# include <iostream>
# include <limits>
# include <stdlib.h>

bool isDouble(std::string s);
void trim(std::string *s);
int  strlen(std::string s);
bool isDigit(char c);
bool isDigits(std::string s);
bool isDigitsWithDecmalPoint(std::string s);
bool isInIntLImits(std::string s);

#endif