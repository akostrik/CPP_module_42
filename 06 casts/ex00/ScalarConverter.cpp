#include "ScalarConverter.hpp"

/////////////////////////////////////////////////// OCCF and <<
// ScalarConverter::~ScalarConverter() {}; ?

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &obj) { *this = obj; };

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
  if(s == "nan" || s == "inf" || s == "-inf") { // SPECIAL
    double d =  std::strtod(s.c_str(), NULL);
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  " << static_cast<float>(d) << std::endl;
    std::cout << "double: " << d << std::endl;
  }
  else if(s == "nanf" || s == "inff" || s == "-inff") { // SPECIAL
    float f = std::strtof(s.c_str(), NULL); // std::atof(literal.c_str());
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
  }
  else if(s.size() == 1 && !std::isdigit(s[0])) { // CHAR
    char c = s[0]; // static_cast<char>(s[0]);
    if (s[0]>=32 && s[0]<=127) //std::isprint(s[0]))
      std::cout << "char:   " << c << std::endl;
    else 
      std::cout << "char:   non dispayable" << std::endl;
    std::cout << "int:    " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float:  " << static_cast<float>(c) << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(c) << std::endl;
  }
  else if(((s[0] == '-' && isDigits(&s[1])) || isDigits(s)) && inLimits(s, "-2147483648", "2147483647")) { // INT
    int i = std::atoi(s.c_str());
    std::cout << "int:    " << i << std::endl;
    if (inLimits(s, "32", "127")) 
      std::cout << "char:   " << static_cast<char>(i)<< std::endl;
    else if (inLimits(s, "-128", "127")) 
      std::cout << "char:   non dispalyable" << std::endl;
    else
      std::cout << "char:   impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float:  " << static_cast<float>(i) << "f" <<std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(i) << std::endl;
  } // limits
  else if((s[0] == '-' || std::isdigit(s[0])) && (s[s.size() - 1] == 'f' && (s[s.size() - 1] = '\0')) && isDigitsWithDecmalPoint(&s[1]) && inLimits(s, "-340282346638528859811704183484516925440.0", "340282346638528859811704183484516925440.0")) {
    float f = std::strtof(s.c_str(), NULL);
    if (inLimits(s, "-128", "127")) // intOk && 
      std::cout << "char:   " << static_cast<char>(f) << std::endl;
    else 
    std::cout << "char:   impossible" << std::endl;
    if (inLimits(s, "-2147483648", "2147483647"))
      std::cout << "int:    " << static_cast<int>(f) << std::endl;
    else
      std::cout << "int:   impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float:  " << f << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(f) << std::endl;
  }
  else if(((s[0] == '-' || std::isdigit(s[0])) && isDigitsWithDecmalPoint(&s[1])) && inLimits(s, "-340282346638528859811704183484516925440.0", "340282346638528859811704183484516925440.0")) {
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
      std::cout << std::fixed << std::setprecision(1) << "float:  " << static_cast<float>(d) << "f" << std::endl;
    else
      std::cout << "float:  impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
  }
  else {
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
  }
}