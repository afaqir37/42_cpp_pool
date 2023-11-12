/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:04:57 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/09 03:04:58 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& tmp) : name(name), weapon(tmp) {}

void HumanA::attack(void)
{
	std::cout << name << " attack with their " << weapon.getType() << '\n';
}