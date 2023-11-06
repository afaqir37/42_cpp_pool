#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& tmp) : name(name), weapon(tmp) {}

void HumanA::attack(void)
{
	std::cout << name << " attack with their " << weapon.getType() << '\n';
}