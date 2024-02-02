#include "Person.hpp"

Person::Person() : _name("Unnamed"), _height(170) {};

//Person::Person(std::string name, int height) : _name(name), _height(height) {};

Person::Person(Person const &o) {
  *this = o;
}

Person& Person::operator = (Person const &o) {
  _name = o._name;
  _height = o._height;
  return *this;
};

bool Person::operator < (Person const &o) {
  return this->_height < o._height;
};

bool Person::operator > (Person const &o) {
  return this->_height > o._height;
};

std::ostream& operator <<(std::ostream& out, const Person& o) {
  out << "[" << o._name << ", height = " << o._height << "]";
  return (out);
}