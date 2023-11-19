#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructor called\n";
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called\n";
    type = other.type;
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called\n";
    if (this != &other)
    {
        type = other.type;
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound(void) const{
    std::cout << "Cat sound: Meoww\n";
}

void Cat::getter(void) {
    brain->getIdeas();
}

void Cat::setter(int index, std::string str) {
    brain->setIdeas(index, str);
}