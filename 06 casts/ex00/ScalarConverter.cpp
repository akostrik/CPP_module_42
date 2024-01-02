#include "ScalarConverter.hpp"

/////////////////////////////////////////////////// OCCF and <<
ScalarConverter::ScalarConverter() {
  charV   = '\0';
  intV    = 0;
  floatV  = 0;
  doubleV = 0;
};

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
  *this = obj;
};

ScalarConverter::~ScalarConverter() {
};

ScalarConverter& ScalarConverter::operator = (ScalarConverter const &obj) {
  this->intV = obj.intV;
  return *this;
};

std::ostream & operator <<(std::ostream &out, const ScalarConverter &obj) {
  if(isDisplayableChar(this->getCharVal()))
    out << "char:   " << obj.getCharVal()   << std::endl;
  else
    out << "char:   indisplayable char"   << std::endl;
  out << "int:    " << obj.getIntVal()    << std::endl;
  out << "float:  " << obj.getFloatVal()  << std::endl;
  out << "double: " << obj.getDoubleVal() << std::endl;
  return (out);
}

/////////////////////////////////////////////////// GETTERS


/////////////////////////////////////////////////// MEMBER FUNCTIONS
std::string	ScalarConverter::detectType(std::string s) {
  if(isChar(s))
    return ("char");
  if(isInt(s))
    return ("int");
  if(isFloat(s))
    return ("float");
  if(isDouble(s))
    return ("double");
  return "indefined";
}

// detect the type of the literal passed as parameter
// convert it from string to its actual type
// convert it explicitly to the three other types
// If a conversion does not make any sense or overflows, display a message to inform the user that the type conversion is impossible
void ScalarConverter::convert (std::string s) {
  std::string type = detectType(s);
  std::cout << "[" << s << "], type = " << type << std::endl;
  if (type == "char") {
    this->charV   = s[0];
    this->intV    = atoi(s.c_str());
    this->floatV  = strtof(s.c_str(), NULL);
    this->doubleV = strtod(s.c_str(), NULL); 
  }
  // int Char = static_cast<int>(this->_charNum);
	// else if (std::isdigit(this->_charNum) && Char > 0)
  // 	this->_intNum = static_cast<int>(Char);
  // 	this->_floatNum = static_cast<float>(Char);
  // 	this->_doubleNum = static_cast<double>(Char);
  // }
  
  // if()
  //   throw ScalarConverter::ConvertionImpossible();
  std::cout << this << std::endl;
}

/////////////////////////////////////////////////// EXCEPTIONS
const char *ScalarConverter::ConvertionImpossible::what() const throw() {
  return "ConvertionImpossible";
}	