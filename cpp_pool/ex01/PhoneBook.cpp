#include "PhoneBook.hpp"

void PhoneBook::add(void)
{
    if (index == 8)
    {
        index = 0;
        full = 1;
    }
    book[index].init();
    index++;
}

void PhoneBook::search(void)
{
    int tmp = 0;
    int fakeIndex = index;

    if (index == 0)
        return;
    std::cout << std::setw(10) << "index"
              << "|" << std::setw(10) << "firstname"
              << "|" << std::setw(10) << "lastname"
              << "|" << std::setw(10) << "nickname" << std::endl;
    if (full)
        fakeIndex = 8;
    while (tmp < fakeIndex)
    {
        std::cout << std::setw(10) << tmp << "|";
        book[tmp].display2();
        tmp++;
    }

    std::cout << "Enter an index: " << std::endl;
    while (1)
    {
        std::cin >> tmp;
        if (std::cin.eof())
            return;
        if (tmp >= 8 || tmp >= fakeIndex || tmp < 0)
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
    phonebook.full = 0;
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