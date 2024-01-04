#include "ScalarConverter.hpp"

/////////////////////////////////////////////////// OCCF and <<
ScalarConverter::ScalarConverter() {
  charOk   = true;
  intOk    = true;
  floatOk  = true;
  doubleOk = true;
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
  if (obj.charIsOk() && obj.getCharV() >= 26 && obj.getCharV() <= 127) 
    out << "char:   " << std::fixed << std::right << std::setw(13) << "'" << obj.getCharV() << "'" << std::endl;
  else if (obj.charIsOk() && (obj.getCharV() < 26 || obj.getCharV() > 127))
    out << "char:   non displayable" << std::endl;
  else if (!obj.charIsOk())
    out << "char:        impossible" << std::endl;
  if (obj.intIsOk()) 
    out << "int:    " << std::fixed << std::right << std::setw(15) << obj.getIntV()    << std::endl;
  else
    out << "int:         impossible" << std::endl;
  if (obj.floatIsOk()) 
    out << "float:  " << std::fixed << std::right << std::setprecision(1) << std::setw(14) << obj.getFloatV()  << "f" << std::endl;
  else
    out << "float:       impossible" << std::endl;
  if (obj.doubleIsOk()) 
    out << "double: " << std::fixed << std::right << std::setprecision(1) << std::setw(15) << obj.getDoubleV() << std::endl;
  else
    out << "double:      impossible" << std::endl;
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

bool ScalarConverter::charIsOk() const {
  return this->charOk;
}

bool ScalarConverter::intIsOk() const {
  return this->intOk;
}

bool ScalarConverter::floatIsOk() const {
  return this->floatOk;
}

bool ScalarConverter::doubleIsOk() const {
  return this->doubleOk;
}

/////////////////////////////////////////////////// MEMBER FUNCTIONS

bool ScalarConverter::isSpecial(std::string s) {
  if(s == "nan" || s == "inf" || s == "-inf") {
    this->doubleV =  std::strtod(s.c_str(), NULL);
    this->floatV  = static_cast<float>(this->doubleV);
    this->charOk    = false;
    this->intOk     = false;
    return true;
  }
  else if(s == "nanf" || s == "inff" || s == "-inff") {
    this->floatV  = std::strtof(s.c_str(), NULL);
    this->doubleV = static_cast<double>(this->floatV);
    this->charOk    = false;
    this->intOk     = false;
    return true;
  }
  return false;
}

bool ScalarConverter::isChar(std::string s) {
  if(strlen(s) == 1 && !isDigit(s[0])) {
    this->charV   = s[0]; // static_cast<char>(s[0]);
    this->intV    = static_cast<int>(this->charV); // s[0];
    this->floatV  = static_cast<float>(this->charV);
    this->doubleV = static_cast<double>(this->charV);
    return true;
  }
  return false;
}

bool ScalarConverter::isInt(std::string s) {
  if((s[0] == '+' || s[0] == '-' || isDigit(s[0])) && isDigits(&s[1]) && isInIntLimits(s)) {
    this->intV    = std::atoi(s.c_str());
    if (isInCharLimits(this->intV))
      this->charV   = static_cast<char>(this->intV);
    else
      this->charOk = false;
    this->floatV  = static_cast<float>(this->intV);
    this->doubleV = static_cast<double>(this->intV);
    return true;
  }
  return false;
}

bool ScalarConverter::isDouble(std::string s) {
  if(((s[0] == '+' || s[0] == '-' || isDigit(s[0])) && isDigitsWithDecmalPoint(&s[1])) ) { // limits
    this->doubleV =  std::strtod(s.c_str(), NULL);
    if (isInIntLimits(s))
      this->intV    = static_cast<int>(this->doubleV);
    else
      this->intOk = false;
    if (this->intOk && isInCharLimits(this->intV))
      this->charV = static_cast<char>(this->doubleV);
    else 
      this->charOk = false;
    this->floatV  = static_cast<float>(this->doubleV); // limits
    return true;
  }
  return false;
}

bool ScalarConverter::isFloat(std::string s) {
  if (s[strlen(s) - 1] == 'f')
    s[strlen(s) - 1] = '\0';
  if((s[0] == '+' || s[0] == '-' || isDigit(s[0])) && isDigitsWithDecmalPoint(&s[1])) { // limits
    this->floatV  = std::strtof(s.c_str(), NULL);
    this->intV    = static_cast<int>(this->floatV);
    this->charV   = static_cast<char>(this->floatV);
    this->doubleV = static_cast<double>(this->floatV);
    return true;
  }
  return false;
}

// detect the type of the literal passed as parameter
// convert it from string to its actual type
// convert it explicitly to the three other types
// if a conversion does not make any sense or overflows, display a message
// static_cast to convert values
// Accept the use of implicit casts for promotion casts only
void ScalarConverter::convert (std::string s) {
  trim(&s);
  std::cout << "trimmed: [" << s << "]" << std::endl;
  if (strlen(s) == 0 || !(isSpecial(s) || isChar(s) || isInt(s) || isDouble(s) || isFloat(s))) {
    this->charOk   = false;
    this->intOk    = false;
    this->floatOk  = false;
    this->doubleOk = false;
  }
}