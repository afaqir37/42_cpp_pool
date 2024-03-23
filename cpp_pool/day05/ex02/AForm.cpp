#include "AForm.hpp"

AForm::AForm() : name("default"), target("unkown person"), isSigned(false), gradeToSign(150), gradeToExecute(150) {
    std::cout << "AForm constructor called\n";
}

AForm::AForm(std::string const & name, std::string const & target, int gradeToSign, int gradeToExecute) : name(name), target(target), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();

    this->isSigned = false;
    std::cout << "AForm constructor called\n";
}

AForm::AForm(AForm& other) : name(other.name), target(other.target), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    this->isSigned = false;
    std::cout << "AForm copy constructor called\n";
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    std::cout << "AForm assignment operator called\n";
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called\n";
}

std::string const & AForm::getName() const {
    return this->name;
}

std::string const & AForm::getTarget() const {
    return this->target;
}

bool AForm::getSigned() const {
    return this->isSigned;
}

int AForm::getGradeToSign() const {
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    this->isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!this->isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->gradeToExecute)
        throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, AForm const &AForm) {
    out << "Form " << AForm.getName() << " is ";
    if (AForm.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << AForm.getGradeToSign() << " to sign and grade " << AForm.getGradeToExecute() << " to execute\n";
    return out;
}


