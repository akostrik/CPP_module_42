#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

private:
  Brain *brain;
	
public: 
        Cat         ();
        ~Cat        ();
        Cat         (Cat const &ref);
  Cat   &operator = (Cat const &ref);

  Brain *getBrain   () const;
  void  makeSound   () const;
};

#endif