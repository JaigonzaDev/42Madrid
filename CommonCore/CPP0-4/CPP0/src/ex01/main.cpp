#include "phonebook.hpp"

int main (void)
{
    PhoneBook Book;
    std::string line;

    while (1)
    {
        std::cout << "ADD - SEARCH - EXIT" << std::endl;
        if (!std::getline(std::cin, line))
            return (1);
        if (line == "ADD")
            Book.ADD();
        if (line == "SEARCH")
            Book.SEARCH();
        if (line == "EXIT")
            Book.EXIT();
    }
    return (0);
}