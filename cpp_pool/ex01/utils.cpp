#include "PhoneBook.hpp"
#include "Contact.hpp"

int checkString(const char *str)
{
    if (!str[0])
        return 1;

    if (str[0] == '+' || str[0] == '-')
        str = str + 1;

    for (int i = 0; str[i]; i++)
        if (!isdigit(str[i]))
            return 1;

    if (strlen(str) == 2 &&  str[0] != '+' && str[0] != '-')
        return 1;
    
    return 0;
}