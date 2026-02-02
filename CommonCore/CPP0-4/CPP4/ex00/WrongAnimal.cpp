#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    _type = "WrongAnimal";
    std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Default Destructor called " << _type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
    if (this != &copy)
        this->_type = copy._type;
    return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
    *this = copy;
    std::cout << "WrongAnimal copy Constructor called" << std::endl;
}


void WrongAnimal::makeSound(void)
{
    std::cout << "Wrong animal sound..." << std::endl;
}

std::string WrongAnimal::getType()
{
    return (_type);
}


