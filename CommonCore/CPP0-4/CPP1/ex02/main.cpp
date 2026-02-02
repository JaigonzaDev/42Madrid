#include <iostream>

int main (void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "Memory Add - String variable:" << &string << std::endl;
    std::cout << "Value - String variable:" << string << std::endl;
    std::cout << "Memory Add - PTR variable:" << stringPTR << std::endl;
    std::cout << "Value - PTR variable:" << *stringPTR << std::endl;
    std::cout << "Memory Add - REF variable:" << &stringREF << std::endl;
    std::cout << "Value - REF variable:" << stringREF << std::endl;
    return (0);
}