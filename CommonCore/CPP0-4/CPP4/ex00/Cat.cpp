#include "Cat.hpp"

Cat::Cat()
{
    _type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Default Destructor called " << _type << std::endl;
}

Cat::Cat(const Cat& copy)
{
    *this = copy;
}

Cat& Cat::operator=(const Cat& copy)
{
    if (this != &copy)
        this->_type = copy._type;
    return (*this);
}

void Cat::makeSound()
{
    std::cout << "MIAU MIAU!!!" << std::endl;
}