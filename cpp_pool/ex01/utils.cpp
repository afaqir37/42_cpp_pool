#include "PhoneBook.hpp"

int checkString(const char *str)
{
    for (int i = 0; str[i] ; i++)
        if (!isdigit(str[i]))
            return 1;

    return 0;
}