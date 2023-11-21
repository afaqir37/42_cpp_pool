#include "Cure.hpp"

Cure::Cure() {
	std::cout << "Cure constructor called\n";
	type = "cure";
}

Cure::Cure(Cure& other) {
	std::cout << "Cure copy constructor called\n";
	type = other.type;
}

Cure& Cure::operator=(const Cure& other) {
	std::cout << "Cure copy assignment operator called\n";
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure destructor called\n";
}

AMateria* Cure::clone() const {
	return new Cure(*this);

}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << type << "’s wounds *\n";
}