#ifndef _PHONE_BOOK_
# define _PHONE_BOOK_
#include <iostream>
#include <string>

class Contact {
public:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};


class PhoneBook {
    Contact book[8];
};


# endif