/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:05:14 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/09 03:05:15 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_
#include <iostream>

class Weapon {
private:
	std::string type;

public:
	Weapon() {};
	Weapon(std::string name);
	const std::string& getType(void);
	void setType(std::string name);
};

#endif