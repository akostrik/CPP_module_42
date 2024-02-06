#include <algorithm>
#include <iostream>
#include <exception>
#include <set>

class Span {
  private:
    std::multiset<unsigned int> _container;
    int                         _N;
                                Span();

  public:
                                Span(unsigned int N);
                                Span(const Span& o);
                                ~Span();
    Span&                       operator=(const Span& o);
    std::multiset<unsigned int> getContainer() const;
    void                        addNumber(const unsigned int a);
    // const unsigned int  shortestSpan();
    // const unsigned int  longestSpan();


  template <typename T>
  void addManyNumbers(T container) {
    (void)container;
  };
};
