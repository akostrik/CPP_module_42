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

typedef std::list<unsigned int>::iterator             list_iterator;
typedef std::map<unsigned int,unsigned int>::iterator map_iterator;
typedef std::vector<unsigned int>::iterator           vector_iterator;

class PmergeMe {
  private:
  std::list<unsigned int> _lst;
  int                     *_order;
                          PmergeMe             ();

  public:
                          PmergeMe             (int argc, char *argv[]);
                          PmergeMe             (const PmergeMe& o);
                          ~PmergeMe            ();
  PmergeMe&               operator=            (const PmergeMe& o);
  void                    calc_order_insertions(int argc);
  unsigned int*           put_map_values_to_array_in_order(std::map<unsigned int, unsigned int> map);
  void                    run                  (std::list<unsigned int> *lst); // * ?
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
