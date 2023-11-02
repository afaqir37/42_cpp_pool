#ifndef _PHONE_BOOK_
#define _PHONE_BOOK_
#include <iostream>
#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void init(void)
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, firstName);
        if (std::cin.eof())
            return;
        std::cout << "Enter last name: ";
        std::getline(std::cin, lastName);
        if (std::cin.eof())
            return;
        std::cout << "Enter a nickname: ";
        std::getline(std::cin, nickname);
        if (std::cin.eof())
            return;
        std::cout << "Enter the phone number: ";
        std::getline(std::cin, phoneNumber);
        if (std::cin.eof())
            return;
        std::cout << "Enter the darkestSecret: ";
        std::getline(std::cin, darkestSecret);
        if (std::cin.eof())
            return;
    }

    void display(void)
    {
        std::cout << firstName << std::endl;
        std::cout << lastName << std::endl;
        std::cout << nickname << std::endl;
        std::cout << phoneNumber << std::endl;
        std::cout << darkestSecret << std::endl;
    }
};

class PhoneBook
{
    Contact book[8];

public:
    int index;
    void add(void);
    void search(void);
};

#endif