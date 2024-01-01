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
  if (this->getIsSigned() == false)
    throw ShrubberyCreationForm::NotSignedException();
  if (b.getGrade() > this->getGradeToSign()) {
    std::cout << b.getName() << " couldn’t execute " << this->getName() << " because of: ";
    throw ShrubberyCreationForm::GradeTooLowException();
  }
  try {
    std::string filename = this->target + "_shrubbery";
    std::ofstream out;               // объект создан, но не связан с файлом
    out.open(filename.c_str());          // связываем объект с файлом

    out << 
    "            # #### ####\n"
    "        ### \\/#|### |/####\n"
    "        ##\\/#/ \\||/##/_/##/_#\n"
    "       ###  \\/###|/ \\/ # ###\n"
    "    ##_\\_#\\_\\## | #/###_/_####\n"
    "    ## #### # \\ #| /  #### ##/##\n"
    "    __#_--###`  ||,###---###-~\n"
    "                ||\n"
    "                ||\n"
    "                ||\n";
    out.close();                      // закрываем файл = отделить объект от файла
  }
  catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  // throw ShrubberyCreationForm::ShrubberyException("File is not open"); ?
};