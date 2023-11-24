/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:35:55 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:35:56 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() {
	type = "ice";
}

Ice::Ice(const Ice& other) {
	type = other.type;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

Ice::~Ice() {
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}