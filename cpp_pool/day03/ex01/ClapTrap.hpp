#ifndef _CLAPTRAP_HPP_
#define _CLAPTRAP_HPP_
#include <iostream>
class ClapTrap {
private:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &other);
	ClapTrap& operator=(const ClapTrap &other);
	~ClapTrap();
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif