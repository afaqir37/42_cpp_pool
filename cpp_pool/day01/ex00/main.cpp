/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:03:49 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/09 03:03:50 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie obj("NUMBER_1");
	obj.announce();

	Zombie *obj2 = newZombie("NUMBER_2");
	if (!obj2)
		return (-1);
	obj2->announce();
	delete obj2;

	randomChump("NUMBER_3");
}