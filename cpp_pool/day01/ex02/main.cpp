/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:04:53 by afaqir            #+#    #+#             */
/*   Updated: 2023/11/09 03:04:54 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address of str               : " << &str << '\n';
	std::cout << "The memory address held by stringPTR: " << stringPTR << '\n';
	std::cout << "The memory address held by stringREF: " << &stringREF << '\n';

	std::cout << "Value of str                 : " << str << '\n';
	std::cout << "Value pointed to by ptr      : " << *stringPTR << '\n';
	std::cout << "Value pointed to by stringREF: " << stringREF << '\n';
}