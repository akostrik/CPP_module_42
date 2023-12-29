#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name0, int grade0) {
  if (grade0 < 1)
    throw Bureaucrat::GradeTooHighException("Grade too high");
  if (grade0 > 150)
    throw Bureaucrat::GradeTooHighException("Grade too low");
  this->name  = name0;
  this->grade = grade0;
  std::cout << "Bureaucrat constructor, name = " << this->name << ", grade = " << this->grade << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &obj) {
  *this = obj;
  std::cout << "Bureaucrat copy constructor, name = " << this->name << ", grade = " << this->grade << std::endl;
};

Bureaucrat& Bureaucrat::operator = (Bureaucrat const &obj) {
  this->name = obj.getName();
  this->grade = obj.getGrade();
  std::cout << "Bureaucrat assignment operator, name = " << this->name << ", grade = " << this->grade << std::endl;
  return *this;
};

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat destructor, name = " << this->name << ", grade = " << this->grade << std::endl;
};


///////////////////////////////////////////////////
std::string& Bureaucrat::getName() const {
  return this->name;
};

int Bureaucrat::getGrade() const {
  return this->grade;
};

void Bureaucrat::incGrade() {
  if (this->grade <= 1)
    throw Bureaucrat::GradeTooHighException("incGrade: grade too high");
  this->grade--;
}

void Bureaucrat::decGrade() {
  if (this->grade >= 150)
    throw Bureaucrat::GradeTooLowException("decGrade: grade too low");
  this->grade++;
}

std::ostream & operator <<(std::ostream &out, const Bureaucrat &obj)
{
  out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
  return (out);
}

///////////////////////////////////////////////////
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &msg) // construtor
{
  std::cout << "GradeTooHighException constructor call\n";
  this->_ErrorMsg = msg;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &msg)
{
  std::cout << "GradeTooLowException constructor call\n";
  this->_ErrorMsg = msg;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() // canonical form ?
{
  std::cout << "GradeTooHighException destructor\n";
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
  std::cout << "GradeTooLowException destructor call\n";
}

// const char *Bureaucrat::GradeTooHighException::what(void) const throw() // Overload basic method
// {

//   if (!this->_ErrorMsg.empty())
//     return ("GradeTooHighException" + this->_ErrorMsg).c_str();
//   else
//     return ("GradeTooHighException: unknown error").c_str();
// }

// const char *Bureaucrat::GradeTooLowException::what(void) const throw()
// {
//   std::string tmp;

//   if (!this->_ErrorMsg.empty())
//     tmp = "GradeTooLowException" + this->_ErrorMsg;
//   else
//     tmp = "GradeTooLowException: unknown error";
//   return (tmp.c_str());
// }
