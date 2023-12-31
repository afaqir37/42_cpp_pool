#include "PhoneBook.hpp"
#include "Contact.hpp"

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
    std::string num;
    std::string str;
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
        std::getline(std::cin, num);
        if (std::cin.eof())
            return;
      
        if (checkString(num.c_str()) || std::atoi(num.c_str()) >= 8 || std::atoi(num.c_str()) >= fakeIndex || std::atoi(num.c_str()) < 0)
        {
            std::cout << "Enter a valid index: " << std::endl;
            continue;
        }
        else
        {
            book[std::atoi(num.c_str())].display();
            break;
        }
    }
}
int main(int ac, char **av)
{
    PhoneBook phonebook;
    std::string command;

    (void)av;
    if (ac != 1)
    {
        std::cout << "just run the program without argument ;)" << std::endl;
        return 0;
    }
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