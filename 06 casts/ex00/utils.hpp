#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <exception>
# include <iostream>
# include <limits>

bool isDisplayableCharAndNotSDigit(std::string s);
bool isIndisplayableChar(std::string s);
bool isInt(std::string s);
bool isFloat(std::string s);
bool isDouble(std::string s);
bool isOnlySpaces(std::string s);
void trim(std::string *s);
void removePlusOrMinus(std::string *s);
int strlen(std::string s);

#endif