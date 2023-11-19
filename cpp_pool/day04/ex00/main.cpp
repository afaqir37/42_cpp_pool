#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); //will output the cat sound!
  j->makeSound();
  meta->makeSound();
  std::cout << "--------------------\n";

  const WrongAnimal* first = new WrongAnimal();
  const WrongAnimal* second = new WrongCat();
  first->makeSound();
  second->makeSound();

  std::cout << "---------------------\n";

  delete meta;
  delete j;
  delete i;

  delete first;
  delete second;
  return 0;

}