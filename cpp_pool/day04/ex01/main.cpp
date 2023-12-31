/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:31:03 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/25 02:51:14 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <stdlib.h>
#include <unistd.h>
int main()
{
  // const Animal* j = new Dog();
  // const Animal* i = new Cat();
  // delete j;//should not create a leak
  // delete i;
  // return 0;

  Animal* obj[4];

  for (int i = 0; i < 2; i++)
    obj[i] = new Cat();

  for (int i = 2; i < 4; i++)
    obj[i] = new Dog();

  for (int i = 0; i < 4; i++)
    delete obj[i];

  // Dog basic;
  // {
  //   Dog tmp = basic;
  // }
  // sleep(4);

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