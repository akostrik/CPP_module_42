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

  // prennent une plage d’itérateurs afin d’ajouter une séquence d’éléments au container
  template <typename T>
  void addManyNumbers(T cont) {
    (void)cont;
  };
};
