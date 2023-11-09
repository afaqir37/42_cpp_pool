/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:00:03 by codespace         #+#    #+#             */
/*   Updated: 2023/11/09 03:04:35 by afaqir           ###   ########.fr       */
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