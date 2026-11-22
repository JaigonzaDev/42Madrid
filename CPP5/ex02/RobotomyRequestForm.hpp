#pragma once
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
    std::string _target;

    public:
        RobotomyRequestForm(const std::string & target);
        virtual void execute(const Bureaucrat& executor) const;
};