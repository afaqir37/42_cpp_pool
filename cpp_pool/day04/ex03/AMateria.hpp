#ifndef _AMATERIA_HPP_
#define _AMATERIA_HPP_
#include "Character.hpp"
#include <iostream>

class AMateria {
protected:
    std::string type;
public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

};

#endif