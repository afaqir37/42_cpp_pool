/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:05:04 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/09 03:05:05 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}
	std::cout << "-------------------------------\n";
	{
		Weapon j = Weapon("attay mna3na3");
		HumanB ali("Ali");
		ali.setWeapon(j);
		ali.attack();
		j.setType("Pistol");
		ali.attack();
	}
	std::cout << "-------------------------------\n";
	{
		Weapon h = Weapon("Ma9la");
		HumanB anas("Anass");
		anas.attack();
		anas.setWeapon(h);
		anas.attack();
	}	
}