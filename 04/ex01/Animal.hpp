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
                      Animal      ();
  virtual             ~Animal     (); 
                      Animal      (Animal const &ref);
  virtual Animal      &operator = (Animal const &ref);

  virtual std::string getType     ()                  const;
  void                setType     (std::string);
  virtual void        makeSound   ()                  const;
};

#endif

// what will happen if non virtual ~Animal? Only ~Animal() is called, never ~Cat()
// non-final class with virtual functions should have virtual destructor
// Virtual destructor lets delete an instance of a child class through a pointer to parent class
