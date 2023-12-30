#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat; // ?

class Form {

private:
  std::string  name;
  bool         isSigned;
  int          gradeToSign;
  int          gradeToExecute;

public:
               Form              (std::string name0, int gradeToSign0, int gradeToExecute0);
               Form              (const Form &obj);
               ~Form             ();
  Form&        operator =        (const Form &obj);

  std::string  getName           () const;
  bool         getIsSigned       () const;
  int          getGradeToSign    () const;
  int          getGradeToExecute () const;

  void         beSigned          (Bureaucrat &b);

  class GradeTooHighException : public std::exception {
    public:
      const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
    public:
      const char *what() const throw();
  };
};

std::ostream &operator <<(std::ostream &out, const Form &f);

#endif
