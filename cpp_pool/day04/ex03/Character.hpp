#ifnded _CHARACTER_HPP_
#define _CHARACTER_HPP_
#include "ICharacter.hpp"

class Character : public ICharacter {
private:
    std::string name;
    AMateria* slot[4];
public:
    Character(std::string name);
    Character(Character& other);
    Character& operator=(const Character& other);
    ~Character();

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);


};

#endif