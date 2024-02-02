#pragma once
#include <iostream>

class Person {
public: 
  std::string _name;
  int         _height;

              Person();
              Person(const Person& o);
              //Person(std::string _name, int height);
  Person&     operator=(const Person& o);
  bool        operator<(const Person& o);
  bool        operator>(const Person& o);
};

std::ostream& operator <<(std::ostream& out, const Person& o);