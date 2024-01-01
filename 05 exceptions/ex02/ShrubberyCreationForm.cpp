#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

/////////////////////////////////////////////////// OCCF
ShrubberyCreationForm::ShrubberyCreationForm(std::string target0) : AForm("ShrubberyCreationForm", 145, 137, target0) {
};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj) :  AForm(obj) { 
  *this = obj;
};

ShrubberyCreationForm::~ShrubberyCreationForm() { // not obligatory ?
};

// если тут копирование всех нестатических членов-данных, добавленных в Child, то оператор присваивания можно не определять, компилятор сам его добавит неявно
ShrubberyCreationForm& ShrubberyCreationForm::operator = (ShrubberyCreationForm const &obj) { // not obligatory ?
  this->name = obj.getName();
  this->gradeToSign = obj.getGradeToSign();
  this->gradeToExecute = obj.getGradeToExecute();
  return *this;
};

/////////////////////////////////////////////////// MEMBER FUNCTIONS
void ShrubberyCreationForm::execute(Bureaucrat const &b) const {
  std::ofstream out;

  if (this->getIsSigned() == false) {
    std::cout << b.getName() << "          1 couldn’t execute " << this->getName() << " because ";
    throw AForm::NotSignedException();
  }
  if (b.getGrade() > this->getGradeToExecute()) {
    std::cout << b.getName() << "          2 couldn’t execute " << this->getName() << " because ";
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