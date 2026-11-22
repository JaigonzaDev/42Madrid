#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "--- Valid bureaucrat and grade changes ---" << std::endl;
    try
    {
        Bureaucrat jaime("Jaime", 2);
        std::cout << jaime << std::endl;

        jaime.incrementGrade();
        std::cout << "After increment: " << jaime << std::endl;

        jaime.decrementGrade();
        std::cout << "After decrement: " << jaime << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Invalid constructor grades ---" << std::endl;
    try
    {
        Bureaucrat tooLow("TooLow", 151);
        std::cout << tooLow << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "151: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat tooHigh("TooHigh", 0);
        std::cout << tooHigh << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "0: " << e.what() << std::endl;
    }

    std::cout << "\n--- Exceptions at the boundaries ---" << std::endl;
    try
    {
        Bureaucrat highest("Highest", 1);
        std::cout << highest << std::endl;
        highest.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Incrementing grade 1: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat lowest("Lowest", 150);
        std::cout << lowest << std::endl;
        lowest.decrementGrade();
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Decrementing grade 150: " << e.what() << std::endl;
    }

    std::cout << "\n--- Copy constructor and assignment ---" << std::endl;
    Bureaucrat original("Original", 42);
    Bureaucrat copy(original);
    Bureaucrat assigned("Assigned", 100);
    assigned = original;

    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy: " << copy << std::endl;
    std::cout << "Assigned: " << assigned << std::endl;

    return (0);
}