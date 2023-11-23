#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() {
	type = "ice";
}

Ice::Ice(const Ice& other) {
	type = other.type;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

Ice::~Ice() {
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}