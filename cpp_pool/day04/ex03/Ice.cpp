#include "Ice.hpp"

Ice::Ice() {
	std::cout << "Ice constructor called\n";
	type = "ice";
}

Ice::Ice(Ice& other) {
	std::cout << "Ice copy constructor called\n";
	type = other.type;
}

Ice& Ice::operator=(const Ice& other) {
	std::cout << "Ice copy assignment operator called\n";
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice destructor called\n";
}

AMateria* Ice::clone() const {
	return Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << type << " *\n";
}