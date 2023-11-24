/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:36:49 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:36:50 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_
#include <iostream>
#include "AMateria.hpp"
#include "Node.hpp"


class LinkedList {
public:
	Node* head;

	LinkedList();
	LinkedList(LinkedList& other);
	LinkedList& operator=(const LinkedList& other);
	~LinkedList();

	void add(AMateria* m);
	int contains(AMateria* obj);
	void setNodeToNull(AMateria* obj);

};

#endif