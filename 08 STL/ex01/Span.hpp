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

  public:
    unsigned int  _N; // private
    unsigned int  size;
    unsigned int  min;
    unsigned int  max;
                  Span(unsigned int N);
                  Span(const Span& o);
                  ~Span();
    Span&         operator=(const Span& o);
    void          addNumber(unsigned int a);
    unsigned int  shortestSpan();
    unsigned int  longestSpan();


    template <typename IterType>
    void addNumbers(IterType begin, IterType end) {
      for (; begin != end; begin++) {
        try {
          addNumber(*begin);
        } catch (std::exception &e) {
          std::cout << e.what() << std::endl;
          break;
        }
      }
    };
};
