#include "ScalarConverter.hpp"

/////////////////////////////////////////////////// OCCF and <<
ScalarConverter::ScalarConverter() {
  charV          = ' ';
  intV           = 3;
  floatV         = 4;
  doubleV        = 5;
  specialFloatV  = "";
  specialDoubleV = "";
};

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
  *this = obj;
};

ScalarConverter::~ScalarConverter() {
};

ScalarConverter& ScalarConverter::operator = (ScalarConverter const &obj) {
  this->intV = obj.intV; // etc
  return *this;
};

std::ostream & operator <<(std::ostream &out, const ScalarConverter &obj) {
  if (obj.getCharV() < 26 || obj.getCharV() > 127)
    out << "char:      indispayable" << std::endl;
  else
    out << "char:   " << std::fixed << std::right << std::setw(15) << obj.getCharV()   << std::endl;
  out << "int:    " << std::fixed << std::right << std::setw(15) << obj.getIntV()    << std::endl;
  out << "float:  " << std::fixed << std::right << std::setprecision(2) << std::setw(15) << obj.getFloatV()  << "f" << std::endl;
  out << "double: " << std::fixed << std::right << std::setprecision(2) << std::setw(15) << obj.getDoubleV() << std::endl;
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

std::string ScalarConverter::getSpecialFloatV() const {
  return this->specialFloatV;
}

std::string ScalarConverter::getSpecialDoubleV() const {
  return this->specialDoubleV;
}

/////////////////////////////////////////////////// MEMBER FUNCTIONS
bool ScalarConverter::isSpace(std::string s) {
  for (int i = 0; s[i] != '\0'; i++)
    if (s[i] != ' ')
        return false;
  this->charV   = ' ';
  this->intV    = 0; //
  this->floatV  = 0;
  this->doubleV = 0;
  return true ;
}

bool ScalarConverter::isSpecialV(std::string s) {
  trim(&s);
  if(s == "+inf" || s == "-inf" || s == "nan") {
    this->specialFloatV = s;
    return true;
  }
  else if(s == "+inff" || s == "-inff" || s == "nanf") {
    this->specialDoubleV = s;
    return true;
  }
  return false;
}

bool ScalarConverter::isChar(std::string s) {
  trim(&s);
  if(!isDigit(s[0]) && strlen(s) == 1) { // s[0] >= 0 && [0] <= 128 ?
    this->charV   = s[0]; // static_cast<char>(s[0]);
    this->intV    = static_cast<int>(this->charV);
    this->floatV  = static_cast<float>(this->charV);
    this->doubleV = static_cast<double>(this->charV);
    return true;
  }
  return false;
}

bool ScalarConverter::isInt(std::string s) {
  trim(&s);
  if((s[0] == '+' || s[0] == '-' || isDigit(s[0])) && isDigits(&s[1]) && isInIntLImits(s)) {
    this->intV    = std::atoi(s.c_str());
    this->charV   = static_cast<char>(this->intV);
    this->floatV  = static_cast<float>(this->intV);
    this->doubleV = static_cast<double>(this->intV);
    return true;
  }
  return false;
}

bool ScalarConverter::isFloat(std::string s) {
  trim(&s);
  if (s[strlen(s) - 1] == 'f')
    s[strlen(s) - 1] = '\0';
  if((s[0] == '+' || s[0] == '-' || isDigit(s[0])) && isDigitsWithDecmalPoint(&s[1])) {
    this->intV    = s[0]; // static_cast<int>(s.c_str());
    this->charV   = atoi(s.c_str());
    this->floatV  = this->intV; // csst implicit strtof(s.c_str(), NULL);`
    this->doubleV = this->intV;
    return true;
    // strtof(s.c_str(), NULL);`
    // 1,175494351 E – 38
    // 3,402823466 E + 38
  }
  return false;
}

bool ScalarConverter::isDouble(std::string s) {
  trim(&s);
  // strtod(s.c_str(), NULL)
  // removeF(&s);
  // limits
  // return isOnlyDigits(s);
  return false;
}

// detect the type of the literal passed as parameter
// convert it from string to its actual type
// convert it explicitly to the three other types
// if a conversion does not make any sense or overflows, display a message
// static_cast to convert values
// Accept the use of implicit casts for promotion casts only
void ScalarConverter::convert (std::string s) {
  if (strlen(s) == 0)
    return ;
  if(isSpace(s) || isSpecialV(s) || isChar(s) || isInt(s) || isFloat(s) || isDouble(s))
    std::cout << "converted" << std::endl;
}