#ifndef _CURE_HPP_
#define _CURE_HPP_
#include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure();
    Cure(Cure& other);
    Cure& operator=(const Cure& other);
    ~Cure();

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
