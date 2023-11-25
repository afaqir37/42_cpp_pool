/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:32:42 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/25 02:53:10 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <stdlib.h>
int main()
{
  //Animal obj; // should throw compiler error
  Cat anotherObj; // should work fine

  // const Animal* j = new Dog();
  // const Animal* i = new Cat();
  // delete j;//should not create a leak
  // delete i;
  // return 0;

  // Animal* obj[4];

  // for (int i = 0; i < 2; i++)
  //   obj[i] = new Cat();

  // for (int i = 2; i < 4; i++)
  //   obj[i] = new Dog();

  // for (int i = 0; i < 4; i++)
  //   delete obj[i];

  // test for deep copy:
  // Cat obj;
  // obj.setter(0, "obj + obj + obj");
  
  // std::cout << "ideas of obj: \n";
  // obj.getter();
  
  // Cat anotherObj;
  // anotherObj = obj;
  // anotherObj.setter(0, "anotherObj + anotherObj + anotherObj");


  // std::cout << "re-check obj's ideas: \n";
  // obj.getter();
  // std::cout << "check anotherObj ideas: \n";
  // anotherObj.getter();




}