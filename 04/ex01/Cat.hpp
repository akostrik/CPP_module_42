#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
private:
  Brain*        _brain;
public: 
                Cat();
                ~Cat();
  Cat&          operator = (const Cat &obj);
  Brain*        getBrain   () const;
  void          makeSound  () const;
};

std::ostream&   operator<<(std::ostream& os, Cat const &obj); // overload insertion operator <<

#endif