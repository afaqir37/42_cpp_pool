#ifndef _HUMANA_HPP_
#define _HUMANA_HPP_
#include "Weapon.hpp"

class HumanA {
private:
	std::string name;
	Weapon& weapon;

public:
	HumanA(std::string name, Weapon& tmp);
	void attack(void);
};

#endif