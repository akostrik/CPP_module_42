#include <algorithm>
#include <iostream>
#include <exception>
#include <climits>
#include <vector>

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

    template <typename Iter>
    void addManyNumbers(Iter &begin, Iter &end) {
      for (Iter *it = &begin; it != &end; it++) {
        try {
          addNumber(*it);
        } catch (std::exception &e) {
          std::cout << e.what() << std::endl;
          break;
        }
      }
      (void)end;
    };
};
