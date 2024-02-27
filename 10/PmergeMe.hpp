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
  std::map<unsigned int, unsigned int> move_right;
                          PmergeMe             ();

  public:
                          PmergeMe             (int argc, char *argv[]);
                          PmergeMe             (const PmergeMe& o);
                          ~PmergeMe            ();
  PmergeMe&               operator=            (const PmergeMe& o);
  void                    run                  ();
  void                    run                  (list_iterator begin, list_iterator end);
  void                    my_advance           (list_iterator *it, list_iterator begin, list_iterator end);
  list_iterator           insert_before_       (list_iterator begin, list_iterator end, unsigned int a);
};

#endif

// void PmergeMe::calc_order_insertions(int N) {
//   int nb_insertions = N / 2;
//   _order = new int[nb_insertions];
//   int size_group = 0;
//   int k = 1;
//   int i = 0;
//   for(; i < nb_insertions;) {
//     size_group = pow(2, k++) - size_group;                                // 0 1  2
//     int where_to_stop = std::min(i + size_group - 1, nb_insertions - 1);
//     for(int v = where_to_stop; i <= where_to_stop; v--, i++)
//       _order[i] = v;
//   }
// }

// list is not adapted for binary search
// for(int i = 1; argv[i] != NULL; i++) {
//   elt_t elt;
//   elt.v = std::strtoul(argv[i], NULL, 10);
//   elt.pair = NULL;
//   if (i % 2 == 0)
//     elt.pair = &(lst.back());
//   lst.push_back(elt);
// }
