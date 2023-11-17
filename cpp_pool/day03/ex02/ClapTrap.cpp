#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "constructor called\n";
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	std::cout << "copy constructor called\n";
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "copy assignment operator called\n";
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints <= 0 || hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy point :/\n";
		return ;
	}
	energyPoints -= 1;
	// hitPoints of target -= this->attackDamage;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";

}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << name << " is defeated :/\n";
		return ;
	}
	hitPoints -= amount;
	std::cout << name << " takes " << amount << " points of damage\n"; 
	if (hitPoints <= 0)
	{
		std::cout << name << " is defeated :/\n";
		return ;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints <= 0)
	{
		std::cout << name << " is out of energy Points :/\n";
		return ;
	}
	if (hitPoints <= 0)
	{
		std::cout << name << " is defeated :/\n";
		return ;
	}
	hitPoints += amount;
	energyPoints -= 1;
	std::cout << name << " repaired itself by " << amount << " hit points\n";
}