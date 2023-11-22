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