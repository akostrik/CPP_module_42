#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>

# define NB_IDEAS 3 ///// 100

class Brain {

private:
  std::string  *ideas;

public: 
               Brain       ();
               ~Brain      ();
               Brain       (Brain const &ref);
  Brain        &operator = (Brain const &ref);

  std::string  *getIdeas   ();
};

#endif