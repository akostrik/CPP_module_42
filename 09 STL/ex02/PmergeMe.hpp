#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <stack>
# include <queue>
# include <list>
# include <string>
# include <fstream>
# include <stdlib.h>
# include <iomanip>
# include <stdexcept>
# include <limits>
# include <algorithm>
# include <exception>

class PmergeMe {
  private:
                          PmergeMe ();
  std::list<unsigned int> l;

  public:
                          PmergeMe (char *argv[]);
                          PmergeMe (const PmergeMe& o);
                          ~PmergeMe();
  PmergeMe&               operator=(const PmergeMe& o);
  void                    run      ();
};

#endif