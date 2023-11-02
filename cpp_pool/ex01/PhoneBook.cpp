#include "PhoneBook.hpp"

void    PhoneBook::add(void)
{
    if (index == 8)
        index = 0;
    book[index].init();
    index++;
}

void    PhoneBook::search(void)
{
    int tmp;

    std::cout << "Enter an index: ";
    std::cin >> tmp;
    book[tmp].display();

}
int main(void)
{
    PhoneBook   phonebook;
    std::string command;
    

    phonebook.index = 0;
    while (1)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        if (command.compare("ADD") && command.compare("SEARCH") && command.compare("EXIT"))
            continue;
        
    
    if (!command.compare("ADD"))
        phonebook.add();
    if (!command.compare("SEARCH"))
        phonebook.search();
    if (!command.compare("EXIT"))
        return 0;

    }

    
}