#ifndef _MATERIA_HPP_
#define _MATERIA_HPP_
#include "AMAteria.hpp"

class Ice : public AMateria {
public:
    Ice();
    Ice(Ice& other);
    Ice& operator=(const Ice& other);
    ~Ice();

    AMateria* clone() const;
};

class Cure : public AMateria {
public:
    Cure();
    Cure(Cure& other);
    Cure& operator=(const Cure& other);
    ~Ice();

    AMateria* clone() const;
}

#endif