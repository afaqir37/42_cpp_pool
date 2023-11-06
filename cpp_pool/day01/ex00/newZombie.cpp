#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *obj = new Zombie(name);
	return obj;
}