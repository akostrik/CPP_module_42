#include "Weapon.hpp"

Weapon::Weapon(std::string type_) : type(type_) {
};

// returns a const reference to type string
std::string Weapon::getType(void) {
    return this->type;
};

void Weapon::setType(std::string type_) {
    this->type = type_;
};
