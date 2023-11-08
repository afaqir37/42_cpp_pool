#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_
#include <iostream>

class Weapon {
private:
	std::string type;

public:
	Weapon() {};
	Weapon(std::string name);
	~Weapon()
	{
		std::cout << "destroyed\n";
	}
	const std::string& getType(void);
	void setType(std::string name);
};

#endif