#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>
# include "Brain.hpp"

class Animal {

protected:                                                       // NEW, Animal should not be instantiable
  std::string   type;

                      Animal      ();
  virtual             ~Animal     (); 
                      Animal      (Animal const &ref);
  virtual Animal      &operator = (Animal const &ref);

public: 
  virtual std::string getType     ()                  const;
  virtual void        makeSound   ()                  const = 0; // NEW pure virtual, Animal should not be instantiable
};

#endif