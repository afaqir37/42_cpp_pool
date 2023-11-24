/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:37:09 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/24 01:37:10 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Node.hpp"

Node::Node(AMateria* obj) : object(obj), next(NULL) { }

Node::Node(Node& other) : object(NULL), next(NULL) {
	if (other.object)
		object = other.object->clone();
}

Node& Node::operator=(const Node& other) {
	if (this != &other) {
		delete object;
		object = NULL;
		if (other.object)
			object = other.object->clone();
	}
	return *this;
}

Node::~Node() {
	delete object;
}