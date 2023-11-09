/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:04:46 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/09 03:04:47 by afaqir           ###   ########.fr       */
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
	Zombie() {};
	~Zombie();
	
	void announce(void);
	void init(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif