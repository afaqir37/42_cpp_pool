#include "FragTrap.hpp"

int main()
{
   FragTrap obj("orten");
   std::cout << "------------\n";
   FragTrap player = obj;
   std::cout << "------------\n";

   FragTrap newPlayer("badMan");
   std::cout << "------------\n";

   
   player = newPlayer;
   std::cout << "-------------\n";

   player.attack("orten");
   player.takeDamage(50);
   player.beRepaired(20);
   player.takeDamage(80);
   std::cout << "-------------\n";
   ClapTrap* ptr = new FragTrap("madMan");
   delete ptr;
}