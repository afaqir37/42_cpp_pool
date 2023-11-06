#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << name << " Zombie Destructed!" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::init(std::string name)
{
	this->name = name;
}