#include "utils.hpp"

bool digitsAndMayBePoint(std::string s) {
  for (int i = 0; s[i] != '\0'; i++)
    if(s[i] == '.') {
      s[i] = '0';
      break ;
    }
  for (int i = 0; s[i] != '\0'; i++) {
    if (!std::isdigit(s[i]))
      return false;
  }
  return true;
}

bool digits(std::string s) {
  for (int i = 0; s[i] != '\0'; i++)
    if (!std::isdigit(s[i]))
      return false;
  return true;
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

int strlen(std::string s) {
  int i;

  for (i = 0; s[i] != '\0'; i++) ;
  return i;
}

static int pos_point(std::string s) {
  int i;

  for (i = 0; s[i] != '\0'; i++)
    if (s[i] == '.')
      break ;
  return i;
}

bool lessOrEqual(std::string s1, std::string s2) {
  std::basic_string<char>::size_type p1 = pos_point(s1);
  std::basic_string<char>::size_type p2 = pos_point(s2);

  s1[p1] = '\0';
  s2[p2] = '\0';
  // if (s1[strlen(s1) - 1] == 'f')
  //   s1[strlen(s1) - 1] = '\0';
  // if (s2[strlen(s2) - 1] == 'f')
  //   s2[strlen(s2) - 1] = '\0';
  if (strcmp(s1.c_str(), s2.c_str()) == 0) {
    return true;
  }
  else if (s1[0] == '-' && s2[0] != '-') 
    return true;
  else if (s1[0] != '-' && s2[0] == '-') 
    return false;
  else if (s1[0] != '-' && s2[0] != '-') {
    if (s1.size() < s2.size()) // strlen ?
      return true;
    if (s1.size() > s2.size())
      return false;
    if (strcmp(s1.c_str(), s2.c_str()) < 0)
      return true;
    if (strcmp(s1.c_str(), s2.c_str()) == 0 && p1 == s1.size() && p2 == s2.size())
      return true;
    if (strcmp(s1.c_str(), s2.c_str()) == 0 && p1 <  s1.size() && p2 == s2.size())
      return false;
    if (strcmp(s1.c_str(), s2.c_str()) == 0 && p1 == s1.size() && p2 <  s2.size())
      return true;
    if (strcmp(s1.c_str(), s2.c_str()) == 0 && p1 <  s1.size() && p2 <  s2.size())
      return lessOrEqual(&s1[p1 + 1], &s2[p2 + 1]);
  }
  else if (s1[0] == '-' && s2[0] == '-') {
    bool t = !lessOrEqual(&s1[1], &s2[1]);
    return (t);
  }
  return false;
}

// 2147483647.99 is in limits [-2147483648, 2147483647] // is it ok?
// -2147483648.99 is in limits [-2147483648, 2147483647]
bool inLimits(std::string s, std::string min, std::string max) {
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
  for (i = strlen(*s) - 1; (*s)[i] == ' ' || (*s)[i] == '\0'; i--) // spaces end
    (*s)[i] = '\0';
  if (strlen(*s) == 0)
    (*s)[0] = ' ';
  if (strlen(*s) == 2 && ((*s)[0] == '+' || (*s)[0] == '-') &&  !std::isdigit((*s)[1]))
    return ;
  if ((*s)[0] == '+') { // remove +
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
  if (strlen(*s) == 0)
    (*s)[0] = '0';
  if (strlen(*s) == 1 && (*s)[0] == '-')
    (*s)[1] = '0';
}

bool isSpecialDouble(std::string s) {
  return (s == "nan" || s == "inf" || s == "-inf");
}

bool isSpecialFloat(std::string s) {
  return (s == "nanf" || s == "inff" || s == "-inff");
}

bool isChar(std::string s) {
  if (strlen(s) != 1)
    return false;
  return !std::isdigit(s[0]);
}

template <typename T> std::string toString(T val) {
    std::ostringstream oss;
    oss << std::fixed << val;
    return oss.str();
}

bool isInt(std::string s) {
  return ((s[0] == '-' && digits(&s[1])             ) || digits(s)                 ) && inLimits(s, toString(std::numeric_limits<int>::min()), toString(std::numeric_limits<int>::max()));
}

bool isFloat(std::string s) {
  // char  *endPtr;
  // strtof(s.c_str(), &endPtr);
  // return (endPtr != s.c_str());

  if (s[strlen(s) - 1] != 'f')
    return false;
  s[strlen(s) - 1] = '\0';
  // std::cout << std::fixed << "fltMax = " << fltMax << std::endl;
  // std::cout << std::fixed << "fltMin = " << fltMin << std::endl;
  return ((s[0] == '-' && digitsAndMayBePoint(&s[1])) || digitsAndMayBePoint(&s[0])) && inLimits(s, toString(-std::numeric_limits<int>::max()), toString(std::numeric_limits<float>::max()));
}

bool isDouble(std::string s) {
  std::string dblMax = toString(std::numeric_limits<double>::max());
  std::string dblMin = toString(-std::numeric_limits<double>::max());
  // std::cout << std::fixed << "dblMax = " << dblMax << std::endl;
  // std::cout << std::fixed << "dblMin = " << dblMin << std::endl;
  return ((s[0] == '-' && digitsAndMayBePoint(&s[1])) || digitsAndMayBePoint(&s[0])) && inLimits(s, toString(-std::numeric_limits<double>::max()), toString(std::numeric_limits<double>::max()));
}
