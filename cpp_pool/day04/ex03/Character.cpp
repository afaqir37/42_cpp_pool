#include "Character.hpp"

Character::Character(std::string name) {
    this->name = name;
    for (int i = 0; i < 4; i++) {
        slot[i] = NULL;
    }
}

Character::Character(Character& other) : ICharacter(other) {
    this->name = other.name;
    for (int i = 0; i < 4; i++)
        slot[i] = other.slot[i] ? other.slot[i]->clone() : NULL;
}

Character& Character::operator=(const Character& other) {
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < 4; i++)
        {
            delete slot[i];
            slot[i] = other.slot[i] ? other.slot[i]->clone() : NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (slot[i]) {
            if (list.contains(slot[i]))
                list.setNodeToNull(slot[i]);
            delete slot[i];
            slot[i] = nullptr;
        }
    }

}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    int i = 0;
    if (m == NULL || doesItExist(m))
        return;
    for (i = 0; i < 4; i++)
        if (slot[i] == NULL)
        {
            slot[i] = m;
            break;
        }

}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && slot[idx]) {
        if (!list.contains(slot[idx]))
            list.add(slot[idx]);
        slot[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && slot[idx]) {
        slot[idx]->use(target);
    }
}

int Character::doesItExist(AMateria* obj) {
    for (int i = 0; i < 4; i++)
        if (slot[i] == obj)
            return 1;

    return 0;
}
