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

// to give to stack the access to its underlying container (container_type)

  typedef typename std::stack<T>::container_type::iterator iterator;

               MutantStack () {}
               ~MutantStack() {}

  MutantStack(const MutantStack<T>  &o): std::stack<T>(o) {} 
 
  MutantStack& operator= (const MutantStack& o) { 
    this->c = o.c;
    //std::stack<T>::operator=(o); 
    return *this; 
  };



  T*           operator->  ()                     { return *this; };
  T&           operator*   () const               { return &this; };
  T*           operator++  ()                     { (*this)++;  return *this; };

  // c = the underlying container
  iterator     begin       ()                     { return (this->c.begin());  };
  iterator     end         ()                     { return (this->c.end());    };
  iterator     rend        ()                     { return (this->c.rend());   };
  iterator     rbegin      ()                     { return (this->c.rbegin()); };
  iterator     cbegin      () const               { return (this->c.begin());  };
  iterator     cend        () const               { return (this->c.end());    };
  iterator     crbegin     () const               { return (this->c.rbegin()); };
  iterator     crend       () const               { return (this->c.rend());   };
  //             iterator    (T* o)               { this(o); }
};

template <typename T>
typename std::stack<T>::container_type::iterator operator++(T o) {
  typename std::stack<T>::container_type::iterator tmp = *o; 
  ++(*o);
  return tmp;
}

template <typename T>
bool operator!=(const typename std::stack<T>::container_type::iterator& a, const typename std::stack<T>::container_type::iterator& b) {
  return a != b;
};

template <typename T>
bool operator==(const typename std::stack<T>::container_type::iterator& a, const typename std::stack<T>::container_type::iterator& b) {
  return a == b;
};

#endif