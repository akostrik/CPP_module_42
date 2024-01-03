#include "utils.hpp"

bool isDigit(char c) {
  return (c >= '0' && c <= '9');
}

int strlen(std::string s) {
  int i;

  for (i = 0; s[i] != '\0'; i++) ;
  return i;
}

bool isLessThan2147483647(std::string s) {
  if (s[0] == '-')
    return true;
  if (s[0] == '+')
    removePlusOrMinus(&s);
  if (strlen(s) <= 9)
    return true;
  if (strlen(s) >= 11)
    return false;
  if (s[0] - '0' > 2 || s[1] - '0' > 1 || s[2] - '0' > 4 || s[3] - '0' > 7 || s[4] - '0' > 4 || s[5] - '0' > 8 || s[6] - '0' > 3 || s[7] - '0' > 6 || s[8] - '0' > 4 || s[9] - '0' > 7)
    return false;
  return true;
}

bool isGreaterThanMinus2147483648(std::string s) {
  if (s[0] == '+' || isDigit(s[0]))
    return true;
  if (s[0] == '-')
    removePlusOrMinus(&s);
  if (strlen(s) <= 9)
    return true;
  if (strlen(s) >= 11)
    return false;
  if (s[0] - '0' > 2 || s[1] - '0' > 1 || s[2] - '0' > 4 || s[3] - '0' > 7 || s[4] - '0' > 4 || s[5] - '0' > 8 || s[6] - '0' > 3 || s[7] - '0' > 6 || s[8] - '0' > 4 || s[9] - '0' > 8)
    return false;
  return true;
}

bool isInIntLImits(std::string s) {
  return (isLessThan2147483647(s) && isGreaterThanMinus2147483648(s));
}

void trim(std::string *s) {
  int i;

  while((*s)[0] == ' ') {
    for (i = 0; (*s)[i] != '\0'; i++)
      (*s)[i] = (*s)[i + 1];
    (*s)[i] = '\0';
  }
  for (i = strlen(*s) - 1; (*s)[i] == ' '; i--)
    (*s)[i] = '\0';
}

void removeF(std::string *s) {
  if (strlen(*s) > 0 && (*s)[strlen(*s) - 1] == 'f')
    (*s)[strlen(*s) - 1] = '\0';
}

void removePlusOrMinus(std::string *s) {

  if ((*s)[0] == '+' || (*s)[0] == '-') {
    (*s)[0] = ' ';
    trim(s);
  }
}

void replaceDecimalPointBy0(std::string *s) {
  int i;

  if (strlen(*s) > 0 && (*s)[strlen(*s) - 1] == '.')
    return ;
  if (strlen(*s) > 1 && (*s)[strlen(*s) - 2] == '.' && (*s)[strlen(*s) -1] == 'f')
    return ;
  for (i = 0; (*s)[i] != '\0'; i++)
    if((*s)[i] == '.') {
      (*s)[i] = '0';
      return ;
    }
}

bool isOnlySpaces(std::string s) {
  for (int i = 0; s[i] != '\0'; i++)
    if (s[i] != ' ')
      return (false);
  return true;
}

static bool isOnlyDigits(std::string s) {
  int i;

  for (i = 1; s[i] != '\0'; i++)
    if (!isDigit(s[i]))
      return false ;
  return true;
}

char convertToChar(std::string s) {
  if(isOnlySpaces(s))
    return ' ';
  trim(&s);
  if (!isDigit(s[0]) && strlen(s) == 1) // s[0] >= 0 && [0] <= 128 ?
    return s[0]; // static_cast<char>(s);
  throw ScalarConverter::ConvertionFailed();
}

int convertToInt(std::string s) {
  trim(&s);
  if ((s[0] == '+' || s[0] == '-' || isDigit(s[0])) && isOnlyDigits(&s[1]) && isInIntLImits(s))
    return atoi(s.c_str()); // static_cast<int>(s.c_str());
  throw ScalarConverter::ConvertionFailed();
}

float convertToFloat(std::string s) {
  trim(&s);
  if(s == "+inff" || s == "-inff" || s == "nanf")
    return true;
  removePlusOrMinus(&s);
  replaceDecimalPointBy0(&s);
  // 1,175494351 E – 38
  // 3,402823466 E + 38
  return isOnlyDigits(s);
}

bool isDouble(std::string s) {
  trim(&s);
  if(s == "+inf" || s == "-inf" || s == "nan")
    return true;
  removePlusOrMinus(&s);
  replaceDecimalPointBy0(&s);
  removeF(&s);
  // limits
  return isOnlyDigits(s);
}

