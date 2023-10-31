#include "Weapon.hpp"

Weapon::Weapon(std::string type_) : type(type_) {
};

// The getType() function returns a const reference to the type string !
std::string Weapon::getType(void) {
    return this->type;
};

void Weapon::setType(std::string type_) {
    this->type = type_;
};
