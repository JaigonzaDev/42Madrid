
#pragma once

#include <string>
#include <exception>
#include <iostream>
class Bureaucrat;

class AForm 
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        AForm(void);
        AForm(const AForm &other);
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        virtual ~AForm(void);

        AForm &operator=(const AForm &other);
        
        void beSigned(const Bureaucrat &obj);
        void checkGrade() const;
        const std::string& getName(void) const;
        bool getIsSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;
        virtual void execute(const Bureaucrat& obj) const = 0;

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

    class FormNotSignedException: public std::exception
    {
        public:
        virtual const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& os, const AForm& bureaucrat);