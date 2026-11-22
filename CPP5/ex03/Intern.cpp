#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void)
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern(void)
{
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    if (formName == "shrubbery creation")
    {
        std::cout << "Intern creates shrubbery creation" << std::endl;
        return new ShrubberyCreationForm(target);
    }

    if (formName == "robotomy request")
    {
        std::cout << "Intern creates robotomy request" << std::endl;
        return new RobotomyRequestForm(target);
    }

    if (formName == "presidential pardon")
    {
        std::cout << "Intern creates presidential pardon" << std::endl;
        return new PresidentialPardonForm(target);
    }

    std::cout << "Intern cannot create " << formName << std::endl;
    return NULL;
}