#pragma once
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private:
    std::string _target;

    public:
        PresidentialPardonForm(const std::string & target);
        virtual void execute (const Bureaucrat& executor) const;
};