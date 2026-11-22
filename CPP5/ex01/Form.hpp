
#pragma once

#include <string>
#include <exception>
#include <iostream>
class Bureaucrat;

class Form 
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        Form(void);
        Form(const Form &other);
        Form(std::string name, int gradeToSign, int gradeToExecute);
        ~Form();

        Form &operator=(const Form &other);
        
        void beSigned(const Bureaucrat &obj);
        void checkGrade() const;
        const std::string& getName(void) const;
        bool getIsSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;

    class GradeTooHighException : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& bureaucrat);