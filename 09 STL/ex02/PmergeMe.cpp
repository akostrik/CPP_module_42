#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
  sec_list = 0;
  sec_vect = 0;
}

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::~PmergeMe() {} 

////////////////////////////////////////////////////////// UTILS
void print(std::string comment, std::list<unsigned int> c) {
  std::cout << comment << ": ";
  for (lst_iter it = c.begin(); it != c.end(); ++it) 
    std::cout << *it << " ";
  std::cout << std::endl;
}

void print(std::string comment, std::vector<unsigned int> c) {
  std::cout << comment << ": ";
  for (vec_iter it = c.begin(); it != c.end(); ++it) 
    std::cout << *it << " ";
  std::cout << std::endl;
}

lst_iter next(lst_iter it) {
  std::advance(it, 1);
  return it;
}

vec_iter next(vec_iter it) {
  std::advance(it, 1);
  return it;
}

lst_iter middle_(lst_iter begin, lst_iter end) {
  lst_iter middle = begin; 
  std::advance(middle, (std::distance(begin, end) + 1 ) / 2);
  return middle;
}

vec_iter middle_(vec_iter begin, vec_iter end) {
  vec_iter middle = begin; 
  std::advance(middle, (std::distance(begin, end) + 1 ) / 2);
  return middle;
}

std::list<unsigned int> deep_copy_left_half(std::list<unsigned int> c1) {
  std::list<unsigned int> c2;
  lst_iter middle = middle_(c1.begin(), c1.end());
  for (lst_iter it = c1.begin(); it != middle; ++it)
    c2.push_back(*it);
  return c2;
}

std::vector<unsigned int> deep_copy_left_half(std::vector<unsigned int> c1) {
  std::vector<unsigned int> c2;
  vec_iter middle = middle_(c1.begin(), c1.end());
  for (vec_iter it = c1.begin(); it != middle; ++it) 
    c2.push_back(*it);
  return c2;
}

std::list<unsigned int> sort_elts_in_every_pair(std::list<unsigned int> c) {
  lst_iter it1 = c.begin();
  lst_iter it2 = middle_(c.begin(), c.end());
  for( ; it2 != c.end() ; ++it1, ++it2)
    if(*it1 > *it2)
      std::swap(*it1, *it2);
  return c;
}

std::vector<unsigned int> sort_elts_in_every_pair(std::vector<unsigned int> c) { ////
  vec_iter it1 = c.begin();
  vec_iter it2 = middle_(c.begin(), c.end());
  for( ; it2 != c.end() ; ++it1, ++it2)
    if(*it1 > *it2)
      std::swap(*it1, *it2);
  return c;
}

std::list<std::pair<unsigned int, unsigned int> > pairs_(std::list<unsigned int> c) {
  std::list<std::pair<unsigned int, unsigned int> > pairs;
  lst_iter it1 = c.begin();
  lst_iter it2 = middle_(c.begin(), c.end());
  for( ; it2 != c.end() ; ++it1, ++it2)
    pairs.push_back(std::pair<unsigned int, unsigned int>(*it1, *it2));
  if (c.size() % 2 == 1)
    pairs.push_back(std::pair<unsigned int, unsigned int>(*it1, 0));
  return pairs;
}

std::vector<std::pair<unsigned int, unsigned int> > pairs_(std::vector<unsigned int> c) {
  std::vector<std::pair<unsigned int, unsigned int> >  pairs ;
  vec_iter it1 = c.begin();
  vec_iter it2 = middle_(c.begin(), c.end());
  for( ; it2 != c.end() ; ++it1, ++it2)
    pairs.push_back(std::pair<unsigned int, unsigned int>(*it1, *it2));
  if (c.size() % 2 == 1)
    pairs.push_back(std::pair<unsigned int, unsigned int>(*it1, 0));
  return pairs;
}

std::list<unsigned int> right_half_(std::list<unsigned int> left_half, std::list<std::pair<unsigned int, unsigned int> > pairs) {
  std::list<unsigned int> right_half;
  for (std::list<unsigned int>::iterator it1 = left_half.begin(); it1 != left_half.end(); ++it1) {
    unsigned int wanted_first = *it1;
    unsigned int wanted_second = 0;
    for (std::list<std::pair<unsigned int, unsigned int> >::iterator it2 = pairs.begin(); it2 != pairs.end(); ++it2)
      if (it2->first == wanted_first) {
        wanted_second = it2->second;
        if (wanted_second > 0)
          right_half.push_back(wanted_second); 
        pairs.erase(it2);
        break ;
      }
  }
  return right_half;
}

std::vector<unsigned int> right_half_(std::vector<unsigned int> left_half, std::vector<std::pair<unsigned int, unsigned int> > pairs) {
  std::vector<unsigned int> right_half;
  for (std::vector<unsigned int>::iterator it1 = left_half.begin(); it1 != left_half.end(); ++it1) {
    unsigned int wanted_first  = *it1;
    unsigned int wanted_second = 0;
    for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it2 = pairs.begin(); it2 != pairs.end(); ++it2)
      if (it2->first == wanted_first) {
        wanted_second = it2->second;
        if (wanted_second > 0) 
          right_half.push_back(wanted_second); 
        pairs.erase(it2);
        break ;
      }
  }
  return right_half;
}

void reverse(std::list<unsigned int> *c, int n, int m) {
  lst_iter left   = c->begin();
  lst_iter right  = c->begin();
  std::advance(left, n);
  std::advance(right, m + 1);
  std::reverse(left, right);
}

