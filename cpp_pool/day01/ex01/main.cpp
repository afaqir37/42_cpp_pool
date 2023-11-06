#include "Zombie.hpp"
#include <cstdlib>

int main()
{
	Zombie obj;
	obj.init("Player");
	obj.announce();

	std::cout << "------------------------\n";
	
	Zombie* obj2 = zombieHorde(4, "Enemy");
	if (!obj2)
		return (-1);
	for (int i = 0; i < 4 ; i++)
		obj2[i].announce();

	std::cout << "------------------------\n";

	Zombie* obj3 = zombieHorde(10, "BadEnemy");
	if (!obj3)
		return (-1);
	for (int i = 0; i < 10 ; i++)
		obj3[i].announce();

	delete[] obj2;
	delete[] obj3;
}