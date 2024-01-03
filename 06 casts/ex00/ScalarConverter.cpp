#include "ScalarConverter.hpp"

/////////////////////////////////////////////////// OCCF and <<
ScalarConverter::ScalarConverter() {
  charV   = "";
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
  if(isDisplayableCharAndNotSDigit(obj.getCharV()))
    out << "char:   " << obj.getCharV()   << std::endl;
  else
    out << "char:   indisplayable char"   << std::endl;
  out << "int:    " << obj.getIntV()    << std::endl;
  out << "float:  " << obj.getFloatV()  << std::endl;
  out << "double: " << obj.getDoubleV() << std::endl;
  return (out);
}

/////////////////////////////////////////////////// GETTERS
std::string ScalarConverter::getCharV() const {
  return this->charV;
}

int ScalarConverter::getIntV() const {
  return this->intV;
}

float ScalarConverter::getFloatV() const {
  return this->floatV;
}

double ScalarConverter::getDoubleV() const {
  return this->doubleV;
}

/////////////////////////////////////////////////// MEMBER FUNCTIONS
std::string	ScalarConverter::detectType(std::string s) {

  if (s[0] == '\0')
    return "indefined";
  if(isOnlySpaces(s))
    return "char";
  trim(&s);
  if(isDisplayableCharAndNotSDigit(s))
    return "char";
  if(isIndisplayableChar(s))
    ; // exception
  if(isInt(s))
    return "int";
  if(isFloat(s))
    return "float";
  if(isDouble(s))
    return "double";
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