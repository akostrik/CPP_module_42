#include "ScalarConverter.hpp"

/////////////////////////////////////////////////// OCCF and <<
ScalarConverter::ScalarConverter() {
  charVal   = '\0';
  intVal    = 0;
  floatVal  = 0;
  doubleVal = 0;
};

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
  *this = obj;
};

ScalarConverter::~ScalarConverter() {
};

ScalarConverter& ScalarConverter::operator = (ScalarConverter const &obj) {
  this->intVal = obj.intVal;
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
  // If a conversion does not make any sense or overflows, display a message to inform the user that the type conversion is impossible
}

// detect the type of the literal passed as parameter
// convert it from string to its actual type
// convert it explicitly to the three other types
void ScalarConverter::convert (std::string s) {
  std::string type = this->detectType(s);
  std::cout << "[" << s << "]" << std::endl;
  std::cout << "type = " << type << std::endl;
  if (type == "char") {
    this->charVal   = this->s[0];
    this->intVal    = atoi(s);
    this->floatVal  = strtof(s, NULL);
    this->doubleVal = strtod(s, NULL); 
  }
  // 	int Char = static_cast<int>(this->_charNum);
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