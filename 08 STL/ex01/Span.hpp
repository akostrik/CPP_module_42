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


    template <typename T>
    void addNumber(T begin, T end) {
      for (; begin != end; begin++) {
        // if (size == _max_size)
        //     throw FullException();
        addNumber(begin);
      }
    }

    // template <typename Iter>
    // void addNumber(Iter &begin, Iter &end) {
    //   std::cout << "     addMany(" << &begin << ", " << &end << ")\n";
    //   std::cout << "2) list: ";
    //   for(unsigned int* ittt = &begin; ittt != (&begin + (sizeof begin / sizeof *(&begin))); ittt++) {
    //     std::cout << *ittt << " ";
    //   }

    //   std::cout << std::endl << "3) list: ";
    //   int k = 0;
    //   //vector<unsigned int>::iterator itt(begin);
    //   //for (Iter *it = itt; it != &end && k <=5 ; std::advance(it, 1), k++)
    //   for (Iter *it = &begin; it != &end && k <=2 ; std::advance(it, 1), k++)
    //     std::cout << *it << " ";
    //   std::cout << std::endl;

    //   k = 0;
    //   for (Iter *it = &begin; it != &end && k <= 2; it++, k++) {
    //     try {
    //       addNumber(*it);
    //     } catch (std::exception &e) {
    //       std::cout << e.what() << std::endl;
    //       break;
    //     }
    //   }
    // };
};
