#include "Zombie.hpp"

int main()
{
	Zombie obj("NUMBER_1");
	obj.announce();

	Zombie *obj2 = newZombie("NUMBER_2");
	obj2->announce();
	delete obj2;

	randomChump("NUMBER_3");
}