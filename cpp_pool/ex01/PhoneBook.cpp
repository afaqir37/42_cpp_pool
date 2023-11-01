#include "PhoneBook.hpp"

int main(void)
{
    std::string command;

    while (command.compare("ADD") && command.compare("SEARCH") && command.compare("EXIT"))
    {
        std::cout << "Enter a command: ";
        std::cin >> command;
    }

    
}