#pragma once

#include <string>
#include <exception>
#include <iostream>

class Form;

class Bureaucrat 
{
    private:
        const std::string _name;
        int _grade;
        void checkGrade() const;

    public:
        Bureaucrat(void);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(int grade);
        Bureaucrat(std::string name);
        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat &other);
        
        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(Form &form);

        const std::string& getName(void) const;
        int getGrade(void) const;

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