void reverse(std::vector<unsigned int> *c, int n, int m) {
  int i = n;
  int j = m;
  for (; i < j; i++, j--)
    std::swap((*c)[i], (*c)[j]);
}

//////////////////////////////////////////////////////////////////// ALGO
void change_order(std::list<unsigned int> *c) {
  unsigned long size_group = 2;
  unsigned long beg_group  = 0;
  unsigned long end_group  = beg_group + size_group - 1;
  for (int pow2 = 4; ; pow2 *= 2) {
    if (end_group >= c->size()) {
      reverse(c, beg_group, c->size() - 1);
      break ;
    }
    reverse(c, beg_group, end_group);
    beg_group += size_group;
    end_group  = beg_group + size_group - 1;
  }
}

void change_order(std::vector<unsigned int> *c) {
  unsigned long size_group = 2;
  unsigned long beg_group  = 0;
  unsigned long end_group  = beg_group + size_group - 1;
  for (int pow2 = 4; ; pow2 *= 2) {
    if (end_group >= c->size()) {
      reverse(c, beg_group, c->size() - 1);
      break ;
    }
    reverse(c, beg_group, end_group);
    beg_group += size_group;
    size_group = pow2 - size_group;
    end_group  = beg_group + size_group - 1;
  }
}

void insert_dichotom(std::list<unsigned int> *c, unsigned int a) {
  lst_iter left   = c->begin();
  lst_iter right  = c->end();
  if (a < *(c->begin())) {
    c->push_front(a);
    return ;
  }
  while (std::distance(left, right) > 1) {
    lst_iter middle  = middle_(left, right);
    if(next(left) == c->end())
      break ;
    else if(a < *middle) 
      right = middle;
    else if(a > *middle)
      left = middle;
    else if (a == *middle) {
      c->insert(middle, a);
      return ;
    }
  }
  ++left;
  c->insert(left, a);
}

void insert_dichotom(std::vector<unsigned int> *c, unsigned int a) {
  vec_iter left   = c->begin();
  vec_iter right  = c->end();
  if (a < *(c->begin())) {
    c->insert(c->begin(), a);
    return ;
  }
  while (std::distance(left, right) > 1) {
    vec_iter middle  = middle_(left, right);
    if(next(left) == c->end())
      break ;
    else if(a < *middle) 
      right = middle;
    else if(a > *middle)
      left = middle;
    else if (a == *middle) {
      c->insert(middle, a);
      return ;
    }
  }
  ++left;
  c->insert(left, a);
}

std::list<unsigned int> run2(std::list<unsigned int> c) {
  if(c.size() <= 1)
    return c;
  if(c.size() == 2 && *(c.begin()) < *(next(c.begin())))
    return c;
  if(c.size() == 2 && *(c.begin()) >= *(next(c.begin()))) {
    std::swap(*(c.begin()), *(next(c.begin())));
    return c;
  }
  c = sort_elts_in_every_pair(c);
  std::cout << "run2 start:   ";
  for (lst_iter it = c.begin(); it != c.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
  std::list<std::pair<unsigned int, unsigned int> > pairs = pairs_(c);

  std::cout << "pairs:        ";
  for ( std::list<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    std::cout << "(" << it->first << " " << it->second << ") ";
  std::cout << std::endl;

  std::list<unsigned int> res  = deep_copy_left_half(c);
  res = run2(res);
  std::list<unsigned int> right_half = right_half_(res, pairs);

  change_order(&right_half);
  for(lst_iter it = right_half.begin(); it != right_half.end(); ++it)
    insert_dichotom(&res, *it);

  std::cout << "res2:         ";
  for (lst_iter it = res.begin(); it != res.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  return res;
}

std::list<unsigned int> PmergeMe::run(std::list<unsigned int> c) {
  clock_t start = clock();
  int nb_zeros = c.size();
  c.erase(std::remove(c.begin(), c.end(), 0), c.end());  
  nb_zeros -= c.size();

  std::list<unsigned int> res = run2(c);

  std::cout << "res:          ";
  for (lst_iter it = res.begin(); it != res.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  for (int i = 0; i < nb_zeros; i++)
    res.push_front(0);
  this->sec_list = 1000000 * (clock() - start) / CLOCKS_PER_SEC;
  return res;
}

std::vector<unsigned int> run2(std::vector<unsigned int> c) {
  if(c.size() <= 1)
    return c;
  if(c.size() == 2 && *(c.begin()) < *(next(c.begin())))
    return c;
  if(c.size() == 2 && *(c.begin()) >= *(next(c.begin()))) {
    std::swap(*(c.begin()), *(next(c.begin())));
    return c;
  }
  std::vector<std::pair<unsigned int, unsigned int> > pairs = pairs_(c);
  std::vector<unsigned int> res  = deep_copy_left_half(c);
  c = sort_elts_in_every_pair(c);
  res = run2(res);
  std::vector<unsigned int> right_half = right_half_(res, pairs);
  change_order(&right_half);
  for(vec_iter it = right_half.begin(); it != right_half.end(); ++it)
    insert_dichotom(&res, *it);
  return res;
}

std::vector<unsigned int> PmergeMe::run(std::vector<unsigned int> c) {
  clock_t start = clock();
  int nb_zeros = c.size();
  c.erase(std::remove(c.begin(), c.end(), 0), c.end());  
  nb_zeros -= c.size();
  std::vector<unsigned int> res = run2(c);
  for (int i = 0; i < nb_zeros; i++)
    res.insert(res.begin(), 0);
  this->sec_vect = 1000000 * (clock() - start) / CLOCKS_PER_SEC;
  return res;
}