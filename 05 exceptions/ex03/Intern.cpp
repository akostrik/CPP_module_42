#include "Intern.hpp"

/////////////////////////////////////////////////// OCCF and <<
Intern::Intern() {
};

Intern::Intern(const Intern &obj) {
  *this = obj;
};

Intern::~Intern() {
};

Intern& Intern::operator = (Intern const &obj) {
  for (int i = 0; i < 3; i++)
    this->data[i].form = obj.data[i].form;
  return *this;
};

std::ostream & operator <<(std::ostream &out, const Intern &obj) {
  out << "intern";
  (void)obj;
  return (out);
}

/////////////////////////////////////////////////// MEMBER FUNCTIONS
AForm *Intern::makeForm (std::string formName, std::string target) {
  AForm *toReturn;

  this->data[0].type = "presidential pardon";
  this->data[0].form = new PresidentialPardonForm(target);
  this->data[1].type = "robotomy request";
  this->data[1].form = new RobotomyRequestForm(target);
  this->data[2].type = "shrubbery creation";
  this->data[2].form = new ShrubberyCreationForm(target);
  toReturn = NULL;
  for (int i = 0; i < 3; i++)
    if (this->data[i].type.compare(formName) == 0)
      toReturn = this->data[i].form;
    else
      delete data[i].form;
  if (toReturn != NULL) {
    std::cout << "Intern creates " << formName << std::endl;
    return toReturn;
	}
  std::cout << "Intern cann't find the form " << formName << std::endl;
  throw Intern::FormNameDoesntExistException();
}

/////////////////////////////////////////////////// EXCEPTIONS
const char *Intern::FormNameDoesntExistException::what() const throw() {
  return "Intern: FormNameDoesntExistException";
}
