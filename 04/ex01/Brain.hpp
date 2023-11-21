#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>

# define NB_IDEAS 2 ///// 100

class Brain {
private:
  std::string *ideas; ///
public: 
               Brain     ();
               Brain     (const Brain &obj);
               ~Brain    ();
  Brain&       operator = (const Brain &obj);
  std::string  *getIdeas() const;
};

std::ostream& operator<<(std::ostream& os, Brain const &obj);

#endif
