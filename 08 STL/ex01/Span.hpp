#include <algorithm>
#include <iostream>
#include <exception>
#include <queue>
#include <climits>
#include <memory> // c++ 11 ?

class Span : public std::priority_queue<unsigned int> {
  private:
                                 Span();

  public:
    unsigned int                 _N;
    unsigned int                 _min;
    unsigned int                 _max;
                                 Span(unsigned int N);
                                 Span(const Span& o);
                                 ~Span();
    Span&                        operator=(const Span& o);
    void                         addNumber(const unsigned int a);
    unsigned int  shortestSpan();
    unsigned int  longestSpan();

  // prennent une plage d’itérateurs afin d’ajouter une séquence d’éléments au container
  template <typename T>
  void addManyNumbers(T cont) {
    (void)cont;
  };
};
