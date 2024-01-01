#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <exception>
# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

typedef struct s_form {
  std::string type;
  AForm       *form;
} t_form;

class AForm;

class Intern {

private:
  t_form data[3];

public:
         Intern      ();
         Intern      (const Intern &obj);
         ~Intern     ();
  Intern &operator = (const Intern &obj);

  AForm  *makeForm   (std::string formName, std::string target); // NEW

  class FormNameDoesntExistException : public std::exception {
    public:
      const char *what() const throw();
  };
};

std::ostream & operator <<(std::ostream &out, const Intern &obj);

#endif
