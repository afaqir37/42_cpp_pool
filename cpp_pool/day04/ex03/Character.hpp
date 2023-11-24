/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:35:47 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:35:48 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "LinkedList.hpp"


class Character : public ICharacter {
private:
    std::string name;
    AMateria* slot[4];
    LinkedList list;    

public:
    Character(std::string name);
    Character(Character& other);
    Character& operator=(const Character& other);
    ~Character();

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

    
    int doesItExist(AMateria* obj);

};

#endif