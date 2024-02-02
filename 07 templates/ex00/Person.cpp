#include "Person.hpp"

Person::Person(std::string name, int height) : _name(name), _height(height) {};

bool Person::operator < (Person const &o) {
  return this->_height < o._height;
};

bool Person::operator > (Person const &o) {
  return this->_height > o._height;
};

// Person::~Person() {
// };

std::ostream& operator <<(std::ostream& out, const Person& o) {
  out << o._name << " height = " << o._height;
  return (out);
}
