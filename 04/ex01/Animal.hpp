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
  std::string   type;

public: 
                      Animal     ();
  virtual             ~Animal    (); 
                      Animal     (Animal const &ref); // constructor cannot be virtual
  virtual Animal      &operator = (Animal const &ref); // virtual ?

  virtual std::string getType    () const;
  virtual void        makeSound  () const;
  //virtual Brain*      getBrain   () const;
};

#endif

// what will happen if non virtual ~Animal? Only ~Animal() is called, never ~Cat()
// non-final class with virtual functions should have virtual destructor
// Virtual destructor lets delete an instance of a child class through a pointer to parent class
