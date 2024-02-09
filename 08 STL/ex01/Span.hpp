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
      std::cout << "call addNumber(" << begin << ", " << *(&begin+1) << ", " << *(&begin+2) << ")" << std::endl;
      std::cout << "begin = " << begin << ", &begin = " << &begin << ", &end = " << &end << std::endl;
      //void Show(std::list<std::string>::const_iterator bgn, std::list<std::string>::const_iterator end);
      for (Iter *it = &begin; it != &end; ) {
//        try {
          std::cout << "it = " << it << ", *it = " << *it << ", addNumber(" << *it << ")" << std::endl;
          addNumber(*it);
          //it = *(&it+1);
          it++;
        // } catch (std::exception &e) {
        //  std::cout << e.what() << std::endl;
        // }
      }
      (void)end;
    };
};
