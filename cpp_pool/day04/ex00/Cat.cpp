#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructor called\n";
    type = "Cat";
}

Cat::Cat(Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called\n";
    type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called\n";
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

void Cat::makeSound(void)  {
    std::cout << "Cat sound: Meoww\n";
}