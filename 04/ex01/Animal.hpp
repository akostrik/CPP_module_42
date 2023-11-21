#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>
# include "Brain.hpp"

class Animal {
protected:
  std::string   _type;

public: 
                  Animal     ();
                  Animal     (const Animal &obj);
  virtual         ~Animal    (); // what will happen without Virtual? Test it
                                 // non-final class with virtual functions should have virtual destructor
                                 // without Virtual Animal::~Animal() is called in any case, and never func Cat::~Animal()
  virtual Animal& operator = (const Animal &obj);
  std::string     getType    (void) const;
  virtual Brain*  getBrain   (void);
  virtual void    makeSound  (void) const;          // virtual
};

#endif
