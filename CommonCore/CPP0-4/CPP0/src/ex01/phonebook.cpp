#include "phonebook.hpp"

void PhoneBook::ADD(void)
{
    std::cout << "Enter First name:" << std::endl;
    std::getline(std::cin, contacts[total_contacts].first_name);
    std::cout << "Enter Last name:" << std::endl;
    std::getline(std::cin, contacts[total_contacts].last_name);
    std::cout << "Enter Nick name:" << std::endl;
    std::getline(std::cin, contacts[total_contacts].nick_name);
    std::cout << "Enter Phone number:" << std::endl;
    std::getline(std::cin, contacts[total_contacts].phone_number);
    std::cout << "Enter Darkest secret:" << std::endl;
    std::getline(std::cin, contacts[total_contacts].darkest_secret);
    if (total_contacts != 7)
        PhoneBook::total_contacts += 1;
}

void PhoneBook::SEARCH(void)
{
    int index = 0;
    std::string line;
    std::cout << std::setw(10) << "index" << "|" 
              << std::setw(10) << "first name" << "|"  
              << std::setw(10) << "last name" << "|" 
              << std::setw(10) << "nickname" << "|" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|" 
        << std::setw(10) << contacts[i].first_name.substr(0, 10) << "|"  
        << std::setw(10) << contacts[i].last_name.substr(0, 10) << "|" 
        << std::setw(10) << contacts[i].nick_name.substr(0, 10) << "|" << std::endl;
    }
    while (index < 1 || index > 8)
    {
        std::cout << "Introduce Index (1-8)" << std::endl;
        std::getline(std::cin, line);
        index = stoi(line);
    }
    int i = 0;
    while (i != index - 1)
        i++;
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "First Name:" << contacts[index - 1].first_name << std::endl;
    std::cout << "Last Name:" << contacts[index - 1].last_name << std::endl;
    std::cout << "Nick Name:" << contacts[index - 1].nick_name << std::endl;
    std::cout << "Phone Number:" << contacts[index - 1].phone_number << std::endl;
    std::cout << "Darkest Secret:" << contacts[index - 1].darkest_secret << std::endl;
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
}

void PhoneBook::EXIT(void)
{
    std::cout << "Bye, bye ..." << std::endl;
    exit(0);
}