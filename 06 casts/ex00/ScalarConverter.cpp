#include "ScalarConverter.hpp"

/////////////////////////////////////////////////// OCCF and <<
ScalarConverter::ScalarConverter(std::string name0, int grade0) {
};

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
  *this = obj;
};

ScalarConverter::~ScalarConverter() {
};

ScalarConverter& ScalarConverter::operator = (ScalarConverter const &obj) {
  return *this;
};

std::ostream & operator <<(std::ostream &out, const ScalarConverter &obj) {
  out << obj.getName() << ", grade = " << obj.getGrade();
  return (out);
}

/////////////////////////////////////////////////// GETTERS

/////////////////////////////////////////////////// MEMBER FUNCTIONS
void ScalarConverter::convert (std::string str) {
  if()
    throw ScalarConverter::ConvertionImpossible();
  std::cout << "decrGrade " << this->name << ", new grade = " << this->grade << std::endl;
}

/////////////////////////////////////////////////// EXCEPTIONS
const char *ScalarConverter::ConvertionImpossible::what() const throw() {
  return "ConvertionImpossible";
}