#include "ScavTrap.hpp"

int main()
{
	ClapTrap wallE("walle");

	wallE.attack("cyborg");
	wallE.beRepaired(1);
	wallE.takeDamage(10);
	wallE.attack("d");
	wallE.takeDamage(4);
	

	std::cout << "----------\n";

	ScavTrap player("pixel");
	player.attack("walle");
	player.takeDamage(32);
	player.takeDamage(90);
	player.guardGate();

	std::cout << "----------\n";

	ClapTrap *ptr = new ScavTrap("pixel");
	ptr->attack("suzan");
	delete ptr;


}