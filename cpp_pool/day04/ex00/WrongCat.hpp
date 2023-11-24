/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:18:12 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:18:13 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WRONG_CAT_HPP_
#define _WRONG_CAT_HPP_
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(WrongCat& other);
        WrongCat& operator=(const WrongCat& other);
        ~WrongCat();

        void makeSound(void) const;
};

#endif