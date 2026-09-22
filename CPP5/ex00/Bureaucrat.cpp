#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(1)
{
    std::cout << "Default Bureceaucrat called" << this->getName() <<
    "with grade" << this->getGrade() << std::endl;
};
 
Bureaucrat::Bureaucrat(std::string name, size_t grade) : _name(name), _grade(grade)
{
    std::cout << "Constructor Bureceaucrat called" << this->getName() <<
    "with grade" << this->getGrade() << std::endl;

    if (grade > 150)
        throw GradeTooHighException();
};

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(1)
{
    std::cout << "Constructor Bureceaucrat called" << this->getName() <<
    "with grade" << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(size_t grade) : _name("Default"), _grade(grade)
{
    std::cout << "Constructor Bureceaucrat called" << this->getName() <<
    "with grade" << this->getGrade() << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName() + "_copy")
{
    std::cout << "Constructor Bureceaucrat called" << this->getName() <<
    "with grade" << this->getGrade() << std::endl;
    *this = other;
};

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}


