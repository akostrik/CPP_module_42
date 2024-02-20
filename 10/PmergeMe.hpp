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

struct Position {
  int* p;
  Position(int* p) : p(p) {}

  int& dereference() const; // Получение текущего элемента.
  bool equal(const Position& other) const; // Проверка на равенство.
  void increment(); // Перемещение вперед.
  void decrement(); // Перемещение назад.
  void advance(std::ptrdiff_t n);  // Перемещение на "n" элементов.
  std::ptrdiff_t distance_to(const Position& other) const; // Расстояние до другой позиции.
};
 
struct my_iterator : std::iterator<std::random_access_iterator_tag, unsigned int> {
  Position pos;       // Вложенный объект Position, и конструктор для него.
  //iterator(Position pos) : pos(pos) {}
  //iterator() = default;       // Операции, необходимые для всех категорий итераторов.
  //iterator(const iterator&) = default;
  //iterator& operator=(const iterator&) = default;
  //~iterator() = default;
  //reference operator*() const { return pos.dereference(); }
  iterator& operator++() { pos.increment(); return *this; }
  //iterator operator++(int) { auto old = *this; ++(*this); return old; }
  //reference operator[](difference_type n) const { auto tmp = *this; tmp += n; return *tmp; }       // Операции, необходимые для RandomAccessIterator.
  iterator& operator+=(difference_type n) { pos.advance(n); return *this; }
  iterator& operator-=(difference_type n) { return *this += -n; }
};

class PmergeMe : public std::list<unsigned int> {
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
  void                    run                  ();
  void                    run(list_iterator begin, list_iterator end);
};

//void swap(iterator& a, iterator& b) { std::swap(a.pos, b.pos); }
//bool operator<(const iterator& lhs, const iterator& rhs) { return lhs.pos.distance_to(rhs.pos) > 0; } // Операции, необходимые для RandomAccessIterator.
//bool operator>(const iterator& lhs, const iterator& rhs) { return rhs < lhs; }
//bool operator<=(const iterator& lhs, const iterator& rhs) { return !(rhs > lhs); }
//bool operator>=(const iterator& lhs, const iterator& rhs) { return !(lhs < rhs); }
//iterator operator+(iterator it, iterator::difference_type n) { it += n; return it; }
//iterator operator+(iterator::difference_type n, iterator it) { return it + n; }
//iterator operator-(iterator it, iterator::difference_type n) { it -= n; return it; }
//iterator::difference_type operator-(const iterator& lhs, const iterator& rhs) { return rhs.pos.distance_to(lhs.pos); }

//int& Position::dereference() const { return *p; }
//bool Position::equal(const Position& other) const { return p == other.p; }
//void Position::increment() { ++p; }
//void Position::decrement() { --p; }
//void Position::advance(std::ptrdiff_t n) { p += n; }
//std::ptrdiff_t Position::distance_to(const Position& other) const { return other.p - p; }
 
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
