#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>

class WrongAnimal {
protected:
  std::string  type;

public: 
               WrongAnimal ();
  virtual      ~WrongAnimal();           // THE DIFFERENCE WITH ANIMAL : virtual removed
               WrongAnimal (const WrongAnimal &ref);
  WrongAnimal& operator =  (const WrongAnimal &ref);

  std::string  getType     () const;
  // WrongCat should output the WrongAnimal sound
  // The WrongCat must output the WrongCat makeSound() only when used as a wrongCat
  void makeSound   () const;     // THE DIFFERENCE WITH ANIMAL : virtual removed
};

#endif
