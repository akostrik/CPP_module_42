
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrav {
private:
  std::string name;
  unsigned int hitPoints;    // the health
  unsigned int energyPoints; // can’t do anything if it has no hit points or energy points
  unsigned int attackDamage;

public: 
  // inherit the constructors and destructor from Clap-Trap
               ClapTrap   ();
               ClapTrap   (std::string name);
               ClapTrap   (const ClapTrap &obj);
               ~ClapTrap  ();
  ClapTrap&    operator = (const ClapTrap &obj);

  void         attack     (const std::string& target); // causes its target to lose <attack damage> hit points, costs 1 energyPoint
  void         takeDamage (unsigned int amount);
  void         beRepaired (unsigned int amount);       // gets <amount> hit points back, costs 1 energyPoint
};


#endif