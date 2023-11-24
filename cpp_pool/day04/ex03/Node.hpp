/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:37:12 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:37:13 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _NODE_HPP_
#define _NODE_HPP_
#include <iostream>
#include "AMateria.hpp"

class Node {
public:
	AMateria* object;
	Node* next;

	Node(AMateria* obj);
	Node(Node& other);
	Node& operator=(const Node& other);
	~Node();


};


#endif
