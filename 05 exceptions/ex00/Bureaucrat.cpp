#include "Bureaucrat.hpp"

/////////////////////////////////////////////////// OCCF
Bureaucrat::Bureaucrat(std::string name0, int grade0) {
  if (grade0 < 1)
    throw Bureaucrat::GradeTooHighException();
  if (grade0 > 150)
    throw Bureaucrat::GradeTooLowException();
  this->name  = name0;
  this->grade = grade0;
  std::cout << "Bureaucrat constructor, name = " << this->name << ", grade = " << this->grade << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &obj) {
  *this = obj;
  std::cout << "Bureaucrat copy constructor, name = " << this->name << ", grade = " << this->grade << std::endl;
};

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat destructor, name = " << this->name << ", grade = " << this->grade << std::endl;
};

Bureaucrat& Bureaucrat::operator = (Bureaucrat const &obj) {
  this->name = obj.getName();
  this->grade = obj.getGrade();
  std::cout << "Bureaucrat assignment operator, name = " << this->name << ", grade = " << this->grade << std::endl;
  return *this;
};

std::ostream & operator <<(std::ostream &out, const Bureaucrat &obj)
{
  out << obj.getName() << ", grade = " << obj.getGrade();
  return (out);
}

/////////////////////////////////////////////////// GETTERS
std::string Bureaucrat::getName() const {
  return this->name;
};

int Bureaucrat::getGrade() const {
  return this->grade;
};

/////////////////////////////////////////////////// MEMBER FUNCTIONS
void Bureaucrat::incrGrade() {
  if (this->grade <= 1)
    throw Bureaucrat::GradeTooHighException();
  this->grade--;
  std::cout << "incGrade, name = " << this->name << ", new grade = " << this->grade << std::endl;
}

void Bureaucrat::decrGrade() {
  if (this->grade >= 150)
    throw Bureaucrat::GradeTooLowException();
  this->grade++;
  std::cout << "decrGrade, name = " << this->name << ", new grade = " << this->grade << std::endl;
}

/////////////////////////////////////////////////// EXCEPTIONS
const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "GradeTooHighException";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "GradeTooLowException";
}