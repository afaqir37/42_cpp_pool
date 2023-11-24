/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:35:40 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:35:41 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AMATERIA_HPP_
#define _AMATERIA_HPP_
#include <iostream>

class ICharacter;

class AMateria {
protected:
    std::string type;
public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

};

#endif