#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* obj = new(std::nothrow) Zombie[N];
	if (!obj)
		return (NULL);
	
	for (int i = 0; i < N; i++)
		obj[i].init(name);
	
	return obj;
}