#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <exception>
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public  AForm{

public:
                         ShrubberyCreationForm  (std::string target);               // obligatory
                         ShrubberyCreationForm  (const ShrubberyCreationForm &obj); // obligatory
                         ~ShrubberyCreationForm ();                                 // obligatory
  ShrubberyCreationForm  &operator =            (const ShrubberyCreationForm &obj); // obligatory

  void                   execute                (Bureaucrat const &obj) const;      // pure virtual func of the parent, should be defined here
};

#endif
