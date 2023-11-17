#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap constructor called\n";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called\n";
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
}

FragTrap& FragTrap::operator=(FragTrap& other) {
    std::cout << "FragTrap assignment operator called\n";
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called\n";
}

void FragTrap::attack(const std::string& target)
{
    
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "Now Give Me A High Fives\n";
}