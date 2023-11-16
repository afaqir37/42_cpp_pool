#ifndef _SCAVTRAP_HPP_
#define _SCAVTRAP_HPP_
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

public:
    ScavTrap(std::string name);
    ScavTrap(ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();
    
    void attack(const std::string& name);
    void guardGate(void);
};

#endif