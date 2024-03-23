#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "unknown person", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    AForm::execute(executor);
    std::cout << "Bzzzz... Drilling noises... Bzzzz...\n";

    static int count = 0;
    count++;

    if (count % 2) {
        std::cout << getTarget() << " has been robotomized successfully\n";
    } else {
        std::cout << getTarget() << " robotomization failed\n";
    }
}