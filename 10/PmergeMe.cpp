#include "PmergeMe.hpp"

/////////////////////////////////////////////////////////////////////////////// UTILS
void PmergeMe::calc_order_insertions(int argc) {
  int nb_insertions = (argc - 1) / 2;
  _order = new int[nb_insertions];
  int size_group = 0;
  int k = 1;
  int i = 0;
  for(; i < nb_insertions;) {
    size_group = pow(2, k++) - size_group;                                // 0 1  2
    int where_to_stop = std::min(i + size_group - 1, nb_insertions - 1);
    for(int v = where_to_stop; i <= where_to_stop; v--, i++)
      _order[i] = v;
  }
}

void binary_search_insert(std::list<unsigned int> half_lst, list_iterator begin, list_iterator end, unsigned int a) {
  //list_iterator insert_after_this_elt;
  //list_iterator middle;
  (void)half_lst;
  (void)begin;
  (void)end;
  (void)a;
  // std::cout << "binary_search_insert " << a << " between " << *begin << " and " << *end << std::endl;
  // std::cout << "distance = " << std::distance(begin, end) << std::endl;
  // while(1) {
  //   middle = begin;
  //   std::cout << "middle = " << *middle << " advance by " << (std::distance(begin, end) / 2) << std::endl;
  //   std::advance(middle, std::distance(begin, end) / 2); // left ?
  //   std::cout << "test middle " << *middle << std::endl;
  //   if(a == *middle) {
  //     insert_after_this_elt = middle ;
  //     break ;
  //   }
  //   else if(a < *middle)
  //     end = middle;
  //   else if(a > *middle)
  //     begin = middle;
  //   if(std::distance(lst.begin(), end) <= 1) {
  //     insert_after_this_elt = begin;
  //     break ;
  //   }
  // }
  //lst.insert(insert_after_this_elt, a);
}

/////////////////////////////////////////////////////////////////////////////// CONSTRUCTORS

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char *argv[]) {
  for(int i = 1; i < argc; i++)
    this->push_back(std::strtoul(argv[i], NULL, 10));
  calc_order_insertions(argc);
}

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::~PmergeMe() { delete _order; } //

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Position {
  int* p;
  Position(int* p) : p(p) {}

  int& dereference() const; // Получение текущего элемента
  bool equal(const Position& other) const;
  void increment();
  void decrement();
  void advance(std::ptrdiff_t n);
  std::ptrdiff_t distance_to(const Position& other) const;
};

struct my_iterator : std::iterator<std::random_access_iterator_tag, unsigned int> {
  Position pos;                                  // Вложенный объект Position, и конструктор для него
  iterator(Position pos) : pos(pos) {}
  //iterator() = default;                        // для всех категорий итераторов
  //iterator(const iterator&) = default;
  //iterator& operator=(const iterator&) = default;
  //~iterator() = default;
  //reference operator*() const { return pos.dereference(); }
  iterator& operator++() { pos.increment(); return *this; }
  iterator operator++(int) { iterator old = *this; ++(*this); return old; }
  //reference operator[](difference_type n) const { iterator tmp = *this; tmp += n; return tmp; } // для RandomAccessIterator.
  iterator& operator+=(difference_type n) { pos.advance(n); return *this; }
  iterator& operator-=(difference_type n) { return *this += -n; }
};

void swap(my_iterator& a, my_iterator& b) { std::swap(a.pos, b.pos); }   // для всех категорий итераторов
bool operator<(const my_iterator& lhs, const my_iterator& rhs) { return lhs.pos.distance_to(rhs.pos) > 0; }   // Операции, необходимые для RandomAccessIterator.
bool operator>(const my_iterator& lhs, const my_iterator& rhs) { return rhs < lhs; }
bool operator<=(const my_iterator& lhs, const my_iterator& rhs) { return !(rhs > lhs); }
bool operator>=(const my_iterator& lhs, const my_iterator& rhs) { return !(lhs < rhs); }
my_iterator operator+(my_iterator it, my_iterator::difference_type n) { it += n; return it; }
my_iterator operator+(my_iterator::difference_type n, my_iterator it) { return it + n; }
my_iterator operator-(my_iterator it, my_iterator::difference_type n) { it -= n; return it; }
my_iterator::difference_type operator-(const my_iterator& lhs, const my_iterator& rhs) { return rhs.pos.distance_to(lhs.pos); }
int& Position::dereference() const { return *p; }
bool Position::equal(const Position& other) const { return p == other.p; }
void Position::increment() { ++p; }
void Position::decrement() { --p; }
void Position::advance(std::ptrdiff_t n) { p += n; }
std::ptrdiff_t Position::distance_to(const Position& other) const { return other.p - p; }

void PmergeMe::run(list_iterator begin, list_iterator end) {
  list_iterator it1;
  list_iterator it2;

  if (std::distance(begin, end) <= 1)
    return ;                        //  1 5 4 8 2 7 3 6

  for (list_iterator it = this->begin(); it != this->end(); ++it) 
    std::cout << *it << " ";
  std::cout << std::endl;

  it1 = begin;
  it2 = begin;
  std::advance(it2, (std::distance(begin, end) + 1) / 2);
  for (; it2 != this->end(); ++it1, ++it2)
    if(*it1 < *it2)
        std::swap(*it1, *it2);
  for (list_iterator it = this->begin(); it != this->end(); ++it) 
    std::cout << *it << " ";
  std::cout << std::endl;

  //iterator first(arr), last(arr+5);
  //std::sort(first, last);
  for (iterator it = this->begin(); it != this->end(); ++it) 
    std::cout << *it << " ";
  std::cout << std::endl;
}

void PmergeMe::run() {
  run(this->begin(), this->end());
}
