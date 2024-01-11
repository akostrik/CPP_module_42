#include "ScalarConverter.hpp"


/////////////////////////////////////////////////// OCCF

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &obj) { *this = obj; };

ScalarConverter& ScalarConverter::operator = (ScalarConverter const &obj) {
  (void)obj;
  return *this;
};

/////////////////////////////////////////////////// MEMBER FUNCTIONS

void ScalarConverter::convert (std::string s) {
  trim(&s);
  std::cout << "trimmed: [" << s << "]" << std::endl;
  if(isSpecialDouble(s)) {
    double d =  std::strtod(s.c_str(), NULL);
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  " << static_cast<float>(d) << std::endl;
    std::cout << "double: " << d << std::endl;
    return ;
  }
  if(isSpecialFloat(s)) {
    float f = std::strtof(s.c_str(), NULL); // std::atof(literal.c_str());
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
    return ;
  }
  if(isChar(s)) {
    char c = s[0];
    if (std::isprint(s[0]))
      std::cout << "char:   '" << c << "'" << std::endl;
    else 
      std::cout << "char:   non dispayable" << std::endl;
    std::cout << "int:    " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float:  " << static_cast<float>(c) << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(c) << std::endl;
    return ;
  }
  if(isInt(s)) {
    std:: cout << "INT" << std::endl;
    int i = std::atoi(s.c_str());
    if (i >= 32 && i <= 126)
      std::cout << "char:   '" << static_cast<char>(i) << "'" << std::endl;
    else if (i >= -128 && i <= 127)
      std::cout << "char:   non dispalyable" << std::endl;
    else
      std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float:  " << i << "f" <<std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(i) << std::endl;
    return ;
  }
  if(isFloat(s)) {
    std:: cout << "FLOAT" << std::endl;
    // if (s[strlen(s) - 1] == 'f') // without if ?
    s[strlen(s) - 1] = '\0';
    std::cout << "s = " << s << std::endl;
    std::cout << "s.c_str() = [" << s.c_str() << "]" << std::endl;
    std::cout << std::fixed << "strtof = [" << std::strtof("2147483647", NULL) << "]" << std::endl;
    float f = std::strtof(s.c_str(), NULL); // distinguer le cas ou la chaîne de caractères contient "0.0" du cas ou aucune valeur flottante ne peut être décodée.
    std::cout << std::fixed << "f = " << f << std::endl;
    if (f >= 32 && f <= 126) // 31 127 ?
      std::cout << "char:   '" << static_cast<char>(f) << "'" << std::endl;
    else if (f >= -128 && f <= 127)
      std::cout << "char:   non dispalyable" << std::endl;
    else 
      std::cout << "char:   impossible" << std::endl;
    std::cout << "inLimits(" << s << ", " << std::numeric_limits<int>::min() << ", " << toString(std::numeric_limits<int>::max()) << ") = " << inLimits(s, toString(std::numeric_limits<int>::min()), toString(std::numeric_limits<int>::max())) << std::endl;
    if (inLimits(s, toString(std::numeric_limits<int>::min()), toString(std::numeric_limits<int>::max())))
      std::cout << "int:    " << static_cast<int>(f) << std::endl;
    else
      std::cout << "int:    impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float:  " << f << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(f) << std::endl;
    return ;
  }
  if(isDouble(s)) {
    std:: cout << "DOUBLE" << std::endl;
    double d =  std::strtod(s.c_str(), NULL);
    std::cout << "strtod = " << std::fixed << std::setprecision(6) << std::strtod(s.c_str(), NULL) << std::endl;
    std::cout << "strtof = " << std::fixed << std::setprecision(6) << std::strtof(s.c_str(), NULL) << std::endl;
    std::cout << "static_cast<float>(double " << d << ") = " << static_cast<float>(d) << std::endl;
    if (d >= 32 && d <= 126)
      std::cout << "char:   '" << static_cast<char>(d) << "'" << std::endl;
    else if (d >= -128 && d <= 127)
      std::cout << "char:   non dispalyable" << std::endl;
    else 
      std::cout << "char:   impossible" << std::endl;
    if (inLimits(s, toString(std::numeric_limits<int>::min()), toString(std::numeric_limits<int>::max())))
      std::cout << "int:    " << static_cast<int>(d) << std::endl;
    else
      std::cout << "int:    impossible" << std::endl;
    if (inLimits(s, toString(-std::numeric_limits<float>::max()), toString(std::numeric_limits<float>::max()))) {
      std::cout << std::fixed << std::setprecision(1) << "float:  " << static_cast<float>(d) << "f" << std::endl;
      float f = d;
      std::cout << std::fixed << std::setprecision(1) << "float:  " << f << "f" << std::endl;
    }
    else
      std::cout << "float:  impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
    return ;
  }
  std::cout << "char:   impossible" << std::endl;
  std::cout << "int:    impossible" << std::endl;
  std::cout << "float:  impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
}

// 100000000000
// 2147483647
// static_cast<float>(100000000000.000000) = 
//                      99999997952.000000