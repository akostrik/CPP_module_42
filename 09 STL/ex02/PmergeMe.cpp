#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
  sec_list = 0;
  sec_vect = 0;
}

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::~PmergeMe() {} 

////////////////////////////////////////////////////////// UTILS
void print_vect(std::string comment, std::vector<unsigned int> v) {
  std::cout << comment << ": ";
  for (vec_iter it = v.begin(); it != v.end(); ++it) 
    std::cout << *it << " ";
  std::cout << std::endl;
}

int nb_zeros_(std::list<unsigned int> l) {
  int nb_zeros = 0;
  for (lst_iter it = l.begin(); it != l.end(); ++it) 
    if (*it == 0)
      nb_zeros++;
  return nb_zeros;
}

int nb_zeros_(std::vector<unsigned int> v) {
  int nb_zeros = 0;
  for (vec_iter it = v.begin(); it != v.end(); ++it) 
    if (*it == 0)
      nb_zeros++;
  return nb_zeros;
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

std::list<unsigned int> deep_copy_left_half(std::list<unsigned int> l1) {
  std::list<unsigned int> l2;
  lst_iter middle = middle_(l1.begin(), l1.end());
  for (lst_iter it = l1.begin(); it != middle; ++it)
    l2.push_back(*it);
  return l2;
}

std::vector<unsigned int> deep_copy_left_half(std::vector<unsigned int> v1) {
  std::vector<unsigned int> v2;
  vec_iter middle = middle_(v1.begin(), v1.end());
  for (vec_iter it = v1.begin(); it != middle; ++it) 
    v2.push_back(*it);
  return v2;
}

std::list<std::pair<unsigned int, unsigned int> > pairs_(std::list<unsigned int> l) {
  std::list<std::pair<unsigned int, unsigned int> > pairs;
  lst_iter it1 = l.begin();
  lst_iter it2 = middle_(l.begin(), l.end());
  for( ; it2 != l.end() ; ++it1, ++it2)
    if(*it1 < *it2) 
      pairs.push_back(std::pair<unsigned int, unsigned int>(*it1, *it2));
    else
      pairs.push_back(std::pair<unsigned int, unsigned int>(*it1, *it2));
  if (l.size() % 2 == 1)
    pairs.push_back(std::pair<unsigned int, unsigned int>(*it1, 0));
  return pairs;
}

std::vector<std::pair<unsigned int, unsigned int> > pairs_(std::vector<unsigned int> v) {
  std::vector<std::pair<unsigned int, unsigned int> >  pairs ;
  vec_iter it1 = v.begin();
  vec_iter it2 = middle_(v.begin(), v.end());
  for( ; it2 != v.end() ; ++it1, ++it2)
    if(*it1 < *it2) 
      pairs.push_back(std::pair<unsigned int, unsigned int>(*it1, *it2));
    else
      pairs.push_back(std::pair<unsigned int, unsigned int>(*it1, *it2));
  if (v.size() % 2 == 1)
    pairs.push_back(std::pair<unsigned int, unsigned int>(*it1, 0));
  return pairs;
}

std::list<unsigned int> right_half_(std::list<unsigned int> left_half, std::list<std::pair<unsigned int, unsigned int> > pairs) {
  std::list<unsigned int> right_half;
  for (std::list<unsigned int>::iterator it1 = left_half.begin(); it1 != left_half.end(); ++it1) {
    unsigned int wanted_first = *it1;
    unsigned int wanted_second;
    for (std::list<std::pair<unsigned int, unsigned int> >::iterator it2 = pairs.begin(); it2 != pairs.end(); ++it2)
      if (it2->first == wanted_first)
        wanted_second = it2->second;
    if (wanted_second > 0)
      right_half.push_back(wanted_second); 
  }
  return right_half;
}

std::vector<unsigned int> right_half_(std::vector<unsigned int> left_half, std::vector<std::pair<unsigned int, unsigned int> > pairs) {
  std::vector<unsigned int> right_half;
  for (std::vector<unsigned int>::iterator it1 = left_half.begin(); it1 != left_half.end(); ++it1) {
    unsigned int wanted_first  = *it1;
    for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it2 = pairs.begin(); it2 != pairs.end(); ++it2) {
      if (it2->first == wanted_first) {
        unsigned int wanted_second = it2->second;
        if (wanted_second > 0) {
          right_half.push_back(wanted_second); 
          pairs.erase(it2);
          break ;
        }
      }
    }
  }
  return right_half;
}

void reverse(std::list<unsigned int> *l, int n, int m) {
  lst_iter left   = l->begin();
  lst_iter right  = l->begin();
  std::advance(left, n);
  std::advance(right, m + 1);
  std::reverse(left, right);
}

void reverse(std::vector<unsigned int> *v, int n, int m) {
  int i = n;
  int j = m;
  for (; i < j; i++, j--)
    std::swap((*v)[i], (*v)[j]);
}

