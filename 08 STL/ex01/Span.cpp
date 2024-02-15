// Vous pouvez avoir recours à quasi l’ensemble de la bibliothèque standard. 
// Donc plutôt que de rester en terrain connu, 
// essayez d’utiliser le plus possible les versions C++ des fonctions C dont vous avec l’habitude

#include "Span.hpp"

Span::Span(unsigned int N) : std::vector<unsigned int>() {
  _N   = N;
  size = 0;
  min  = UINT_MAX;
  max  = 0;
}

Span::Span(const Span& o) : std::vector<unsigned int>() {
  *this = o;
}

Span::~Span() {}

Span& Span::operator=(const Span& o) {
  std::copy(o.begin(), o.end(), this->begin());
  _N   = o._N;
  size = o.size;
  min  = o.min;
  max  = o.max;
  return *this;
}

////////////////////////////////////////////
void Span::addNumber(unsigned int a) {
  if(size == _N)
    throw std::overflow_error("Span has no free space");
  this->push_back(a);
  if (min > a)
    min = a;
  if (max < a)
    max = a;
  size++;
}

unsigned int Span::shortestSpan() {
  if(size < 2)
    throw std::exception();

  std::cout << "not sorted  : ";
  for (std::vector<unsigned int>::iterator it = this->begin(); it != this->end(); it++)
    std::cout << *it << "  ";
  std::sort(this->begin(), this->end());                                                 // algo
  std::cout << std::endl << "sorted      : ";
  for (std::vector<unsigned int>::iterator it = this->begin(); it != this->end(); it++)
    std::cout << *it << "  ";

  std::vector<unsigned int> *spans = new std::vector<unsigned int>(this->size);
  std::adjacent_difference(this->begin(), this->end(), spans->begin());                 // numeric>
  std::rotate(spans->begin(), spans->begin() + 1, spans->end());                        // algo
  spans->pop_back();

  std::cout << std::endl << "spans       : ";
  for (std::vector<unsigned int>::iterator it = spans->begin(); it != spans->end(); it++)
    std::cout << *it << "  ";
  std::cout << std::endl << std::endl;

  return *std::min_element(spans->begin(), spans->end());                               // algo

  // std::vector<unsigned int> rotatedCopy = *this;
  // std::rotate(rotatedCopy.begin(),rotatedCopy.begin() + 1,rotatedCopy.end()); // algo
  // std::cout << "rotated copy: ";
  // for (std::vector<unsigned int>::iterator it = rotatedCopy.begin(); it != rotatedCopy.end(); it++)
  //   std::cout << *it << "  ";
  // rotatedCopy.pop_back();

  //std::transform(x.begin()+1, x.end(), y.begin(), y.begin()+1, std::min<тип>);

  // int min(int x, int y) { return (x < y) ? x : y; }
  // std::transform(x.begin()+1,x.end(),y.begin(),y.begin()+1, min);

  // transform(str1.begin(), str1.end(), str1.begin(), ::tolower);

  // transform( ia, ia+5, vec.begin(), outfile, difference ); https://it.wikireading.ru/36213 

}

unsigned int Span::longestSpan() {
  if(size < 2)
    throw std::exception();
  return (max - min);
}