#ifndef _FORM_HPP_
#define _FORM_HPP_

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    std::string const name;
    std::string const target;
    bool isSigned;
    int const gradeToSign;
    int const gradeToExecute;

public:
    AForm();
    AForm(std::string const & name, std::string const & target, int gradeToSign, int gradeToExecute);
    AForm(AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string const & getName() const;
    std::string const & getTarget() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat &bureaucrat);

    virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif