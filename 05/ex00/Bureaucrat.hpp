#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <iostream>

class Bureaucrat {

private:
  std::string  name;
  int          grade;

public:
               Bureaucrat  (std::string name0, int grade0);
               Bureaucrat  (const Bureaucrat &obj);
               ~Bureaucrat ();
  Bureaucrat&  operator =  (const Bureaucrat &obj);

  std::string  &getName    () const; // !!! &
  int          getGrade    () const;
  void         incGrade    ();
  void         decGrade    ();

  class GradeTooHighException: public std::exception
  // exception classes don’t have to be designed in Orthodox Canonical Form
  {
    private:
      std::string _ErrorMsg;
    public:
      GradeTooHighException(const std::string &error); // (const char * error);
      ~GradeTooHighException() throw();
      const char *what() const throw();
  };

  class GradeTooLowException : public std::exception
  {
    private:
      std::string _ErrorMsg;
    public:
      GradeTooLowException(const std::string &error);
      ~GradeTooLowException() throw();
      const char *what() const throw();
  };
};

std::ostream & operator <<(std::ostream &out, const Bureaucrat &b);

#endif
