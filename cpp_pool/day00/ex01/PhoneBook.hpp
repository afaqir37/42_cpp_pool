#ifndef _PHONE_BOOK_
#define _PHONE_BOOK_
#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdlib.h>
#include "Contact.hpp"

int checkString(const char *s);

class PhoneBook
{
    Contact book[8];

public:
    int     index;
    int     full;
    void    add(void);
    void    search(void);
};

#endif