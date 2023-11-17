#include "ScavTrap.hpp"

int main()
{
	ClapTrap wallE("walle");

	wallE.attack("cyborg");
	wallE.takeDamage(10);
	wallE.beRepaired(10);
	wallE.takeDamage(10);
	wallE.takeDamage(10);

	ScavTrap player("pixel");
	player.attack("walle");
	player.takeDamage(32);
	player.takeDamage(90);
	player.guardGate();

	// ClapTrap *ptr = new ScavTrap("pixel");
	// ptr->attack("suzan");
	// delete ptr;


}