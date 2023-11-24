/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:37:01 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:37:02 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource& other) {
	for (int i = 0; i < 4; i++)
		materias[i] = other.materias[i] ? other.materias[i]->clone() : NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++)	{
			delete materias[i];
			materias[i] = other.materias[i] ? other.materias[i]->clone() : NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		delete materias[i];
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (materias[i] == NULL) {
			materias[i] = m;
			return;
		}
	}

}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (materias[i] && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return NULL;
}
