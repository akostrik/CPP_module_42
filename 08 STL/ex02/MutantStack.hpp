#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <algorithm>
# include <iostream>
# include <exception>
# include <climits>
# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
  public:
  typedef typename std::stack<T>::container_type::iterator iterator; // the stack access its underlying container (c)

               MutantStack ()                       : std::stack<T>()  {}
               MutantStack (const MutantStack<T> &o): std::stack<T>(o) {}             // useless
               ~MutantStack()                     {}
  MutantStack& operator=   (const MutantStack& o) { this->c = o.c; return *this; };   // useless

  iterator     begin       ()                     { return this->c.begin();  };
  iterator     end         ()                     { return this->c.end();    };
  iterator     rend        ()                     { return this->c.rend();   };
  iterator     rbegin      ()                     { return this->c.rbegin(); };
  iterator     cbegin      () const               { return this->c.begin();  };
  iterator     cend        () const               { return this->c.end();    };
  iterator     crbegin     () const               { return this->c.rbegin(); };
  iterator     crend       () const               { return this->c.rend();   };
};

#endif