#ifndef _CLAPTRAP_HPP_
#define _CLAPTRAP_HPP_
#include <iostream>
class ClapTrap {
private:
	std::string name;
	int hitPoints = 10;
	int energyPoints = 10;
	int attackDamage = 0;

public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &other);
	void operator=(ClapTrap &other);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif