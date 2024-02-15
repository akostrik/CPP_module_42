#ifndef SPAN_HPP
# define SPAN_HPP
#include <algorithm>
#include <iostream>
#include <exception>
#include <climits>
#include <vector>
#include <list>
#include <iterator>
#include <functional>
#include <numeric>

class Span : public std::vector<unsigned int> {
  private:  
                  Span();
    unsigned int  _N; 
    unsigned int  size;
    unsigned int  min;
    unsigned int  max;

  public:
                  Span        (unsigned int N);
                  Span        (const Span& o);
                  ~Span       ();
    Span&         operator=   (const Span& o);
    void          addNumber   (unsigned int a);
    unsigned int  shortestSpan();
    unsigned int  longestSpan ();
    unsigned int  diff        (unsigned int n1, unsigned int n2);

    template <typename IterType>
    void addNumber(IterType new_diapason_begin, IterType new_diapason_end) {
      if (size + std::distance(new_diapason_begin, new_diapason_end) > _N)
        throw std::overflow_error("Span has no free space");
      unsigned int potentially_new_min = *std::min_element(new_diapason_begin, new_diapason_end);
      unsigned int potentially_new_max = *std::max_element(new_diapason_begin, new_diapason_end);
      if (potentially_new_min < min)
        min = potentially_new_min;
      if (max < potentially_new_max)
        max = potentially_new_max;
      this->insert (this->begin(), new_diapason_begin, new_diapason_end);
      size += std::distance(new_diapason_begin, new_diapason_end);
    };
};
#endif