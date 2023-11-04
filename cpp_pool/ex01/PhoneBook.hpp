#ifndef _PHONE_BOOK_
#define _PHONE_BOOK_
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <stdlib.h>
int checkString(const char *s);

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    int     containsOnlyWhiteSpaces(const char *str);
    void    init(void);
    void    display(void);
    void    display2(void);
};

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