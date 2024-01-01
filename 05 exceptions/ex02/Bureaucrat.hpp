#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat {

private:
  std::string  name;
  int          grade;

public:
               Bureaucrat  (std::string name0, int grade0);
               Bureaucrat  (const Bureaucrat &obj);
               ~Bureaucrat ();
  Bureaucrat   &operator =  (const Bureaucrat &obj);

  std::string  getName     () const;
  int          getGrade    () const;
  void         incrGrade   ();
  void         decrGrade   ();
  void         signForm    (AForm *f);
  void         executeForm (AForm const &f);                     // Form, not AForm //NEW

  class GradeTooHighException : public std::exception {
    public:
      const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
    public:
      const char *what() const throw();
  };
};

std::ostream & operator <<(std::ostream &out, const Bureaucrat &obj);

#endif
