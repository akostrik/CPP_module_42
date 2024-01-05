#include "ScalarConverter.hpp"

/////////////////////////////////////////////////// OCCF and <<
ScalarConverter::ScalarConverter() {
};

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
  *this = obj;
};

ScalarConverter::~ScalarConverter() {
};

ScalarConverter& ScalarConverter::operator = (ScalarConverter const &obj) {
  (void)obj;
  return *this;
};

/////////////////////////////////////////////////// MEMBER FUNCTIONS


// detect the type of the literal passed as parameter
// convert it from string to its actual type
// convert it explicitly to the three other types
// if a conversion does not make any sense or overflows, display a message
// static_cast to convert values
// Accept the use of implicit casts for promotion casts only
void ScalarConverter::convert (std::string s) {
  trim(&s);
  std::cout << "trimmed: [" << s << "]" << std::endl;
  if (strlen(s) == 0) {
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
  }
  else if(s == "nan" || s == "inf" || s == "-inf") {
    double d =  std::strtod(s.c_str(), NULL);
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  " << static_cast<float>(d) << std::endl;
    std::cout << "double: " << d << std::endl;
  }
  else if(s == "nanf" || s == "inff" || s == "-inff") {
    float f = std::strtof(s.c_str(), NULL);
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  " << f << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
  }
  else if(strlen(s) == 1 && !isDigit(s[0])) {
    char c = s[0]; // static_cast<char>(s[0]);
    std::cout << "char:   " << c << std::endl;
    std::cout << "int:    " << static_cast<int>(c) << std::endl;
    std::cout << "float:  " << static_cast<float>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
  }
  else if((s[0] == '+' || s[0] == '-' || isDigit(s[0])) && isDigits(&s[1]) && inLimits(s, "-2147483648", "2147483647")) {
    int i = std::atoi(s.c_str());
    std::cout << "int:    " << i << std::endl;
    if (inLimits(s, "-128", "127")) 
      std::cout << "char:   " << static_cast<char>(i)<< std::endl;
    else
      std::cout << "char:   impossible" << std::endl;
    std::cout << "float:  " << static_cast<float>(i) << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
  } // limits
  else if((s[0] == '+' || s[0] == '-' || isDigit(s[0])) && (s[strlen(s) - 1] == 'f' && (s[strlen(s) - 1] = '\0')) && isDigitsWithDecmalPoint(&s[1]) && inLimits(s, "-340282346638528859811704183484516925440.0", "340282346638528859811704183484516925440.0")) {
    float f = std::strtof(s.c_str(), NULL);
    if (inLimits(s, "-128", "127")) // intOk && 
      std::cout << "char:   " << static_cast<char>(f) << std::endl;
    else 
    std::cout << "char:   impossible" << std::endl;
    if (inLimits(s, "-2147483648", "2147483647"))
      std::cout << "int:    " << static_cast<int>(f) << std::endl;
    else
      std::cout << "int:   impossible" << std::endl;
    std::cout << "float:  " << f << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
  }
  else if(((s[0] == '+' || s[0] == '-' || isDigit(s[0])) && isDigitsWithDecmalPoint(&s[1])) && inLimits(s, "-340282346638528859811704183484516925440.0", "340282346638528859811704183484516925440.0")) {
    double d =  std::strtod(s.c_str(), NULL);
    if (inLimits(s, "-128", "127")) // intOk && 
      std::cout << "char:   " << static_cast<char>(d) << std::endl;
    else 
      std::cout << "char:   impossible" << std::endl;
    if (inLimits(s, "-2147483648", "2147483647"))
      std::cout << "int:    " << static_cast<int>(d) << std::endl;
    else
      std::cout << "int:    impossible" << std::endl;
    if (inLimits(s, "-340282346638528859811704183484516925440.0", "340282346638528859811704183484516925440.0"))
      std::cout << "float:  " << static_cast<float>(d) << std::endl;
    else
      std::cout << "float:  impossible" << std::endl;
    std::cout << "double: " << d << std::endl;
  }
  else {
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
  }
}