#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Default Destructor called " << _type << std::endl;
}

Dog::Dog(const Dog& copy)
{
    *this = copy;
}

Dog& Dog::operator=(const Dog& copy)
{
    if (this != &copy)
        this->_type = copy._type;
    return (*this);
}

void Dog::makeSound()
{
    std::cout << "WOOF WOOF!!!" << std::endl;
}