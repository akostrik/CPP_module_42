#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <exception>
# include <iostream>
# include <limits>
# include <stdlib.h>
// # include <string.h> ///////////////// strcmp

bool isDouble(std::string s);
void trim(std::string *s);
int  strlen(std::string s);
int  strcmp(std::string s1, std::string s2);
bool isDigit(char c);
bool isDigits(std::string s);
bool isDigitsWithDecmalPoint(std::string s);
bool isInLimits(std::string s, std::string min, std::string max);
// bool isInIntLimits(std::string s);
// bool isInCharLimits(int n);

#endif