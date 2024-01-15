// s.back() != 'f' 
// s.find( '.' ) == 0
// s.compare( "nan" ) == 0 

#include "ScalarConverter.hpp"

bool ScalarConverter::fInTheEnd(std::string s) {
  int len;

  for (len = 0; s[len] != '\0'; len++) ;
  return (s[len - 1] == 'f');
} 

bool ScalarConverter::thereIsPoint(std::string s) {
  for (int i = 0; s[i] != '\0'; i++) 
    if (s[i] == '.')
      return true;
  return false;
} 

int ScalarConverter::strlen(std::string s) {
  int len;

  for (len = 0; s[len] != '\0'; len++) ;
  return len;
}

bool ScalarConverter::isSingleDigitNumber(std::string s) {
  if (ScalarConverter::strlen(s) == 1 && s[0] >= '0' && s[0] <= '9')
    return true;
  if (ScalarConverter::strlen(s) == 2 && s[0] >= '0' && s[0] <= '9'   && s[1] == 'f')
    return true;
  if (ScalarConverter::strlen(s) == 2 && (s[0] == '+' || s[0] == '-') && s[1] >= '0' && s[1] <= '9')
    return true;
  if (ScalarConverter::strlen(s) == 3 && (s[0] == '+' || s[0] == '-') && s[1] >= '0' && s[1] <= '9' && s[2] == 'f')
    return true;
  return false;
}

bool ScalarConverter::isChar(std::string s) {
  return (ScalarConverter::strlen(s) == 1 && s[0] >= CHAR_MIN && !(s[0] >= '0' && s[0] <= '9'));
}

bool ScalarConverter::isDisplayableChar(std::string s) {
  return (ScalarConverter::strlen(s) == 1 && s[0] >= 32 && s[0] <= 126 && !(s[0] >= '0' && s[0] <= '9'));
}

// bool ScalarConverter::isDisplayableChar(double d) {
//   return (d >= 32 && d <= 126);
// }

// bool ScalarConverter::isNonDisplayableChar(double d) {
//   return (d >= CHAR_MIN && d <= CHAR_MAX && (d < 32 || d > 126));
// }

// bool ScalarConverter::isDisplayableChar(char c) {
//   return (c >= 32 && c <= 126);
// }

bool ScalarConverter::isNonDisplayableChar(std::string s) {
  return (ScalarConverter::strlen(s) == 1 && s[0] >= CHAR_MIN && (s[0] < 32 || s[0] > 126));
}

void ScalarConverter::convert(std::string s) {
  if (s == "+inf" || s == "+inff") {
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
    std::cout << "(detected type: special)" << std::endl;
    return;
  }
  if (s == "-inf" || s == "-inff") {
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
    std::cout << "(detected type: special)" << std::endl;
    return ;
  }
  if (s == "nan" || s == "nanf") {
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
    std::cout << "(detected type: special)" << std::endl;
    return ;
  }
  if (ScalarConverter::isChar(s)) {
    char c = s[0];
    if (c >= 32 && c <= 126)
      std::cout << "char:   '" << c << "' (detected type)" << std::endl;
    else
      std::cout << "char:   Non displayable (detected type)" << std::endl;
    std::cout << "int:    " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "float:  " << static_cast<float>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "double: " << static_cast<double>(c) << std::endl;
    return ;
  }

  char    *end;
  double  d = strtod(s.c_str(), &end);
  if (errno == ERANGE || (*end != '\0' && *end != 'f')) {
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    std::cout << "(type non detected)" << std::endl;
    return ;
  }
  if (d >= INT_MIN && d <= INT_MAX && !ScalarConverter::fInTheEnd(s) && !thereIsPoint(s)) {
    int i = std::atoi(s.c_str());
    if (static_cast<char>(i) >= 32 && static_cast<char>(i) <= 126)
      std::cout << "char:   '" << static_cast<char>(i) << "'" << std::endl;
    else
      std::cout << "char:   Non displayable" << std::endl;
    std::cout << "int:    " << i << " (detected type)" << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "float:  " << static_cast<float>(i) << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "double: " << static_cast<double>(i) << std::endl;
    return ;
  }
  if (d >=-FLT_MAX && d <= FLT_MAX && ScalarConverter::fInTheEnd(s)) {
    float f = std::strtof(s.c_str(), NULL);
    if (static_cast<char>(f) >= 32 && static_cast<char>(f) <= 126)
      std::cout << "char:   '" << static_cast<char>(f) << "'" << std::endl;
    else
      std::cout << "char:   Non displayable" << std::endl;
    if (d >= INT_MIN && d <= INT_MAX)
      std::cout << "int:    " << static_cast<int>(f) << std::endl;
    else
      std::cout << "int:    string-argument out of range [INT_MIN; INT_MAX]" << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "float:  " << f << "f (detected type)" << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "double: " << static_cast<double>(f) << std::endl;
    return ;
  }
  if (!ScalarConverter::fInTheEnd(s)) {
    if (static_cast<char>(d) >= 32 && static_cast<char>(d) <= 126)
      std::cout << "char:   '" << static_cast<char>(d) << "'" << std::endl;
    else
      std::cout << "char:   Non displayable" << std::endl;
    if (d >= INT_MIN && d <= INT_MAX)
      std::cout << "int:    " << static_cast<int>(d) << std::endl;
    else
      std::cout << "int:    string-argument out of range [INT_MIN; INT_MAX]" << std::endl;
    if (d >= -FLT_MAX && d <= FLT_MAX)
      std::cout << std::fixed << std::setprecision(2) << "float:  " << static_cast<float>(d) << "f" << std::endl;
    else
      std::cout << "float:  string-argument out of range [FLT_MIN; FLT_MAX]" << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "double: " << d << " (detected type)" << std::endl;
    return ;
  }
  std::cout << "char:   impossible" << std::endl;
  std::cout << "int:    impossible" << std::endl;
  std::cout << "float:  impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
  std::cout << "(type: non detected)" << std::endl;
}
