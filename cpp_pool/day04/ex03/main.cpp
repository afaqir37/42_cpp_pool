#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "LinkedList.hpp"

int main()
{
	LinkedList list;
	AMateria* obj = new Ice();
	list.add(obj);
	obj = new Cure();
	list.add(obj);
	obj = new Ice();
	list.add(obj);


	Node* tmp = list.head;
	while (tmp)
	{
		std::cout << tmp->object->getType();
		tmp = tmp->next;
	}
}