#include "PresidentialPardonForm.hpp"

/////////////////////////////////////////////////// OCCF
PresidentialPardonForm::PresidentialPardonForm(std::string target0) : AForm("PresidentialPardonForm", 145, 137, target0) {
};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj) : AForm(obj) {
  *this = obj;
};

PresidentialPardonForm::~PresidentialPardonForm() {
};

PresidentialPardonForm& PresidentialPardonForm::operator = (PresidentialPardonForm const &obj) {
  this->name = obj.getName();
  this->gradeToSign = obj.getGradeToSign();
  this->gradeToExecute = obj.getGradeToExecute();
  return *this;
};

/////////////////////////////////////////////////// MEMBER FUNCTIONS
void PresidentialPardonForm::execute(Bureaucrat const &b) const {

  if (this->getIsSigned() == false) {
    std::cout << b.getName() << "          couldn’t execute " << this->getName() << " because ";
    throw AForm::NotSignedException();
  }
  if (b.getGrade() > this->getGradeToExecute()) {
    std::cout << b.getName() << "          couldn’t execute " << this->getName() << " because ";
    throw AForm::GradeTooLowException();
  }
  std::cout << "               " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
  std::cout << b.getName() << " executed " << this->getName() << std::endl;
};