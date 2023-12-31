#include "AForm.hpp"

/////////////////////////////////////////////////// OCCF and <<
AForm::AForm(std::string name0, int gradeToSign0, int gradeToExecute0, std::string target0) {
  this->name           = name0;
  this->gradeToSign    = gradeToSign0;
  this->gradeToExecute = gradeToExecute0;
  this->target         = target0;
  this->isSigned       = false;
};

AForm::AForm(const AForm &obj) {
  *this = obj;
};

AForm::~AForm() {
};

AForm& AForm::operator = (AForm const &obj) {
  this->name           = obj.getName();
  this->gradeToSign    = obj.getGradeToSign();
  this->gradeToExecute = obj.getGradeToExecute();
  this->isSigned       = obj.getIsSigned();
  this->target         = obj.getTarget();
  return *this;
};

std::ostream & operator <<(std::ostream &out, const AForm &obj) {
  out << obj.getName() << ", gradeToSign = " << obj.getGradeToSign() << ", gradeToExecute = " << obj.getGradeToExecute() << ", isSigned = " << obj.getIsSigned();
  return (out);
}

/////////////////////////////////////////////////// GETTERS
std::string AForm::getName() const {
  return this->name;
};

bool AForm::getIsSigned() const {
  return this->isSigned;
};

int AForm::getGradeToSign() const {
  return this->gradeToSign;
};

int AForm::getGradeToExecute() const {
  return this->gradeToExecute;
};

std::string AForm::getTarget() const {
  return this->target;
};

/////////////////////////////////////////////////// MEMBER FUNCTIONS
void AForm::beSigned (Bureaucrat &b) {
  if (b.getGrade() > this->getGradeToSign()) {
    std::cout << b.getName() << " couldn’t sign " << this->getName() << " because of: ";
    throw AForm::GradeTooLowException();
  }
  this->isSigned = true;
}

/////////////////////////////////////////////////// EXCEPTIONS
const char *AForm::GradeTooHighException::what() const throw() {
  return "AForm: GradeTooHighException";
};

const char *AForm::GradeTooLowException::what() const throw() {
  return "AForm: GradeTooLowException";
};

const char *AForm::NotSignedException::what() const throw() {
  return "AForm: NotSignedException";
};
