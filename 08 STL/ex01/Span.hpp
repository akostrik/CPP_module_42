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
    void addManyNumbers(Iter &i, Iter &end) {
    //void Show(std::list<std::string>::const_iterator bgn, std::list<std::string>::const_iterator end);
      //for (; i != end; ++i) {
//        try {
          std::cout << "call addNumber(" << i << ")" << std::endl;
          addNumber(i);
          addNumber(*(&i+1));
          addNumber(*(&i+2));
          std::cout << "return " << std::endl;
        // } catch (std::exception &e) {
        //  std::cout << e.what() << std::endl;
        // }
      //}
      (void)end;
    };
};
