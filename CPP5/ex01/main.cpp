#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    std::cout << "--- Valid form and signing ---" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat worker("Worker", 100);
        Form form("Holiday request", 50, 100);

        std::cout << form << std::endl;
        boss.signForm(form);
        worker.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Invalid form grades ---" << std::endl;
    try
    {
        Form invalidLow("Invalid low", 151, 100);
        std::cout << invalidLow << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "151: " << e.what() << std::endl;
    }

    try
    {
        Form invalidHigh("Invalid high", 0, 100);
        std::cout << invalidHigh << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "0: " << e.what() << std::endl;
    }

    std::cout << "\n--- Form copy and assignment ---" << std::endl;
    try
    {
        Form original("Original", 50, 100);
        Form copy(original);
        Form assigned("Assigned", 20, 80);

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;

        assigned = original;
        std::cout << "Assigned: " << assigned << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}