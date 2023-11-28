#include "Character.hpp"

Character::Character( std::string const & name ) : _name(name) {
  for (int i = 0; i < 4; i++) 
    this->_inventory[i] = NULL;
  std::cout << "Character   " << this->_name << " default constructor" << std::endl;
}

// Any copy (using copy constructor or copy assignment operator) must be deep
// the Materias of a Character must be deleted before the new ones are added to their inventory
Character::Character(Character const & src) : _name(src._name) {
  // for (int i = 0; i < 4; i++)
  //     this->_inventory[i] = src._inventory[i];
  *this = src;
  std::cout << "Character   " << this->_name << " copy     constructor" << std::endl;
}

// Any copy (using copy constructor or copy assignment operator) must be deep
// the Materias of a Character must be deleted before the new ones are added to their inventory
Character& Character::operator=( Character const & ref ) {
  this->_name = ref._name;
  for (int i = 0; i < 4; i++)
      this->_inventory[i] = ref._inventory[i];
  std::cout << "Character   " << this->_name << " assignment operator" << std::endl;
  return *this;
}

// the Materias must be deleted when a Character is destroyed
Character::~Character() {
  std::cout << "Character   " << this->_name << " descructor" << std::endl;
  for (int i = 0; i < 4; i++)
      if (this->_inventory[i])
          delete this->_inventory[i];
}



// Your character’s inventory will be able to support any type of AMateria
void Character::equip( AMateria* m) {
  for (int i = 0; i < 4; i++)
    if (this->_inventory[i] == NULL) {
      this->_inventory[i] = m;
      std::cout << "Character   " << this->_name << " equipped with " << m->getType() << std::endl;
      return;
    }
  std::cout << "Character   " << this->_name << " can't equip " << m->getType() << std::endl;
}

// must NOT delete the Materia
// Handle the Materias your character left on the floor as you like
// Save the addresses before calling unequip(), or anything else, to avoid memory leaks
void Character::unequip( int idx ) {
  if (this->_inventory[idx]) {
    delete this->_inventory[idx];
    this->_inventory[idx] = NULL;
    std::cout << "Character   " << this->_name << " unequipped" << std::endl;
  }
  else
    std::cout << "Character   " << this->_name << " can't unequip" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
  if (this->_inventory[idx]) {
    this->_inventory[idx]->use(target);
    std::cout << "Character   " << this->_name << " uses " << this->_inventory[idx]->getType() << std::endl;
  }
  else
    std::cout << "Character  " << this->_name << " can't use" << std::endl;
}

std::string const& Character::getName() const {
  return this->_name;
}