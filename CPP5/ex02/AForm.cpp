
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("Default"), _signed(0), _gradeToSign(150), _gradeToExecute(150) 
{
    checkGrade();
    std::cout << "Default AForm called: " << this->getName() 
            << " , signed =" << this->getIsSigned() 
            << " , gradeToSign =" << this->getGradeToSign()
            << " , gradeToExecute:" << this->getGradeToExecute() << std::endl;
};
 
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(0), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
    checkGrade();
    std::cout << "Constructor AForm called: " << this->getName() <<
    " , signed =" << this->getIsSigned() << " , gradeToSign ="
    << this->getGradeToSign() << " , gradeToExecute:"
    << this->getGradeToExecute() << std::endl;
};

AForm::AForm(const AForm &other): _name(other.getName()), _signed(other.getIsSigned()), _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute()) 
{
    checkGrade();
    std::cout << "Copy AForm called: " << this->getName() <<
    " , signed =" << this->getIsSigned() << " , gradeToSign ="
    << this->getGradeToSign() << " , gradeToExecute:"
    << this->getGradeToExecute() << std::endl;
};

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed!");
};


AForm::~AForm(void)
{
    std::cout << "Destructor AForm called" << this->getName() << std::endl;
};

const std::string& AForm::getName(void) const
{
    return (_name);
};

bool AForm::getIsSigned(void) const
{
    return (_signed);
};

int AForm::getGradeToSign(void) const
{
    return (_gradeToSign);
};

int AForm::getGradeToExecute(void) const
{
    return (_gradeToExecute);
};

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
};

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
};

void AForm::checkGrade() const
{
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
    if (_gradeToExecute < 1 || _gradeToSign < 1)
        throw GradeTooHighException();
};

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
};

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
};

std::ostream& operator<<(std::ostream &os, const AForm &obj)
{
    os << obj.getName()
       << ", signed: " << obj.getIsSigned()
       << ", grade to sign: " << obj.getGradeToSign()
       << ", grade to execute: " << obj.getGradeToExecute();
    return os;
}
