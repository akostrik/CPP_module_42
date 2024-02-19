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
# include <iterator>     // std::next c+11 ?
# include <algorithm>    // std::for_each
# include <bits/stdc++.h>

typedef std::list<unsigned int>::iterator list_iterator;
typedef std::map<unsigned int,unsigned int>::iterator map_iterator;

class PmergeMe {
  private:
  std::list<unsigned int> _lst;
  int                     nb_insertions; // size()
  int                     *order;
                          PmergeMe             ();

  public:
                          PmergeMe             (int argc, char *argv[]);
                          PmergeMe             (const PmergeMe& o);
                          ~PmergeMe            ();
  PmergeMe&               operator=            (const PmergeMe& o);
  void                    calc_order_insertions(int argc);
  void                    run                  (std::list<unsigned int> lst);
  void                    run                  ();
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

// map no
// void sort_every_pair(std::map<unsigned int, unsigned int> map) {
//   for(map_iterator it = map.begin(); it != map.end();) {
//     if(it->first < it->second) {
//       map_iterator to_erase = it;
//       it++;
//       map.insert(map.begin(), std::pair<unsigned int, unsigned int>(to_erase->second, to_erase->first));
//       map.erase(to_erase);
//     } 
//     else
//       it++;
//   }