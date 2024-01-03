#include "ScalarConverter.hpp"

/////////////////////////////////////////////////// OCCF and <<
ScalarConverter::ScalarConverter() {
  charV   = ' ';
  intV    = 3;
  floatV  = 4;
  doubleV = 5;
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
  out << "int:    " << obj.getIntV()    << std::endl;
  out << "float:  " << obj.getFloatV()  << std::endl;
  out << "double: " << obj.getDoubleV() << std::endl;
  if (obj.getCharV() < 26 || obj.getCharV() > 127)
    out << "char:   indispayable" << std::endl;
  else
    out << "char:   " << obj.getCharV()   << std::endl;
  return (out);
}

/////////////////////////////////////////////////// GETTERS
char ScalarConverter::getCharV() const {
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
// detect the type of the literal passed as parameter
// convert it from string to its actual type
// convert it explicitly to the three other types
// if a conversion does not make any sense or overflows, display a message
void ScalarConverter::convert (std::string s) {
  if (strlen(s) == 0)
    throw ScalarConverter::ConvertionFailed();
  try {
    this->charV   = convertToChar(s);
    this->intV    = 0;
    this->floatV  = 0;
    this->doubleV = 0;
    std::cout << "char" << std::endl;
  } catch (...) {
    try {
      this->intV = convertToInt(s);
      std::cout << "int" << std::endl;
    } catch (...) {
      std::cout << "catch2" << std::endl;
      throw ScalarConverter::ConvertionFailed();
    }
  }
  // if(convertToIndisplaybleChar(s))
  //   ;
  // if(isInt(s))
  // if(isFloat(s))
  // if(isDouble(s))
  //   return "double";
  // return "indefined";

  // if (type == "char") {
  //   this->charV   = s[0];
  //   this->intV    = atoi(s.c_str());
  //   this->floatV  = strtof(s.c_str(), NULL);
  //   this->doubleV = strtod(s.c_str(), NULL); 
  // }

  // int Char = static_cast<int>(this->_charNum);
	// else if (std::isdigit(this->_charNum) && Char > 0)
  // 	this->_intNum = static_cast<int>(Char);
  // 	this->_floatNum = static_cast<float>(Char);
  // 	this->_doubleNum = static_cast<double>(Char);
  // }
  
  // if()
  //   throw ScalarConverter::ConvertionFailed();
}

/////////////////////////////////////////////////// EXCEPTIONS
const char *ScalarConverter::ConvertionFailed::what() const throw() {
  return "ConvertionFailed";
}