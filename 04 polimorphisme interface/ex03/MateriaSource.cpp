#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++)
    materias[i] = NULL;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++)
    if (materias[i])
      delete materias[i];
}

MateriaSource::MateriaSource(MateriaSource const & src) {
  *this = src;
}

MateriaSource& MateriaSource::operator=(MateriaSource const & ref) {
  for (int i = 0; i < 4; i++)
    materias[i] = ref.materias[i];
  return *this;
}



// to generate a new Materia using just a string that identifies its type
AMateria* MateriaSource::getMateria(std::string const & type) {
  for (int i = 0; i < 4; i++)
    if (materias[i] && materias[i]->getType() == type)
      return materias[i];
  return NULL;
}

// Copies the Materia passed as a parameter and store it in memory so it can be cloned later
// MateriaSource can know at most 4 Materias, they are not necessarily unique
void    MateriaSource::learnMateria(AMateria* m) {
  for (int i = 0; i < 4; i++)
    if (materias[i] == NULL) {
      materias[i] = m;
      std::cout << "MateriaSource learned " << m->getType() << std::endl;
      return;
    }
  std::cout << "MateriaSource can't learn " << m->getType() << std::endl;
}

AMateria*   MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < 4; i++)
    if (materias[i] && materias[i]->getType() == type)
      return materias[i]->clone(); // new Materia - a copy of the Materia previously learned, whose type equals the one passed as parameter
  return NULL; // Returns 0 if the type is unknown
}