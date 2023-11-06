#ifndef _CONTACT_HPP_
#define _CONTACT_HPP_
#include <iostream>

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



#endif