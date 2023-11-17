#ifndef _SCAVTRAP_HPP_
#define _SCAVTRAP_HPP_
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap(std::string name);
    ScavTrap(ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();
    
    void attack(const std::string& name);
    void guardGate(void);
};

#endif