#include "Serializer.hpp"

////////////////////////////////////////////////////// OCCF
Serializer::Serializer() {};

Serializer::Serializer(const Serializer &obj) { 
  *this = obj; 
};

Serializer& Serializer::operator = (Serializer const &obj) {
  (void)obj;
  return *this;
};

Serializer::~Serializer() {};

////////////////////////////////////////////////////// MEMBER FUNCITONS
// converts a pointer to uintptr_t
uintptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

// converts unsigned int to Data*
Data* Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}
