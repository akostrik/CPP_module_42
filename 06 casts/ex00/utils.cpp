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

int pos_point(std::string s) {
  int i;

  for (i = 0; s[i] != '\0'; i++)
    if (s[i] == '.')
      break ;
  return i;
}

bool lessOrEqual(std::string s1, std::string s2) {
  int p1 = pos_point(s1);
  int p2 = pos_point(s2);

  std::cout << std::endl << "f lessOrEqual(" << s1 << ", " << s2 << ")" << std::endl;
  // std::cout << "p1 = " << p1 << std::endl;
  // std::cout << "p2 = " << p2 << std::endl;
  s1[p1] = '\0';
  s2[p2] = '\0';
  if (strcmp(s1.c_str(), s2.c_str()) == 0) {
    std::cout << "LessOrEqual(" << s1 << ", " << s2 << ") returns true (0)" << std::endl;
    return true;
  }
  else if (s1[0] == '-' && s2[0] != '-') {
    std::cout << "LessOrEqual(" << s1 << ", " << s2 << ") returns true (1)" << std::endl;
    return true;
  }
  else if (s1[0] != '-' && s2[0] == '-') {
    std::cout << "LessOrEqual(" << s1 << ", " << s2 << ") returns false (2)" << std::endl;
    return false;
  }
  else if (s1[0] != '-' && s2[0] != '-') {
    if (strlen(s1) < strlen(s2)) {
      std::cout << "LessOrEqual(" << s1 << ", " << s2 << ") returns true (3)" << std::endl;
      return true;
    }
    if (strlen(s1) > strlen(s2)) {
      std::cout << "LessOrEqual(" << s1 << ", " << s2 << ") returns false (4)" << std::endl;
      return false;
    }
    if (strcmp(s1.c_str(), s2.c_str()) < 0) {
      std::cout << "LessOrEqual(" << s1 << ", " << s2 << ") returns true (5)" << std::endl;
      return true;
    }
    if (strcmp(s1.c_str(), s2.c_str()) == 0 && p1 == strlen(s1) && p2 == strlen(s2)) {
      std::cout << "LessOrEqual(" << s1 << ", " << s2 << ") returns true (6)" << std::endl;
      return true;
    }
    if (strcmp(s1.c_str(), s2.c_str()) == 0 && p1 <  strlen(s1) && p2 == strlen(s2)) {
      std::cout << "LessOrEqual(" << s1 << ", " << s2 << ") returns false (7)" << std::endl;
      return false;
    }
    if (strcmp(s1.c_str(), s2.c_str()) == 0 && p1 == strlen(s1) && p2 <  strlen(s2)) {
      std::cout << "LessOrEqual(" << s1 << ", " << s2 << ") returns true (8)" << std::endl;
      return true;
    }
    if (strcmp(s1.c_str(), s2.c_str()) == 0 && p1 <  strlen(s1) && p2 <  strlen(s2)) {
      std::cout << "LessOrEqual(" << s1 << ", " << s2 << ") returns ... (9)" << std::endl;
      return lessOrEqual(&s1[p1 + 1], &s2[p2 + 1]);
    }
  }
  else if (s1[0] == '-' && s2[0] == '-') {
    bool t = !lessOrEqual(&s1[1], &s2[1]);
    std::cout << "LessOrEqual(" << s1 << ", " << s2 << ") returns " << t << " (10)" << std::endl;
    return (t);
  }
  std::cout << "LessOrEqual(" << s1 << ", " << s2 << ") returns fqlse (11)" << std::endl;
  return false;
}

bool inLimits(std::string s, std::string min, std::string max) {
  //std::cout << "inLimits: " << s.c_str() << " <= " << max << ":  " << lessOrEqual(s.c_str(), max) << std::endl;
  //std::cout << "inLimits: " << min << " <= " << s.c_str() << ": " << lessOrEqual(min, s.c_str()) << std::endl;
  return (lessOrEqual(s.c_str(), max) && lessOrEqual(min, s.c_str()));
}

// trim whitespaces and extra zeros
// for ex: "   -00023.700  " -> "-23.7"
void trim(std::string *s) {
  int i;

  if (strlen(*s) == 0)
    return ;
  while((*s)[0] == ' ') { // spaces beginning
    for (i = 0; (*s)[i] != '\0'; i++)
      (*s)[i] = (*s)[i + 1];
    (*s)[i] = '\0';
  }
  for (i = strlen(*s) - 1; (*s)[i] == ' '; i--) // spaces end
    (*s)[i] = '\0';
  if (strlen(*s) == 0)
    (*s)[0] = ' ';
  if ((*s)[0] == '+') {
    for (i = 0; (*s)[i] != '\0'; i++)
      (*s)[i] = (*s)[i + 1];
    (*s)[i] = '\0';
  }
  while((*s)[0] == '0') { // zeros beginning
    for (i = 0; (*s)[i] != '\0'; i++)
      (*s)[i] = (*s)[i + 1];
    (*s)[i] = '\0';
  }
  if (strlen(*s) == 0)
    (*s)[0] = '0';
  if ((*s)[0] == '-' && (*s)[1] != '\0') { // zeros beginning after -
    while((*s)[1] == '0') {
      for (i = 1; (*s)[i] != '\0'; i++)
        (*s)[i] = (*s)[i + 1];
      (*s)[i] = '\0';
    }
    if ((*s)[1] == '-')
      (*s)[1] = '0';
  }
  for (i = 0; (*s)[i] != '\0'; i++) { // zeros end
    if ((*s)[i] == '.') {
      int p = i;
      for (i = strlen(*s) - 1; i > p; i--) {
        if ((*s)[i] == '0')
          (*s)[i] = '\0';
        else
          break ;
      }
      if (i == p)
        (*s)[i + 1] = '0';
      break ;
    }
  }
}

// -340282346638528859811704183484516925440.0000000000000000 Float lowest
//  340282346638528859811704183484516925440.0000000000000000 Float max