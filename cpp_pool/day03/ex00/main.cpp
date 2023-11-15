#include "ClapTrap.hpp"

int main()
{
	ClapTrap wallE("walle");

	wallE.attack("cyborg");
	wallE.takeDamage(10);
	wallE.beRepaired(10);
	wallE.takeDamage(10);
	wallE.takeDamage(10);


}