#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <exception>
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public  AForm{

public:
                         ShrubberyCreationForm  (std::string target);
                         ShrubberyCreationForm  (const ShrubberyCreationForm &obj);
                         ~ShrubberyCreationForm ();
  ShrubberyCreationForm  &operator =            (const ShrubberyCreationForm &obj);

  void                   execute                (Bureaucrat const &b) const; // pure virtual func of the parent, should be defined here

  class ShrubberyException: public std::exception { // no needed ?
    public:
      const char * what() const throw();
  };
};

#endif
