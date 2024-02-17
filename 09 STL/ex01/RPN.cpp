#include "RPN.hpp"

RPN::RPN() : std::stack<float>() {}

RPN::~RPN() {}

RPN::RPN(const RPN& o) : std::stack<float>() {
  *this = o;
}

template <class ADAPTER>
typename ADAPTER::container_type & get_container (ADAPTER &a) {
  struct hack : ADAPTER {
    static typename ADAPTER::container_type & get (ADAPTER &a) {
      return a.*&hack::c;
    }
  };
  return hack::get(a);
}

// template <class T, class S, class C>
//   S& Container(std::priority_queue<T, S, C>& q) {
//     struct HackedQueue : private std::priority_queue<T, S, C> {
//       static S& Container(std::priority_queue<T, S, C>& q) {
//         return q.*&HackedQueue::c;
//       }
//     };
//   return HackedQueue::Container(q);
// }

RPN& RPN::operator=(const RPN& o) { // to test
  std::stack<float>::container_type underliyng_container_of_o    = o.c;
  std::stack<float>::container_type underliyng_container_of_this = this->c;
  underliyng_container_of_this = underliyng_container_of_o;
  return *this;
}

RPN::RPN(std::string arg) : std::stack<float>() {
  arg.erase(std::remove_if(arg.begin(), arg.end(), isspace), arg.end()); // remove spaces
  for(std::string::iterator it = arg.begin(); it != arg.end(); ++it) {
    if (*it >= '0' && *it <= '9')
      this->push(*it - '0');
    else if ((*it == '+' || *it == '-' || *it == '*' || *it == '/') && this->size() >= 2) {
      float b = this->top();
      this->pop();
      float a = this->top();
      this->pop();
      if (*it == '+')
        this->push(a + b);
      if (*it == '-')
        this->push(a - b);
      if (*it == '*')
        this->push(a * b);
      if (*it == '/')
        this->push(a / b);
    }
    else {
      std::cout << arg << " : in not valid" << std::endl;
      return ;
    }
  }
  std::cout << this->top() << std::endl;
}
