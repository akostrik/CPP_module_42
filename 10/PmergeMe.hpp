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

class PmergeMe : public std::list<unsigned int> {
  private:
  int                     *_order;
                          PmergeMe             ();

  public:

                          PmergeMe             (int argc, char *argv[]);
                          PmergeMe             (const PmergeMe& o);
                          ~PmergeMe            ();
  PmergeMe&               operator=            (const PmergeMe& o);
  void                    calc_order_insertions(int argc);
  void                    run                  ();
  void                    run                  (list_iterator begin, list_iterator end);
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
