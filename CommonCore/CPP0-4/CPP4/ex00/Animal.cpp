#include "Animal.hpp"

Animal::Animal()
{
    _type = "Animal";
    std::cout << "Animal Constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Default Destructor called " << _type << std::endl;
}

Animal& Animal::operator=(const Animal& copy)
{
    if (this != &copy)
        this->_type = copy._type;
    return (*this);
}

Animal::Animal(const Animal& copy)
{
    *this = copy;
    std::cout << "Animal copy Constructor called" << std::endl;
}


void Animal::makeSound(void)
{
    std::cout << "Unknown animal sound..." << std::endl;
}

std::string Animal::getType()
{
    return (_type);
}


