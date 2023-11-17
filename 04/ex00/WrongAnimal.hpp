#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>

class WrongAnimal {
protected:
  std::string  _type;

public: 
               WrongAnimal ();
               WrongAnimal (const WrongAnimal &obj);
               ~WrongAnimal(); // THE ONLY DIFFERENCE WITH ANIMAL : 2 words virtual removed
  WrongAnimal& operator =  (const WrongAnimal &obj);

  std::string  getType     (void) const;
  void         makeSound   ()     const; // THE ONLY DIFFERENCE WITH ANIMAL : 2 words virtual removed
};

#endif
