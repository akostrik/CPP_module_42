#include "AForm.hpp"

/////////////////////////////////////////////////// OCCF and <<
AForm::AForm(std::string name0, int gradeToSign0, int gradeToExecute0, std::string target0) {
  if (gradeToSign0 < 1 || gradeToExecute0 < 1)
    throw Bureaucrat::GradeTooHighException();
  if (gradeToSign0 > 150 || gradeToExecute0 > 150)
    throw Bureaucrat::GradeTooLowException();
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
  out << obj.getName() << ", " << obj.getGradeToSign() << ", " << obj.getGradeToExecute() << ", isSigned = " << obj.getIsSigned();
  return (out);
}

/////////////////////////////////////////////////// GETTERS
std::string AForm::getName()  const {
  return this->name;
};

bool AForm::getIsSigned()      const {
  return this->isSigned;
};

int AForm::getGradeToSign()    const {
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
    std::cout << b.getName() << "          can’t sign " << this->getName() << " because ";
    throw AForm::GradeTooLowException();
  }
  this->isSigned = true;
  std::cout << b.getName() << " signed   " << this->getName() << std::endl;
}

/////////////////////////////////////////////////// EXCEPTIONS
const char *AForm::GradeTooHighException::what() const throw() {
  return "AForm: GradeTooHighException";
};

const char *AForm::GradeTooLowException::what()  const throw() {
  return "AForm: GradeTooLowException";
};

const char *AForm::NotSignedException::what()    const throw() {
  return "AForm: NotSignedException";
};
