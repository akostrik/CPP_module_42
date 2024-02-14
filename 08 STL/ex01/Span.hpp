#ifndef SPAN_HPP
# define SPAN_HPP
#include <algorithm>
#include <iostream>
#include <exception>
#include <climits>
#include <vector>
#include <list>
#include <iterator>

class Span : public std::vector<unsigned int> {
  private:  
                  Span();
    unsigned int  _N; 
    unsigned int  size;
    unsigned int  min;
    unsigned int  max;

  public:
                  Span(unsigned int N);
                  Span(const Span& o);
                  ~Span();
    Span&         operator=(const Span& o);
    void          addNumber(unsigned int a);
    unsigned int  shortestSpan();
    unsigned int  longestSpan();


    template <typename IterType>
    void addNumber(IterType begin, IterType end) {
      std::cout << "6) size = " << size << ", dist = " << std::distance(begin, end) << ", _N = " << _N << " !" << std::endl;
      if (size + std::distance(begin, end) > _N)
        throw std::overflow_error("Span has no free space");
      this->insert (this->begin(), begin, end);
      size += std::distance(begin, end);
      // for (; begin != end; begin++) {
      //   try {
      //     addNumber(*begin);
      //   } catch (std::exception &e) {
      //     std::cout << e.what() << std::endl;
      //     break;
      //   }
      // }
    };
};
#endif