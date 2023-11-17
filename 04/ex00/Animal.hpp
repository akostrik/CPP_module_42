#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>

class Animal {
protected:
  std::string  _type;

public: 
               Animal     ();
               Animal     (const Animal &obj);
  virtual      ~Animal    ();                    // virtual too ! (PB non-final 'Animal' has virtual functions but non-virtual destructor)
  Animal&      operator = (const Animal &obj);

  std::string  getType    (void) const;
  virtual void makeSound  ()     const;          // virtual!
};

#endif
