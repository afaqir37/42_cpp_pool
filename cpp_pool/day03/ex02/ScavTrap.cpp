#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called\n";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap& other) :  ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called\n";
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator called\n";
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (energyPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " is out of energy pont :/\n";
		return ;
	}
	energyPoints -= 1;
	// hitPoints of target -= this->attackDamage;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";

}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << name << " have enterred in Gate keeper mode.\n";
}