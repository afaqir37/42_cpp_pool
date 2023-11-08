#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *obj = new(std::nothrow) Zombie(name);
	if (!obj)
		return NULL;
	return obj;
}