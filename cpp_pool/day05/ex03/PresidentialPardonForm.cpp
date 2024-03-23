#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "unknown person", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other) : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    AForm::execute(executor);
    std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

