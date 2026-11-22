#pragma once
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
    std::string _target;

    public:
        ShrubberyCreationForm(const std::string & target);
        virtual void execute(const Bureaucrat& executor) const;
};