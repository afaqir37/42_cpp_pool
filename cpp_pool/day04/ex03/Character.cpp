#include "Character.hpp"

Character::Character(std::string name) {
    std::cout << "Character constructor called\n";
    this->name = name;
    for (int i = 0; i < 4; i++) {
        slot[i] = NULL;
        pool[i] = NULL;
    }
}

Character::Character(Character& other) : ICharacter(other) {
    std::cout << "Character copy constructor called\n";
    this->name = name;
    for (int i = 0; i < 4; i++)
        slot[i] = other.slot[i] ? other.slot[i]->clone() : NULL;
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character copy assignment operator called\n";
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < 4; i++)
        {
            delete slot[i];
            slot[i] = other.slot[i] ? other.slot[i]->clone() : NULL;
        }
    }
}

Character::~Character() {
    std::cout << "Character destructor called\n";
    for (int i = 0; i < 4; i++)
        delete slot[i];
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    int i = 0;

    for (i = 0; i < 4; i++)
        if (slot[i] == NULL)
        {
            slot[i] = m;
            break;
        }

}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && slot[idx])
    {

    }
}