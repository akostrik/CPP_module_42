#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

// abstract class
// contains at least one pure virtual function
// the virtual function should be defined in the child class

class Bureaucrat;

class AForm {

protected:
  std::string  name;
  bool         isSigned;
  int          gradeToSign;
  int          gradeToExecute;
  std::string  target;

public:
               AForm             (std::string name0, int gradeToSign0, int gradeToExecute0, std::string target);
               AForm             (AForm const &obj);
               ~AForm            ();
  AForm&       operator =        (AForm const &obj);

  std::string  getName           () const;
  bool         getIsSigned       () const;
  int          getGradeToSign    () const;
  int          getGradeToExecute () const;
  std::string  getTarget         () const;

  void         beSigned          (Bureaucrat &b);
  virtual void execute           (Bureaucrat const &b) const = 0; // pure virtual function // NEW

  class GradeTooHighException : public std::exception {
    public:
      const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
    public:
      const char *what() const throw();
  };

  class NotSignedException : public std::exception {
    public:
      const char *what() const throw();
  };
};

std::ostream &operator <<(std::ostream &out, AForm const &f);

#endif
