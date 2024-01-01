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
  Bureaucrat   &operator = (const Bureaucrat &obj);

  std::string  getName     () const;
  int          getGrade    () const;

  void         incrGrade   ();
  void         decrGrade   ();

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
