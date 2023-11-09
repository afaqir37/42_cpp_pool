/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:05:01 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/09 03:05:02 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::HumanB(std::string name, Weapon& wpn)
{
	this->name = name;
	this->weapon = &wpn;
}

void HumanB::setWeapon(Weapon& club)
{
	weapon = &club;
}

void HumanB::attack(void)
{
	if (weapon == NULL)
	{
		std::cout << name << " doesn't have a weapon :/" << '\n';
		return ;
	}
	std::cout << name << " attack with their " << weapon->getType() << '\n';
}