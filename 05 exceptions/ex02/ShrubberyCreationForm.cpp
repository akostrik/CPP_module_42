#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

/////////////////////////////////////////////////// OCCF
ShrubberyCreationForm::ShrubberyCreationForm(std::string target0) : AForm("ShrubberyCreationForm", 145, 137, target0) {
  this->isSigned       = false;
};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj) :  AForm(obj) { 
  *this = obj;
};

ShrubberyCreationForm::~ShrubberyCreationForm() { // not obligatory ?
};

// если тут копирование всех нестатических членов-данных, добавленных в Child, то оператор присваивания можно не определять, компилятор сам его добавит неявно
ShrubberyCreationForm& ShrubberyCreationForm::operator = (ShrubberyCreationForm const &obj) {
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
  std::ofstream f;               // объект создан, но не связан с файлом
  f.open("_shrubbery");          // связываем объект с файлом
  f << "Работа с файлами в С++"; // запись строки в файл
  f.close();                     // закрываем файл = тделить объект от файла
}