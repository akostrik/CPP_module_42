#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::~PmergeMe() {} 

////////////////////////////////////////////////////////// UTILS
lst_iter next(lst_iter it) {
  std::advance(it, 1);
  return it;
}

lst_iter middle_(lst_iter begin, lst_iter end) {
  lst_iter middle = begin; 
  std::advance(middle, (std::distance(begin, end) + 1 ) / 2);
  return middle;
}

std::list<unsigned int> deep_copy_left_half(std::list<unsigned int> l1) {
  std::list<unsigned int> l2;
  std::list<unsigned int>::iterator middle = middle_(l1.begin(), l1.end());
  for (lst_iter it = l1.begin(); it != middle; ++it) 
    l2.push_back(*it);
  return l2;
}

std::map<unsigned int, unsigned int> pairs_as_map(std::list<unsigned int> l) {
  std::map<unsigned int, unsigned int>  pairs ;
  lst_iter it1 = l.begin();
  lst_iter it2 = middle_(l.begin(), l.end());
  for( ; it2 != l.end() ; ++it1, ++it2)
    if(*it1 < *it2) 
      pairs.insert(std::pair<unsigned int, unsigned int>(*it1, *it2));
    else
      pairs.insert(std::pair<unsigned int, unsigned int>(*it1, *it2));
  if (l.size() % 2 == 1)
    pairs.insert(std::pair<unsigned int, unsigned int>(*it1, 0));
  return pairs;
}

std::list<std::pair<unsigned int, unsigned int> > pairs_as_list(std::list<unsigned int> l) {
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

std::list<unsigned int> right_half_from_map(std::list<unsigned int> left_half, std::map<unsigned int, unsigned int> pairs) {
  std::list<unsigned int> right_half;
  for (std::list<unsigned int>::iterator it = left_half.begin(); it != left_half.end(); ++it) {
    unsigned int wanted_second = pairs.find(*it)->second;
    if (wanted_second > 0)
      right_half.push_back(wanted_second); 
  }
  return right_half;
}

std::list<unsigned int> right_half_from_list(std::list<unsigned int> left_half, std::list<std::pair<unsigned int, unsigned int> > pairs) {
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

void reverse(std::list<unsigned int> *l, int n, int m) {
  lst_iter left   = l->begin();
  lst_iter right  = l->begin();
  std::advance(left, n);
  std::advance(right, m + 1);
  std::reverse(left, right);
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

std::list<unsigned int> PmergeMe::run_list(std::list<unsigned int> l) {
  if(l.size() <= 1)
    return l;
  if(l.size() == 2 && *(l.begin()) < *(next(l.begin())))
    return l;
  if(l.size() == 2 && *(l.begin()) >= *(next(l.begin()))) {
    std::swap(*(l.begin()), *(next(l.begin())));
    return l;
  }
  std::list<std::pair<unsigned int, unsigned int> > pairs = pairs_as_list(l);
  std::list<unsigned int> left_half  = deep_copy_left_half(l);
  left_half = PmergeMe().run_list(left_half);
  std::list<unsigned int> right_half = right_half_from_list(left_half, pairs);
  change_order(&right_half);
  for(lst_iter it = right_half.begin(); it != right_half.end(); ++it)
    insert_dichotom(&left_half, *it);
  return left_half;
}

// 0  1  0  3  2  9  8  7  6  5  4 19 18 17 16 15 14 13 12 11 10 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20                        order

// 0  1  3  5  11  21  43  85  171  341  683  1365  2731  5461  10923  21845  43691  87381  174763  349525                                                jacobstal numbers
//    2  2  6  10  22  42                                                                                                                                 size group
//    0  2  4  10  20                                                                                                                                     partic positions
//[0] 1 [2] 3 [4] 5  6  7  8  9[10]11 12 13 14 15 16 17 18 19[20]21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41[42]43 44 45 46 47 48 49   partic positions
//[1] 0 [3] 2 [9] 8  7  6  5  4[19]18 17 16 15 14 13 12 11 10[41]40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20
//+3    +7    +15              +31

// 0 [1] 2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1
//[0] 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1 +4 (2nd jn, 2^2)

// 0  1  2 [3] 4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1
// 0  1 [2] 3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1 +8 (3st jn, 2^3)

// 0  1  2  3  4  5  6  7  8 [9]10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1
// 0  1  2  3 [4] 5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1 +16 (4th jn, 2^4)

// 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18[19]20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1
// 0  1  2  3  4  5  6  7  8  9[10]11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1 +32 (5th jn, 2^5)

// 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40[41]42 43 44 45 46 47 48 49   -1 
// 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19[20]21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49   -1 +64 (6th jn, 2^6)

  // move_right[0] = 3;
  // move_right[2] = 7;
  // move_right[4] = 15;
  // move_right[10] = 31;
  // move_right[20] = 63;
  // move_right[42] = 127;
  // move_right[84] = 255;
  // move_right[170] = 511;
  // move_right[340] = 1023;
  // move_right[682] = 2047;
  // move_right[1364] = 4095;
  // move_right[2730] = 8191;
  // move_right[5460] = 16383;
  // move_right[10922] = 32767;
  // move_right[21844] = 65535;
  // move_right[43690] = 131071;
  // move_right[87380] = 262143;
  // move_right[174762] = 524287;
  // move_right[349524] = 1048575;
