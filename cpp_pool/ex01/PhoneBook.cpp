#include "PhoneBook.hpp"

void PhoneBook::add(void)
{
    if (index == 8)
        index = 0;
    book[index].init();
    index++;
}

void PhoneBook::search(void)
{
    int tmp;
    
    std::cout << "Enter an index: " << std::endl;
    while (1)
    {
        std::cin >> tmp;
        if (std::cin.eof())
            return ;
        if (tmp >= 8 || tmp >= index || tmp < 0)
        {
            std::cout << "Enter a valid index: " << std::endl;
            continue;
        }
        else
        {
            book[tmp].display();
            break;
        }
    }
    std::cin.ignore();
}
int main(void)
{
    PhoneBook phonebook;
    std::string command;

    phonebook.index = 0;
    while (1)
    {
        if (std::cin.eof())
            return 0;
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        if (std::cin.eof())
            return 0;
        if ((command.compare("ADD") && command.compare("SEARCH") && command.compare("EXIT")))
            continue;

        if (!command.compare("SEARCH"))
            phonebook.search();
        if (!command.compare("ADD"))
            phonebook.add();
        if (!command.compare("EXIT"))
            return 0;
    }
}