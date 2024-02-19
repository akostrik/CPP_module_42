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
# include <exception>
# include <cmath>
# include <iterator>     // std::next
# include <algorithm>    // std::for_each

typedef std::map<unsigned int, unsigned int>::iterator map_iterator;
class PmergeMe {
  private:
  //std::set<elt_t>              set;
  std::map<unsigned int, unsigned int> map;
  int                                 *order;
                          PmergeMe ();

  public:
                          PmergeMe (int argc, char *argv[]);
                          PmergeMe (const PmergeMe& o);
                          ~PmergeMe();
  PmergeMe&               operator=(const PmergeMe& o);
  void                    run      (std::map<unsigned int, unsigned int> map);
  void                    run      ();
};

#endif

// list is not adapted for binary search
// for(int i = 1; argv[i] != NULL; i++) {
//   elt_t elt;
//   elt.v = std::strtoul(argv[i], NULL, 10);
//   elt.pair = NULL;
//   if (i % 2 == 0)
//     elt.pair = &(lst.back());
//   lst.push_back(elt);
// }
// void delete_every_second(std::list<elt_t> *lst) {
//   size_t size = lst->size();
//   std::list<elt_t>::iterator it = lst->begin();
//   while(size--) {
//     std::list<elt_t>::iterator toErase = it;
//     it++;
//     if (size%2 == 1)
//       lst->erase(toErase);
//   }
// }
// typedef struct elt_s{
//   unsigned int v;
//   elt_s        *pair;
// } elt_t;
