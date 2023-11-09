/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:00:03 by codespace         #+#    #+#             */
/*   Updated: 2023/11/09 02:00:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_
#include <iostream>
#include <new>
class Zombie
{
private:
	std::string name;

public:
	Zombie(std::string name);
	~Zombie();
	
	void announce(void);
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif