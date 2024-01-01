#ifndef ROBOTOMYREQUEST_HPP
# define ROBOTOMYREQUEST_HPP

# include <string>
# include <exception>
# include <iostream>
# include <fstream>
# include <ctime>
# include <cstdlib>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public  AForm{

public:
                       RobotomyRequestForm  (std::string target);             // obligatory
                       RobotomyRequestForm  (const RobotomyRequestForm &obj); // obligatory
                       ~RobotomyRequestForm ();                               // obligatory
  RobotomyRequestForm  &operator =          (const RobotomyRequestForm &obj); // obligatory

  void                 execute              (Bureaucrat const &b) const;      // pure virtual func of the parent, should be defined here
};

#endif
