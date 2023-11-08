#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_
#include <iostream>
#include <new>
class Zombie
{
private:
	std::string name;

public:
	Zombie(std::string name);
	~Zombie();
	
	void announce(void);
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif