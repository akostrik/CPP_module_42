#include "utils.hpp"

bool isDigit(char c) {
  return (c >= '0' && c <= '9');
}

int strlen(std::string s) {
  int i;

  for (i = 0; s[i] != '\0'; i++) ;
  return i;
}

int strcmp(std::string s1, std::string s2) { // s1 == s2 ne marche pas
  int i;

  for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
    if (s1[i] < s2[i])
      return -1;
    if (s1[i] > s2[i])
      return 1;
  }
  return 0;
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

void removeF(std::string s) {
  if (strlen(s) > 0 && s[strlen(s) - 1] == 'f')
    s[strlen(s) - 1] = '\0';
}

void removePlusOrMinus(std::string *s) {

  if ((*s)[0] == '+' || (*s)[0] == '-') {
    (*s)[0] = ' ';
    trim(s);
  }
}

void replaceDecimalPointBy0(std::string s) {
  int i;

  if (strlen(s) > 0 && s[strlen(s) - 1] == '.')
    return ;
  if (strlen(s) > 1 && s[strlen(s) - 2] == '.' && s[strlen(s) -1] == 'f')
    return ;
  for (i = 0; s[i] != '\0'; i++)
    if(s[i] == '.') {
      s[i] = '0';
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
  return true ;
}

bool isDisplayableCharAndNotSDigit(std::string s) {
  return s[0] >= 32 && s[0] <= 126 && !isDigit(s[0]) && s[1] == '\0';
}

bool isIndisplayableChar(std::string s) {
  return ((s[0] < 32 || s[0] > 126) && s[1] == '\0');
}

bool isInt(std::string s) {
  if (strcmp(s, "-2147483648") == 0) // itoa(std::numeric_limits<int>::min())
    return true;
  removePlusOrMinus(&s);
  if (!isOnlyDigits(s))
    return false;
  if (strlen(s) <= 9)
    return true ;
  std::cout << "[" << s << "], strlen = " << strlen(s) << std::endl;
  if (strlen(s) >= 11)
    return false;
  std::cout << "strcmp(" << s << ", 2147483647) = " << strcmp(s, "2147483647") << std::endl;
  return (strcmp(s, "2147483647") <= 0); // itoa(std::numeric_limits<int>::max())
  //if (s[0] > 2 || s[1] > 1 || s[2] > 4 || s[3] > 7 || s[5] > 4 || s[6] > 8 || s[7] > 3 || s[8] > 6 || s[9] > 4 || s[10] > 7)
}

// +nanf? -nanf?
bool isFloat(std::string s) {
  if(s == "+inff" || s == "-inff" || s == "nanf")
    return true;
  removePlusOrMinus(&s);
  replaceDecimalPointBy0(s);
  // limits
  return isOnlyDigits(s);
}

bool isDouble(std::string s) {
  if(s == "+inf" || s == "-inf" || s == "nan")
    return true;
  removePlusOrMinus(&s);
  replaceDecimalPointBy0(s);
  removeF(s);
  // limits
  return isOnlyDigits(s);
}

