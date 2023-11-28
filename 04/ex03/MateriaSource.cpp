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
// Like the Character, the MateriaSource can know at most 4 Materias. They are not necessarily unique.
void    MateriaSource::learnMateria(AMateria* m) {
  for (int i = 0; i < 4; i++)
    if (materias[i] == NULL) {
      materias[i] = m;
      // std::cout << "MateriaSource learned " << m->getType() << std::endl;
      return;
    }
  // std::cout << "MateriaSource can't learn " << m->getType() << std::endl;
}

// Returns a new Materia. 
// The latter is a copy of the Materia previously learned by the MateriaSource whose type equals the one passed as parameter. 
// Returns 0 if the type is unknown.
AMateria*   MateriaSource::createMateria( std::string const& type ) {
  for ( int i = 0; i < 4; i++ )
    if ( materias[i] && materias[i]->getType() == type )
      return materias[i]->clone();
  return NULL;
}