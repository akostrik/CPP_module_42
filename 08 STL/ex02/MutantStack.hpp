// the operations shown in the examples using iterators
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <exception>
#include <climits>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
  public:
  typedef typename std::stack<T>::container_type::iterator iterator;

               MutantStack() {} // : std::stack<T>()
               ~MutantStack() {} // virtual // this->c.clear();
               MutantStack(const MutantStack& o) {   *this = o; } // std::stack<T>() ? // std::stack<T>(o)
  MutantStack& operator=(const MutantStack& o) { std::stack<T>::operator=(o); return *this; }; // this->c = obj.c; 

  iterator     begin()         { return (this->c.begin());  };
  iterator     end()           { return (this->c.end());    };
  iterator     rbegin()        { return (this->c.rbegin()); };
  iterator     rend()          { return (this->c.rend());   };
  iterator     cbegin()  const { return (this->c.begin());  };
  iterator     cend()    const { return (this->c.end());    };
  iterator     crbegin() const { return (this->c.rbegin()); };
  iterator     crend()   const { return (this->c.rend());   };

  // iterator(pointer ptr)  {
  //   arr(ptr);
  // }

  // T& operator*() const { 
  //   return *arr;
  // }

  // T* operator->() {
  //   return arr;
  // }

  // bool operator==(const iterator& a, const iterator& b) {
  //   return a.arr == b.arr;
  // };
};

// template <typename T>
// typename std::stack<T>::container_type::iterator& operator++() {
//   (this->iterator)++;
//   return *this;
// }

template <typename T>
typename std::stack<T>::container_type::iterator operator++(T o) {
  typename std::stack<T>::container_type::iterator tmp = *o; 
  ++(*o);
  return tmp;
}

template <typename T>
bool operator!=(const typename std::stack<T>::container_type::iterator& a, const typename std::stack<T>::container_type::iterator& b) {
  return a.arr != b.arr;
};

#endif