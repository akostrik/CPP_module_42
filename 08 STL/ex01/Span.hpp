#include <algorithm>
#include <iostream>
#include <exception>
#include <queue>

class Span : public std::priority_queue<unsigned int> {
  private:
    // std::priority_queue<unsigned int> _cont;
    //std::priority_queue<unsigned int> _inverted_cont;
    unsigned int                 _N;
                                 Span();

  public:
                                 Span(unsigned int N);
                                 Span(const Span& o);
                                 ~Span();
    Span&                        operator=(const Span& o);
    // std::priority_queue<unsigned int>  getCont(); // const ?
    void                         addNumber(const unsigned int a);
    // const unsigned int  shortestSpan();
    // const unsigned int  longestSpan();


  template <typename T>
  void addManyNumbers(T cont) {
    (void)cont;
  };
};
