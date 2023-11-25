/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:23:03 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/25 02:25:07 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WRONGANIMAL_HPP_
#define _WRONGANIMAL_HPP_
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