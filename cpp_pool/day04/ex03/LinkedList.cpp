#include "LinkedList.hpp"

LinkedList::LinkedList() : head(NULL) { }

LinkedList::LinkedList(LinkedList& other) {
	if (other.head == NULL)
		head = NULL;
	else {
		head = new Node(*other.head);
		Node* tmpOther = other.head->next;
		Node* tmpThis = head;
		while (tmpOther) {
			tmpThis->next = new Node(*tmpOther);
			tmpOther = tmpOther->next;
			tmpThis = tmpThis->next;
		}
	}
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
	if (this != &other) {
		Node* tmp = head;
		while (tmp) {
			Node* next = tmp->next;
			delete tmp;
			tmp = next;
		}

		if (other.head == NULL)
			head = NULL;
		else {
			head = new Node(*other.head);
			Node* tmpOther = other.head->next;
			Node* tmpThis = head;
			while (tmpOther)
			{
				tmpThis->next = new Node(*tmpOther);
				tmpThis = tmpThis->next;
				tmpOther = tmpOther->next;
			}
		}
	}
	return *this;
}

LinkedList::~LinkedList() {
	Node* tmp = head;
	while (tmp) {
		Node* next = tmp->next;
		delete tmp;
		tmp = next;
	}
}

void LinkedList::add(AMateria* m) {
	if (m == NULL)
		return;
	Node* tmp = head;
	if (tmp == NULL)
		head = new Node(m);
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new Node(m);
	}
}