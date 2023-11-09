/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:58:41 by codespace         #+#    #+#             */
/*   Updated: 2023/11/09 01:58:42 by codespace        ###   ########.fr       */
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