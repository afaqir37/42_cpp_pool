/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:04:49 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/09 03:04:50 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* obj = new(std::nothrow) Zombie[N];
	if (!obj)
		return (NULL);
	
	for (int i = 0; i < N; i++)
		obj[i].init(name);
	
	return obj;
}