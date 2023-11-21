
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>
# include <cctype>
# include <cstring>
# include <iomanip>
# include "ScavTrap.hpp"

// inherits the constructors and destructor from ScavTrap
class FragTrap : public ClapTrap {
public: 
               FragTrap   ();
               FragTrap   (std::string name);
               FragTrap   (const FragTrap &obj);
               ~FragTrap  ();

  void         highFivesGuys(void);
};

#endif