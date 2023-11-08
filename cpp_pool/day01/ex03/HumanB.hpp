#ifndef _HUMANB_HPP_
#define _HUMANB_HPP_
#include "Weapon.hpp"

class HumanB {
private:
	std::string name;
	Weapon* weapon;

public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon& wpn);
	void setWeapon(Weapon& club);
	void attack(void);
};

#endif