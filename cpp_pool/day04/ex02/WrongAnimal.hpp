/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:32:59 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:33:00 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WRONG_ANIMAL_HPP_
#define _WRONG_ANIMAL_HPP_
#include <iostream>

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal(std::string name = "WrongAnimal");
        WrongAnimal(WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual ~WrongAnimal();

        std::string getType(void) const;
        void makeSound(void) const;
};


#endif