#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
# include <iostream>

class ICharacter;

class AMateria {
protected:
  std::string         type;

public:
                      AMateria();
  virtual             ~AMateria();
                      AMateria(std::string const & type);
                      AMateria(AMateria const & src);

  std::string const & getType() const;
  virtual AMateria*   clone()   const = 0;      // AMateria class is abstract (clone() is a pure function)
  virtual void        use(ICharacter& target);
};

#endif
