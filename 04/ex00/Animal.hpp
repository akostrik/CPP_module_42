#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>

class Animal {
private:
  std::string protected type;

public: 
               Animal     ();
               Animal     (std::string name);
               Animal     (const Animal &obj);
               ~Animal    ();
  Animal&      operator = (const Animal &obj);

  std::string  getType    (void) const;
  virtual void makeSound  ();
};

#endif
