#include "Character.hpp"

Character::Character(std::string name) {
    std::cout << "Character constructor called\n";
    this->name = name;
}

Character(Character& other) : ICharacter(other) {
    std::cout << "Character copy constructor called\n";
    this->name = name;
}