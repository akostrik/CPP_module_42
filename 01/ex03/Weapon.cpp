#include "Weapon.hpp"

Weapon::Weapon(std::string type_) : type(type_) {
};

std::string Weapon::getType(void) {
    return this->type;
};

void Weapon::setType(std::string type_) {
    this->type = type_;
};
