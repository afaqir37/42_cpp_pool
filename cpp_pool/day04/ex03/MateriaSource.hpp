#ifndef _MATERIASOURCE_HPP_
#define _MATERIASOURCE_HPP_
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria *materias[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();

	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};

#endif