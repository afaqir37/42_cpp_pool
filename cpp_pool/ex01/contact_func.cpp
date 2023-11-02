#include "PhoneBook.hpp"

int Contact::containsOnlyWhiteSpaces(const char *str)
{
	for (int i = 0; str[i]; i++)
		if (!isspace(str[i]))
			return 0;
	return 1;
}

void Contact::init(void)
{
	while (1)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, firstName);
		if (std::cin.eof())
			return;
		if (containsOnlyWhiteSpaces(firstName.c_str()))
			continue;
		else
			break;
	}
	while (1)
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, lastName);
		if (std::cin.eof())
			return;
		if (containsOnlyWhiteSpaces(lastName.c_str()))
			continue;
		else
			break;
	}
	while (1)
	{
		std::cout << "Enter a nickname: ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
			return;
		if (containsOnlyWhiteSpaces(nickname.c_str()))
			continue;
		else
			break;
	}
	while (1)
	{
		std::cout << "Enter the phone number: ";
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
			return;
		if (containsOnlyWhiteSpaces(phoneNumber.c_str()))
			continue;
		else
			break;
	}
	while (1)
	{
		std::cout << "Enter the darkestSecret: ";
		std::getline(std::cin, darkestSecret);
		if (std::cin.eof())
			return;
		if (containsOnlyWhiteSpaces(darkestSecret.c_str()))
			continue;
		else
			break;
	}
}

void Contact::display(void)
{
	std::cout << "first name: " << firstName << std::endl;
	std::cout << "last name: " << lastName << std::endl;
	std::cout << "nickname: " << nickname << std::endl;
	std::cout << "phone number: " << phoneNumber << std::endl;
	std::cout << "darkest secret: " << darkestSecret << std::endl;
}

void Contact::display2(void)
{
	std::cout << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|";
	std::cout << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|";
	std::cout << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << std::endl;
}