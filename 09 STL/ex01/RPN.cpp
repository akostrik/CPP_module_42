#include "RPN.hpp"

RPN::RPN() : std::stack<float>() {}

RPN::~RPN() {}

RPN::RPN(const RPN& o) : std::stack<float>() {
  *this = o;
}

RPN& RPN::operator=(const RPN& o) {
  std::stack<float>::container_type underliyng_cont_o    = o.c;
  this->c = underliyng_cont_o;
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
    else
      throw std::invalid_argument("Error");
  }
  if (this->size() != 1)
    throw std::invalid_argument("Error");
}

void RPN::run() {
  std::cout << this->top() << std::endl;
}