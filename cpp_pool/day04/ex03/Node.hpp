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
