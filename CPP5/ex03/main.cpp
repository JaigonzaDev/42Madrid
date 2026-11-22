#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
    Intern intern;
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 100);

    AForm* shrubbery = intern.makeForm("shrubbery creation", "garden");
    AForm* robotomy = intern.makeForm("robotomy request", "Bender");
    AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");
    AForm* unknown = intern.makeForm("unknown form", "Nobody");

    std::cout << "\n--- Unknown form ---" << std::endl;
    if (unknown == NULL)
        std::cout << "Unknown form was not created" << std::endl;

    std::cout << "\n--- Signing and executing ---" << std::endl;
    if (shrubbery != NULL)
    {
        boss.signForm(*shrubbery);
        boss.executeForm(*shrubbery);
    }

    if (robotomy != NULL)
    {
        boss.signForm(*robotomy);
        boss.executeForm(*robotomy);
    }

    if (pardon != NULL)
    {
        worker.signForm(*pardon);
        boss.signForm(*pardon);
        worker.executeForm(*pardon);
        boss.executeForm(*pardon);
    }

    delete shrubbery;
    delete robotomy;
    delete pardon;

    return (0);
}