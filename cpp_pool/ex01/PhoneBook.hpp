#ifndef _PHONE_BOOK_
#define _PHONE_BOOK_
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    int containsOnlyWhiteSpaces(const char *str)
    {
        for (int i = 0; str[i]; i++)
            if (!isspace(str[i]))
                return 0;
        return 1;
    }

    void init(void)
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

    void display(void)
    {
        std::cout << firstName << std::endl;
        std::cout << lastName << std::endl;
        std::cout << nickname << std::endl;
        std::cout << phoneNumber << std::endl;
        std::cout << darkestSecret << std::endl;
    }

    void display2(void)
    {
        std::cout << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|";
        std::cout << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|";
        std::cout << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << std::endl;
    }
};

class PhoneBook
{
    Contact book[8];

public:
    int index;
    int full;
    void add(void);
    void search(void);
};

#endif