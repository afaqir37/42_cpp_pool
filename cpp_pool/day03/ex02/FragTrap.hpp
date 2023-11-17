#ifndef _FRAGTRAP_HPP_
#define _FRAGTRAP_HPP_
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap& other);
        FragTrap& operator=(FragTrap& other);
        ~FragTrap();

        virtual void attack(const std::string& target);
        void highFivesGuys(void);
};


#endif