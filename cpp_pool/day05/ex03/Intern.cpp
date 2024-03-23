#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern& Intern::operator=(const Intern &) {
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}



AForm* Intern::makeForm(std::string const &name, std::string const &target) {
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*formCreators[3])(std::string) = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};

    for (int i = 0; i < 3; i++) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    std::cout << "Form " << name << " not found" << std::endl;
    return NULL;
}