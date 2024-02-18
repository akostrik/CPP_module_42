#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <stack>
# include <queue>
# include <list>
# include <set>
# include <map>
# include <string>
# include <fstream>
# include <stdlib.h>
# include <iomanip>
# include <stdexcept>
# include <limits>
# include <algorithm>
# include <exception>
# include <cmath>

class PmergeMe {
  private:
  std::list<unsigned int>             lst;
  std::set<unsigned int>              set;
  std::map<unsigned int,unsigned int> map;
  int                                 *order;
                          PmergeMe ();

  public:
                          PmergeMe (int argc, char *argv[]);
                          PmergeMe (const PmergeMe& o);
                          ~PmergeMe();
  PmergeMe&               operator=(const PmergeMe& o);
  void                    run      (std::map<unsigned int,unsigned int> map);
  void                    run      ();
};

#endif