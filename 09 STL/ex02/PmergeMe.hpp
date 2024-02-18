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

typedef struct elt_s{
  unsigned int v;
  elt_s        *pair;
} elt_t;

class PmergeMe {
  private:
  std::list<elt_t>             lst;
  //std::set<elt_t>              set;
  //std::map<unsigned int,unsigned int> map;
  int                                 *order;
                          PmergeMe ();

  public:
                          PmergeMe (int argc, char *argv[]);
                          PmergeMe (const PmergeMe& o);
                          ~PmergeMe();
  PmergeMe&               operator=(const PmergeMe& o);
  void                    run      (std::list<elt_t> lst);
  void                    run      ();
};

#endif

    // if(i % 2 == 0 && argv[i + 1] != NULL)
    //   map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i], NULL, 10), std::strtoul(argv[i + 1], NULL, 10)));
    // else if (i % 2 == 0 && argv[i + 1] == NULL)
    //   map.insert(std::pair<unsigned int, unsigned int>(std::strtoul(argv[i], NULL, 10), std::strtoul(argv[i], NULL, 10)));
