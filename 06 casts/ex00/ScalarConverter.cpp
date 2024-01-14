// s.back() != 'f' 
// s.find( '.' ) == 0
// s.compare( "nan" ) == 0 

#include "ScalarConverter.hpp"

bool ScalarConverter::fInTheEnd(std::string s) {
  int len;

  for (len = 0; s[len] != '\0'; len++) ;
  return (s[len - 1] == 'f');
}

void ScalarConverter::convert(std::string s) {
  if (s == "+inf" || s == "+inff") {
    std::cout << "type:   special" << std::endl;
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
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

  char    *end;
  double  d = strtod(s.c_str(), &end);
  if (errno == ERANGE || (*end != '\0' && *end != 'f')) {
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    std::cout << "(type: non detected)" << std::endl;
    return ;
  }
  if (d >= CHAR_MIN && d <= CHAR_MAX && !ScalarConverter::fInTheEnd(s)) {
    char c = s[0];
    if (d >= 32 || d <= 126)
      std::cout << "char:   '" << c << "'" << std::endl;
    else
      std::cout << "char:   Non displayable" << std::endl;
    std::cout << "int:    " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float:  " << static_cast<float>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(c) << std::endl;
    std::cout << "(detected type: char)" << std::endl;
    return ;
  }
  if (d >= INT_MIN && d <= INT_MAX && !ScalarConverter::fInTheEnd(s)) {
    int i = std::atoi(s.c_str());
    if (d >= 32 && d <= 126)
      std::cout << "char:   '" << static_cast<char>(i) << "'" << std::endl;
    else if (d >= CHAR_MIN && d <= CHAR_MAX)
      std::cout << "char:   Non displayable" << std::endl;
    else
      std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float:  " << static_cast<float>(i) << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(i) << std::endl;
    std::cout << "(detected type: int)" << std::endl;
    return ;
  }
  if (d >=-FLT_MAX && d <= FLT_MAX && ScalarConverter::fInTheEnd(s)) {
    float f = std::strtof(s.c_str(), NULL);
    if (d >= 32 && d <= 126)
      std::cout << "char:   '" << static_cast<char>(f) << "'" << std::endl;
    else if (d >= CHAR_MIN && d <= CHAR_MAX)
      std::cout << "char:   Non displayable" << std::endl;
    else
      std::cout << "char:   impossible" << std::endl;
    if (d >= INT_MIN && d <= INT_MAX)
      std::cout << "int:    " << static_cast<int>(f) << std::endl;
    else
      std::cout << "int:    impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float:  " << f << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(f) << std::endl;
    std::cout << "(detected type: float)" << std::endl;
    return ;
  }
  if (!ScalarConverter::fInTheEnd(s)) {
    if (d >= 32 && d <= 126)
      std::cout << "char:   '" << static_cast<char>(d) << "'" << std::endl;
    else if (d >= CHAR_MIN && d <= CHAR_MAX)
      std::cout << "char:   Non displayable" << std::endl;
    else
      std::cout << "char:   impossible" << std::endl;
    if (d >= INT_MIN && d <= INT_MAX)
      std::cout << "int:    " << static_cast<int>(d) << std::endl;
    else
      std::cout << "int:    impossible" << std::endl;
    if (d >= -FLT_MAX && d <= FLT_MAX)
      std::cout << std::fixed << std::setprecision(1) << "float:  " << static_cast<float>(d) << "f" << std::endl;
    else
      std::cout << "float:  impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
    std::cout <<  "(detected type: double)" << std::endl;
    return ;
  }
  std::cout << "char:   impossible" << std::endl;
  std::cout << "int:    impossible" << std::endl;
  std::cout << "float:  impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
  std::cout << "(type: non detected)" << std::endl;
}