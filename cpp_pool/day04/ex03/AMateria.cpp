/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:35:36 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:35:37 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() {
}

AMateria::AMateria(std::string const & type) {
    this->type = type;
}

AMateria::AMateria(AMateria& other) {
    this->type = other.type;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

AMateria::~AMateria() {
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "this function will never be used to attack " << target.getName() << std::endl;
}