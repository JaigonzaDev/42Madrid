
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("Default"), _signed(0), _gradeToSign(150), _gradeToExecute(150) 
{
    checkGrade();
    std::cout << "Default Form called: " << this->getName() 
            << " , signed =" << this->getIsSigned() 
            << " , gradeToSign =" << this->getGradeToSign()
            << " , gradeToExecute:" << this->getGradeToExecute() << std::endl;
};
 
Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(0), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
    checkGrade();
    std::cout << "Constructor Form called: " << this->getName() <<
    " , signed =" << this->getIsSigned() << " , gradeToSign ="
    << this->getGradeToSign() << " , gradeToExecute:"
    << this->getGradeToExecute() << std::endl;
};

Form::Form(const Form &other): _name(other.getName()), _signed(other.getIsSigned()), _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute()) 
{
    checkGrade();
    std::cout << "Copy Form called: " << this->getName() <<
    " , signed =" << this->getIsSigned() << " , gradeToSign ="
    << this->getGradeToSign() << " , gradeToExecute:"
    << this->getGradeToExecute() << std::endl;
};

Form::~Form(void)
{
    std::cout << "Destructor Form called" << this->getName() << std::endl;
};

const std::string& Form::getName(void) const
{
    return (_name);
};

bool Form::getIsSigned(void) const
{
    return (_signed);
};

int Form::getGradeToSign(void) const
{
    return (_gradeToSign);
};

int Form::getGradeToExecute(void) const
{
    return (_gradeToExecute);
};

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
};

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
};

void Form::checkGrade() const
{
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
    if (_gradeToExecute < 1 || _gradeToSign < 1)
        throw GradeTooHighException();
};

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
};

Form& Form::operator=(const Form &other)
{
    if (this != &other)
        _signed = other._signed;
    return *this;
};

std::ostream& operator<<(std::ostream &os, const Form &obj)
{
    os << obj.getName()
       << ", signed: " << obj.getIsSigned()
       << ", grade to sign: " << obj.getGradeToSign()
       << ", grade to execute: " << obj.getGradeToExecute();
    return os;
}
