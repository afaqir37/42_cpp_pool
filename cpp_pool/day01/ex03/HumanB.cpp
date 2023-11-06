#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void HumanB::setWeapon(Weapon& club)
{
	weapon = &club;
}

void HumanB::attack(void)
{
	std::cout << name << " attack with their " << weapon->getType() << '\n';
}