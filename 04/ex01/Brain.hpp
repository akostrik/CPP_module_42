#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>

class Brain {
private:
  std::string ideas[100];
public: 
               Brain     ();
               Brain     (const Brain &obj);
               ~Brain    ();
  Brain&       operator = (const Brain &obj);
  std::string* getIdeas();
};

#endif
