#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>

// all virtual methods that are not pure should be defined
// a destructor must be defined even if it is declared pure-virtual
class Animal {
protected:
  std::string  _type;

public: 
               Animal     ();
               Animal     (const Animal &obj);
               ~Animal    ();
  Animal&      operator = (const Animal &obj);

  std::string  getType    (void) const;
  virtual void makeSound  ()     const;
};

#endif
