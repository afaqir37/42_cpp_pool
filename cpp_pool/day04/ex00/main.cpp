#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
  Animal* meta = new Animal();
  Animal* j = new Dog();
  Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
// delete meta;
// delete j;
// delete i;
return 0;

}