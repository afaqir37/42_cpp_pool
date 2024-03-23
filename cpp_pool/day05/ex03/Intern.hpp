#ifndef _INTERN_HPP_
#define _INTERN_HPP_

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;
class Bureaucrat;

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    virtual ~Intern();

    AForm* makeForm(std::string const & name, std::string const & target);

private:
    AForm* createShrubberyCreationForm(std::string target);
    AForm* createRobotomyRequestForm(std::string target);
    AForm* createPresidentialPardonForm(std::string target);
};


#endif