/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:20:07 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/25 02:36:53 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAT_HPP_
#define _CAT_HPP_
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain* brain;
    public:
        Cat();
        Cat(Cat& other);
        Cat& operator=(const Cat& other);
        virtual ~Cat();

        void makeSound(void) const;
        void getter(void);
        void setter(int index, std::string str);
};

#endif