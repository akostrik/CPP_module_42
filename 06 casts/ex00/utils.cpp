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

bool s1IsLessThenS2(std::string s1, std::string s2) {
  if (s1[0] == '-' && s2[0] != '-')
    return true;
  if (s1[0] != '-' && s2[0] == '-')
    return false;
  if (s1[0] != '-' && s2[0] != '-') {
    if (strlen(s1) < strlen(s2))
      return true;
    if (strlen(s1) > strlen(s2))
      return false;
    return (strcmp(s1.c_str(), s2.c_str()) <= 0);
  }
  if (s1[0] == '-' && s2[0] == '-') {
    if (strlen(s1) < strlen(s2))
      return false;
    if (strlen(s1) > strlen(s2))
      return true;
   return (strcmp(s1.c_str(), s2.c_str()) >= 0);
  }
  return true;
}

bool isInLimits(std::string s, std::string min, std::string max) {
  for (int i = 0; s[i] != '\0'; i++)
    if (s[i] == '.')
      s[i] = '\0'; /////////////
  return (s1IsLessThenS2(s.c_str(), max) && s1IsLessThenS2(min, s.c_str()));
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