#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>

class ClapTrap {
private:
  int              raw;
  static int const n = 8;

public: 
                   ClapTrap();
                   ClapTrap(std::string name);
                   ClapTrap(const ClapTrap &obj);
                   ~ClapTrap();
  ClapTrap&        operator = (const ClapTrap &obj);

};

#endif