//////////////////////////////////////////////////////////////////// ALGO
void change_order(std::list<unsigned int> *l) {
  unsigned long size_group = 2;
  unsigned long beg_group  = 0;
  unsigned long end_group  = beg_group + size_group - 1;
  for (int pow2 = 4; ; pow2 *= 2) {
    if (end_group >= l->size()) {
      reverse(l, beg_group, l->size() - 1);
      break ;
    }
    reverse(l, beg_group, end_group);
    beg_group += size_group;
    end_group  = beg_group + size_group - 1;
  }
}

void change_order(std::vector<unsigned int> *v) {
  unsigned long size_group = 2;
  unsigned long beg_group  = 0;
  unsigned long end_group  = beg_group + size_group - 1;
  for (int pow2 = 4; ; pow2 *= 2) {
    if (end_group >= v->size()) {
      reverse(v, beg_group, v->size() - 1);
      break ;
    }
    reverse(v, beg_group, end_group);
    beg_group += size_group;
    size_group = pow2 - size_group;
    end_group  = beg_group + size_group - 1;
  }
}

void insert_dichotom(std::list<unsigned int> *l, unsigned int a) {
  lst_iter left   = l->begin();
  lst_iter right  = l->end();
  if (a < *(l->begin())) {
    l->push_front(a);
    return ;
  }
  while (std::distance(left, right) > 1) {
    lst_iter middle  = middle_(left, right);
    if(next(left) == l->end())
      break ;
    else if(a < *middle) 
      right = middle;
    else if(a > *middle)
      left = middle;
    else if (a == *middle) {
      l->insert(middle, a);
      return ;
    }
  }
  ++left;
  l->insert(left, a);
}

void insert_dichotom(std::vector<unsigned int> *v, unsigned int a) {
  vec_iter left   = v->begin();
  vec_iter right  = v->end();
  if (a < *(v->begin())) {
    v->insert(v->begin(), a);
    return ;
  }
  while (std::distance(left, right) > 1) {
    vec_iter middle  = middle_(left, right);
    if(next(left) == v->end())
      break ;
    else if(a < *middle) 
      right = middle;
    else if(a > *middle)
      left = middle;
    else if (a == *middle) {
      v->insert(middle, a);
      return ;
    }
  }
  ++left;
  v->insert(left, a);
}

std::list<unsigned int> run2(std::list<unsigned int> l) {
  if(l.size() <= 1)
    return l;
  if(l.size() == 2 && *(l.begin()) < *(next(l.begin())))
    return l;
  if(l.size() == 2 && *(l.begin()) >= *(next(l.begin()))) {
    std::swap(*(l.begin()), *(next(l.begin())));
    return l;
  }
  std::list<std::pair<unsigned int, unsigned int> > pairs = pairs_(l);
  std::list<unsigned int> left_half  = deep_copy_left_half(l);
  left_half = run2(left_half);
  std::list<unsigned int> right_half = right_half_(left_half, pairs);
  change_order(&right_half);
  for(lst_iter it = right_half.begin(); it != right_half.end(); ++it)
    insert_dichotom(&left_half, *it);
  return left_half;
}

std::list<unsigned int> PmergeMe::run(std::list<unsigned int> l) {
  clock_t start = clock();
  int nb_zeros = nb_zeros_(l);
  std::cout << "nb_zeros = " << nb_zeros << std::endl;
  std::list<unsigned int> ret = run2(l);
  ret.insert(l.begin(), nb_zeros, 0); // pb
  this->sec_list = 1000000 * (clock() - start) / CLOCKS_PER_SEC;
  return ret;
}

std::vector<unsigned int> run2(std::vector<unsigned int> v) {
  if(v.size() <= 1)
    return v;
  if(v.size() == 2 && *(v.begin()) < *(next(v.begin())))
    return v;
  if(v.size() == 2 && *(v.begin()) >= *(next(v.begin()))) {
    std::swap(*(v.begin()), *(next(v.begin())));
    return v;
  }
  std::vector<std::pair<unsigned int, unsigned int> > pairs = pairs_(v);
  std::vector<unsigned int> left_half  = deep_copy_left_half(v);
  left_half = PmergeMe().run(left_half);
  std::vector<unsigned int> right_half = right_half_(left_half, pairs);
  change_order(&right_half);
  for(vec_iter it = right_half.begin(); it != right_half.end(); ++it)
    insert_dichotom(&left_half, *it);
  return left_half;
}

std::vector<unsigned int> PmergeMe::run(std::vector<unsigned int> v) {
  clock_t start = clock();
  std::vector<unsigned int> ret = run2(v);
  int nb_zeros = nb_zeros_(v);
  v.insert(v.begin(), nb_zeros, 0);
  this->sec_vect = 1000000 * (clock() - start) / CLOCKS_PER_SEC;
  return ret;
}