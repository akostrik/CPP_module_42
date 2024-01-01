#include "RobotomyRequestForm.hpp"

/////////////////////////////////////////////////// OCCF
RobotomyRequestForm::RobotomyRequestForm(std::string target0) : AForm("RobotomyRequestForm", 145, 137, target0) {
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
  std::ofstream out;

  if (this->getIsSigned() == false) {
    std::cout << b.getName() << "          couldn’t execute " << this->getName() << " because ";
    throw AForm::NotSignedException();
  }
  if (b.getGrade() > this->getGradeToExecute()) {
    std::cout << b.getName() << "          couldn’t execute " << this->getName() << " because ";
    throw AForm::GradeTooLowException();
  }
  out.open((this->target + "_shrubbery").c_str());
  out << 
  "            # #### ####\n"
  "        ### \\/#|### |/####\n"
  "        ##\\/#/ \\||/##/_/##/_#\n"
  "       ###  \\/###|/ \\/ # ###\n"
  "    ##_\\_#\\_\\## | #/###_/_####\n"
  "    ## #### # \\ #| /  #### ##/##\n"
  "      __#_--###`  ||,###---###-~\n"
  "                 ||\n"
  "                 ||\n"
  "                 ||\n";
  out.close();
  std::cout << b.getName() << " executed " << this->getName() << std::endl;
};