#include "utils.hpp"

bool isDigit(char c) {
  return (c >= '0' && c <= '9');
}

bool isDigitsWithDecmalPoint(std::string s) {
  if ((s)[strlen(s) - 1] == '.') // ?
    return false;
  for (int i = 0; s[i] != '\0'; i++)
    if(s[i] == '.') {
      s[i] = '0';
      break ;
    }
  for (int i = 1; s[i] != '\0'; i++)
    if (!isDigit(s[i]))
      return false;
  return true;
}

bool isDigits(std::string s) {
  for (int i = 1; s[i] != '\0'; i++)
    if (!isDigit(s[i]))
      return false;
  return true;
}

int strlen(std::string s) {
  int i;

  for (i = 0; s[i] != '\0'; i++) ;
  return i;
}

bool isLessThan2147483647(std::string s) {
  int i;

  if (s[0] == '-')
    return true;
  if (s[0] == '+') {
    for (i = 0; ; i++)
      s[i] = s[i + 1];
    s[i] = '\0';
  }
  if (strlen(s) <= 9)
    return true;
  if (strlen(s) >= 11)
    return false;
  if (s > "2147483647")
  //if (s[0] - '0' > 2 || s[1] - '0' > 1 || s[2] - '0' > 4 || s[3] - '0' > 7 || s[4] - '0' > 4 || s[5] - '0' > 8 || s[6] - '0' > 3 || s[7] - '0' > 6 || s[8] - '0' > 4 || s[9] - '0' > 7)
    return false;
  return true;
}

bool isGreaterThanMinus2147483648(std::string s) {
  int i;

  if (s[0] == '+' || isDigit(s[0]))
    return true;
  if (s[0] == '-') {
    for (i = 0; ; i++)
      s[i] = s[i + 1];
    s[i] = '\0';
  }
  if (strlen(s) <= 9)
    return true;
  if (strlen(s) >= 11)
    return false;
  if (s > "2147483648")
  // if (s[0] - '0' > 2 || s[1] - '0' > 1 || s[2] - '0' > 4 || s[3] - '0' > 7 || s[4] - '0' > 4 || s[5] - '0' > 8 || s[6] - '0' > 3 || s[7] - '0' > 6 || s[8] - '0' > 4 || s[9] - '0' > 8)
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

// -340282346638528859811704183484516925440.0000000000000000 Float lowest
//  340282346638528859811704183484516925440.0000000000000000 Float max