#include <algorithm>
#include <iostream>
#include <exception>
#include <climits>
#include <vector>

class Span {
  private:  
                  Span();

  public:
    unsigned int* arr;
    unsigned int  N; // private
    unsigned int  i;
    unsigned int  min;
    unsigned int  max;
                  Span(unsigned int N);
                  Span(const Span& o);
                  ~Span();
    Span&         operator=(const Span& o);
    void          addNumber(const unsigned int a);
    unsigned int* getArr();
    unsigned int  shortestSpan();
    //unsigned int  longestSpan();

  // prennent une plage d’itérateurs afin d’ajouter une séquence d’éléments au container
  template <typename T>
  void addManyNumbers(T cont) {
    (void)cont;
  };
};
