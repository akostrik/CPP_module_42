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
# include <iterator>     // std::next c+11 ?s
# include <algorithm>    // std::for_each
# include <bits/stdc++.h>

typedef std::list<unsigned int>::iterator      lst_iter;
typedef std::set<unsigned int>::iterator       set_iter;

class PmergeMe  {
  private:

  public:
                          PmergeMe             ();
                          PmergeMe             (const PmergeMe& o);
                          ~PmergeMe            ();
  PmergeMe&               operator=            (const PmergeMe& o);
  std::list<unsigned int> run                  (std::list<unsigned int> l);
  std::set<unsigned int>  run                  (std::set<unsigned int> s);
};

#endif
