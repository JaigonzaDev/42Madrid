
class Bureaucrat 
{
    private:
        const std::string _name;
        size_t _grade;

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &src)
        Bureaucrat(std::string name, size_t grade);
        Bureaucrat(size_t grade);
        Bureaucrat(std::string name);
        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat &src)

        void incrementGrade(void);
        void decrementGrade(void);

        void getName(void);
        void setName(void);

    class GradeTooHighException : std::exception
    {
        public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : std::exception
    {
        public:
        virtual const char* what() const throw();
    };
};
