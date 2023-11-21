#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
private:
  Brain* brain;
public: 
         Cat();
         ~Cat();
  Cat&   operator = (const Cat &obj);
  Brain* getBrain();
  void   makeSound() const;
};

#endif
