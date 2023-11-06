#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}
	std::cout << "-------------------------------\n";
	{
		Weapon j = Weapon("attay mna3na3");
		HumanB ali("Ali");
		ali.setWeapon(j);
		ali.attack();
		j.setType("Pistol");
		ali.attack();
	}
}