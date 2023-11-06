#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_
#include <iostream>
#include <new>

class Zombie
{
private:
	std::string name;

public:
	Zombie() {};
	~Zombie();
	
	void announce(void);
	void init(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif