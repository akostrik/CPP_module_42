
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>
# include <cctype>
# include <cstring>
# include <iomanip>
# include "ClapTrap.hpp"

// inherits the constructors and destructor from Clap-Trap
class ScavTrap : public ClapTrap {
public: 
               ScavTrap   ();
               ScavTrap   (std::string name);
               ScavTrap   (const ScavTrap &obj);
               ~ScavTrap  ();

  void         attack     (const std::string& target);
  void         guardGate  ();
};

#endif