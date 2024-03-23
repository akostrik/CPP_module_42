#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <queue>
# include <string>
# include <fstream>
# include <stdlib.h>
# include <iomanip>
# include <stdexcept>
# include <limits>
# include <algorithm>
# include <exception>

class RPN : std::stack<float> {
  private:
                   RPN ();

  public:
                   RPN (std::string arg);
                   RPN (const RPN& o);
                   ~RPN();
  RPN& operator=       (const RPN& o);
  void             run ();
};

#endif