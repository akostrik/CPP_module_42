#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <exception>
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public  AForm{

public:
                         PresidentialPardonForm  (std::string target);                // obligatory
                         PresidentialPardonForm  (const PresidentialPardonForm &obj); // obligatory
                         ~PresidentialPardonForm ();                                  // obligatory
  PresidentialPardonForm  &operator =            (const PresidentialPardonForm &obj); // obligatory

  void                   execute                 (Bureaucrat const &b) const;         // pure virtual func of the parent, should be defined here
};

#endif
