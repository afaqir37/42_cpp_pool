#include "AMateria.hpp"

AMateria::AMateria() {
    std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(std::string const & type) {
    std::cout << "AMateria constructor called\n";
    this->type = type;
}

AMateria::AMateria(AMateria& other) {
    std::cout << "AMateria copy constructor called\n";
    this->type = other.type;
}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "AMAteria copy assignment operator called\n";
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called\n";
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) { }