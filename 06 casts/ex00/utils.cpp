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

int strcmp(std::string s1, std::string s2) {
  int i;

  for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
    if(s1[i] > s2[i])
      return 1;
    if(s1[i] < s2[i])
      return -1;
  }
  if(s1[i] > s2[i])
    return 1;
  if(s1[i] < s2[i])
    return -1;
  return 0;
}

bool isInCharLimits(int n) {
  return (n <= -127 && n <= 128);
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
  std::cout << "[" << s << "] <= 2147483647     -> " << (s <= "2147483647") << std::endl;
  std::cout << s << ".compare(2147483647) -> " << s.compare("2147483647") << std::endl;
  std::cout << "strcmp(" << s.c_str() << ",2147483647)  -> " << strcmp(s.c_str(),"2147483647") << std::endl;
  //return (s <= "2147483647");
  //return (s.compare("2147483647") <= 0);
  return (strcmp(s.c_str(), "2147483647") <= 0);
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
  return (strcmp(s.c_str(), "2147483648") <= 0);
}

bool isInIntLimits(std::string s) {
  for (int i = 0; s[i] != '\0'; i++)
    if (s[i] == '.')
      s[i] = '\0';
  return (isLessThan2147483647(s) && isGreaterThanMinus2147483648(s));
}

void trim(std::string *s) {
  int i;

  if (strlen(*s) == 0)
    return ;
  while((*s)[0] == ' ') {
    for (i = 0; (*s)[i] != '\0'; i++)
      (*s)[i] = (*s)[i + 1];
    (*s)[i] = '\0';
  }
  for (i = strlen(*s) - 1; (*s)[i] == ' '; i--)
    (*s)[i] = '\0';
  if (strlen(*s) == 0)
    (*s)[0] = ' ';
  if ((*s)[0] == '+') {
    for (i = 0; (*s)[i] != '\0'; i++)
      (*s)[i] = (*s)[i + 1];
    (*s)[i] = '\0';
  }
  while((*s)[0] == '0') {
    for (i = 0; (*s)[i] != '\0'; i++)
      (*s)[i] = (*s)[i + 1];
    (*s)[i] = '\0';
  }
  if (strlen(*s) == 0)
    (*s)[0] = '0';
  if ((*s)[0] == '-' && (*s)[1] != '\0') {
    while((*s)[1] == '0') {
      for (i = 1; (*s)[i] != '\0'; i++)
        (*s)[i] = (*s)[i + 1];
      (*s)[i] = '\0';
    }
    if ((*s)[1] == '-')
      (*s)[1] = '0';
  }
}

// -340282346638528859811704183484516925440.0000000000000000 Float lowest
//  340282346638528859811704183484516925440.0000000000000000 Float max