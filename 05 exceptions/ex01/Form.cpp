#include "Form.hpp"

/////////////////////////////////////////////////// OCCF
Form::Form(std::string name0, int gradeToSign0, int gradeToExecute0) {
  if (gradeToSign0 < 1 || gradeToExecute0 < 1)
    throw Form::GradeTooHighException();
  if (gradeToSign0 > 150 || gradeToExecute0 > 150)
    throw Form::GradeTooLowException();
  this->name           = name0;
  this->isSigned       = false;
  this->gradeToSign    = gradeToSign0;
  this->gradeToExecute = gradeToExecute0;
};

Form::Form(const Form &obj) {
  *this = obj;
};

Form::~Form() {
};

Form& Form::operator = (Form const &obj) {
  this->name = obj.getName();
  this->gradeToSign = obj.getGradeToSign();
  this->gradeToExecute = obj.getGradeToExecute();
  return *this;
};

std::ostream & operator <<(std::ostream &out, const Form &obj)
{
  out << obj.getName() << ", gradeToSign = " << obj.getGradeToSign() << ", gradeToExecute = " << obj.getGradeToExecute() << ", isSigned = " << obj.getIsSigned();
  return (out);
}

/////////////////////////////////////////////////// GETTERS
std::string Form::getName() const {
  return this->name;
};

bool Form::getIsSigned() const {
  return this->isSigned;
};

int Form::getGradeToSign() const {
  return this->gradeToSign;
};

int Form::getGradeToExecute() const {
  return this->gradeToExecute;
};

/////////////////////////////////////////////////// MEMBER FUNCTIONS
void Form::beSigned (Bureaucrat &b) {
  if (b.getGrade() > this->getGradeToSign())
    throw Form::GradeTooLowException();
  this->isSigned = true;
}

/////////////////////////////////////////////////// EXCEPTIONS
const char *Form::GradeTooHighException::what() const throw() {
  return "Form: GradeTooHighException";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Form: GradeTooLowException";
}