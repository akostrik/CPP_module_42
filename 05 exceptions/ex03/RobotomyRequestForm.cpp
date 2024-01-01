#include "RobotomyRequestForm.hpp"

/////////////////////////////////////////////////// OCCF
RobotomyRequestForm::RobotomyRequestForm(std::string target0) : AForm("RobotomyRequestForm", 25, 5, target0) {
};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj) : AForm(obj) {
  *this = obj;
};

RobotomyRequestForm::~RobotomyRequestForm() {
};

RobotomyRequestForm& RobotomyRequestForm::operator = (RobotomyRequestForm const &obj) {
  this->name = obj.getName();
  this->gradeToSign = obj.getGradeToSign();
  this->gradeToExecute = obj.getGradeToExecute();
  return *this;
};

/////////////////////////////////////////////////// MEMBER FUNCTIONS
void RobotomyRequestForm::execute(Bureaucrat const &b) const {
  if (this->getIsSigned() == false) {
    std::cout << b.getName() << "          couldn’t execute " << this->getName() << " because ";
    throw AForm::NotSignedException();
  }
  if (b.getGrade() > this->getGradeToExecute()) {
    std::cout << b.getName() << "          couldn’t execute " << this->getName() << " because ";
    throw AForm::GradeTooLowException();
  }
  if (rand() & 1)
    std::cout << "               BZZZZZZZZZZ..." << getTarget() << " has been robotomized successfully !" << std::endl;
  else
    std::cout << "The " << getTarget() << "robotomization failed !" << std::endl;
  std::cout << b.getName() << " executed " << this->getName() << std::endl;
};