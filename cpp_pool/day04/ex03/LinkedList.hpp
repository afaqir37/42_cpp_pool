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

};

#endif