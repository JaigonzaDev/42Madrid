#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
    Bureaucrat executor("Executor", 1);
    Bureaucrat worker("Worker", 100);

    ShrubberyCreationForm shrubbery("garden");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << "--- Execute before signing ---" << std::endl;
    executor.executeForm(shrubbery);

    std::cout << "\n--- Signing forms ---" << std::endl;
    executor.signForm(shrubbery);
    executor.signForm(robotomy);
    worker.signForm(pardon);
    executor.signForm(pardon);

    std::cout << "\n--- Execute with sufficient grade ---" << std::endl;
    executor.executeForm(shrubbery);
    executor.executeForm(robotomy);
    executor.executeForm(pardon);

    std::cout << "\n--- Execute with insufficient grade ---" << std::endl;
    worker.executeForm(robotomy);

    return (0);
}