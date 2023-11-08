#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::HumanB(std::string name, Weapon& wpn)
{
	this->name = name;
	this->weapon = &wpn;
}

void HumanB::setWeapon(Weapon& club)
{
	weapon = &club;
}

void HumanB::attack(void)
{
	if (weapon == NULL)
	{
		std::cout << name << " doesn't have a weapon :/" << '\n';
		return ;
	}
	std::cout << name << " attack with their " << weapon->getType() << '\n';
}