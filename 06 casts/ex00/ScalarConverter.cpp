#include "ScalarConverter.hpp"

/////////////////////////////////////////////////// OCCF and <<
ScalarConverter::ScalarConverter() {
  charVl = '\0';
  intVal = 0;
  floatV = 0;
  doublV = 0;
};

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
  *this = obj;
};

ScalarConverter::~ScalarConverter() {
};

ScalarConverter& ScalarConverter::operator = (ScalarConverter const &obj) {
  (void)obj;
  // intVal = 
  return *this;
};

std::ostream & operator <<(std::ostream &out, const ScalarConverter &obj) {
  (void)obj;

	// out << "char: ";
	// if (n < 0 || n > 127 || conv.isNum == 2)
	// 	out << "impossible" << std::endl;
	// else if ((n >= 0 && n <= 31) || n == 127)
	// 	out << "Non displayable" << std::endl;
	// else
	// 	out << conv.getChar() << std::endl;
	
	// out << "int: ";
	// if (conv.isNum == 2)
	// 	out << "impossible" << std::endl;
	// else
	// 	out << conv.getInt() << std::endl;
	
	// out << "float: ";
	// if (conv.noDec)
	// 	out << conv.getFloat() << ".0f" << std::endl;
	// else if (conv.isNum == 2)
	// 	out << conv.getSpecialCase() << "f" << std::endl;
	// else
	// 	out << conv.getFloat() << "f" << std::endl;
	
	// out << "double: ";
	// if (conv.noDec)
	// 	out << conv.getDouble() << ".0" << std::endl;
	// else if (conv.isNum == 2)
	// 	out << conv.getSpecialCase() << std::endl;
	// else
	// 	out << conv.getDouble() << std::endl;

	// else
	// 	out << "Error: it's not a numeric" << std::endl;
  return (out);
}

/////////////////////////////////////////////////// MEMBER FUNCTIONS
std::string	ScalarConverter::detectType(std::string s) {
  std::cout << "[" << s << "]" << std::endl;
  if(isChar(s))
    return ("char");
  if(isInt(s))
    return ("int");
  if(isFloat(s))
    return ("double");
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
void ScalarConverter::convert (std::string str) {
  std::string type = this->detectType(str);
  std::cout << "type = " << type << std::endl;
  // if (length == 1 && str.at(0) ) {
  //   this->charVl = this->str[0];
  //   this->intVal = this->
  //   this->floatV = strtof(str, NULL);
  //   this->doublV = strtod(str, NULL); 
  // 	this->_charNum = this->_charConversion(num);
  // 	int Char = static_cast<int>(this->_charNum);

	// else if (std::isdigit(this->_charNum) && Char > 0)
  // 	this->_intNum = static_cast<int>(Char);
  // 	this->_floatNum = static_cast<float>(Char);
  // 	this->_doubleNum = static_cast<double>(Char);
  // }
  // else if (length == 3 && str.at(0) == '\'' && && str.at(2) == '\'') {
  
  // }
  // else if (length == 3 && str.at(0) == '\'' && && str.at(2) == '\'') {
  
  // }
  // if()
  //   throw ScalarConverter::ConvertionImpossible();
  // std::cout << this << std::endl;
}

/////////////////////////////////////////////////// EXCEPTIONS
const char *ScalarConverter::ConvertionImpossible::what() const throw() {
  return "ConvertionImpossible";
}	