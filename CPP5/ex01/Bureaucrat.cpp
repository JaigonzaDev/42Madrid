#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(1)
{
    std::cout << "Default Bureaucrat called: " << this->getName() <<
    " with grade " << this->getGrade() << std::endl;
};
 
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    checkGrade();
    std::cout << "Constructor Bureaucrat called: " << this->getName() <<
    " with grade " << this->getGrade() << std::endl;

};

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(1)
{
    checkGrade();
    std::cout << "Constructor Bureaucrat called: " << this->getName() <<
    " with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("Default"), _grade(grade)
{
    checkGrade();
    std::cout << "Constructor Bureaucrat called: " << this->getName() <<
    " with grade " << this->getGrade() << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other.getName()), _grade(other.getGrade())
{
};

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Destructor Bureaucrat called" << this->getName() << std::endl;
};

void Bureaucrat::incrementGrade(void)
{
    if (_grade == 1)
        throw GradeTooHighException();
    _grade--;
};

void Bureaucrat::decrementGrade(void)
{
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
};

const std::string& Bureaucrat::getName(void) const
{
    return (_name);
};

int Bureaucrat::getGrade(void) const
{
    return (_grade);
};

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
};

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
};

void Bureaucrat::checkGrade() const
{
    if (_grade > 150)
        throw GradeTooLowException();
    if (_grade < 1)
        throw GradeTooHighException();
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
        this->checkGrade();
    }
    return *this;
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return os;
};
