/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:35:49 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:35:50 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() {
	type = "cure";
}

Cure::Cure(const Cure& other) {
	type = other.type;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

Cure::~Cure() {
}

AMateria* Cure::clone() const {
	return new Cure(*this);

}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}