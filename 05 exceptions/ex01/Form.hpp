#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

private:
  std::string name;
  bool        isSigned;
  int         gradeToSign;
  int         gradeToExecute;

public:
              AForm             (std::string name0, int gradeToSign0, int gradeToExecute0);
              AForm             (const AForm &obj);
              ~AForm            ();
  AForm       &operator =       (const AForm &obj);

  std::string getName           () const;
  bool        getIsSigned       () const;
  int         getGradeToSign    () const;
  int         getGradeToExecute () const;

  void        beSigned          (const Bureaucrat &obj);

  class GradeTooHighException : public std::exception {
    public:
      const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
    public:
      const char *what() const throw();
  };
};

std::ostream &operator <<(std::ostream &out, const AForm &obj);

#endif
