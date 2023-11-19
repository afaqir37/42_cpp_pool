#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string name) {
    std::cout << "WrongAnimal constructor called\n";
    type = name;
}

WrongAnimal::WrongAnimal(WrongAnimal& other) {
    std::cout << "WrongAnimal copy constructor called\n";
    type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy assignment operator\n";
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

 WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called\n";
}

 void WrongAnimal:: makeSound(void) const{
    std::cout << "each wrongAnimal has a specific sound\n";
}

std::string WrongAnimal::getType(void) const {
    return type;
}