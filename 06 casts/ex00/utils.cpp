#include "utils.hpp"

bool consistsOfSpacesOnly(std::string s) {
  if (s[0] == '\0')
    return false;
  for (int i = 0; s[i] != '\0'; i++)
    if (s[i] != ' ')
      return (false);
  return true;
}

void trim(std::string s) { // pointer str?
  int i;

  while(s[0] == ' ') {
    for (i = 0; s[i] != '\0'; i++)
      s[i] = s[i + 1];
    s[i] = '\0';
  }
  for (i = 0; s[i] != '\0'; i++)
    ;
  i--;
  for (; s[i] == ' '; i--)
    s[i] = '\0';
}

void removeF(std::string s) {
  int i;

  for (i = 0; s[i] != '\0'; i++)
    ;
  i--;
  if (i > 0 && s[i] == 'f')
    s[i] = '\0';
}

void removePlusOrMinus(std::string s) {
  int i;

  if (s[0] == '+') {
    for (i = 0; s[i] != '\0'; i++)
      s[i] = s[i + 1];
    s[i] = '\0';
    return ;
  }
  if (s[0] == '-') {
    for (i = 0; s[i] != '\0'; i++)
      s[i] = s[i + 1];
    s[i] = '\0';
  }
}

void removeDecimalPoint(std::string s) { // to replace . by 0 ?
  int i;

  for (i = 0; s[i] != '\0'; i++)
    ;
  if (i > 0 && s[i] == '.')
    return ;
  if (i > 1 && s[i - 1] == '.' && s[i] == 'f')
    return ;
  for (i = 0; s[i] != '\0'; i++)
    if(s[i] == '.') {
      for (; ; i++)
        s[i] = s[i + 1];
      s[i] = '\0';
      return ;
    }
}

bool isDigit(char c) {
  return (c >= '0' && c <= '9');
}

bool isDisplayableChar(char c) {
  return (c >= 32 && c <= 126);
}

bool isChar(std::string s) { // and not digit
  if (s[0] == '\0')
    return false ;
  if(consistsOfSpacesOnly(s))
    return true;
  trim(s);
  return s[0] != '\0' && s[1] == '\0' && s[0] >= 32 && s[0] <= 126 && !isDigit(s[0]);
}

static bool containsOnlyDigits(std::string s) {
  int i;

  trim(s);
  for (i = 1; s[i] != '\0'; i++)
    if (!isDigit(s[i]))
      return false ;
  return true ;
}

bool isInt(std::string s) {
  int i;

  trim(s);
  if (s[0] == '\0')
    return false ;
  if (s == "-2147483648") // itoa(std::numeric_limits<int>::min())
    return true;
  removePlusOrMinus(s);
  if (!containsOnlyDigits(s))
    return false;
  for (i = 1; s[i] != '\0'; i++)
    ;
  i--;
  if (i >= 11)
    ; //throw exception;
  if (i <= 9)
    return true ;
  // if (s[0] > 2 || s[1] > 1 || s[2] > 4 || s[3] > 7 || s[5] > 4 || s[6] > 8 || s[7] > 3 || s[8] > 6 || s[9] > 4 || s[10] > 7)
  if (s > "2147483647") // itoa(std::numeric_limits<int>::max())
    return false ;
  return true ;
}

bool isFloat(std::string s) {
  trim(s);
  if (s[0] == '\0')
    return false ;
  if(s == "+inff" || s == "-inff" || s == "nanf")
    return true;
  removePlusOrMinus(s);
  removeDecimalPoint(s);
  // limits
  return containsOnlyDigits(s);
}

bool isDouble(std::string s) {
  trim(s);
  if (s[0] == '\0')
    return false ;
  if(s == "+inf" || s == "-inf" || s == "nan")
    return true;
  removePlusOrMinus(s);
  removeDecimalPoint(s);
  removeF(s);
  // limits
  return containsOnlyDigits(s);
}

